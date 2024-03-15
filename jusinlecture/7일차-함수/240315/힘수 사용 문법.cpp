#include <iostream>

using namespace std;

#pragma region 함수 오버로딩

//void	Render();
//void	Render(int _iA);
////int		Render(int _iA);
//void	Render(float _fA);
//void	Render(int _iA, int _iB);
//
//int main()
//{
//	// 함수 오버로딩 : 함수의 이름이 같을 때 어떤 함수를 호출할 지 결정하는 문법
//
//	// 1. 함수의 이름이 같을 때, 매개 변수의 개수에 따라 어떤 함수를 호출할 지 결정
//	// 2. 함수의 이름이 같을 때, 매개 변수의 자료형에 따라 어떤 함수를 호출할 지 결정
//	// 3. 함수 오버로딩 문법은 함수 이름과 매개 변수에 따라 호출된다. 반환 타입의 다른 점은 오버로딩에 영향을 주지 못함
//
//	//Render(3.14f);
//
//	//cout << Render(100) << endl;
//
//	return 0;
//}
//
//void	Render()
//{
//	cout << "hello world" << endl;
//}
//void	Render(int _iA)
//{
//	cout << _iA << endl;
//	cout << "hello _iA" << endl;
//}
///*
//int		Render(int _iA)
//{
//	return _iA;
//}*/
//
//void Render(float _fA)
//{
//	cout << _fA << endl;
//	cout << "hello _float" << endl;
//}
//void	Render(int _iA, int _iB)
//{
//	cout << "hello _iA and _iB" << endl;
//}

#pragma endregion 함수 오버로딩

#pragma region default 매개 변수

//void	Draw(int _iA = 100);				// 함수 선언 시점에 default 매개 변수를 세팅
//void	Draw(int _iA, int _iB = 100);		// default 매개 변수는 반드시 맨 오른쪽에 있는 변수부터 초기화 식을 삽입해야 한다.
//											// default 매개 변수를 사용하다 보면 오버로딩에 의해서 잘못된 동작 상태를 구현할 수 있으니 주의해야 한다.
//int main()
//{
//	/*Draw(100);
//	Draw(100);
//	Draw(100);
//	Draw(200);
//	Draw(100);
//	Draw(100);*/
//
//	//Draw(200);
//	Draw(50);
//
//	return 0;
//}
//
//void	Draw(int _iA )
//{
//	cout << _iA << endl;
//}
//
//void	Draw(int _iA, int _iB)
//{
//	cout << _iA << "\t" << _iB << endl;
//}


#pragma endregion default 매개 변수

#pragma region 재귀 함수

void Recursive(int _iNumber);

int main()
{
	// 재귀 함수 : 함수 자신이 스스로를 다시 호출하는 구조
	// 목적 : 

	Recursive(3);

	return 0;
}

void Recursive(int _iNumber)
{
	if (0 == _iNumber)			// 재귀 함수 탈출 조건
		return;

	cout << "재귀 함수 호출" << endl;

	Recursive(_iNumber - 1);
}

#pragma endregion 재귀 함수
