
🔵 GetType() and typeof()
   
    --> The GetType() method returns the runtime type of an object.
    
        The typeof() method takes the name of a data type (e.g. int, float, or the
        name of a class) and returns the type of that name, which we can then
        compare with the result of the GetType() method on the left.
        
        정리하자면 GetType()는 인스턴스의 형식을 호출하고, 
        typeof()는 클래스의 형식을 호출한다.
        
---------------------------------------     
                                    * 위의 클래스들은 생략.
class C_sharp_book
{
    public static void Main()
    {

        Member[] clubMembers = new Member[5];    // We declare an array of Member type and add 5 members.

        clubMembers[0] = new NormalMember("Special Rate", "James", 1, 2010);
        clubMembers[1] = new NormalMember("Normal Rate", "Andy", 2, 2011);
        clubMembers[2] = new NormalMember("Normal Rate", "Bill", 3, 2011);
        clubMembers[3] = new VIPMember("Carol", 4, 2012);
        clubMembers[4] = new VIPMember("Evelyn", 5, 2012);

        foreach (Member m in clubMembers)
        {
            m.CalculateAnnualFee();
            Console.WriteLine(m.ToString());
        }

        if (clubMembers[0].GetType() == typeof(VIPMember))    // NO 출력
            Console.WriteLine("YES");
        else
            Console.WriteLine("NO");
            
        Console.WriteLine(clubMembers[0].GetType());      // NormalMember 출력
        Console.WriteLine(clubMembers[4].GetType());      // VIPMember 출력
        Console.WriteLine(typeof(NormalMember));          // NormalMember 출력
        Console.WriteLine(typeof(VIPMember));             // VIPMember 출력
    }
}

------------------------

🔵 Abstract Classes and Methods

   --> 추상 클래스는 인스턴스를 생성할 수 없는 클래스이다.
       클래스 선언문에 abstract 지정자를 붙이면 추상 클래스가 된다.
       
       추상 메서드는 구현 코드를 가지지 않은 메서드를 말한다.
       추상 메서드는 abstract 지정자를 붙이고 매개변수와 리턴 타입은 가지지만
       본체는 가지지 않고 세미클론으로 끝낸다.
   
       추상 메서드는 코드를 정의하지 않으므로 파생 클래스에서 재정의해야지만 호출이 가능하다.
       파생 클래스에서 반드시 재정의해야 하므로 virtual를 붙이지 않아도 자동으로 가상이다.
   
       추상 메서드가 하나라도 선언되어있으면 그 클래스 또한 무조건 추상이어야한다.
   
-----------------------
   
using System;

abstract class MyAbstractClass                      // 추상 클래스 MyAbstractClass 선언
{ 
    private string message = "Hello C#";
    public void PrintMessage()
    {
        Console.WriteLine(message);
    }
    public abstract void PrintMessageAbstract();     // 추상 메서드 PrintMessageAbstract 선언
}

class ClassA : MyAbstractClass                // 추상 클래스 MyAbstractClass를 상속받음
{
    public override void PrintMessageAbstract()       // 추상 메서드 PrintMessageAbstract() 오버라이딩
    {
        Console.WriteLine("C# is fun!!");
    }
}

class C_sharp_book
{
    public static void Main()
    {
        //MyAbstractClass abClass = new MyAbstractClass();    <-- 🎈🎈 MyAbstractClass는 추상 클래스이므로 객체를 생성할 수 없음!!
        ClassA a = new ClassA();
        a.PrintMessage();
        a.PrintMessageAbstract();
    }
}


출력결과:
            Hello C#
            C# is fun!!

------------------------------

🔵 Interfaces

  --> 인터페이스는 클래스가 아니므로 다중 상속이 가능하다. 
      메소드만을 포함할 수 있다. 하지만 C#에서는 property가 메서드로 구현되므로 인터페이스에 포함이 가능하다.
      자식 클래스에서 구현할 때, 반드시 public 접근 제한자를 명시해야 한다.


using System;

class C_sharp_book
{
    public static void Main()
    {
        ClassA a = new ClassA();
        a.MyNumber = 5;
        a.IShapeMethod();
        a.MyRoomName = "SunFlower";
        a.IRoomMethod();
    }
}

interface IShape            // 현재 인터페이스들을 보면 선언만 되어있고 구현은 되어있지 않다. 구현은 이 인터페이스를 상속받은 클래스에서 해주면 된다.
{                              따라서 현재 인터페이스에서 구현되어있는 필드와 메소드가 만약 상속받은 클래스안에 없다면 오류를 발생시킨다.
    int MyNumber
    {
        get;
        set;
    }
    void IShapeMethod();
}

interface IRoom
{
    string MyRoomName
    {
        get;
        set;
    }
    void IRoomMethod();
}

class ClassA : IShape, IRoom    // ClassA에 인터페이스를 다중 상속
{  
    private int myNumber;
    private string myRoomName = "";
    public int MyNumber
    {
        get
        {
            return myNumber;
        }
        set
        {
            if (value < 0)
                myNumber = 0;
            else 
                myNumber = value;
        }
    }

    public string MyRoomName
    {
        get { return myRoomName; }
        set { myRoomName = value; }
    }

    public void IShapeMethod()                       // 인터페이스로 상속받은 메소드는 override 키워드가 필요없다.
    {
        Console.WriteLine("The number is {0}.", MyNumber);
    }
    public void IRoomMethod()
    {
        Console.WriteLine("The Room-Name is {0}.", MyRoomName);
    }
}






