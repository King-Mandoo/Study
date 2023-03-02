using System;
class C_sharp_book
{
    public static void Main()
    {
        char file_type = 'j';

        if (file_type == 's')
            Console.WriteLine("small");
        else if (file_type == 'm')
            Console.WriteLine("middle");
        else if (file_type == 'l')
            Console.WriteLine("large");
        else
            Console.WriteLine("Nothing");
    }
}

-------------------------------------

using System;
class C_sharp_book
{
    public static void Main()
    {
        int x = 2;
        int y = 3;

        if (x == 2)                // 이렇게가 되네..??
            if (y > 3)
                x = 5;
            else 
                x = 9;
    }
}

--------------------------------------

using System;
class C_sharp_book
{
    public static void Main()
    {
        int count = 1;

        while(count < 100)
        {
            Console.WriteLine("{0}", count);
            count++;
        }
    }
}

--------------------------------------

using System;
class C_sharp_book
{
    public static void Main()
    {
        for(int count = 1; count < 100; count++)
        {
            Console.WriteLine("{0}", count);
        }
    }
}

--------------------------------------

using System;
class C_sharp_book
{
    public static void Main()
    {
        for (int i = 0; ++i <= 10; Console.WriteLine("{0}", i)) ;
    }
}
              
                                          // 1부터 10까지 출력 두 가지 방법.

using System;
class C_sharp_book
{
    public static void Main()
    {
        for (int i = 1; i <= 10; Console.WriteLine("{0}", i), i++) ;
    }
}

----------------------------------------

using System;
class C_sharp_book
{
    public static void Main()
    {
        string name = "Sun";

        switch(name)
        {
            case "Robert":
                Console.WriteLine("HI Bob");
                break;
            case "Richard":
                Console.WriteLine("HI Rich");
                break;
            case "Kalee":
                Console.WriteLine("You GO Girl!");
                break;
            default:
                Console.WriteLine("Hi {0}", name);
                break;
        }
    }
}

----------------------------------------

using System;
class C_sharp_book
{
    public static void Main()
    {
        System.Random rnd = new System.Random();

        int nbr = 0;
        int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0;

        for(int i = 0; i < 100; i++)
        {
            nbr = (int)rnd.Next(1, 7);

            Console.WriteLine("{0}번째 주사위 수 : {1}", i + 1, nbr);

            if (nbr == 1)
                n1++;
            else if (nbr == 2)
                n2++;
            else if (nbr == 3)
                n3++;
            else if (nbr == 4)
                n4++;
            else if (nbr == 5)
                n5++;
            else
                n6++;
        }
        Console.WriteLine("1이 나온 횟수 : {0}", n1);
        Console.WriteLine("2가 나온 횟수 : {0}", n2);
        Console.WriteLine("3이 나온 횟수 : {0}", n3);
        Console.WriteLine("4가 나온 횟수 : {0}", n4);
        Console.WriteLine("5가 나온 횟수 : {0}", n5);
        Console.WriteLine("6이 나온 횟수 : {0}", n6);
    }
}
