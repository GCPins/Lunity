using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Net;
using System.Security.AccessControl;
using System.Security.Principal;
using System.Threading;
using System.Web.Script.Serialization;

namespace Lunity_Injector
{
    class Program
    {
        static bool started = false;
        static bool beta = false;
#if DEBUG
        static bool debug = true;
#else
        static bool debug = false;
#endif
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
        static string[] neededLibs = { "Lunity.dll" };
        static void Main(string[] args)
        {
            if (debug)
            {
                displayError("Youre using a debug build!");
                File.Create(debugLog).Close();
                Console.BackgroundColor = ConsoleColor.DarkBlue;
                new Thread(() =>
                {
                    if (debug)
                    {
                        using (FileStream stream = File.Open(debugLog, FileMode.Open, FileAccess.Read, FileShare.ReadWrite))
                        {
                            using (StreamReader reader = new StreamReader(stream))
                            {
                                while (!reader.EndOfStream)
                                {
                                    lastLog += reader.ReadLine();
                                }
                            }
                        }
                        while (true)
                        {
                            string newLog = "";
                            using (FileStream stream = File.Open(debugLog, FileMode.Open, FileAccess.Read, FileShare.ReadWrite))
                            {
                                using (StreamReader reader = new StreamReader(stream))
                                {
                                    while (!reader.EndOfStream)
                                    {
                                        newLog += reader.ReadLine();
                                    }
                                }
                            }
                            string added = newLog.Substring(lastLog.Length);
                            Console.WriteLine(added);
                            lastLog = newLog;
                            Thread.Sleep(100);
                        }
                    }
                }).Start();
            }
            Console.ForegroundColor = ConsoleColor.White;
            Console.BackgroundColor = ConsoleColor.Black;
            Console.WriteLine("Lunity injector by ASM");
            if (!beta)
            {
                Console.WriteLine("Downloading lunity...");
                updateLunity();
                Console.WriteLine("Lunity updated!");
            }
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
                Thread.Sleep(6000);
            }
            injectLunity();
            Console.WriteLine("Injected!");
            if (!debug)
                Thread.Sleep(1000);
            else
                Console.ReadLine();
        }

        public static string getLatestVersion()
        {
            WebClient wc = new WebClient();
            wc.Headers.Add("user-agent", " Mozilla/5.0 (Windows NT 6.1; WOW64; rv:25.0) Gecko/20100101 Firefox/25.0");
            JavaScriptSerializer serializer = new JavaScriptSerializer();
            List<RootObject> data = serializer.Deserialize<List<RootObject>>(wc.DownloadString("https://api.github.com/repos/LunityClient/LunityReleases/releases"));
            return data[0].tag_name;
        }
        public static bool downloadLunity(string ver)
        {
            WebClient wc = new WebClient();
            wc.Headers.Add("user-agent", " Mozilla/5.0 (Windows NT 6.1; WOW64; rv:25.0) Gecko/20100101 Firefox/25.0");
            JavaScriptSerializer serializer = new JavaScriptSerializer();
            List<RootObject> data = serializer.Deserialize<List<RootObject>>(wc.DownloadString("https://api.github.com/repos/LunityClient/LunityReleases/releases"));
            foreach (RootObject ro in data)
            {
                if (ro.tag_name == ver)
                {
                    downloadFile(dataDir + "/Lunity.dll", ro.assets[0].browser_download_url);
                    return true;
                }
            }
            return false;
        }
        public static void downloadFile(string dest, string url)
        {
            WebClient wc = new WebClient();
            wc.Headers.Add("user-agent", " Mozilla/5.0 (Windows NT 6.1; WOW64; rv:25.0) Gecko/20100101 Firefox/25.0");
            wc.DownloadFile(url, dest);
        }
        public static void updateLunity()
        {
            try
            {
                downloadLunity(getLatestVersion());
            }
            catch (Exception)
            {
                Console.WriteLine("An error occoured while updating!");
                Console.WriteLine("Press enter to try injecting anyway or close the window to quit");
                Console.ReadLine();
            }
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
                foreach(string lib in neededLibs)
                {
                    if (!File.Exists(dataDir + "/" + lib))
                    {
                        displayError("Missing "+ lib + "!");
                        return false;
                    }
                    applyAppPackages(dataDir + "/" + lib);
                }
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
            foreach (string lib in neededLibs)
            {
                InjectDll(dataDir + "/" + lib);
            }
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
