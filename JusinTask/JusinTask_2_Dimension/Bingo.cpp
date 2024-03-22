
// 1. 5 * 5 배열을 이용하여 빙고를 만들어라
// - 1~25까지 5*5 배열을 만든다
// - 숫자를 입력 받고 입력 받은 값과 일치한 위치의 숫자를 *로 출력한다.
// - * 이 다섯개인줄이 발생할 경우 빙고를 증가시킨다.
// - 5 빙고 이상이면 종료

//생각

//1. 맵 만들기
//2. 맵 초기화하기
//3. 5빙고 될때까지 반복 while문
//3-1. 숫자 입력받고 입력 위치 -1로 변경하기
//3-2. *추가된 맵 출력하기
//-----------------------------
//컴퓨터 추가
//컴퓨터용 맵
// //초기화때 컴퓨터맵도 같이
// 
//사용자입력대신 1~25사이 랜덤수 무작위 뽑기
//나머지 동일
//사용자 빙고 수 컴퓨터 빙고 수 라운드마다 비교하다 어느 한쪽이 5 도달하면 승리한쪽 출력 후 종료

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

//빙고판 사이즈
const int iSize(5);
int iBoard[iSize][iSize]; // 빙고 판
int iComputerBoard[iSize][iSize]; // 컴퓨터 빙고 판
int iComputerRandomNumberArray[iSize * iSize]; //컴퓨터 램덤 수 저장할 배열
//랜덤 시드값 변경 함수
void Set_Random_Seed();
// 빙고 판 초기화 함수
void InitializeBoard();

// 빙고 판 출력 함수
void Print_Board(int(*Board)[5]);

// 입력한숫자 위치 찾아서 표시 (-1로 변경) 함수
void Mark_Number(int(*Board)[5],int number);

// 빙고 체크 함수 (인자: 빙고 체크 원하는 배열)
void checkBingo(int(*Board)[5],int* pbingoCount);


int main() {
    InitializeBoard();
    int ibingoCount(0); // 빙고 카운트
    int iComputerbingoCount(0); //컴퓨터 빙고 카운트
    int iInput(0);
    int iComputerNumber(0);
    int iComputerRandomNumberArray_Index(0);
    while (ibingoCount < 5&&iComputerbingoCount<5) {
        cout << "유저 보드 출력" << endl;
        Print_Board(iBoard);
        cout << "----------------------" << endl;
        cout << "컴퓨터 보드 출력" << endl;
        Print_Board(iComputerBoard);
        cout << "----------------------" << endl;
        //유저 입력한위치 유저보드 *변경하고 빙고 개수 세기
        cout << "1~25사이 숫자 입력 : ";
        cin >> iInput;

        if (iInput < 1 || iInput > 25) {
            cout << "잘못된 입력" << endl;
            continue;
        }
        //변경하려는 위치의 값이 이미 -1이면 continue
        int iRow = (iInput-1) / iSize;
        int iCol = (iInput-1) % iSize;
        if (iBoard[iRow][iCol] == -1)
        {
            cout << "이미 *인 위치" << endl;
            cout << "+++++++++++++++++";
            continue;
        }
        Mark_Number(iBoard,iInput);
        checkBingo(iBoard,&ibingoCount);

        cout << "현재 유저 빙고 수: " << ibingoCount << endl;
        cout << "----------------------" << endl;
        //컴퓨터 랜덤 수 뽑아서 컴퓨터 보드 * 변경하고 빙고 개수 세기
        iComputerNumber = iComputerRandomNumberArray[iComputerRandomNumberArray_Index];
        iComputerRandomNumberArray_Index++;
        Mark_Number(iComputerBoard, iComputerNumber);
        checkBingo(iComputerBoard,&iComputerbingoCount);
        cout << "현재 컴퓨터 빙고 수: " << iComputerbingoCount << endl;
        cout << "----------------------" << endl;
    }
    if (ibingoCount == 5)
    {
        cout << "유저 먼저 5빙고 달성, 종료" << endl;
    }
    else
    {
        cout << "ㅋㅋ" << endl;
    }
    return 0;
}

void Set_Random_Seed()
{
    srand(unsigned(time(NULL)));
}
void InitializeBoard() 
{
    int number = 1;
    for (int i = 0; i < iSize; ++i) {
        for (int j = 0; j < iSize; ++j) {
            iBoard[i][j] = number++;
        }
    }
    number = 1;
    for (int i = 0; i < iSize; ++i) {
        for (int j = 0; j < iSize; ++j) {
            iComputerBoard[i][j] = number++;
        }
    }
    //컴퓨터 뽑을 수 저장된 배열 뒤섞어 놓기
    for (int i = 0; i < iSize * iSize; i++)
        iComputerRandomNumberArray[i] = i + 1;
    for (int i = 0; i < 100; i++)
    {
        swap(iComputerRandomNumberArray[rand() % 25], iComputerRandomNumberArray[rand() % 25]);
    }
}

void Print_Board(int(*Board)[5]) 
{
    for (int i = 0; i < iSize; ++i) {
        for (int j = 0; j < iSize; ++j) {
            if (Board[i][j] == -1) {
                cout << setw(3) << "*";
            }
            else {
                cout << setw(3) << Board[i][j];
            }
        }
        cout << endl;
    }
}

void Mark_Number(int(*Board)[5],int number) 
{
    for (int i = 0; i < iSize; ++i) {
        for (int j = 0; j < iSize; ++j) {
            if (Board[i][j] == number) {
                Board[i][j] = -1;
                return;
            }
        }
    }
}

void checkBingo(int(*Board)[5],int* pbingoCount)
{
    *pbingoCount = 0;
    // \ 방향대각선빙고 횟수, / 방향 대각선빙고 횟수
    int idiagStarCount1(0), idiagStarCount2(0);

    //모든 행 순회
    for (int i = 0; i < iSize; ++i) {
        //행빙고횟수, 열빙고횟수
        int irowStarCount(0), icolStarCount(0);

        //모든 열 순회
        for (int j = 0; j < iSize; ++j) {
            //현재 행의 * 개수 세기
            if (Board[i][j] == -1) irowStarCount++;
            //현재 열의 * 개수 세기
            if (Board[j][i] == -1) icolStarCount++;
        }
        //현재 행렬의 행이 * 5개면 빙고 하나 ++
        //() 빼면 값말고 주소가 증가하는걸 주의!!!!!!!!!!!!!!!!!!!!!!!!!
        if (irowStarCount == iSize) (*pbingoCount)++;
        //현재 행렬의 열이 * 5개면 빙고 하나 ++
        if (icolStarCount == iSize) (*pbingoCount)++;

        //현재 \방향 대각선 *개수 세기
        if (Board[i][i] == -1) idiagStarCount1++;
        //현재 /방향 
        if (Board[i][iSize - i - 1] == -1) idiagStarCount2++;
    }

    //현재 \방향 대각선 *이 5개면 빙고 하나++
    if (idiagStarCount1 == iSize) (*pbingoCount)++;
    //현재 /방향 대각선 *이 5개면 빙고 하나++
    if (idiagStarCount2 == iSize) (*pbingoCount)++;
}