  우선 도움이 되는 블로그: https://blog.daum.net/jeensik82/48
-------------------------------------------------------------------

class
{
    //field                *필드: scope 내의 영역
    method                
    {                 
        //field
    }
{ 
                   
                            이와 마찬가지로 namespace 또한 이러한 필드를 가지게 된다.
                            
namespace
{
   class
   {
      method
      {
         //field
      }
   }
}

-------------  이러한 점을 응용하여

namespace CSharp
{

    class MainApp
    {
        static void Main()
        {
            InterFace1.User myid1 = new InterFace1.User(100, 100);   // 이렇게 nammespace내부의 class명은 같지만 namespace의 이름은 다르기 때문에 각각 호출이 가능하다.
            InterFace2.User myid2 = new InterFace2.User(100, 100);
        }
    }
}

namespace InterFace1
{
    class User
    {
        private int HP;
        private int MP;

        public User(int HP, int MP)
        {
            this.HP = HP;
            this.MP = MP;
        }
    }
}

namespace InterFace2
{
    class User
    {
        private int HP;
        private int MP;

        public User(int HP, int MP)
        {
            this.HP = HP; 
            this.MP = MP;
        }
    }
}
-------------
          하지만 여기서 이러한 namespace의 이름을 일일히 적어주는 것이 번거로우니 
          사용하는 키워드가 바로 using 이다.

using InterFace1;
    
namespace CSharp
{

    class MainApp
    {
        static void Main()
        {
            User myid1 = new User(100, 100);   // 생략이 가능
            InterFace2.User myid2 = new InterFace2.User(100, 100);
        }
    }
}
--------
          하지만 여기서 드는 의문..
          같은 이름을 가진 클래스를 가진 namespace 영역을 생략하게 된다면..??   

using InterFace1;
using InterFace2;
    
namespace CSharp
{

    class MainApp
    {
        static void Main()
        {
            User myid1 = new User(100, 100);   // 오류가 발생한다..  모호한 
            User myid2 = new User(100, 100);
        }
    }
}
