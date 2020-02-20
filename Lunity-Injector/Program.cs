using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.IO.Pipes;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Runtime.InteropServices;
using System.Security.AccessControl;
using System.Security.Principal;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Lunity_Injector
{
    public class Program
    {
        static Process mcProc;
        static IntPtr pHandle;
        public static void Main(string[] args)
        {
            Console.WriteLine("Lunity injector");
            
            Process[] mcProcs = Process.GetProcessesByName("Minecraft.Windows");
            if (mcProcs.Length == 0)
            {
                Console.WriteLine("Could not find Minecraft!");
                Thread.Sleep(1000);
                return;
            }

            mcProc = mcProcs[0];
            pHandle = Win32.OpenProcess(0x1F0FFF, true, mcProc.Id);

            Console.Write("Path to CLR Injector: ");
            string clrDll = Console.ReadLine();
            clrDll = clrDll.Replace("\"", "");
            Console.Write("Path to Injectable: ");
            string clrInjectable = Console.ReadLine();

            applyAppPackages(clrDll);

            InjectDll(clrDll);
            Console.WriteLine("Injected CLR!");

            IPAddress localAddr = IPAddress.Parse("127.0.0.1");
            TcpListener server = new TcpListener(localAddr, 600);
            server.Start();

            while (true)
            {
                Console.WriteLine("Waiting for a connection...");
                TcpClient client = server.AcceptTcpClient();
                Console.WriteLine("Connection received!");
            }
        }

        public static void applyAppPackages(string file)
        {
            FileInfo fInfo = new FileInfo(file);
            FileSecurity fSecurity = fInfo.GetAccessControl();
            fSecurity.AddAccessRule(new FileSystemAccessRule(new SecurityIdentifier(WellKnownSidType.WorldSid, null), FileSystemRights.FullControl, InheritanceFlags.None, PropagationFlags.NoPropagateInherit, AccessControlType.Allow));
            fInfo.SetAccessControl(fSecurity);
        }

        public static String GetStringResource(IntPtr hModuleInstance, uint uiStringID)
        {
            StringBuilder sb = new StringBuilder(255);
            Win32.LoadString(hModuleInstance, uiStringID, sb, sb.Capacity + 1);
            return sb.ToString();
        }

        //Code from https://github.com/erfg12/memory.dll/blob/master/Memory/memory.cs
        public static void InjectDll(String strDllName)
        {
            IntPtr bytesout;

            foreach (ProcessModule pm in mcProc.Modules)
            {
                if (pm.ModuleName.StartsWith("inject", StringComparison.InvariantCultureIgnoreCase))
                    return;
            }

            if (!mcProc.Responding)
                return;

            int lenWrite = strDllName.Length + 1;
            UIntPtr allocMem = Win32.VirtualAllocEx(pHandle, (UIntPtr)null, (uint)lenWrite, 0x00001000 | 0x00002000, 0x04);

            Win32.WriteProcessMemory(pHandle, allocMem, strDllName, (UIntPtr)lenWrite, out bytesout);
            UIntPtr injector = Win32.GetProcAddress(Win32.GetModuleHandle("kernel32.dll"), "LoadLibraryA");

            if (injector == null)
                return;

            IntPtr hThread = Win32.CreateRemoteThread(pHandle, (IntPtr)null, 0, injector, allocMem, 0, out bytesout);
            if (hThread == null)
                return;

            int Result = Win32.WaitForSingleObject(hThread, 10 * 1000);
            if (Result == 0x00000080L || Result == 0x00000102L)
            {
                if (hThread != null)
                    Win32.CloseHandle(hThread);
                return;
            }
            Win32.VirtualFreeEx(pHandle, allocMem, (UIntPtr)0, 0x8000);

            if (hThread != null)
                Win32.CloseHandle(hThread);

            return;
        }
    }
}
