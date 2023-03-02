
🔵 Inheritance : 상속
 
      Inheritance is one of the key concepts of object-oriented programming.
      Simply stated, inheritance allows us to create a new class from an existing
      class so that we can effectively reuse existing code.

---------------
 
using System; 

class Member
{
    protected int annualFee;
    private string name;
    private int memberID;
    private int memberSince;

    public Member()
    {
        Console.WriteLine("Parent Constructor with no parameter");
    }
}

class NormalMember : Member    // Member 클래스를 상속받겠다는 뜻.    ✅ 여기서 Member클래스를 부모클래스(기반클래스) 
{                                                                        NormalMember클래스를 자식클래스(파생클래스)라고 한다.
    public NormalMember()
    {
        Console.WriteLine("Child constructor with no parameter");
    }
}
class C_sharp_book
{
    public static void Main()
    {
        NormalMember normalMember = new NormalMember();
    }
}

실행결과: 
           Parent Constructor with no parameter       // 실행결과를 보면 부모 클래스의 생성자가 먼저 실행된다.
           Child constructor with no parameter
 
---------------  
                 🎈🎈 이제 아래 코드를 한번 봐보자 만약 부모 클래스의 생성자에 매개변수가 들어있다면 코드를 어떻게 작성해야할까????
                 
                       그건 바로 base 키워드를 사용하는 것이다.
using System; 

class Member
{
    protected int annualFee;
    private string name;
    private int memberID;
    private int memberSince;

    public override string ToString()
    {
        return "\nName: " + name + "\nMember ID: " + memberID + "\nMember Since: " 
                + memberSince + "\nTotal AnnualFee: " + annualFee;
    }

    public Member(string pName, int pMemberID, int pMemberSince)   // 매개변수 전달받음
    {
        Console.WriteLine("Parent Constructor with 3 parameters");
        name = pName;
        memberID = pMemberID;
        memberSince = pMemberSince;
    }
}

class NormalMember : Member
{
    public NormalMember(string remarks) : base ("선태욱", 1, 2022)    // base 키워드를 사용하여 매개변수 전달
    {
        Console.WriteLine("Remarks = {0}", remarks);
    }
}
class C_sharp_book
{
    public static void Main()
    {
        NormalMember normalMember = new NormalMember("Special Rate");
        Console.WriteLine(normalMember.ToString());
    }
}
--------------------------
                   🎈🎈 이 방법 외에도 아래의 코드처럼 작성이 가능하다.
                   
                   ✅ 잘보면 name, memberID, memeberSince는 매개변수로 전달받고 전달 받은 것을 부모클래스의 생성자에 전달해 준다.
 
 class NormalMember : Member
{                          
    public NormalMember(string remarks, string name, int memberID, int memberSince) : base(name, memberID, memberSince)
    {                                                            
        Console.WriteLine("Remarks = {0}", remarks);        
    }                                        
}                           
class C_sharp_book
{
    public static void Main()
    {
        NormalMember normalMember = new NormalMember("Special Rate", "선태욱", 1, 2022);
        Console.WriteLine(normalMember.ToString());
    }
}
 
 
 
---------------------- 완성된 코드

using System; 

class Member
{
    protected int annualFee;
    private string name;
    private int memberID;
    private int memberSince;

    public override string ToString()
    {
        return "\nName: " + name + "\nMember ID: " + memberID + "\nMember Since: " 
                + memberSince + "\nTotal AnnualFee: " + annualFee;
    }
    public Member()
    {
        Console.WriteLine("Parent Constructor with no parameter");
    }
    public Member(string pName, int pMemberID, int pMemberSince)
    {
        Console.WriteLine("Parent Constructor with 3 parameters");
        name = pName;
        memberID = pMemberID;
        memberSince = pMemberSince;
    }
}

class NormalMember : Member
{
    public NormalMember(string remarks, string name, int memberID, int memberSince) : base(name, memberID, memberSince)
    {
        Console.WriteLine("Remarks = {0}", remarks);
    }
    public void CalculateAnnualFee()
    {
        annualFee = 100 + 12 * 30;
    }
}
class VIPMember : Member
{
    public VIPMember(string name, int memberID, int memberSince) : base(name, memberID, memberSince)
    {
        Console.WriteLine("Child Constructor with 3 parameters");
    }
    public void CalculateAnnualFee()
    {
        annualFee = 1200;
    }
}

class C_sharp_book
{
    public static void Main()
    {
        NormalMember mem1 = new NormalMember("Special Rate", "선태욱", 1, 2022);
        mem1.CalculateAnnualFee();
        VIPMember mem2 = new VIPMember("이병건", 2, 2023);
        mem2.CalculateAnnualFee();
        Console.WriteLine(mem1.ToString());
        Console.WriteLine(mem2.ToString());
    }
}

실행결과: 
             Parent Constructor with 3 parameters
             Remarks = Special Rate
             Parent Constructor with 3 parameters
             Child Constructor with 3 parameters

             Name: 선태욱
             Member ID: 1
             Member Since: 2022
             Total AnnualFee: 460

             Name: 이병건
             Member ID: 2
             Member Since: 2023
             Total AnnualFee: 1200

-------------------------------------

🔵 Polymorphism : 다형성

    --> 다형성은 형태는 같지만 자세히 보면 그 형태의 고유한 특징을 가지는 것을 말한다.
    
        아래의 코드들을 봐보자...!!!!!!!!

------------------------------
                          *우선 Main() 메소드에 Member형(class) 메소드를 선언했다.
using System; 

class Member
{
    protected int annualFee;
    private string name;
    private int memberID;
    private int memberSince;

    public override string ToString()
    {
        return "\nName: " + name + "\nMember ID: " + memberID + "\nMember Since: " 
                + memberSince + "\nTotal AnnualFee: " + annualFee;
    }
    public Member()
    {
        Console.WriteLine("Parent Constructor with no parameter");
    }
    public Member(string pName, int pMemberID, int pMemberSince)
    {
        Console.WriteLine("Parent Constructor with 3 parameters");
        name = pName;
        memberID = pMemberID;
        memberSince = pMemberSince;
    }
}

class NormalMember : Member
{
    public NormalMember(string remarks, string name, int memberID, int memberSince) : base(name, memberID, memberSince)
    {
        Console.WriteLine("Remarks = {0}", remarks);
    }
    public void CalculateAnnualFee()
    {
        annualFee = 100 + 12 * 30;
    }
}
class VIPMember : Member
{
    public VIPMember(string name, int memberID, int memberSince) : base(name, memberID, memberSince)
    {
        Console.WriteLine("Child Constructor with 3 parameters");
    }
    public void CalculateAnnualFee()
    {
        annualFee = 1200;
    }
}

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
            m.CalculateAnnualFee();                <---  🎈🎈 하지만 여기서 오류가 뜨게 된다.
            Console.WriteLine(m.ToString());
        }
    }
}                               ✅ 오류가 뜨는 이유는 Member 형으로 선언된 배열인 clubMembers에는 
                                   CalculateAnnualFee() 메소드가 선언되어 있지 않기 때문이다.
                                   물론 자식 클래스인 NormalMember와 VIPMember에는 선언이 되어있다.
                                   이 문제를 해결하기 위해서 Member 클래스에 CalculateAnnualFee() 메소드를 선언해주면 된다.
 
 
----------------------------
                                 *CalculateAnnualFee() 메소드 선언
using System;

class Member
{
    protected int annualFee;
    private string name;
    private int memberID;
    private int memberSince;

    public override string ToString()
    {
        return "\nName: " + name + "\nMember ID: " + memberID + "\nMember Since: "
                + memberSince + "\nTotal AnnualFee: " + annualFee;
    }
    public Member()
    {
        Console.WriteLine("Parent Constructor with no parameter");
    }
    public Member(string pName, int pMemberID, int pMemberSince)
    {
        Console.WriteLine("Parent Constructor with 3 parameters");
        name = pName;
        memberID = pMemberID;
        memberSince = pMemberSince;
    }
    public void CalculateAnnualFee()
    {
        annualFee = 0;                   <---  🎈🎈 이렇게 CalculateAnnualFee() 메소드를 선언해준다. 
    }
}

class NormalMember : Member
{
    public NormalMember(string remarks, string name, int memberID, int memberSince) : base(name, memberID, memberSince)
    {
        Console.WriteLine("Remarks = {0}", remarks);
    }
    public void CalculateAnnualFee()
    {
        annualFee = 100 + 12 * 30;
    }
}
class VIPMember : Member
{
    public VIPMember(string name, int memberID, int memberSince) : base(name, memberID, memberSince)
    {
        Console.WriteLine("Child Constructor with 3 parameters");
    }
    public void CalculateAnnualFee()
    {
        annualFee = 1200;
    }
}

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
    }
}
                                                     ✅ 실행결과를 보면 알 수 있듯이 모든 Total AnnualFee가 0으로 출력이된다.
실행결과 :                                               그렇다면 이 문제를 어떻게 해결해줄 수 있을까???
            Remarks = Normal Rate                        아래의 코드를 봐보자.
            Parent Constructor with 3 parameters
            Remarks = Normal Rate
            Parent Constructor with 3 parameters
            Child Constructor with 3 parameters
            Parent Constructor with 3 parameters
            Child Constructor with 3 parameters

            Name: James
            Member ID: 1
            Member Since: 2010
            Total AnnualFee: 0

            Name: Andy
            Member ID: 2
            Member Since: 2011
            Total AnnualFee: 0

            Name: Bill
            Member ID: 3
            Member Since: 2011
            Total AnnualFee: 0

            Name: Carol
            Member ID: 4
            Member Since: 2012
            Total AnnualFee: 0

            Name: Evelyn
            Member ID: 5
            Member Since: 2012
            Total AnnualFee: 0
 
----------------------------------------------
 
using System;

class Member
{
    protected int annualFee;
    private string name;
    private int memberID;
    private int memberSince;

    public override string ToString()
    {
        return "\nName: " + name + "\nMember ID: " + memberID + "\nMember Since: "
                + memberSince + "\nTotal AnnualFee: " + annualFee;
    }
    public Member()
    {
        Console.WriteLine("Parent Constructor with no parameter");
    }
    public Member(string pName, int pMemberID, int pMemberSince)
    {
        Console.WriteLine("Parent Constructor with 3 parameters");
        name = pName;
        memberID = pMemberID;
        memberSince = pMemberSince;
    }
    public virtual void CalculateAnnualFee()       // 🎈🎈 챕터 7에서 봤던 virtual 키워드이다. 
    {                                                      자식클래스에서 이 함수를 오버라이딩이 가능하도록 허용한다.
        annualFee = 0;
    }
}

class NormalMember : Member
{
    public NormalMember(string remarks, string name, int memberID, int memberSince) : base(name, memberID, memberSince)
    {
        Console.WriteLine("Remarks = {0}", remarks);
    }
    public override void CalculateAnnualFee()         // 🎈🎈 override를 사용하여 함수를 재정의
    {
        annualFee = 100 + 12 * 30;
    }
}
class VIPMember : Member
{
    public VIPMember(string name, int memberID, int memberSince) : base(name, memberID, memberSince)
    {
        Console.WriteLine("Child Constructor with 3 parameters");
    }
    public override void CalculateAnnualFee()       // 🎈🎈 override를 사용하여 함수를 재정의
    {
        annualFee = 1200;
    }
}

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
    }
}


실행결과:                                         ✅ 이제 각자의 매년 요금이 제대로 출력된다.
         Child Constructor with 3 parameters

         Name: James
         Member ID: 1
         Member Since: 2010
         Total AnnualFee: 460

         Name: Andy
         Member ID: 2
         Member Since: 2011
         Total AnnualFee: 460

         Name: Bill
         Member ID: 3
         Member Since: 2011
         Total AnnualFee: 460

         Name: Carol
         Member ID: 4
         Member Since: 2012
         Total AnnualFee: 1200

         Name: Evelyn
         Member ID: 5
         Member Since: 2012
         Total AnnualFee: 1200
         
                                                이것이 바로 다형성의 힘이다!!! (사실 아직 아무런 느낌없음)
         
 
