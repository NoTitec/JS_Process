// 240409.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

//�Ϲ���������
int		g_iNumber = 100;

class CObj
{
public:
	//static Ŭ���� �ɹ������� ������� Ŭ���� �ɹ��������ƴ϶� ���μ� �����̳� �ʱ�ȭ �ȵ�
	CObj()// : m_iA(100)
	{
		//m_iA = 100;
	}

public:
	void	Render()
	{
		cout << m_iA << endl;
	}

	void		Add()	{		m_iA++;	}

	static		void	Print()
	{
		int		iData = 10;
		iData = 20;
		cout << iData << endl;

		g_iNumber = 300;
		cout << g_iNumber << endl;
		
		//m_iB = 4000;				// Ŭ������ ��� ���� �б�� ���⸦ ��� ������� ����(static �Լ��� class���κ��� ��� �Ұ�)
		// cout << m_iB << endl;

		//static ������ ��밡��
		m_iA = 200;
		cout << m_iA << endl;
	}

private:
	//class �ɹ����� �Ǵ� class ������� ȣĪ
	static int		m_iA;	// ���� Ÿ���� ��ü�� ��� �޸� ������ �����Ͽ� ��� class 2���� �������� �ٰ��� ����
	int				m_iB;
};

//�ܺμ� �ʱ�ȭ�Ҷ� namespace �ʼ�
int		CObj::m_iA = 100;

int main()
{
	//static �Լ��� ���������� �ܺμ� ���� namespace �ʿ�
	CObj::Print();


	/*CObj		Obj;

	Obj.Add();
	Obj.Add();
	Obj.Add();

	Obj.Render();

	cout << "---------------------------" << endl;

	CObj		Temp;

	Temp.Add();
	Temp.Add();
	Temp.Add();
	
	Temp.Render();*/

	//cout << CObj::m_iA << endl;

	//Obj.Render();

    return 0;
}

