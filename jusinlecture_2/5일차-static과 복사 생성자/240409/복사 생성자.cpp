#include "stdafx.h"

#include <stdio.h>
//�׿��� �Ի繮��

class CName
{
public:
	CName(const char* pName)
	{
		int iLength = strlen(pName) + 1;
		//�����Ҵ�
		m_pName = new char[iLength];
		strcpy_s(m_pName, iLength, pName);
	}

	CName(const CName& rhs)
	{
		//�⺻ ��������ڴ� �Ʒ� �ּ�ó����� �ɹ������� �ܼ� 1:1 ���Կ����ϴ½����� �����Ǿ�����
		//m_pName = rhs.m_pName;
		
		// ���� ���� ������ ��
		int		iLength = strlen(rhs.m_pName) + 1;
		m_pName = new char[iLength];
		strcpy_s(m_pName, iLength, rhs.m_pName);
		
		cout << "���� ������ ȣ��" << endl;
	}

	~CName() { delete[]m_pName; }
public:
	void		PrintN() { printf("%s\n", m_pName); }

private:
	char*		m_pName;
};

void	Draw(CName name) { name.PrintN(); }
//void Draw(CName& name) {name.PrintN();}
int main()
{
	//����� ���� �����ڷ� ��ü ����
	CName		Name("neo-peple");

	//�Ű������� ��üŸ���̹Ƿ� ��������� ȣ��
	//�⺻�������� ��� Draw�Լ� ȣ��� Name��ü�� �ּҰ��� �ܼ� 1:1 ����
	//Draw�Լ��� ��ü�� ������ Name���� �ٸ� ��ü��
	//�׷��� �ɹ��� m_pName�� ���� �ּҸ� ����Ű����
	//�̻�Ȳ���� Draw�Լ��� ������ ����� ��ü �Ҹ��ϸ� �Ҹ���ȣ��
	//�̶� m_pName�� delete�ϸ� ������ �ɹ��� ����Ű�� ������ �����ع���
	//�̴� ����������� ���������� ���� �����̸� �̸� �ذ��ϱ� ���ؼ�
	//1. ��������ڸ� �������Ͽ� ���� ���縦 �����ϴ���
	//2. �ƴϸ� �Լ��� &��ü�� �޾� ������ü�� �޵����ϴ½����� �ؾ���
	//�������縦 ����ؾ� �ϴ°��
	//1. �ɹ������� �������ΰ�� 2. ������,�Ҹ��ڿ��� �����Ҵ�����ϴ°��
	Draw(Name);

	return 0;
}


#pragma region ���� ������

//class CObj
//{
//public:
//	//�⺻ ������ ������
//	CObj(int _iA) : m_iA(_iA) { cout << "������ ȣ��" << endl; }
//	//�⺻ ���� ������ ������
//	CObj(const CObj& rhs) : m_iA(rhs.m_iA)
//	{
//		cout << "���� ������ ȣ��" << endl;
//	}
//
//public:
//	void Render() { cout << m_iA << endl; }
//	
//	void Draw(CObj Temp)		// 2. �Լ��� �Ű� ������ ��ü Ÿ���� ���
//	{
//		Temp.Render();
//	}
//
//	CObj		Get_Obj()		// 3. �Լ��� ��ȯ Ÿ���� ��ü Ÿ���� ���
//	{
//		return *this;
//	}
//private:
//	int		m_iA;
//};
//
//int main()
//{
//	CObj		Origin(500);
//	//Origin.Render();
//
//	CObj		CopyOrigin(Origin);		// 1. ���� ������ ��ü�� �Ű� ������ �����Ͽ� ��ü�� �����ϴ� ���
//	CopyOrigin.Render();
//
//	//CObj		TEST(700);
//
//	//Origin.Draw(TEST);
//
//	//Origin.Get_Obj().Render();
//
//	return 0;
//}

#pragma endregion ���� ������


