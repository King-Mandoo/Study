 
    ✅ 구조체, 열거형 등등 이런 것들을 사용자 정의 데이터 타입(user-defined data type)이라고 한다.

🔵 Enum 

       There are two main reasons for using enums.   // 열거형을 사용하는 데에는 두 가지 이유가 있다.
     
      1. The first is to improve the readability of your code. // 첫 번째는 당신의 코드의 가독성을 향상시켜준다.
      
         myDays = DaysOfWeek.Mon;   
                                   이 코드가
         myDays = 1;               이 코드보다 더 설명이 잘 된다.
         
      2. The second reason is to restrict the values that a variable can take. // 두 번째는 변수가 취할 수 있는 값을 제한하기 위해서이다.
      
         그니까 아래의 코드와 같이 월화수목금을 저장하는 코드를 짤 경우, 실수로 요일을 저장하는 변수에 10을 넣어버리는 그런 경우들을
         미리 막을 수 있다.

-----------------
using System;

enum DaysOfWeek    // 열거형 DaysOfWeek
{
    Sun, Mon, Tues, Wed, Thurs, Fri, Sat
}

class C_sharp_book
{
    public static void Main()
    {    
        DaysOfWeek myDays = DaysOfWeek.Mon;  // DaysOfWeek 타입의 변수 myDays에 DaysOfWeek.Mon 할당
        
        Console.WriteLine(myDays);  // Mon 출력    
        Console.WriteLine((int)myDays); // 1 출력         🎈🎈 이렇게 숫자형 타입과 호환이 가능하다.
        Console.WriteLine((DaysOfWeek)1); // Mon 출력
    }
}

-----------------

🔵 Struct
      
    --> C#의 구조체는 정말 다양한 기능을 소화해낼 수 있다.
        메소드도 생성이 가능하고, 생성자 또한 포함한다.
        
        
        There are two main differences between a struct and a class. // 구조체와 클래스의 두 가지 차이점.
        
        1. Firstly, the struct data type does not support inheritance. Hence you cannot derive one
           struct from another. However, a struct can implement an interface. 
           // 구조체 데이터 타입은 상속을 지원하지 않는다. 따라서 파생 구조체를 생성하지 못한다.
              그러나 인터페이스는 상속이 가능하다.
              
        2. The second difference between structs and classes is that structs are value types while classes are reference types. 
           // 구조체는 값 형식이고 클래스는 참조 형식이다.
           
-----------------------
using System;

struct MyStruct
{
    //Fields
    private int x, y;
    private AnotherClass myClass;
    private Days myDays;

    //Constructor
    public MyStruct(int a, int b, int c)     // MyStruct 구조체의 생성자
    {
        myClass = new AnotherClass();
        myClass.number = a;
        x = b;
        y = c;
        myDays = Days.Mon;
    }

    public void PrintStatement()
    {
        Console.WriteLine("x = {0}, y = {1}, myDays = {2}", x, y, myDays);
    }
}

class AnotherClass
{
    public int number;
}

enum Days { Mon, Tues, Wed }

class C_sharp_book
{
    public static void Main()
    {
        MyStruct myStruct = new MyStruct(100, 101, 102);    
        myStruct.PrintStatement();                         // x = 101, y = 102, myDays = Mon 출력
    }
}

------------------------------------------------------------------------------------------------------------------------------------------

                        ❌ 내가 잘못 생각했던 부분..
using System;
struct MyStruct
{
    public int a;
}
class MyClass
{
    public int a;
}
class C_sharp_book
{
    static void Add (int a)
    {                                                    ✅ Add() 메서드에 전달해준 건 정수 값이다. 따라서 당연히 
        a++;                                                 myClass.a의 주소를 전달해준 것이 아니라 myClass.a의 값인 100을 전달해 준 것이므로
    }                                                        당연히 myClass.a의 값의 변화는 결코 없다.
    public static void Main()
    {
        MyStruct myStruct = new MyStruct();
        myStruct.a = 5;

        MyClass myClass = new MyClass();
        myClass.a = 100;

        Console.WriteLine(myStruct.a);   // 5 출력
        Add(myStruct.a);
        Console.WriteLine(myStruct.a);   // 5 출력

        Console.WriteLine(myClass.a);   // 100 출력
        Add(myClass.a);
        Console.WriteLine(myClass.a);   // 100 출력  <-- 🎈🎈 여기서 당연히 나는 101이 출력 될줄 알았다.
    }
}

------------       
                              🟢 따라서 코드를 바꿔봤다.
using System;
struct MyStruct
{
    public int a;
}
class MyClass
{
    public int a;
}
class C_sharp_book
{
    public static void Main()
    {
        MyStruct myStruct = new MyStruct();
        myStruct.a = 3;
                                                              
        MyClass myClass = new MyClass();
        myClass.a = 100;

        Console.WriteLine(myStruct.a);     // 3 출력
        AddStruct(myStruct); 
        Console.WriteLine(myStruct.a);     // 3 출력

        Console.WriteLine(myClass.a);      // 100 출력
        AddClass(myClass);
        Console.WriteLine(myClass.a);      // 500 출력
    }
    static void AddStruct(MyStruct myStruct)                  ✅ 당연히 이번에는 내가 생각했던 방식대로 값이 출력이 된다.
    {                                                             AddClass() 메소드에 myClass의 객체의 주소를 보내줬으므로 
        myStruct.a = 200;                                         메소드 내에서 값을 바꿀 수가 있다.
    }                                                             이와 반대로 구조체는 구조체의 객체를 전달해도 값 형식이므로
    static void AddClass(MyClass myClass)                         아무런 변화를 가져올 수 없다.
    {
        myClass.a = 500;
    }
}
                                              읽어볼만한 블로그: https://kukuta.tistory.com/385
