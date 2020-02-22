namespace Injectable
{
    public class EntryClass
    {
        public static int Main(string param)
        {
            unsafeStarter();
            return 0;
        }

        public static unsafe void unsafeStarter()
        {
            //Code to kill CPU so we know its running :'D
            ulong i = 0;
            while (true)
            {
                i++;
                if (i < i + 1)
                {
                    *(ulong*)(0x000000459D4FFC98) = i;
                    continue;
                }
            }
        }
    }
}