#include "stdafx.h"

int	g_iNumber = 50;

class CObj
{
public:
	CObj() : m_iA(100), m_iB(200)			// ������ �̴ϼȶ����� : ����� ��� �ʱ�ȭ�� ����
	{ 
		//m_iA = 100; 
	}
	CObj(int _iA, int _iB) : m_iA(_iA), m_iB(_iB) {}

public:
	void	Render() { cout << m_iA << endl; }
	
	void	Print()const;
	void	Print();
	
	void	Draw() const;

private:
	const int		m_iA;
	int				m_iB;
};
void CObj::Print() const
{
	cout << "jusin academy" << endl;
}

void CObj::Print()
{
	cout << "school" << endl;
}


void	CObj::Draw() const			// ��� ������ ���� �б� ������ �Լ��� �ǹ�
{
	// int		iData(0);
	// iData = 100;
	// cout << iData << endl;
	// 
	// g_iNumber = 500;
	// cout << g_iNumber << endl;
	// 
	// m_iB = 2000;
	// cout << m_iB << endl;

	cout << "hello world" << endl;

	Print();			// const �� ���� ���� ��� �Լ��� ȣ���Ϸ��� ��� ��� ������ ���Ⱑ ���� �� �ֱ� ������ �����Ϸ��� ������ ����Ŵ
}

int main()
{
	// ��ü ���� ��, const�� ���ο� ���� �Լ� �����ε� ���� ��

	//const CObj		Obj;

	//Obj.Render();
	//Obj.Draw();
	//Obj.Print();

	const CObj*		pObj = new CObj;

	pObj->Print();

	delete pObj;
	pObj = nullptr;

	return 0;
}