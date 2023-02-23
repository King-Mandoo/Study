

       복사 생성자가 호출되는 시점.
         
         - case 1 : 기존에 생성된 객체를 이용해서 새로운 객체를 초기화하는 경우
         
                    Person man1("Sun tae uk", 24);
                    Person man2 = man1;   // 복사 생성자 호출
           
         - case 2 : Call-by-value 방식의 함수호출 과정에서 객체를 인자로 전달하는 경우
         
         - case 3 : 객체를 반환하되, 참조형으로 반환하지 않는 경우
         
--------------------------------------------------------------------------------------------------------------------------

🟢 메모리 공간의 할당과 초기화가 동시에 일어나는 상황!

 ✔ 메모리 공간을 할당과 동시에 num2에 저장된 값으로 초기화하는 경우

 int num = num2
 
-------------------------------------------------------
           
 ✔ Call-by-value 방식의 함수호출 과정에서 인자로 전달하는 경우
           
int SimpleFunc(int n)    // int n = num;  이렇게..
{
   ...       
}                   

int main()
{
   int num = 10;
   SimpleFunc(num);       // 호출되는 순간 매개변수 n이 할당과 동시에 초기화
}        
          
-------------------------------------------------------
  
  ✔ 값을 반환하되, 참조형으로 반환하지 않는 경우
  
int SimpleFunc(int n)    // int n = num;  
{
   return n;         // 반환하는 순간 메모리 공간이 할당되면서 동시에 초기화!
}                    // ✅ Q. 아니 반환하는 공간이 변수도 아닌데 어떻게 메모리 공간이 할당되지??  

int main()
{
   int num = 10;
   cout << SimpleFunc(num);     // 이곳에서 별도의 메모리 공간이 할당되고 초기화가 동시에 일어난다. (눈에 보이지 않아서 약간 헷갈린다)
}
                        ✅ A. 값을 반환하면 반환된 값은 별도의 메모리 공간이 할당되어서 저장이 된다.
                               그렇지 않다면 어떻게 cout << SimpleFunc(num); 은 출력이 될까?
                          
                         🎈🎈 "함수가 값을 반환하면, 별도의 메모리 공간이 할당되고, 이 공간에 반환 값이 저장된다(반환 값으로 초기화된다)."
                          
                               C에서의 이에 관한 질문 : https://kldp.org/node/163726

--------------------------------------------------------------------------------------------------------------------------
  
   위에서 메모리 공간의 할당과 초기화가 동시에 일어나는 총 3가지의 경우를 알아보았다.
  
   이는 객체를 대상으로 해도 달라지지 않는다.
  
  
   ✔ case 1 
   SoSimple obj2 = obj1; 


   ✔ case 2
   SoSimple SimpleFuncObj(SoSimple ob)
   {
     ...
   }
   int main()
   {
     SoSimple obj;
     SimpleFuncObj(obj);
     ...
   }


    ✔ case 3
    SoSimple SimpleFuncObj(SoSimple ob)  // 당연히 여기서 또한, SoSimple ob = obj; 라는 문장으로 할당과 동시에 초기화 !
    {
      return ob;    // 반환하는 순간 메모리 공간이 할당되면서 동시에 초기화 !
    }
    int main()
    {
      SoSimple obj;
      SoSimple obj2 = SimpleFuncObj(obj);
    }
