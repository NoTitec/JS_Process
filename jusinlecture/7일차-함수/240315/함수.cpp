#include <iostream>

using namespace std;


	//void		Func		()		// 함수 선언부
   // 반환타입		함수 이름		매개 변수, 파라미터, 인자값
	//{
		// 함수 몸체, 정의부, 코드 블럭	
	//}

void	Render();		// 함수 선언부
void	Draw(int _iDst);
int		Get_Number();
int		Add(int _iTmp, int _iSrc);

int main()
{
	//Render();		// 함수 호출 연산자
	
	//Draw(100);
	//int	iSrc(200);
	//Draw(iSrc);

	//cout << Get_Number() << endl;
	// Draw(Get_Number());
	// cout << Add(10, Get_Number()) << endl;

	/////////////////////////////////////////////////

	// int	iNumber(300);
	// Draw(iNumber);		// call by value
	// cout << iNumber << endl;

	cout << Get_Number() << endl;

	return 0;
}

void	Render()		// 함수 정의부
{
	cout << "hello world" << endl;
}

void	Draw(int _iDst)		// 매개 변수(stack)
{
	//cout << _iDst << endl;

	_iDst += 50;
}
int		Get_Number()
{
	int		iTmp(500);		// 지역 변수(stack)

	return iTmp;
	//return	500;
}
int		Add(int _iTmp, int _iSrc)
{
	return _iTmp + _iSrc;
}