using System;

namespace Lunity_Injectable
{
    public class EntryClass
    {
        public static void Main(string param)
        {
            unsafeStarter();
        }

        public static unsafe void unsafeStarter()
        {
            //Code to kill CPU so we know its running :'D
            UInt64 i = 0;
            while (true)
            {
                i++;
                if (i < i + 1)
                {
                    *(UInt64*)(0x7FF790A61CBC) = i;
                    continue;
                }
            }
        }
    }
}
