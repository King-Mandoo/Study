
  C# 클래스에는 특별한 용도의 메서드가 있다.  생성자(constructor)은 그중 하나이다.
  클래스에 생성자 메서드를 추가하면 객체가 "생성"되는 시점에서 해당 메서드가 자동으로 호출된다.
  
  1. 생성자는 클래스명과 동일하다.            2. 반환타입을 명시하지 않는다.
  
------------------------------------------
using System;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("person 객체가 생성되기 전..");
            Person person = new Person();                    //객체가 생성되는 시점에 해당 메서드가 자동으로 호출
            Console.WriteLine("person 객체가 생성된 후..");
        }
    }

    class Person
    {
        string name;
        public Person()
        {
            name = "선태욱";
            Console.WriteLine("생성자 호출 : {0}", name); 
        }
    }
}      
                                                                  출력결과: 
                                                                            person 객체가 생성되기 전..
                                                                            생성자 호출 : 선태욱
                                                                            person 객체가 생성된 후..
                                                                            
                                                                            
----------------------------------------------------------

 *매개변수를 갖는 생성자
using System;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("person 객체가 생성되기 전..");
            Person person = new Person("부끄부끄");               // 매개변수를 전달
            Console.WriteLine("person 객체가 생성된 후..");
        }
    }

    class Person
    {
        string name;
        public Person(string name)
        {
            Console.WriteLine("생성자 호출 : {0}", name);
        }
    }
}
-----------------------------------------------------------------

 *생성자를 여러개 정의 하기
   
using System;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            Person Sun = new Person("선태욱");
            Person Kang = new Person("강동원", 188.3f);
            Person Lee = new Person("이말년", 178.3f, 70);
        }
    }

    class Person
    {
        string name;
        public Person(string name)
        {
            Console.WriteLine("이름 : {0}", name);
        }
        public Person(string name, float tall)
        {
            Console.WriteLine("이름 : {0}, 키 : {1}cm", name, tall);
        }
        public Person(string name, float tall, double weight)
        {
            Console.WriteLine("이름 : {0}, 키 : {1}cm, 몸무게: {2}kg", name, tall, weight);
        }
    }
}
