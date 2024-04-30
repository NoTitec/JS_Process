#include "stdafx.h"

class CObj
{
public:
	CObj() : m_iX(10), m_iY(20) {}

public:
	void		Render() const
	{
		m_iX = 100;
		m_iY = 200;

		cout << m_iX << endl;
		cout << m_iY << endl;
	}

private:
	mutable int		m_iX;		// 읽기 전용 함수 안에 있는 멤버 변수 쓰기를 허용하는 키워드
	mutable int		m_iY;		
};





int main()
{
	// CObj		Obj;
	// Obj.Render();

	int		iNumber1(0), iNumber2(0);

	cout << "숫자 입력 : ";
	cin >> iNumber1 >> iNumber2;

	try
	{
		if (0 == iNumber2)
			throw iNumber2;

		cout << "나눗셈 : " << (iNumber1 / iNumber2) << endl;
		cout << "나머지 : " << (iNumber1 % iNumber2) << endl;

	}

	catch (int)
	{
		cout << "0 나누기 안됨" << endl;
	}
	



	/*if (0 == iNumber2)
		cout << "0 나누기 안됨" << endl;

	else
	{
		cout << "나눗셈 : " << (iNumber1 / iNumber2) << endl;
		cout << "나머지 : " << (iNumber1 % iNumber2) << endl;
	}*/
	


	return 0;
}