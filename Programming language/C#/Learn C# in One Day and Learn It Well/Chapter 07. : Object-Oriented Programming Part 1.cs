* C#의 Main() 메소드
   -->   If we want, we can change the name of the Program class to something else, but the Main()
         method must be called Main(). The Main() method must be present in all C# programs.
         
  🔵 Fields : A field is simply a variable that is declared inside a class.
  
        private string nameOfStaff;
        private const int hourlyRate = 30;
        private int hWorked;                      현재 이렇게 추가했다.
        
        🟠 책에서는 왜 우리가 접근 제어자인 private를 사용한 이유에 대해 설명해준다.

        Notice that there is a word private in front of each declaration statement?
        This is known as an access modifier. Access modifiers are like gate
        keepers, they control who has access to that field (i.e. who can read and 
        modify the value of that field).           
                                                     // i.e. : 다시 말해서
                                                     
        There are two reasons why we do not want the three fields to be accessible outside the class.
        
     1. The first reason is that there is no need for other classes to know about those fields.
        // 첫 번째 이유는 다른 클래스에서 이곳 클래스의 필드를 알 필요가 없다.
        
        * 캡슐화에 대한 간략한 설명
        This is known as encapsulation. Encapsulation enables an object to hide
        data and behaviour from other classes that do not need to know about them.
        This makes it easier for us to make changes to our code in future if
        necessary. We can safely change the value of hourlyRate inside Staff class
        without affecting other classes.
        
        // Encapsulation : 캡슐화    (캡슐화는 은닉성을 포함하고 있음)
        
     2. The second reason for declaring a field as private is that we do not want
        other classes to freely modify them. 
        This helps to prevent the fields from being corrupted.
        // private로 선언한 두 번째 이유는, 다른 클래스에서 이것들을 자유롭게 수정하는 것을 원치 않기 때문이다.
           이것은 필드가 부패되는 것을 방지해준다.
        
        
  🔵 Properties 
      
    --> A property is commonly used to provide access to a private field in cases where the field is needed by other classes.
    
   ✅ 여기서 드는 의문점) private 접근 제한자를 사용했으면서 왜 프로퍼티를 사용해서 접근이 가능하도록 하는 걸까???
     
        This may sound like a contradiction. Earlier, we mentioned that we use private fields so that other
        classes do not have access to them. If that is the case, why are we allowing
        access to them via properties?            
                                               * contradiction 뜻 : 모순
  
        여기에 대한 의문을 살짝 알려준다.
        
        One of the main reasons is that using properties gives us greater control
        over what rights other classes have when assessing these private fields.
        We’ll see how to do that later.  
        // 프로퍼티를 사용하면 우리는 커다란 권한을 얻는다.  private 필드를 할당할 때 다른 클래스들이 가지는 권한을 말이다.
  
--------------------

   // A property contains two special methods known as accessors. The first accessor is a getter and the second is a setter.
   
using System;

class circle
{
    private int x;
    private int y;
    private double radius;

    public int X   // 프로퍼티 이름 : X
    {
        get { return x; }
        set { x = value; }      // value is a keyword when it used inside a setter.
    }

    public int Y  // 프로퍼티 이름 : Y
    {
        get { return y; }
        set { y = value; }
    }

    public double Radius  // 프로퍼티 이름 : Radius
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
--------------------  
                                    이렇게 줄일 수도 있다. 
using System;

class circle
{                             // 따로 private 필드를 선언해주지 않아도 된다.
    public int X 
    {
        get;            // 자동구현 프로퍼티라고 한다. (Auto-implemented Properties)
        set;
    }

    public int Y
    {
        get;
        set;
    }

    public double Radius
    {
        get;
        set;
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
  
           프로퍼티에 대하여 도움이 되는 블로그 : https://dev-junwoo.tistory.com/93#3.%20Private%20Set%20/%20init
                                                 https://constructionsite.tistory.com/38
  
-------------------------------------
   
  🔵 Overloading
  
        --> 오버로딩은 하나의 메서드 이름으로 여러 메서드를 구현하는 것을 말한다.
   
          1. 함수의 이름을 같게 한다.
          2. 각각 함수의 매개변수를 다르게 한다.
  
 using System;

class calculator
{
    static public int add(int a, int b)
    {
        return a + b;
    }
    static public int add(int a, int b, int c)
    {
        return a + b + c;
    }
    static public double add(double a, double b)
    {
        return a + b;
    }

}
class C_sharp_book
{
    public static void Main()
    {
        Console.WriteLine(calculator.add(5, 3));
        Console.WriteLine(calculator.add(2, 1, 50));
        Console.WriteLine(calculator.add(3.13, 4.52));
    }
} 
  
  
  🔵 The ToString() method
  
      -->  The ToString() method is a special method that returns a string that represents the current class.
           // ToString() 메소드는 현재의 클래스를 대표하는 문자열을 반환하는 특별한 메소드이다.
          
    (* Object는 모든 클래스의 최상위 클래스이다. C#의 거의 모든 자료형은 System.Object로 부터 상속받는다.)
                                  
      ✅ C#에는 System 네임스페이스 안에  "public class Object"로 Object 클래스가 정의되어 있는데
      
          이 안에는 여러 메소드들이 있다.
            
            1  Equals(Object)

            2	Equals(Object,Object)

            3	Finalize()

            4	GetHashCode()

            5	GetType()

            6	MemberwiseClone()

            7	ReferenceEquals(Object,Object)

            8	ToString()
                                             이렇게 말이다.
     
          이 책에서는 그중 하나인 ToString() 메소드를 소개시켜준다.
   
                                                       도움되는 블로그: https://kangworld.tistory.com/190 
  
       ✅ Override : 내가 이해한 바로는 부모 클래스로부터 상속받은 메소드를 다시 재정의하고 싶을 때
                      오버라이드를 사용하는 것으로 보인다.
      
          *Override 뜻: to decide against or refuse to accept a previous decision, an order, a person, etc.:
-------------------------           
using System; 
class Minus
{
    public int minus(int a, int b)
    {
        return a - b;
    }
}
class Add
{
    public int add(int a, int b)
    {
        return a + b + c;
    }
    public override string ToString()       // 오버라이딩
    {
        return "This is Overriding";
    }
}
class C_sharp_book
{
    public static void Main()
    {
        object a = 5;
        Console.WriteLine(a);
        object b = "Hello";
        Console.WriteLine(b);

        Add add = new Add();
        Minus minus = new Minus();

        Console.WriteLine(add);                 // "This is Overriding" 출력
        Console.WriteLine(add.ToString());      // "This is Overriding" 출력
        Console.WriteLine(minus);               // "Minus" 출력
        Console.WriteLine(minus.ToString());    // "Minus" 출력
    }
}
-------------------------  
  
 ✅ Overriding 한 다른 예시
 
using System; 
class Minus
{
    public virtual int minus(int a, int b)  // virtual 클래스는 자식 클래스에서 이 함수를 재정의하도록 허용해주는 키워드이다.
    {
        return a - b;
    }
}
class Add : Minus
{
    public int c;
    public override int minus(int a, int b)
    {
        return a - b + c;
    }
    public int add(int a, int b)
    {
        return a + b + c;
    }
    public override string ToString()
    {
        return "This is Overriding";
    }
}
class C_sharp_book
{
    public static void Main()
    {
        Add add = new Add();
        Minus minus = new Minus();

        add.c = 5;

        Console.WriteLine(minus.minus(100, 88));   // 12 출력
        Console.WriteLine(add.minus(100, 88));     // 17 출력
    } 
}
  
  
  🔵 Constructors (생성자)
       
      --> It is the first method that is called whenever we create a object from our class. 
          // 생성자는 우리가 클래스로부터 객체를 호출할 때 언제나 호출되는 첫 번째 메소드이다.
   
            A constructor always has the same name as the class 
            and does not return any value. We do not need to use the void keyword
            when declaring a constructor.

            Declaring a constructor is optional. If you do not declare your own
            constructor, C# creates one for you automatically. The default constructor
            simply initializes all the fields in the class to default values, which is
            normally zero for numeral fields and empty string for string fields.

--------------------------- 
using System; 

class SayHello
{
    public SayHello()
    {
        Console.WriteLine("Hello");
    }
}
class C_sharp_book
{
    public static void Main()
    {
        SayHello hello = new SayHello();   // "Hello" 출력
    }
---------------------------  

using System; 

class SayHello
{
    public SayHello(string MyName)
    {
        Console.WriteLine("Hello "+ MyName);
    }
}
class C_sharp_book
{
    public static void Main()
    {
        SayHello hello = new SayHello("선태욱");  // "Hello 선태욱" 출력
    }
}
----------------------------
   
  🔵 Static Keyword

         Previously, we looked at how we can use the Staff class to create our
         staff1, staff2 and staff3 objects. However, there are some classes or
         class members that can be accessed without the need to create any objects.
         These are known as static classes or class members and are declared using
         the static keyword.
            
using System; 

class ThisIsStatic
{
    public static int a;
    public static int pro { get; set; }

    public static double Func(double a, double b)
    {
        return a + b;
    }
}
class C_sharp_book
{
    public static void Main()
    {
        Console.WriteLine("a = " + ThisIsStatic.a);    // 0 출력
        ThisIsStatic.a = 5;
        Console.WriteLine("a = " + ThisIsStatic.a);    // 5출력

        ThisIsStatic.pro = 3;
        Console.WriteLine("pro = " + ThisIsStatic.pro);  // 3 출력 

        Console.WriteLine("Func() = " + ThisIsStatic.Func(3.15, 152.35));  // 155.5 출력
    }
}


   
  🔵 Using Arrays and Lists
     
-------------     
using System;

class Array
{
    public static void A(int[] a)
    {
        for (int i = 0; i < a.Length; i++)
        {
            Console.Write(a[i]);
        }
    }
}
class C_sharp_book
{
    public static void Main()
    {
        int[] a = { 1, 2, 3, 4, 5, 6, 7 };

        Array.A(a);   // 1234567 출력
    }
}
-------------     
                   ✅ List는 크기를 정하지 않은 배열이라고 생각하면 된다. 동적으로 크기를 조절할 수 있다.
using System; 

class MyList
{
    public static void A(List<int> a)
    {
        for (int i = 0; i < 10; i++)
        {
            a.Add(i + 1);     //  i + 1값을 저장해준다.
            Console.Write(a[i]);  // 12345678910 출력
        }

        foreach (int i in a)
        {
            Console.Write(i);  // 12345678910 출력
        }
    }
}
class C_sharp_book
{
    public static void Main()
    {
        List<int> mylist = new List<int>();
        MyList.A(mylist);
    }
}  

----------------------
 
using System;           ✅ 메소드의 반환값을 배열로 선언
 
class MyArray
{
    public static int[] Array()
    {
        int [] array = new int[5];

        for(int i = 0; i < array.Length; i++)
        {
            array[i] = Convert.ToInt32(Console.ReadLine());    // 배열에 값을 입력해줌
        }

        return array;  // 배열을 반환함
    }
}
class C_sharp_book
{
    public static void Main()
    {
        int[] aa = MyArray.Array();       // aa에 값을 전달함
       
        for(int i = 0; i < aa.Length;i++)
        {
            Console.WriteLine(aa[i]);   // 
        }    
    }
}
----------------------
 
using System;           ✅ 리스트의 반환값을 배열로 선언

class MyList
{
    public static List<int> List()      // 리스트를 반환해주는 함수 선언 
    {
        List<int> mylist = new List<int>();   
        int input = 0;

        for(int i = 0; i < 5; i++)
        {
            input = Convert.ToInt32(Console.ReadLine()); 
            mylist.Add(input);
        }

        return mylist;
    }
}
class C_sharp_book
{
    public static void Main()
    {
        List<int> list = MyList.List();    // list에 mylist값 전달

        for(int i = 0; i < list.Count; i++)
        {
            Console.WriteLine(list[i]);
        }
    }
}
     
     

  🔵 Using params keyword
     
       --> params 키워드를 사용하면 자신이 원하는 만큼, 개수의 제한 없이 매개변수를 전달 할 수 있다.
     
  -------------------------------------------------------------------------------------------------------------------------------   
     ▼ C# params 규칙: 1. 선언부에서 params 키워드는 타입 맨 앞에 와야합니다.: 
                       2. 가변인자 매개변수를 선언할때는 [] 를 이용해서 1차원 배열로 선언해야합니다.: 
                       3. 데이터 타입이 애매할때는 모든 클래스의 최상위 클래스인 object 클래스 배열로 해도 됩니다. 
                                           
                                              출처: https://blockdmask.tistory.com/317 [개발자 지망생:티스토리]
   -------------------------------------------------------------------------------------------------------------------------------
           
      Next, let’s explore the params keyword. The params keyword is useful
      when we do not know the number of arguments a method has. For instance,
      we may have a method that prints a series of names, but we do not know
      how many names there are in advance. In cases like this, we can use an
      array as the parameter and add the params keyword in front of it.
     
---------------
using System; 

class ParamsFunc
{
    public static void PrintNames(params string[] names)  // params 키워드를 사용하여 string형의 이름을 전달받음
    {
        for (int i = 0; i < names.Length; i++)
        {
            Console.Write(names[i] + " ");
        }
        Console.WriteLine();
    }

}
class C_sharp_book
{
    public static void Main()
    {
        ParamsFunc.PrintNames("선태욱");
        ParamsFunc.PrintNames("선태욱", "이병건");
        ParamsFunc.PrintNames("선태욱", "이병건", "주호민");
    }
}
---------------

               ✅ object 클래스를 활
using System; 

class ParamsFunc
{
    public static void PrintFile(params object[] file)
    {
        for (int i = 0; i < file.Length; i++)
        {
            Console.Write(file[i] + " ");
        }
        Console.WriteLine();
    }

}
class C_sharp_book
{
    public static void Main()
    {
        ParamsFunc.PrintFile("선태욱");
        ParamsFunc.PrintFile("선태욱", 171.3);
        ParamsFunc.PrintFile("선태욱", 171.3, 68);
    }
}
     
     
