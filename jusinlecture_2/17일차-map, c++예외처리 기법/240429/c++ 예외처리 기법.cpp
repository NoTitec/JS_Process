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
	mutable int		m_iX;		// �б� ���� �Լ� �ȿ� �ִ� ��� ���� ���⸦ ����ϴ� Ű����
	mutable int		m_iY;		
};





int main()
{
	// CObj		Obj;
	// Obj.Render();

	int		iNumber1(0), iNumber2(0);

	cout << "���� �Է� : ";
	cin >> iNumber1 >> iNumber2;

	try
	{
		if (0 == iNumber2)
			throw iNumber2;

		cout << "������ : " << (iNumber1 / iNumber2) << endl;
		cout << "������ : " << (iNumber1 % iNumber2) << endl;

	}

	catch (int)
	{
		cout << "0 ������ �ȵ�" << endl;
	}
	



	/*if (0 == iNumber2)
		cout << "0 ������ �ȵ�" << endl;

	else
	{
		cout << "������ : " << (iNumber1 / iNumber2) << endl;
		cout << "������ : " << (iNumber1 % iNumber2) << endl;
	}*/
	


	return 0;
}