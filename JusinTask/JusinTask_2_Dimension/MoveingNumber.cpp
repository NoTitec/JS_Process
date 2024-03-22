#include<iostream>
#include<iomanip>
using namespace std;
// 2. 숫자(0) 이동 시키기

/*
- 0~24까지 5 * 5배열 상태로 출력
- 2. 아래 4. 왼쪽 6. 오른쪽 8. 위
- 번호를 눌렀을 경우 숫자 0의 위치를 이동

0	1	2		1	0	2		1	4	2
3	4	5	-6>	3	4	5 -2>	3	0	5
6	7	8		6	7	8		6	7	8
*/

//생각-----------------------------
// 
//1. 5*5 크기 맵 생성
// 1-1 맵용 2차원 배열 필요
// 
//2. 시작위치 0,0
// 2-1 위치저장용 배열 필요
// 
//3. 상하좌우 이동 배열생성
// 3-1 상하좌우 이동량용 배열 필요
// 3-2. 버튼에따라 이동방향 정할 배열 필요
// 
//4. 버튼 누르면 일단 맵 범위 안벗어나는지 체크
// 
//5. 맵 범위를 벗어나지 않으면 이동하려는 좌표값과 내위치값을 swap
// 
//6. -1을 입력하면 게임이 종료되도록

//함수
// 현재 맵 출력하는 함수
void Print_Current_Map(int(*Array)[5]);

// 이동하려는 위치가 맵 벗어나는지 체크하는 함수
bool Is_Move_Location_Valid(int*x,int*y);



// 맵!!
int iMap[5][5] = {};
// 현재 좌표 저장할 배열
int iLocationArray[2] = {};
//각 방향 배열
int dx[4] = { 0, 0, -1, 1 }; // 상, 하, 좌, 우
int dy[4] = { -1, 1, 0, 0 }; // 상, 하, 좌, 우

//방향 배열
int directions[4] = { 0,1,2,3 }; //상, 하, 좌, 우

//게임 종료위한 bool 변수
bool bEnd(true);

int main()
{
	//맵 초기화용 for문
	for (int i = 0; i < 5; i++)
	{
		for(int j=0;j<5;j++)
		{ 
			iMap[i][j] = i * 5 + j;
		}
	}
	//초기 상태 출력
	Print_Current_Map(iMap);

	//사용자 입력 저장 변수
	int iInput(0);

	//-1을 입력하지 않는 한 무한히 이동 진행하는 while문
	while (bEnd)
	{
		//이동하려는 좌표 저장할 변수
		int nx(0);
		int ny(0);
		int dd(0);
		//가고싶은 방향 입력
		cout << "진행하고자하는 방향을 선택 (종료는 -1)" << endl;
		cout << "2. 아래 4. 왼쪽 6. 오른쪽 8. 위" << endl;
		cin >> iInput;

		//이동하려는 좌표 계산
		switch (iInput)
		{
			//상
		case 8:
			dd = directions[0];
			//이동하려는 좌표
			nx=iLocationArray[0] + dx[dd];
			ny=iLocationArray[1] + dy[dd];
			//이동하려는 좌표가 유효한 위치면 이동
			if (Is_Move_Location_Valid(&nx,&ny))
			{
				swap(iMap[ny][nx],iMap[iLocationArray[1]][iLocationArray[0]]);
				iLocationArray[0] = nx;
				iLocationArray[1] = ny;
				Print_Current_Map(iMap);
			}
			else
			{
				cout << "맵 범위 벗어남" << endl;
			}
			break;
			//하
		case 2:
			dd = directions[1];
			//이동하려는 좌표
			nx = iLocationArray[0] + dx[dd];
			ny = iLocationArray[1] + dy[dd];
			//이동하려는 좌표가 유효한 위치면 이동
			if (Is_Move_Location_Valid(&nx, &ny))
			{
				swap(iMap[ny][nx], iMap[iLocationArray[1]][iLocationArray[0]]);
				iLocationArray[0] = nx;
				iLocationArray[1] = ny;
				Print_Current_Map(iMap);
			}
			else
			{
				cout << "맵 범위 벗어남" << endl;
			}
			break;
			//좌
		case 4:
			dd = directions[2];
			//이동하려는 좌표
			nx = iLocationArray[0] + dx[dd];
			ny = iLocationArray[1] + dy[dd];
			//이동하려는 좌표가 유효한 위치면 이동
			if (Is_Move_Location_Valid(&nx, &ny))
			{
				swap(iMap[ny][nx], iMap[iLocationArray[1]][iLocationArray[0]]);
				iLocationArray[0] = nx;
				iLocationArray[1] = ny;
				Print_Current_Map(iMap);
			}
			else
			{
				cout << "맵 범위 벗어남" << endl;
			}
			break;
			//우
		case 6:
			dd = directions[3];
			//이동하려는 좌표
			nx = iLocationArray[0] + dx[dd];
			ny = iLocationArray[1] + dy[dd];
			//이동하려는 좌표가 유효한 위치면 이동
			if (Is_Move_Location_Valid(&nx, &ny))
			{
				swap(iMap[ny][nx], iMap[iLocationArray[1]][iLocationArray[0]]);
				iLocationArray[0] += dx[dd];
				iLocationArray[1] += dy[dd];
				Print_Current_Map(iMap);
			}
			else
			{
				cout << "맵 범위 벗어남" << endl;
			}
			break;
			//종료
		case -1:
			bEnd = false;
			break;
			//기타입력
		default:
			cout << "잘못된 입력입니다";
			break;
		}
	}
	return 0;
}

//인자로 들어온 5*5배열의 내용 예쁘게 출력해주는 함수
void Print_Current_Map(int(*Array)[5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout <<setw(3)<< Array[i][j];
		}
		cout << endl;
	}
	cout << "-------------------" << endl;
}

bool Is_Move_Location_Valid(int* x, int* y)
{
	//x좌표가 맵 범위를 벗어나는 경우
	if (*x < 0 || *x >= 5)
	{
		return false;
	}
	//y좌표가 맵 범위를 벗어나는 경우
	if (*y < 0 || *y >= 5)
	{
		return false;
	}
	return true;
}
