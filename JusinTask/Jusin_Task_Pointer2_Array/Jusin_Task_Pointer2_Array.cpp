﻿// Jusin_Task_Pointer2_Array.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 1. 2중 for문과 배열을 이용하여 다음의 숫자 상태를 출력하라
/*

1	2	3	4	5
6	7	8	9	10
11	12	13	14	15
16	17	18	19	20
21	22	23	24	25

*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //25개 int 담을 수 있는 배열 선언
    int iArray[25] = {};
    //배열에 0~25까지 숫자 담기
    for (int i = 0; i < 25; i++)
    {
        iArray[i] = i + 1;
    }
    //배열에 있는 수를 5개씩 끊어서 마지막 원소까지 출력하기
    //1줄 늘어날때마다 j 전에 i*5만큼 점프해야함
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <5; j++)
        {
            cout <<setw(3)<< iArray[j+(i*5)];
        }
        cout << endl;
    }
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.