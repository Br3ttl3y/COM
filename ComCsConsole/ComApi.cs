using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace ComCsConsole
{
    internal static class ComApi
    {
        internal static void DynamicCluck()
        {
            Cluck();
        }

        // This will not work for you, make sure you build the COMConsoleApp.dll
        // And point this to the Full Qualified Path of that new DLL.
        [DllImport(@"D:\Code\COMConsoleApp\debug\COMConsoleApp.dll")]
        private static extern void Cluck();
    }
}
