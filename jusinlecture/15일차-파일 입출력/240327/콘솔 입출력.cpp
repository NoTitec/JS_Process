// 240327.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

// https://hungrysoul9.github.io/2019/09/26/add-vs-pre-complied-header/

int main()
{
	

	// 텍스트 모드 문자열 함수
	
	// putchar : 아스키 코드 문자 한 글자를 출력하는 함수
	// putchar(65);		// 콘솔용 텍스트 모드 문자 함수
	
	// fputc : 아스키 코드 문자 한 글자를 출력하는 함수
	// fputc('B', stdout);	// 범용적인 텍스트 모드 문자 함수

	// getchar : 아스키 코드 문자 한 글자를 입력받는 함수

	/* char	ch = getchar();
	 putchar(ch);
	 
	// fgetc : 아스키 코드 문자 한 글자를 입력받는 함수
	int ch = fgetc(stdin); // 범용적인 텍스트 모드 문자 함수
	fputc(ch, stdout);
	*/
	
	// EOF : end of file (파일의 끝에 도달했다는 것을 알려주는 상수 값)
	
	//while (true)
	//{
	//	char	ch = getchar();

	//	if (EOF == ch)		// ctrl + z키를 입력하면 입력 버퍼에 EOF가 삽입
	//		break;

	//	if ('a' <= ch && 'z' >= ch)
	//		ch -= 32;

	//	else if ('A' <= ch && 'Z' >= ch)
	//		ch += 32;

	//	putchar(ch);
	//}

	// 문자열 출력 함수
	// //호출 후 자동 줄바꿈
	//puts("hello");
	//호출 후 자동 줄바꿈 x
	//fputs("hello", stdout);

	//'\r'(carriage return) + '\n' : carriage return은 개행 한 줄의 맨 앞으로 데이터들을 이동시킨다는 이스케이프 문자

	// 문자열 입력 함수
	// char szName[8] = "";
	
	// gets_s(szName, sizeof(szName));	// 공백(스페이스)을 읽어온다. enter를 읽어들이지 못함
	// puts(szName);

	// fgets(szName, sizeof(szName), stdin);	// enter(개행 문자)가 나올 때까지 읽어온다. 문자열의 null문자까지 고려, enter도 읽어들임
	// fputs(szName, stdout);

	// 버퍼 비우기 함수 : 입력 버퍼 비우기는 불가능
	// fflush(stdout) : 출력 버퍼 비우기

	/*char	szID[9] = "";
	char	szName[16] = "";

	fgets(szID, sizeof(szID), stdin);
	
	while ('\n' != getchar());

	fgets(szName, sizeof(szName), stdin);

	fputs(szID, stdout);
	fputs(szName, stdout);*/

    return 0;
}

