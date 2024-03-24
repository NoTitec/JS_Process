// Grade_System_Struct.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
// 1. 구조체를 이용하여 성적표 프로그램을 만들어라.

// 1. 입력 2. 출력 3. 검색(이름)
// - 입력 시에는 세 명의 학생의 정보를 입력만 받는다.
// - 출력 시에는 모든 학생의 정보를 출력만 한다.
// - 검색 시에는 이름을 입력하여 이름과 일치한 학생의 성적만 출력

#include <iostream>

using namespace std;

//학생 정보 구조체 정의
typedef struct tagStudent {
    char s_Name[20];
    int iMath;
    int iEnglish;
    float fAvg;
}STUDENT,*LPSTUDENT;

//메뉴 출력함수
void Print_Menu();

//학생 3명 정보 저장할 학생 구조체 배열

STUDENT tStudentArray[3] = {};
//학생배열 포인터 저장용 
LPSTUDENT lpstudentarray = tStudentArray;
//프로그램 종료 제어 bool 변수
bool bEnd(true);
//찾음 판별용 bool 변수
bool bFind(false);
int main()
{
    int iInput(0);
   
    while (bEnd)
    {
        Print_Menu();

        cin >> iInput;

        switch (iInput)
        {
            //세 명의 학생의 정보를 입력만 받는다.
        case 1:
            for (int i = 0; i < sizeof(tStudentArray) / sizeof(tagStudent); i++)
            {
                cout << i + 1 << " 번째 학생 정보 입력 : " << endl;
                LPSTUDENT lpCurrentStudent = tStudentArray + i;
                cin >> lpCurrentStudent->s_Name >> lpCurrentStudent->iMath >> lpCurrentStudent->iEnglish;
                //평균저장시 명시적으로 float 로 변환해야함 안그러면 몫만 저장됨
                lpCurrentStudent->fAvg = float(lpCurrentStudent->iMath + lpCurrentStudent->iEnglish) / 2.f;
            }
            break;
            // - 출력 시에는 모든 학생의 정보를 출력만 한다.
        case 2:
            for (int i = 0; i < sizeof(tStudentArray) / sizeof(tagStudent); i++)
            {
                cout << i + 1 << " 번째 학생 정보 출력 : " << endl;
                LPSTUDENT lpCurrentStudent = tStudentArray + i;
                cout << "이름 : " << lpCurrentStudent->s_Name << " 수학 : " << lpCurrentStudent->iMath << " 영어 : " << lpCurrentStudent->iEnglish << " 평균 : " << lpCurrentStudent->fAvg << endl;

            }
            break;
            // - 검색 시에는 이름을 입력하여 이름과 일치한 학생의 성적만 출력
        case 3:
            cout << "찾으려는 학생 이름 입력"<<endl;
            bFind = false;
            char s_findName[20];
            cin >> s_findName;
            for (int i = 0; i < sizeof(tStudentArray) / sizeof(tagStudent); i++)
            {
                LPSTUDENT lpCurrentStudent = tStudentArray + i;
                if (!strcmp(lpCurrentStudent->s_Name, s_findName))
                {
                    cout << "학생 발견" << endl;
                    cout <<"이름 : " << lpCurrentStudent->s_Name << endl;
                    cout << " 수학 : " << lpCurrentStudent->iMath << endl;
                    cout << "영어 : " << lpCurrentStudent->iEnglish << endl;
                    cout << "평균 : " << lpCurrentStudent->fAvg << endl;

                    bFind = true;
                    break;
                }
            }
            if(!bFind)
            cout << "찾으려는 학생 정보 없음" << endl;
            break;

        case 4:
            bEnd = false;
            break;
            
        default:
            cout << "잘못된 입력" << endl;
            break;
        }
    }
    
    return 0;
}

void Print_Menu()
{
    cout << "1. 학생 정보 입력(총 3명) 2. 출력 3. 검색(이름) 4.종료";
}
