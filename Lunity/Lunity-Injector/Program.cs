using System;
using System.Diagnostics;
using System.IO;
using System.Security.AccessControl;
using System.Security.Principal;
using System.Threading;

namespace Lunity_Injector
{
    class Program
    {
        static bool started = false;
        static bool debug = true;
        public static string debugLog = Environment.ExpandEnvironmentVariables(@"%appdata%\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\debug.txt");
        static string lastLog = "";
        static void displayError(string error)
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine(error);
            Console.ForegroundColor = ConsoleColor.White;
        }
        public static Process game;
        public static IntPtr pHandle;
        public static string dataDir = Environment.ExpandEnvironmentVariables(@"%appdata%\Lunity");
        static void Main(string[] args)
        {
            Console.ForegroundColor = ConsoleColor.White;
            Console.WriteLine("Lunity injector by ASM");
            Console.WriteLine("Verifying Lunity...");
            if (!verifyLunity())
            {
                Console.WriteLine("An error occoured during Lunity verification...");
                Console.WriteLine("For help, join this server: https://discord.gg/gNdBNTT");
                Console.WriteLine("When asking for help, please supply the ENTIRE error above.");
                Console.ReadLine();
                return;
            }
            Console.WriteLine("Lunity is properly downloaded!");
            Console.WriteLine("Waiting for Minecraft...");
            awaitGame();
            Console.WriteLine("Minecraft found, injecting!");
            if (started)
            {
                Thread.Sleep(2000);
            }
            injectLunity();
            Console.WriteLine("Injected!");
            displayError("Youre using a debug build!");
            Console.BackgroundColor = ConsoleColor.DarkBlue;
            if (debug)
            {
                lastLog = File.ReadAllText(debugLog);
                while (true)
                {
                    string newLog = File.ReadAllText(debugLog);
                    string added = newLog.Substring(lastLog.Length);
                    Console.Write(added);
                    lastLog = newLog;
                    Thread.Sleep(100);
                }
            }
            Thread.Sleep(1000);
        }

        public static void applyAppPackages(string file)
        {
            FileInfo fInfo = new FileInfo(file);
            FileSecurity fSecurity = fInfo.GetAccessControl();
            fSecurity.AddAccessRule(new FileSystemAccessRule(new SecurityIdentifier("S-1-15-2-1"), FileSystemRights.FullControl, InheritanceFlags.None, PropagationFlags.NoPropagateInherit, AccessControlType.Allow));
            fInfo.SetAccessControl(fSecurity);
        }

        private static bool verifyLunity()
        {
            try
            {
                if (!Directory.Exists(dataDir))
                {
                    Directory.CreateDirectory(dataDir);
                }
                if (!File.Exists(dataDir + "/Lunity.dll"))
                {
                    displayError("Missing Lunity.dll!");
                    return false;
                }
                applyAppPackages(dataDir + "/Lunity.dll");
                return true;
            }catch(Exception ex)
            {
                Console.WriteLine(ex.Message);
                Console.WriteLine(ex.StackTrace);
                return false;
            }
        }

        public static void awaitGame()
        {
            while (true)
            {
                Thread.Sleep(100);
                Process[] possiblilties = Process.GetProcessesByName("Minecraft.Windows");
                if (possiblilties.Length < 1)
                {
                    if (!started)
                    {
                        Process.Start("minecraft://");
                        started = true;
                    }
                    continue;
                }
                Process tempGame = possiblilties[0];
                game = tempGame;
                pHandle = Win32.OpenProcess(0x1F0FFF, true, game.Id);
                break;
            }
        }
        public static void injectLunity()
        {
            InjectDll(dataDir + "/Lunity.dll");
        }

        //Code from https://github.com/erfg12/memory.dll/blob/master/Memory/memory.cs
        public static void InjectDll(string strDllName)
        {
            IntPtr bytesout;

            foreach (ProcessModule pm in game.Modules)
            {
                if (pm.ModuleName.StartsWith("inject", StringComparison.InvariantCultureIgnoreCase))
                    return;
            }

            if (!game.Responding)
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
