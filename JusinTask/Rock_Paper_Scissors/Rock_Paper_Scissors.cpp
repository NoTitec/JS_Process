// Rock_Paper_Scissors.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
//2. 가위 바위 보 게임 만들기
//
//- 난수를 뽑아서 0~2의 숫자를 만든다.(컴퓨터의 가위 바위 보 값에 해당)
//- 1. 가위 2. 바위 3. 보 4. 종료
//- 사용자가 입력한 값과 난수에 의해 발생한 가위 바위 보를 비교하여 승, 무, 패를 계산
//- 총 5라운드 실행 후, 마지막 라운드 종료 시 몇 승 몇 무 몇 패를 출력
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int iRound(1), iComputerValue(0), iInput(0), iWin(0), iDefeat(0), iDraw(0);
    bool bChoice(true);
    srand(unsigned(time(NULL)));

    while ((iRound <= 5) && bChoice)
    {
        system("cls");
        cout << "현재 라운드: " << iRound<<endl;
        iComputerValue = rand() % 3;
        //0이면 가위, 1이면 바위, 2이면 보
        
        cout << "1. 가위 2. 바위 3. 보 4. 종료"<<endl;
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            if (iComputerValue == 0)
            {
                cout << "컴퓨터 : 가위" << endl;
                cout << "내가 낸 것 : 가위" << endl;
                cout << "무승부";
                iDraw++;
            }
            else if (iComputerValue == 1)
            {
                cout << "컴퓨터 : 바위" << endl;
                cout << "내가 낸 것 : 가위" << endl;
                cout << "패배";
                iDefeat++;
            }
            else
            {
                cout << "컴퓨터 : 보" << endl;
                cout << "내가 낸 것 : 가위" << endl;
                cout << "승리";
                iWin++;
            }
            break;
        case 2:
            if (iComputerValue == 0)
            {
                cout << "컴퓨터 : 가위" << endl;
                cout << "내가 낸 것 : 바위" << endl;
                cout << "승리";
                iWin++;
            }
            else if (iComputerValue == 1)
            {
                cout << "컴퓨터 : 바위" << endl;
                cout << "내가 낸 것 : 바위" << endl;
                cout << "무승부";
                iDraw++;
            }
            else
            {
                cout << "컴퓨터 : 보" << endl;
                cout << "내가 낸 것 : 바위" << endl;
                cout << "패배";
                iDefeat++;
            }
            break;
        case 3:
            if (iComputerValue == 0)
            {
                cout << "컴퓨터 : 가위" << endl;
                cout << "내가 낸 것 : 보" << endl;
                cout << "패배";
                iDefeat++;
            }
            else if (iComputerValue == 1)
            {
                cout << "컴퓨터 : 바위" << endl;
                cout << "내가 낸 것 : 보" << endl;
                cout << "승리";
                iWin++;
            }
            else
            {
                cout << "컴퓨터 : 보" << endl;
                cout << "내가 낸 것 : 보" << endl;
                cout << "무승부";
                iDraw++;
            }
            break;
        case 4:
            cout << "대결 종료";
            iRound--;
            bChoice = false;
            break;
        default:
            cout << "잘못된 값을 입력했습니다 다시 입력하세요";
            iRound--;
            break;

        }
        iRound++;
        system("pause");
    }

    //프로그램 종료 또는 라운드 다 돌았으므로 승,패,무승부 횟수 출력
    system("cls");
    cout << "승: " << iWin << " 패: " << iDefeat << " 무승부: " << iDraw;
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
