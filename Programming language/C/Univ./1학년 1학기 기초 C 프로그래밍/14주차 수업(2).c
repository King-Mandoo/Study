2022. 06. 02.

🟡 파일 입출력 함수
 
   
🟠 파일 입출력의 기본 과정
   
    --> 표준 입출력 장치(키보드, 모니터)는 항상 준비 되어 있기 때문에 scanf()나 printf() 같은 함수로 바로 사용할 수 있었다.
        하지만 파일 입출력을 위해서는 반드시 두 가지 작업을 추가로 해야 한다.
        
        바로 파일을 사용하기 전의 '파일 열기' 작업과 파일 사용이 끝난 후의 '파일 닫기' 작업이다.
        
        파일 포인터 선언하기 --> fopen() 함수로 파일 열기 --> 파일 처리 함수로 파일을 읽거나 파일에 쓰기 --> fclose() 함수로 파일 닫기
        
     🔷 1단계: 파일 포인터 선언하기
     
           --> 파일을 열려면 가장 먼저 '파일 포인터'라고 하는 포인터 변수를 선언해야 한다.
           
                FILE *변수 이름;
                
     🔷 2단계: fopen() 함수로 파일열기
     
           --> 파일 포인터를 선언했으면 파일을 열기 위해 함수를 사용한다.
               
                  변수 이름 = fopen("파일 이름", "열기 모드");
                  
                  파일의 열기 모드는 파일을 여는 목적을 알려준다.
                  단순히 내용을 읽기 위해 파일을 열 때는 r(read)을 사용하고, 어떤 내용을 쓰기 위해 파일을 열 때는 w(write) 또는 a(append)를 사용한다. 
                  
                  * w: 파일이 없다면 새로 생성하고, 파일이 있다면 기존 파일을 무시하고 새로 덮어 쓴다.
                  * a: 파일이 없다면 새로 생성하지만 파일이 있다면 기존 파일의 맨 끝에서부터 이어 쓴다.
                     추가한다는 의미로 append의 약자인 'a'를 사용한다.
                     
                       *append 뜻: 추가하다, 덧붙이다
                  
                  
     🔷 3단계: 파일 처리 함수로 파일을 읽거나 파일에 쓰기
     
     🔷 4단계: fclose() 함수로 파일 닫기
     
             fclose(파일 포인터);
             

🟠 파일을 이용한 입력

     🔷 파일의 문자열 읽기: fgets()

               --> fgets(문자배열, 읽을 최대 문자 수, 파일 포인터);
               
#include <stdio.h>

int main()
{
	char s[20];
	FILE* rfp;   //(reading file pointer)

	rfp = fopen("C:\\Temp\\file1.txt", "r");

	fgets(s, 10, rfp);

	puts(s);

	fclose(rfp);

	return 0;
}

     🔷 도스 명령어 type의 구현

          --> type 명령어는 지정한 파일의 내용을 화면에 출력하는 기능을 한다.
             
               type 파일 이름

#include <stdio.h>

int main()
{
	char str[200];
	FILE* rfp;   //(reading file pointer)

	rfp = fopen("C:\\windows\\win.ini", "r");

	for (;;)
	{
		fgets(str, 200, rfp);   // 파일에서 한 줄씩 읽어온다.

		if (feof(rfp))    // 파일의 끝이라면 for문을 종료한다.
			break;

		printf("%s", str);
		//puts(str);         <-- ✅ Q. puts() 함수를 사용하면 왜 각 문장의 출력이 줄바꿈이 두 번이 돼서 나올까?    
	}                             A. 아래에 적어놈
 
	fclose(rfp);
	return 0;
}

출력결과: 
           ; for 16-bit app support
           [fonts]
           [extensions]
           [mci extensions]
           [files]
           [Mail]
           MAPI=1
           CMCDLLNAME32=mapi32.dll
           CMC=1
           MAPIX=1
           MAPIXVER=1.0.0.1
           OLEMessaging=1

----------------------------------
🎈🎈
#include <stdio.h>

int main()
{
	char str[100];

	gets(str);   
 //scanf("%s", str);  <-- scanf() 도 버퍼를 사용하므로 똑같은 결과를 초래한다.
 
	puts(str);
}

"ABC"를 입력했을 때의 출력결과 :

                              ABC
                              ABC

                              C : \Users\asus\OneDrive\바탕 화면\study_Cprogramming\x64\Debug\study.exe(프로세스 1248개)이(가) 종료되었습니다(코드: 0개).
                              이 창을 닫으려면 아무 키나 누르세요...
                              
✅ ABC 그다음 ABC 다음에 여백이 생기는 이유는 gets 함수에 "ABC" 그리고 '\n'를 입력하기 때문에 puts 함수가 "ABC\n"를 출력해주기 때문이다. 
   그리고 puts 함수에 자체적으로 '\n'을 포함하기때문에 두번의 줄바꿈이 이루어진다.

---------------------------------------
   
       🔷 서식을 지정하여 파일 읽기: fscanf()
   
          --> fscanf(파일 포인터, "서식", 입력할 매개변수들 .. );

#include <stdio.h>

int main()
{
	FILE* rfp;
	int hap = 0;
	int in;

	rfp = fopen("C:\\Temp\\file1.txt", "r");

	for (int i = 0; i < 6; i++)
	{
		fscanf(rfp, "%d", &in);
		hap = hap + in;
	}

	printf("합계: %d", hap);

	fclose(rfp);

	return 0;
}




#include <stdio.h>

int main()
{
	FILE* rfp;
	float hap = 0;
	float in;

	rfp = fopen("C:\\Temp\\file1.txt", "r");

	for (int i = 0; i < 6; i++)
	{
		fscanf(rfp, "%f", &in);
		hap = hap + in;
	}

	printf("합계: %f", hap);

	fclose(rfp);

	return 0;
}


🟠 파일을 이용한 출력

     🔷 파일의 문자열 출력: fputs()
     
#include <stdio.h>

int main() 
{
	char s[20];
	FILE* wfp;

	wfp = fopen("file1.txt", "w");
	gets(s);    <-- 배열 s에 문자열을 담는다.

	fputs(s, wfp);  <-- 배열 s를 wfp 주소에 있는 파일에 복사한다.

	fclose(wfp);

	return 0;
}

     🔷 도스 명령어 copy의 구현
     
#include <stdio.h>

int main() 
{
	char str[200];
	FILE* rfp;
	FILE* wfp;

	rfp = fopen("C:\\windows\\win.ini", "r");
	wfp = fopen("file1.txt", "w");

	for (;;)
	{
		fgets(str, 200, rfp);

		if (feof(rfp))
			break;

		fputs(str, wfp);
	}

	fclose(rfp);
	fclose(wfp);                    🎈🎈  내가 헷갈린 건 "왜 콘솔창에 아무것도 뜨지않지?" 였다. 그런데 생각해보니
                                              파일 출력 함수는 파일에 출력을 시키는 거지, 콘솔창에 출력 시키는 것이 아니었다.
	return 0;
} 

      🔷 서식을 지정하여 파일 출력: fprintf()
      
       -->  fprintf(파일 포인터, "서식", 출력할 매개변수들..);
	 
	 
#include <stdio.h>

void main()
{
	int num;
	int hap = 0;
	FILE* wfp;

	wfp = fopen("file1.txt", "w");

	for (int i = 0; i < 5; i++)
	{
		printf("숫자%d: ", i + 1);
		scanf("%d", &num);
		hap = hap + num;
	}

	fprintf(wfp, "합계: %d", hap);

	fclose(wfp);
}	 
	 
	 
----------------------------------------------------------------------------------------------------------------------------------------------------------------

📌예제 문제풀이📌

예제 30.  틀림❌  	 
	 
#include <stdio.h>

int main()
{
	FILE* wfp;

	wfp = fopen("file1.txt", "w");

	for(int i =1; i <=9; i++)
		fprintf(wfp, " #제%d단#", i);

	fprintf(wfp, "\n");
	fprintf(wfp, "\n");

	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			fprintf(wfp, "%2dX%2d=%2d", j, i, j * i);
		}
		fprintf(wfp, "\n");
	}

	fclose(wfp);    <-- 파일을 안닫아줘서 틀림.. 꼭 닫아주자..!

	return 0;
} 
	 

예제 31.  맞음⭕  하지만 이상한 점이 있음

#include <stdio.h>
#include <string.h>

int main()
{
	FILE* rfp;
	FILE* wfp;
	char aa[200];
	char bb[200];
	int change;

	rfp = fopen("file1.txt", "r");
	wfp = fopen("file2.txt", "w");

	while (1)
	{
		//fgets(aa, 200, rfp);    <-- ✅ Q. 왜 fgets() 함수는 줄을 자동으로 띄어주는 거지..? 이 함수를 쓰면 fprintf("\n")을 안해줘도 알아서 줄 바꿈이 된다.
		fscanf(rfp, "%s", aa);

		change = strlen(aa);

		if (feof(rfp))
			break;

		for (int i = 0; i < change; i++)
		{
			bb[i] = aa[(change - 1) - i];
	        
		}
		bb[change] = '\0';

		fprintf(wfp, "%s\n", bb);
		//fputs(bb, wfp);
	}

	fclose(rfp);
	fclose(wfp);

	return 0;
}
                                 ✅ A. fgets() 함수는 '\n'까지 읽어오기 때문이다.   근데 file2에서 왜 맨 위에도 공백이 생기는 걸까..??
				        
			               그건 file1을 거꾸로 읽어 오면 '\n' 부터 읽어오기 때문이다.
