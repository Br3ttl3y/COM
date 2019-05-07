using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ComCsConsole
{
    /// <summary>
    /// To build and run this properly:
    /// Change COMConsoleApp to build as DLL before continuing with this
    /// program.  Also when you build the DLL make sure you edit the path to
    /// that DLL in the ComApi.cs file.
    /// </summary>
    internal class Program

    {
        private static void Main(string[] args)
        {
            ComApi.DynamicCluck();

#if DEBUG
            Console.WriteLine(Environment.NewLine);
            Console.WriteLine("Press enter to close...");
            Console.ReadLine();
#endif
        }
    }
}
