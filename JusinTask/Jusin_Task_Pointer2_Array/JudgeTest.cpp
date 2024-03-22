#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

//스트라이크 횟수 저장 변수
int iStrike(0);
//볼 횟수 저장 변수
int iBol(0);
//랜덤 숫자 3개 담을 배열
int iRandomArray[3] = {8,7,7};

//사용자 입력 숫자 3개 담을 배열
int iInputarray[3] = {};

//시드값 초기화 함수
void Set_Random_Number_Seed();
//1~9 랜덤수 뽑아내는 함수
int Get_1_9_Random_Number();
//배열 내용 출력하는 함수
void Print_Array(int iArray[], int iArraySize);
//랜덤수 배열크기만큼 생성해서 담는 함수
void Fill_3_Random_Number_To_Array(int iArray[], int iArraySize);
//숫자 세개 입력받아서 iInputArray에 담는 함수
void Get_Input_For_iArray(int iArray[], int iArraySize);
//비교 결과(승리시 true 반환)
bool Compare_Two_iArray_Is_Equal(int iRandomArray[], int iInputArray[], int* pBol, int* pStrike, int* i);
//최대 9라운드 승리조건 : 스트라이크 시 승리, 패배조건: 9라운드 다 돌때까지 스트라이크 3회 도달 못한경우


int main()
{
	//시드값 변경
	Set_Random_Number_Seed();
	//무작위 숫자 3개 뽑아 랜덤숫자 배열 담기
	//Fill_3_Random_Number_To_Array(iRandomArray, 3);
	//스트라이크 3회가 되면 게임 종료
	for (int i = 0; i < 9; i++)
	{
		cout << "정답 : ";
		Print_Array(iRandomArray, 3);
		cout << endl;
		//숫자 3개 입력받아 입력 배열 담기
		Get_Input_For_iArray(iInputarray, 3);
		//랜덤배열, 입력 배열 비교하여 판별하고 결과 출력
		//스트라이크시 승리
		if (Compare_Two_iArray_Is_Equal(iRandomArray, iInputarray, &iBol, &iStrike, &i))
		{
			cout << "스트라이크~";
			return 0;
		}
	}
	//9라운드 다돌때까지 승리 못한경우 패배
	cout << "Lose~" << endl;
	return 0;
}
void Set_Random_Number_Seed()
{
	srand(unsigned(time(NULL)));
}
//1~9 랜덤수 뽑아내는 함수
int Get_1_9_Random_Number()
{
	int iRandomNumber = rand() % 9 + 1;
	return iRandomNumber;
}
//배열 내용 출력하는 함수
void Print_Array(int iArray[], int iArraySize)
{
	for (int i = 0; i < iArraySize; i++)
	{
		cout << setw(2) << iArray[i];
	}
}
//랜덤수 배열크기만큼 생성해서 담는 함수
void Fill_3_Random_Number_To_Array(int iArray[], int iArraySize)
{
	for (int i = 0; i < iArraySize; i++)
	{
		iArray[i] = Get_1_9_Random_Number();
	}
}
//배열크기만큼 입력받아서 배열에 담는 함수
void Get_Input_For_iArray(int iArray[], int iArraySize)
{
	cout << "숫자 입력 : ";
	for (int i = 0; i < iArraySize; i++)
	{
		cin >> iArray[i];
	}
}
//인자: 랜덤 배열, 입력 배열, 볼 int 포인터 , 스트라이크 int 포인터, 라운드 포인터
bool Compare_Two_iArray_Is_Equal(int iRandomArray[], int iInputArray[], int* pBol, int* pStrike, int* i)
{
	*pBol = 0;
	*pStrike = 0;

	//이미 판별된 숫자는 제외
	bool bmatchedRandomArray[3] = { false };
	bool bmatchedInputArray[3] = { false };
	//값, 위치 모두 같은 경우 계산
	for (int i = 0; i < 3; i++)
	{
		if (iRandomArray[i] == iInputArray[i])
		{
			*pStrike += 1;
			bmatchedRandomArray[i] = true;
			bmatchedInputArray[i] = true;
		}
	}
	//스트라이크면 true반환 후 종료
	if (*pStrike == 3)
	{
		return true;
	}
	//스트라이크가 아니면 현재 회차수, 몇 스트라이크 몇 볼인지 출력하고 함수 종료
	// 값은 같지만 위치는 다른 경우의 수를 계산
	//입력한 숫자와 출력된 숫자가 값만 같으면 볼
	for (int i = 0; i < 3; i++)
	{
		//매칭이 안된 인덱스일때만 탐색
		if (!bmatchedRandomArray[i])
		{
			for (int j = 0; j < 3; j++)
			{
				if (!bmatchedRandomArray[i]&&!bmatchedInputArray[j])
				{
					//값이 같고 인덱스 위치가 다른경우
					if (iRandomArray[i] == iInputArray[j] && i != j)
					{
						*pBol += 1;
						bmatchedRandomArray[i] = true;
						bmatchedInputArray[j] = true;
						break;
					}
				}
			}
		}
	}
	cout << *i + 1 << "회 : ";
	Print_Array(iInputArray, 3);
	cout << " " << *pStrike << "스트라이크" << *pBol << "볼" << endl;
	return false;
}

// 3. 야구 게임 만들기
/*
- 1~9까지의 숫자 중 무작위로 3개를 골라내어 화면에 출력한다(정렬하지 않음)
- 숫자 세 개를 입력받는다.
- 입력한 숫자와 출력된 숫자가 값도 자리도 맞으면 스트라이크, 값만 같으면 볼
//a1[ 1, 2, 2] a2[2,2,1]
- 매 회 입력 시, 몇 스트라이크 몇 볼인지 출력
- 3 스트라이크면 승리 출력 후 종료
- 9회까지 3 스트라이크를 만들지 못하면 패배

정답 : 8	 1	5
1회 :  1  2  3	 0 스트라이크 1볼
2회 :  1  8  5	 1 스트라이크 2볼
3회 :  8  1  5   3 스트라이크 0볼
*/