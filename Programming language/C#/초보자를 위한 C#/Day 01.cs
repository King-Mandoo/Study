using System;

namespace ConsoleApp1
{
    class C_sharp_book
    {
        static void Main()  // 잘보면 Main이 대문자다. 주의필요  C언어는 int main() 이었기에 헷갈릴 수 있다.
        {
            int radius = 4;
            const double PI = 3.14159;
            double circum, area;

            area = PI * radius * radius;
            circum = 2 * PI * radius;

            Console.WriteLine("반지름 = {0}, PI = {1}", radius, PI);
            Console.WriteLine("원의 면적: {0}", area);
            Console.WriteLine("원주: {0}", circum);
        }
    }
}

------------------------------------------------

using System;

namespace ConsoleApp1
{
    class C_sharp_book
    {
        static void Main()
        {
            int x, y;
            for (x = 0; x < 10; x++, System.Console.Write("\n"))
                for (y = 0; y < 10; y++)
                    System.Console.Write("X");
        }
    }
}

---------------------------------------------------

using System;

namespace ConsoleApp1
{
    class C_sharp_book
    { 
        static void Main()
        {
            System.Console.WriteLine("잘 살펴봐!");
            System.Console.WriteLine("찾을 수 있을 거야!");
        }
    }
}

------------------------------------------------------

using System;

namespace ConsoleApp1
{
    class C_sharp_book
    {
        static void Main()
        {
            int x, y;
            for (x = 0; x < 10; x++, System.Console.Write("\n"))
                for (y = 0; y < 10; y++)
                    System.Console.Write("{0}", (char)1);
        }
    }
}
