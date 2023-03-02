2022. 05. 24. 

🟡 자바스크립트 시작

🟢 자바스크립트 언어란?

  --> 자바스크립트 언어의 중요한 특성
        
        첫째, 자바스크립트는 조각난 소스 코드 형태로 HTML 페이지에 내장된다.
        둘째, 자바스크립트 소스 코드는 컴파일 과정 없이 브라우저 내부의 자바스크립트 처리기(인터프리티)에 의해 바로 실행된다.
        셋째, 자바스크립트는 C언어 구조를 차용하고 단순화시켜 쉽게 배울 수 있다.

🟢 웹 페이지에서 자바스크립트의 역할

  --> 웹 페이지는 HTML5 태그, CSS3 스타일 시트, 자바스크립트 프로그램의 3가지 코드가 결합되어 작성된다.
      HTML5 태그로는 웹 페이지의 구조와 내용을 작성한다.
      색상이나 폰트, 배치 등 웹 페이지의 모양은 CSS3로 꾸민다.
      자바스크립트는 사용자의 입력을 처리하거나 웹 애플리케이션을 작성하는 등 웹 페이지의 동적 제어에서 사용된다.
      
     🔷 사용자의 입력 및 계산
      
       --> HTML 폼은 입력 창만 제공할 뿐, 입력을 받고 계산하는 기능은 수행할 수 없다.
           키나 마우스의 입력과 계산은 오직 자바스크립트로만 처리 가능하다.
           
     🔷 웹 페이지 내용 및 모양의 동적 제어
     
     🔷 브라우저 제어
     
     🔷 웹 서버와의 통신
     
     🔷 웹 애플리케이션 작성
     
🟢 자바스크립트 코드의 위치

 * HTML 태그의 이벤트 리스너 속성에 작성
 * <script></script> 내에 작성
 * 자바스크립트 파일에 작성
 * URL 부분에 작성

 🔷 HTML 태그의 이벤트 리스너 속성에 자바스크립트 코드 작성
   
   --> HTML 태그에는 마우스가 클릭되는 등 이벤트가 발생할 때 처리하는 코드를 등록하는 리스너 속성이 있다.
       개발자들은 이 속성에 이벤트를 처리할 자바스크립트 코드를 작성할 수 있다.
       
       <img src="apple.png" alt="img" onclick="this.src='banana.png'">  -->  <img> 태그의 onclick 이벤트 리스너 속성에 자바스크립트 코드를 작성한 사례이다.
       
    🎈🎈 이벤트(event)는 사용자의 입력 행위를 브라우저가 웹 페이지에 전달하는 수단이다.
         사용자가 HTML 태그가 출력된 영역에 키를 입력하거나 마우스를 클릭하면 이벤트(event)가 발생하며, 이벤트는 해당 HTML 태그에게 전달된다.
         이벤트는 click, change, mousemove 등 많은 종류가 있으며, 
         이벤트를 처리하는 자바스크립트 코드를 이벤트 리스너(event listener)라고 한다.
         onclick, onchange, onmousemove와 같이 이벤트 앞에 on을 붙인 이름이 HTML 태그의 이벤트 리스너 속성으로 사용되며,
         이 속성에 자바스크립트 코드를 작성한다.
    
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>이벤트 리스너 속성에 자바스크립트 코드</title>
</head>
<body>
<h3>마우스 올려 보세요</h3>
<hr>
<img src="media/apple.png" alt="이미지"
		onmouseover="this.src='media/banana.png'"    <-- 마우스를 올리면 바나나 이미지로 변경
		onmouseout="this.src='media/apple.png'">     <-- 마우스를 때면 다시 사과 이미지로 변경
</body>
</html>

 🔷 <script></script> 태그에 자바스크립트 코드 작성
 
   * <script></script>는 <head></head>나 <body></body> 내 어디든 들어갈 수 있다.
   * 웹 페이지 내에 <script></script>를 여러 번 작성할 수 있다.


<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>script 태그에 자바스크립트 작성</title>
<script>
function over(obj) {
	obj.src="media/banana.png";
}
function out(obj) {
	obj.src="media/apple.png";
}
</script>
</head>
<body>
<h3>마우스 올려 보세요</h3>
<hr>
<img src="media/apple.png" alt="이미지"
		onmouseover="over(this)"
		onmouseout="out(this)">
</body>
</html>

  🔷 자바스크립트 코드를 별도 파일에 작성
  
   <script src="파일이름.js"> // 이곳에 자바스크립트 코드를 추가 작성하면 안 됨 </script>


  🔷 URL 부분에 자바스크립트 코드 작성
  
    --> 다음과 같이 <a> 태그의 href 속성에도 자바스크립트 코드를 작성할 수 있다.
  
<head>
<meta charset="UTF-8">
<title>URL에 자바스크립트 작성</title>
</head>
<body>
<h3>링크의 href에 자바스크립트 작성</h3>
<hr>
<a href="javascript:alert('클릭하셨어요?')">  
클릭해보세요</a>
</body>
</html>


🟢 자바스크립트로 HTML 콘텐츠 출력
 
  --> 자바스크립트 코드로 HTML 콘텐츠를 웹 페이지에 직접 삽입하여 바로 브라우저 윈도우에 출력되게 할 수 있다.
      이때 document.write()나 document.writeln()을 사용한다.
      
      document.write("<h3>Welcome!</h3>");   <-- 이러면 h3 크기의 글자로 "Welcome!"이 출력된다.

     🎈🎈 document.write() document.writeln()의 차이
          --> writeln()은 텍스트에 '\n'을 덧붙여 출력한다. '\n'을 덧붙이는 효과는 고작해야 빈칸 하나에 불과하며 다음 줄로 넘어가는 것은 아니다...!!

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>document.write() 활용</title>
</head>
<body>
<h3>document.write() 활용</h3>
<hr>
<script>
	document.write("<h3>Welcome!</h3>");
	document.write("2 + 5 는 <br>");
	document.write("<mark>7 입니다.</mark>");
</script>
</body>
</html>

🟢 자바스크립트 다이얼로그 : 사용자 입력 및 메시지 출력

   🔷 프롬프트 다이얼로그, prompt("메시지", "디폴트 입력값")
   
     --> prompt() 함수는 다이얼로그를 출력하고 사용자로부터 문자열을 입력받아 리턴한다.
         "디폴트 입력값"은 생략 가능하다.
         prompt()는 사용자가 입력한 문자열을 리턴하지만, 아무 값도 입력되지 않았으면 ""를, 취소 버튼이나 강제로 다이얼로그를 닫은 경우 null을 리턴한다.
         
         
         let ret = prompt("이름을 입력하세요", "선태욱");
         if (ret == null) 
         {
            // 취소 버튼이나 다이얼로그를 닫은 경우
         } 
         else if (ret == "")
         {
            // 문자열 입력 없이 확인 버튼 누른 경우
         }
         else 
         {
            // ret에는 사용자가 입력한 문자열
         }
           
    🔷 확인 다이얼로그, confirm("메시지")
    
       --> confirm() 함수는 '메시지'와 확인/취소 (ok/cancel) 버튼을 가진 다이얼로그를 출력한다.
           사용자가 확인 버튼을 누르면 true, 취소 버튼이나 강제로 다이얼로그를 닫으면 false를 리턴한다.
           
         let ret = confirm("전송할까요?")
         if (ret == true)
         {
            // 사용자가 "확인" 버튼을 누른 경우
         }
         else
         {
            // 취소 버튼이나 다이얼로그를 닫은 경우
         }
         
     🔷 경고 다이얼로그, alert("메시지")
       
        --> alert() 함수는 다이얼로그를 출력하여 단순히 메시지를 전달한다.
        
        alert("클릭하였습니다.");
  

🟡 데이터 타입과 변수

🟢 자바스크립트 식별자

   --> 식별자(identifier)란 자바스크립트 개발자가 자바스크립트 프로그램의 변수, 상수(리터럴), 함수에 붙이는 이름이다.
   
       * 첫 번째 문자 - 알파벳(A~Z, a~z), 언더스코어(_), $ 문자만 사용가능
       * 두 번째 이상 문자 - 알파벳, 언더스코어, 0~9, $ 사용가능
       * 대소문자 구분 - MYhome 과 myhome은 다른 변수

🟢 문장 구분
  
   --> 세미클론(;) 으로 문장과 문장을 구분한다.
   
🟢 주석문

   -->  // 와 /* */ 
   
🟢 데이터 타입

	🔷 데이터 타입 종류
	  
	       * 숫자 타입 : 42, 3.14
	       
	       * 논리 타입 : true, false
	       
	       * 문자열 타입 : '좋은 세상', "a", "365", "2+4" 
	          --> 자바스크립트에서는 문자 타입이 없어, 문자는 모두 문자열로 표현한다.
		  
	       * 객체 레퍼런스 타입 : 객체를 가리킴. C 언어의 포인터와 유사
	       
	       * null : 값이 없음을 표시하는 특수 키워드. Null, NULL과는 다름

🟢 변수
   
    --> 자바스크립트에서 변수를 선언하는 방법은 3가지이다.
    
        1. var를 이용하는 방법
	2. let을 이용하는 방법
	3. const를 이용하는 방법
	
    🔷 변수 선언 방법
    
    🔷 변수 타입과 값
    
      --> 자바스크립트에는 변수 타입이 없으므로 다음과 같이 var/let/const와 변수명만으로 선언한다.
      	  그리고 변수에는 아무 값이나 저장할 수 있다.
    
    🔷 변수의 사용 범위와 생명
    
    🔷 this로 전역변수 접근
    
      --> 함수 f() 내에서 변수 x를 접근하면 지역 변수 x이며, this.x로 하면 전역 변수에 접근할 수 있다.
          let으로 선언된 전역 변수는 this로 접근할 수 없다.
    
var x=10;  // 전역 변수 x 선언

function f() {
	var x;  // 지역 변수 x 선언
	x = 1;  // 지역 변수 x에 1 저장
	this.x = 100;  // 전역 변수 x에 100 저장
}


🟢 let의 특징

   * var는 동일한 변수를 재선언할 수 있지만, let으로는 동일한 변수를 재선언할 수 없다.
   * let은 변수의 사용범위를 블록 내로 제한한다.
   
   🔷 let으로는 동일한 변수를 재선언할 수 없다.
   
   🔷 let은 변수 사용 범위를 블록 내로 제한
   
   🔷 var보다 let의 사용 권고

🟢 상수

   --> 상수는 변하지 않는 값을 가지는 이름이며 const 키워드를 이용하여 다음과 같이 초깃값과 함께 선언한다.
   
    	const MAX = 10; // 10의 값을 가지는 상수 MAX 선언
	MAX = 20;  // 오류. 상수는 값을 바꿀 수 없다.

🟢 리터럴
 
  --> 변수가 데이터 저장 공간의 이름이라면, 리터럴(literal)는 데이터 값 그 자체이다.
  
    * literal 뜻 : 문자 그대로의, 기본적인
    
       문자열 리터럴은 이중인용부호("")이나 단일인용부호('') 중 아무 것이나 사용해도 된다.
       문자열 내에 이중인용부호("")를 사용하고자 한다면 \"로 사용하면 된다.
       
       
       🔷 문자열 내 문자열
         
	   --> 문자열 안에 다른 문자열을 포함하고자 할 때 예시. -->  <p onmouseover = "document.body.style.color = 'brown'">
 
	 

🟡 식과 연산자

🟢 산술 연산

🟢 증감 연산

🟢 대입 연산

🟢 비교 연산
    
   🎈🎈  ==와 ===의 차이점
   
       --> ==는 Equal Operator이고,  ===는 Strict Equal Operator이다. 
           ===는 Strict, 즉 엄격한 Equal Operator로써, "엄격하게" 같음을 비교할 때 사용하는 연산자이다. 
	   ===는 a === b 라고 할때, 값과 값의 종류(Data Type)가 모두 같은지를 비교해서, 같으면 true, 다르면 false라고 한다. 
    
		var a = 1; 
		var b = "1"; 
		console.log(a == b); // true 
		console.log(a === b); // false 
		
		-------
		
		console.log(0 == "0"); // true 
		console.log(0 === "0"); // false 
		console.log(0 == ""); // true 
		console.log(0 === ""); // false 
		
		--------
		
		console.log(true == 1); // true 
		console.log(true === 1); // false      <-- 1과 ture의 데이터 타입이 다르기 때문에 거짓이다.
						
			                  출처: https://steemit.com/kr-dev/@cheonmr/js-operator

    
🟢 논리 연산

🟢 조건 연산 

   --> condition ? expT : expF
       
       codition이 true이면 조건식의 전체 결과는 exput의 계산 값이 되고, false이면 expF의 계산 값이 된다.
       
       let x = 5, y = 3;
       let big (x > y) ? x : y;   // x > y가 true이므로 x 값 5가 big에 대입된다.
       
       -----
       
       let a = 3, b = 5;
       document.write("a=" + a + ", b=" + b + "<br><br>");
       document.write("두수의 차이 : " + ((a>b) ? (a-b):(b-a)));   <-- a > b가 false이므로 b-a 값이 출력
       
       출력결과
	       a=3, b=5

	       두수의 차이 : 2
     

🟢 비트 연산

🟢 문자열 연산

    🔷 문자열 연결
      
        --> +, += 연산자는 문자열 연결에도 사용된다. 
	    이때 피연산자 중 하나는 반드시 문자열이어야 한다.
	    
	    "abc" + "de"   // "abcde"
	    "abc" + 23    // "abc23"
	    23 + "abc"    // "23abc"
	    23 + "35"     // "2335"
	    23 + 35       // 58
	    
	    23 + 35 + "abc"  // "58abc"
	    "abc" + 23 + 35  // "abc2335"
	    
     🔷 문자열 비교
     
       let name = "kitae"
       let res1 = (name == "kitae")  // res1 = true
       let res2 = (name > "park")  //  res2 = false. "kitae" 가 "park" 보다 영어사전에서 앞에 있음 (사전에서 먼저 나오면 작은 것이다.   ABCDEFGHIJKLMNOPQRSTUVWXYZ)
     

🟡 조건문

🟢 if 문

🟢 if-else 문

🟢 다중 if-else 문

🟢 switch 문

🟡 반복문

🟢 for 문

🟢 while 문

🟢 do-while 문

🟢 break 문

🟢 continue 문

🟡 함수

🟢 함수 개념

🟢 함수의 구성

🟢 함수 호출

🟢 자바스크립트의 전역 함수





