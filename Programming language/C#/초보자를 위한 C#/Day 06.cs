using System;

class circle
{
    public int x;
    public int y;
    public double radius;
}
class C_sharp_book
{
    public static void Main()
    {
        circle c1 = new circle();
        circle c2 = new circle();

        c1.x = 3;
        c1.y = 5;
        c1.radius = 10.62;

        c2.x = 10;
        c2.y = 15;
        c2.radius = 20.52;

        Console.WriteLine("c1의 중심점: {0}, {1}\nc1의 반지름: {2}", c1.x, c1.y, c1.radius);
        Console.WriteLine("---------------------------------------");
        Console.WriteLine("c2의 중심점: {0}, {1}\nc2의 반지름: {2}", c2.x, c2.y, c2.radius);
    }
}

--------------------------------------

using System;

class circle
{
    private int x;
    private int y;
    private double radius;

    public int X
    {
        get { return x; }
        set { x = value; }
    }

    public int Y
    {
        get { return y; }
        set { y = value; }
    }

    public double Radius
    {
        get { return radius; }
        set { radius = value; }
    }
}
class C_sharp_book
{
    public static void Main()
    {
        circle c1 = new circle();
        circle c2 = new circle();

        c1.X = 13;
        c1.Y = 50;
        c1.Radius = 10.62;

        c2.X = 10;
        c2.Y = 15;
        c2.Radius = 20.52;

        Console.WriteLine("c1의 중심점: {0}, {1}\nc1의 반지름: {2}", c1.X, c1.Y, c1.Radius);
        Console.WriteLine("---------------------------------------");
        Console.WriteLine("c2의 중심점: {0}, {1}\nc2의 반지름: {2}", c2.X, c2.Y, c2.Radius);
    }
}

----------------------------------------------------------

using System;

class MyNumber
{
    private int num;

    public int Num
    {
        get
        {
            return num / 100;
        }
        set
        {
            num = value * 100;
        }
    }
}
class C_sharp_book
{
    public static void Main()
    {
        MyNumber floo = new MyNumber();

        floo.Num = 50;

        Console.WriteLine("{0}", floo.Num);
    }
}

-----------------------------------------------------

using System;
using System;

class die
{
    public int dice_page;
    public int dice_number;
    public int dice_count;
}
class C_sharp_book
{
    public static void Main()
    {
        die dice = new die();

        dice.dice_page = 6;
        dice.dice_number = 5;
        dice.dice_count = 3;

        Console.WriteLine("주사위 면 수 : {0}\n주사위 면에 적힌 수 : {1}\n현재 던져진 주사위의 값 : {2}", dice.dice_page, dice.dice_number, dice.dice_count);
    }
}

--------------------------------------------------------

using System;

class die
{
    public int side;
    public int value;
}
class C_sharp_book
{
    public static void Main()
    {
        Random rnd = new System.Random();

        die dice1 = new die();
        die dice2 = new die();

        dice1.side = 6;
        dice2.side = 12;

        dice1.value = (int)rnd.Next(1, dice1.side + 1);    // 1 ~ 6
        dice2.value = (int)rnd.Next(1, dice2.side + 1);    // 1 ~ 12

        Console.WriteLine("첫 번째 주사위의 면 수와 값: {0}, {1}", dice1.side, dice1.value);
        Console.WriteLine("두 번째 주사위의 면 수와 값: {0}, {1}", dice2.side, dice2.value);


    }
}
