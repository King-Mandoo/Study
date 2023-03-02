using System;
class C_sharp_book
{
    public static void Main()
    {
        int a = 66;

        if (a > 65)
        {
            Console.WriteLine("The value is greater that 65!");
        }
    }
}

---------------------------------------------------------

using System;
class C_sharp_book
{
    public static void Main()
    {
        char a = 't';

        if (a == 't' || a == 'T')
        {
            Console.WriteLine("a is 't' or 'T'.");
        }
    }
}

----------------------------------------------------------

using System;
class C_sharp_book
{
    public static void Main()
    {
        int intVal = 5;
        short ShortVal = (short)intVal;  // 명시적 형변환
    }
}

-----------------------------------------------------------

using System;
class C_sharp_book
{
    public static void Main()
    {
        decimal DecVal = 3.14m;
        long LongVal = (long)DecVal;
    }
}

------------------------------------------------------------

using System;
class C_sharp_book
{
    public static void Main()
    {
        int ch = 65;
        char Charval = (char)ch;
    }
}
