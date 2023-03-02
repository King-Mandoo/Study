using System;
using System.IO;

namespace ConsoleApp1
{
    class C_sharp_book
    {
        public static void Main(string[] args)
        {
            try
            {
                int ctr = 0;
                if (args.Length <= 0)
                {
                    Console.WriteLine("형식: ListIT 파일명");
                    return;
                }
                else
                {
                    FileStream f = new FileStream(args[0], FileMode.Open);
                    try
                    {
                        StreamReader t = new StreamReader(f);
                        string line;
                        while ((line = t.ReadLine()) != null)
                        {
                            ctr++;
                            Console.WriteLine("{0} : {1}", ctr, line);
                        }
                        f.Close();
                    }
                    finally
                    {
                        f.Close();
                    }
                }
            }
            catch (System.IO.FileNotFoundException)
            {
                Console.WriteLine("ListIT에서 {0} 파일을 찾을 수 없습니다", args[0]);
            }

            catch(Exception e)
            {
                Console.WriteLine("Exception: {0} \n \n", e);
            }
        }
    }
}

------------------------------------------------

class Exercise2
{
    public static void Main()
    {
        int x = 0;

        for(x=1; x<=10;x++)
        {
            System.Console.Write("{0:D3} ", x);
        }
    }
}

  출력결과: 001 002 003 004 005 006 007 008 009 010
  
----------------------------------------------------

class bugbust
{
    public static void Main()
    {
        System.Console.WriteLine("\n재미있는 숫자는 {0} 이다",123);
    }
}

----------------------------------------------------

using System;
class C_sharp_book
{
    public static void Main()
    {
        System.Console.WriteLine("안녕 내 이름은 {0}이야", "선태욱");
        System.Console.WriteLine("안녕 내 이름은 선태욱이야");
    }
}
