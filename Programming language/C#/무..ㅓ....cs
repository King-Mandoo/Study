표준 출력 
            Console.Write()  /  Console.WriteLine()            static(정적 메서드) 이기 때문에 바로바로 사용 가능.

-----------------------------------------
public class MyClass
{
   private int val = 1;
   
   // 인스턴스 메서드
   public int InstRun()
   {
      return val;
   }
   
   // 정적(Static) 메서드
   public static int Run() 
   {
      return 1;
   }
}

public class Client
{
   public void Test()
   {
      // 인스턴스 메서드 호출
      MyClass myClass = new MyClass();
      int i = myClass.InstRun();

      // 정적 메서드 호출
      int j = MyClass.Run();
   }
}
-------------------------------------

            Console.WriteLine("Hello, World!");

            Console.WriteLine("{0} {1}", 3.14f, 12);     // 이런 식으로 표현도 가능하구나 .

            Console.WriteLine("{0} + {1} = {2}", 2, 4, 2 + 4);

            Console.WriteLine("{0:C} {1:P} {2:X}", 123, 123.45, 125); 

----------------------------------------
            
C#의 모든 데이터 형은 object로 부터 파생된 객체 

* 정수형
bool       1byte    System.Boolean
char       2byte    System.Char     // c#에서 char형은 2바이트.
byte       1byte    System.Byte
sbyte      1byte    System.SByte
short      2byte    System.Int16
ushort     2byte    System.UInt16
int        4byte    System.Int32
uint       4byte    System.UInt32
long       8byte    System.Int64
ulong      8byte    System.UInt64

* 실수형
float    4byte      System.Single
double   8byte      System.Double
decimal  16byte     System.Decimal

* 문자열형
string   System.String

--------------------------------------
namespace ConsoleApp1 
{
    class Study
    {
        static bool BoolVar;   // 정적 메서드를 사용했기 때문에 main에서 별다른 호출 없이 사용 가능.   초기화가 안된 bool의 초기 값은 False.
        static void Main(string[] args)
        {
            bool LocalBoolVar = true;
            Console.WriteLine("{0} {1}", BoolVar, LocalBoolVar);  // False True 출력
        } 
    }
}
--------------------------------------
* char 형    -->  유니코드  // 유니코드라고 아스키 코드와 완전히 다른건 아니다.

namespace ConsoleApp1
{
    class Study
    {
        static void Main(string[] args) 
        {
            char AA = 'A';
            int Num = AA;
            Num = Num + 1;
            Console.WriteLine("AA = " + (int)AA + ", 문자 상수 값 = " + Num + ", 유니코드 문자 = " + (char)Num);
        }
    }                // 출력 결과: AA = 65, 문자 상수 값 = 66, 유니코드 문자 = B
}  
-----------------------------------------------
namespace ConsoleApp1
{
    class Study
    {
        static void Main(string[] args) 
        {
            Console.WriteLine("{0} ~ {1}", short.MinValue, short.MaxValue); // short. 을 보아, 우리는 short가 객체라는 것을 알 수 있다.
        } 
    }                      // 출력결과 :  -32768 ~ 32767
}
--------------------------------------------------
namespace ConsoleApp1
{
    class Study
    {
        static void Main(string[] args) 
        {
            float test = 3.14f;
            double test2 = 3.14;
            decimal test3 = 3.14m;

            Console.WriteLine(test);
            Console.WriteLine(test2);
            Console.WriteLine(test3);
        }
    }
}
----------------------------------------------------
namespace ConsoleApp1
{
    class Study
    {
        static void Main(string[] args) 
        {
            string a = "hello";
            string b = "apple";

            if (a == b)
                Console.WriteLine("Yes");
            else
                Console.WriteLine("NO");    // NO 
        }
    }
}
------------------------------------------------------
namespace ConsoleApp1
{
    class Study
    {
        static void Main(string[] args) 
        {
            string str1 = "Hello";
            string str2 = " World!";
            string str3 = str1 + str2;
            string str4 = "program" + "ming";
            Console.WriteLine("{0} {1}", str3, str4);
            Console.WriteLine(str3[4]);

            if (str3 == "Hello World!")
                Console.WriteLine("같다");
            else
                Console.WriteLine("다르다");
        }
    }
}

 출력결과:  
            Hello World! programming
            o
            같다
-------------------------------------------------------
namespace ConsoleApp1
{
    class Study
    {
        static void Main(string[] args) 
        {
            string str1 = "Hello";
            string str2 = " World!";
            string str3 = str1 + str2;

            Console.WriteLine("문자 개수: {0}", str3.Length);   // 12 출력
        }
    }
}
-------------------------------------------------------
namespace ConsoleApp1
{
    class Study
    {
        static void Main(string[] args) 
        {
            string str1 = "C:\\temp\\test.txt";
            string str2 = @"C:\temp\test.txt";

            Console.WriteLine(str1);
            Console.WriteLine(str2);
        }
    }
}                       출력결과: 
                                    C:\temp\test.txt
                                    C:\temp\test.txt
