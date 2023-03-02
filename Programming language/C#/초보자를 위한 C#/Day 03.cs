2022.07.20.수

using System;
class C_sharp_book
{
    public static void Main()
    {
        int ctr;
        char ch;

        Console.WriteLine("\n숫자 값\n");

        for(ctr = 97; ctr <= 122; ctr++)
        {
            ch = (char)ctr;
            Console.WriteLine("{0}은 {1}이다.", ctr, ch);
        }
    }
}

---------------------------------

using System;
class C_sharp_book
{
    public static void Main()
    {
        float xyz = 123.456f;  // f 잊지말기

        Console.WriteLine(xyz);
    }
}

----------------------------------

using System;
class C_sharp_book
{
    public static void Main()
    {
        double my_double;
        decimal my_decimal;

        my_double = 3.14;
        my_decimal = 3.14m;    // m 잊지말기

        Console.WriteLine("My double is {0}\nMy decimal is {1}", my_double, my_decimal);
    }
}

-------------------------------------

using System;
class C_sharp_book
{
    public static void Main()
    {
        int a = 10;
        float b = 1.879f;

        Console.WriteLine("a = {0}\nb = {1}", a, b);
    }
}

