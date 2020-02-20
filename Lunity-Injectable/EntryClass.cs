using System;

namespace Lunity_Injectable
{
    public class EntryClass
    {
        public static unsafe void Main(string param)
        {
            //Code to kill CPU so we know its running :'D
            UInt64 i = 0;
            while (true)
            {
                i++;
                if(i < i + 1)
                {
                    *(UInt64*)(0x7FF668C41C8C) = i;
                    continue;
                }
            }
        }
    }
}
