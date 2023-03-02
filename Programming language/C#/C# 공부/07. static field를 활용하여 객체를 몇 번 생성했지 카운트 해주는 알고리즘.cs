using System;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            Instance_count c1 = new Instance_count();
            Console.WriteLine("the number of times the instance was called : {0}", Instance_count.count);
            Instance_count c2 = new Instance_count();
            Console.WriteLine("the number of times the instance was called : {0}", Instance_count.count);
            Instance_count c3 = new Instance_count();
            Console.WriteLine("the number of times the instance was called : {0}", Instance_count.count);
        }
    }

    class Instance_count
    {
        public static int count;

        public Instance_count()
        {
            count++;
        }
    }
}
