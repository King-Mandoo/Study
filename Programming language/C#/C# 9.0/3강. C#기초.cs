2022. 07. 04. 월

1.1 닷넷 프레임워크 (.NET Framework)

3.1 기본 자료형
  
 3.1.1 정수형 기본 타입
 
     --> 컴퓨터는 태상 자체가 0과 1이라는 비트(bit)로 구성돼 있기 때문에 오직 '숫자'만이 의미가 있다.
         즉, 컴퓨터 세상에서는 모든 것이 숫자인데, 사실은 알파벳조차도 'A'는 65, 'B'는 66, ... 과 같은 식으로 각각 대응되는 숫자로
         약속돼 있다.
         
         sbyte :  -128 ~ 127                                            부호 있는 8비트 정수
          byte :  0 ~ 255                                               부호 없는 8비트 정수
         short :  -32,768 ~ 32,767                                      부호 있는 16비트 정수
         ushort : 0 ~ 65,535                                            부호 없는 16비트 정수
         int : -2,147,483,648 ~ 2,147,483,647                           부호 있는 32비트 정수
         uint : 0 ~ 4,294,967,295                                       부호 없는 32비트 정수
         long : -9,223,372,036,854,775,808 ~ 9223,372,036,854,775,807   부호 있는 64비트 정수
         ulong : 0 ~ 18,446,744,073,709,551,615                         부호 없는 64비트 정수
         
         왜 이렇게 나눠야만 했을까?
         그 이유는 저장 공간의 효율을 높이기 위해서다.
         

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        { 
            int n1 = 50;  // 32비트 정수형
            int n2;
            n2 = 100;

            long sum = n1 + n2;   // 64비트 정수형

            Console.WriteLine(sum);   // 출력 결과: 200
        }
    }
}

  
  3.1.2 실수형 기본 타입
   
     --> float    4바이트
         double   8바이트
         decimal  16바이트

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            float f = 5.2f;
            double d = 10.5;
            decimal money = 200.099m;   // decimal의 경우네는 소수점을 포함하는 경우 m을 붙여야 한다.

            Console.WriteLine(f);
            Console.WriteLine(d);
            Console.WriteLine(money);
        }
    }
}


  3.1.3 문자형 기본 타입
  
  문자형은 사칙연산(+, -, *, /)을 하려는 경우 컴파일할 때 오류가 발생한다.

            char ch1 = 'a';
            char ch2 = 'A';
            char ch3 = ch1 + ch2;   // 오류 발생

            Console.Write(ch3);
  


using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            char ch1 = '\t';
            char ch2 = 'T';
            char ch3 = '\n';
            char ch4 = 'N';

            Console.Write(ch1);
            Console.Write(ch2);
            Console.Write(ch3);
            Console.WriteLine(ch4);  // Console.Write()에 '\n'을 덧붙여서 출력하는 것과 같다.
            Console.WriteLine(ch2);
        }
    }
}
  
-----------------
  
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            string text1 = "Hello, World!";
            Console.WriteLine(text1);

            string text2 = "\"Hello, World!\"";  //   \" 을 붙이면 " 또한 출력이 가능함
            Console.WriteLine(text2);

            Console.WriteLine(text1 + " <<>> " + text2);  // 이런식으로 string은 char형과는 달리 '+'연산을 지원한다. 이를 통해 문자열을 연결할 수 있다.
        }
    }
}

  
  3.1.4 불린(boolean)형 기본 타입
  
      -->  C#에는 bool이라는 자료형이 있으며, 오직 true/false 값만을 담을 수 있다.
    
          영국의 수학자였던 죠지 불(George Boole, 1815-64)의 이름을 따서 만든 불린 데이터 형은 True/False 혹은 0/1 이라는 이진 값을 갖는다. 
          1854년에 '사고의 법칙'이라는 책을 썼던 그는 AND, OR, NOT 이라는 이진 연산자를 사용해 이진 정보를 처리할 수 있는 모델을 만들 수 있도록 해주었는데, 
          인간의 정신작용 또한 인식된 정보를 '참' 또는 '거짓'이라는 두 개의 환원된 정보로 처리하는 과정에서 이루어진다고 생각했다.
            
                                                                                                          출처: http://www.terms.co.kr/Boolean.htm
 

            bool isNumeric = false;
            Console.WriteLine(isNumeric); // False 출력

                                                   

                                                     C#은 정적 타입 언어이기에 자료형을 꼭 명시해야 한다.
                                                       
                                                       
                                                       
3.2 형변환                                                    
                                                       
  3.2.1 암시적 변환                                               
                                                       
 class Program
    {
        static void Main(string[] args)
        {
            byte b = 255;        // byte 데이터에는 0 ~ 255 범위의 수가 담겨진다.
            short s = b;         // short 데이터에는 -32,768 ~ 32,767 범위의 수를 담을 수 있다. 따라서 변수 s안에 b를 넣는 건 문제가 되지 않는다.
                                 // 물론 그 반대 상황이면 byte가 short보다 작은 범위를 나타내므로 오류가 발생한다.
            
            Console.WriteLine(s);
        }
    }                                                       
                                                       
                                                       
  3.2.2 명시적 변환                                                          
                                                       
    class Program
    {
        static void Main(string[] args)
        {
            short b = 255;
            byte s = (byte)b;      // 이렇게 변환을 하면 오류가 발생하지 않도록 할 수 있다.
            
            Console.WriteLine(s);
        }
    }                                                      
                                  
                         * 형변환을 다른 말로 캐스팅(casting)이라고 한다.
                                                       
3.3 기본 문법 요소

  3.3.1 예약어, 키워드  
  
  3.3.2 식별자
  
  3.3.3 리터럴  
  
  3.3.4 변수  
      
       --> 변수는 '식별자'의 하나로서 변수가 선언됐을 때 그와 함께 지정된 형식에 부합하는 저장소가 메모리에 할당돼 값을 담아 놓을 수 있는 역할을 한다.
           닷넷에서 변수의 종류는 크게 두 가지인데, 값 형식(Value Type)을 가르키는 변수와 참조 형식(Reference Type)을 가리키는 변수가 있다.
                           
     3.3.4.1 두 가지 저장소: 스택과 힙  
      
     3.3.4.2 값 형식을 가리키는 변수
     
     3.3.4.3 참조 형식을 가리키는 변수 
     
        --> "값 형식"과 "참조 형식"의 유일한 차이점은 바로 "값"을 스택에 저장하느냐 힙에 저장하느냐에 있다.
            
            "값 형식"은 그 변수의 타입에 해당하는 값을 스택에 저장하지만
            "참조 형식"을 위한 변수는 그 값을 담기 위해 별도로 힙 영역의 메모리를 할당하고,
             스택의 변수 값은 다시 힙의 데이터 주소를 가리키게 된다.
              
             값을 할당하지 않은 string 변수는 어떤 값을 가지게 될까?
               
             참조형 변수의 경우 숫자 0을 대입할 수는 없으므로 이런 목적으로 C#은 특별하게 null 예약어를 준비해 두고 있다.
             따라서 아래의 두 가지 스택 변수는 동일하게 숫자 0을 담고 있게 된다.
               
             string text1;
             string text2 = null;
                                        즉, 초기화 되지 않은 모든 참조형 변수는 null 값을 가진다.
                                          
     3.3.4.4 기본값 
     
       bool result;    // 변수 result에는 false 값이 들어 있다.
       int n;          // 변수 n에는 0 값이 들어 있다.
       string text;    // 변수 text에는 null 값이 들어 있다.
     
  3.3.5 상수
  
  3.3.6 연산자, 문장 부호
     
3.4 배열    
     
       --> 배열도 참조 형식에 속한다.
    
namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] products = new int[5];  // 배열 선언

            for(int i = 0; i <products.Length; i++)
            {
                products[i] = i + 1;
                Console.WriteLine(products[i]);
            }
        }
    }
}     
     
--------------------------------------------------------
  
namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] products = new int[5] { 5, 6, 8, 8, 5 };    // int[] products = new int[] { 5, 6, 8, 8, 5 };

            for(int i = 0; i <products.Length; i++)
            {
                Console.WriteLine(products[i]);
            }
        }
    }
}
     
  3.4.1 다차원 배열
  
     int [,] arr2 = new int[10, 5];
     short [,,] arr3 = new short[3, 5, 2];

  3.4.2 가변 배열
  
  
  
  
  
