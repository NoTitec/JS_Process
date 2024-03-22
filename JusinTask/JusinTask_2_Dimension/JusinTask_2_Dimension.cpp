// JusinTask_2_Dimension.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

// 3. 2차원 배열을 이용하여 90도 회전하는 상태 출력하기
/*

1	2	3			7	4	1			9	8	7			3	6	9			1	2	3
4	5	6	-1회전>	8	5	2	-2회전>	6	5	4	-3회전>	2	5	8 -4회전>	4	5	6
7	8	9			9	6	3			3	2	1			1	4	7			7	8	9

*/

//2차원 배열 선언 과 동시 초기화
int Array[3][3] =
{
    {1,2,3},
    {4,5,6},
    {7,8,9}
};

//인자로 들어온 2차원 배열을 90도 시계방향 시키는 함수
void Rotate_Matrix_90_Degree(int(*Array)[3]);
//2차원배열을 출력하는 함수
void Print_Matrix(int(*Array)[3]);


int main()
{
    //4번 회전시키면서 원본배열, 회전한배열 출력

    for (int i = 0; i < 4; i++)
    {
        cout << i+1 << "회차" << endl;
        Print_Matrix(Array);
        cout << "----------" << endl;
        Rotate_Matrix_90_Degree(Array);
        Print_Matrix(Array);
        cout << "----------" << endl;
    }
    return 0;
}

void Rotate_Matrix_90_Degree(int(*Array)[3])
{
    // 모든 i,j 원소 자리바꾸기
    for (int i = 0; i < 3; ++i) {
        for (int j = i; j < 3; ++j) {
            swap(Array[i][j], Array[j][i]);
        }
    }
    // 열 뒤집기
    for (int i = 0; i < 3; ++i) {
        swap(Array[i][0], Array[i][2]);
    }

    //반대로하면 시계반대방향
}

void Print_Matrix(int(*Array)[3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<Array[i][j];
        }
        cout << endl;
    }
}
