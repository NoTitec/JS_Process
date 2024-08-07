﻿// JusinTask_1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int i_KoreanScore, i_EnglishScore, i_MathScore;

int main()
{
    cout << "국어, 영어, 수학 점수 입력: (공백기준 입력)"<<"\n";
    cin >> i_KoreanScore >> i_EnglishScore >> i_MathScore;

    int i_TotalScore(i_KoreanScore + i_EnglishScore + i_MathScore);
    float f_Avg(0.f);
    f_Avg = (float)i_TotalScore / 3.f;
    //cout <<"국어: "<<i_KoreanScore<<" 영어: "<<i_EnglishScore<<" 수학: "<<i_MathScore << " 총점: " << i_TotalScore<<" 평균: "<<f_Avg;

    if (90.f <= f_Avg <= 100.f)
    {
        cout << "A학점";
    }
    else if (80.f <= f_Avg <= 90.f)
    {
        cout << "B학점";
    }
    else if (70.f <= f_Avg <= 80.f)
    {
        cout << "C학점";
    }
    else if (60.f <= f_Avg <= 70.f)
    {
        cout << "D학점";
    }
    else
    {
        cout << "F학점";
    }
    return 0;
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
