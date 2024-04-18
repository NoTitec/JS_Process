#include "stdafx.h"

#pragma region ������ �����ε�

class CObj
{
public:
	//�⺻������
	CObj() {}
	//���� �ΰ��� ������
	CObj(int _iX, int _iY) : m_iX(_iX), m_iY(_iY) {}

 //�⺻ ���Ի����� ������
	// Cobj A();
	// Cobj B();
	// A=B;
	CObj& operator =(CObj& rObj)
	{
		m_iX = rObj.m_iX;
		m_iY = rObj.m_iY;

		// m_pData = rObj.m_pData; 
		// �ʿ信 ���� ���� ����(?)�� �����ϵ��� �ڵ带 �����ؾ� �� �� �ִ�.

		return *this;
	}
	//�⺻�Ҹ���
	~CObj() {}

public:
	void	Render() { cout << m_iX << "\t" << m_iY << endl; }

	CObj	operator +(CObj& rObj)
	{
		CObj	Result(m_iX + rObj.m_iX, m_iY + rObj.m_iY);

		return Result;
	}

	CObj	operator +(int _iData)
	{
		CObj	Result(m_iX + _iData, m_iY + _iData);

		return Result;
	}

	CObj&	operator++()	// ���� ����
	{
		m_iX += 1;
		m_iY += 1;

		return *this;
	}

	CObj	operator++(int)	// ���� ����, ���������̶� �Ȱ��̻��ܼ� �����ϱ� ����
	{
		CObj	Result(*this);

		m_iX += 1;
		m_iY += 1;

		return Result;
	}


private:
	int		m_iX;
	int		m_iY;
	int*	m_pData;
};

CObj	operator+ (int _iData, CObj& rObj)
{
	CObj	Result(rObj + _iData);

	return Result;
}
//
//int main()
//{
//	// ������ �����ε� : �Լ� �����ε��� ��Ģ�� �����ڿ� �����ϴ� ��������, �������� �̸��� �� �Լ��� ����� �����ϴ� ����
//	// ������ �����ε��� ������ ����, ���� ��ü�� �������� ������ �����Ѵ�.
//	// ���� �������� ����� �ٸ� ������� �ٲ� �� ����.
//
//	// Ŭ���� ����θ� �����ε��� ������ �����ڵ�
//	// '=', '()', '[]', '->'
//
//
//	// operator <- : ������ �����ε��� ���� ����ϴ� Ű����
//
//	// CObj	Temp(10, 20);
//	// CObj	Src(30, 40);
//
//	// Temp = Temp + Src;
//	//Temp = Temp + 20;
//
//	//Temp = 20 + Temp;
//
//	//++(++Temp);
//	// (Temp++)++;
//
//	// Temp.Render();
//
//
//	return 0;
//}
#pragma endregion ������ �����ε�

#pragma region �Լ� ��ü

// �Լ� ��ü : ��ü�� �Լ�ó�� ����ϴ� ����, ()�����ڸ� �����ε��Ͽ� �����ϴ� ���
// STL �˰����� �����ڷ� ����ϱ� ���� �ַ� �ۼ�
// ������ : BOOL Ÿ���� ��ȯ ������ ���� �Լ� �Ǵ� �Լ���ü�ν� ��, ������ ���� �˰����� ���� ���θ� �Ǵ� �����ִ� ����

class CPlus
{
public:
	int	operator()(int _iDst, int _iSrc)
	{
		return _iDst + _iSrc;
	}
};

class CSortRule
{
public:
	virtual bool operator()(int _iDst, int _iSrc) = 0;
};

class CAscendingSort : public CSortRule
{
public:
	virtual bool operator()(int _iDst, int _iSrc)
	{
		if (_iDst > _iSrc)
			return true;
		
		else
			return false;

		//return _iDst > _iSrc;
	}
};

class CDescendingSort : public CSortRule
{
public:
	CDescendingSort(int _iData)  : m_iData(_iData){}

public:
	virtual bool operator()(int _iDst, int _iSrc)
	{
		if (_iDst < _iSrc)
			return true;

		else
			return false;

		//return _iDst < _iSrc;
	}

private:
	int		m_iData;
};

bool	Less(int _iDst, int _iSrc)
{
	return _iDst > _iSrc;
}

bool	Greater(int _iDst, int _iSrc)
{
	return _iDst < _iSrc;
}

void	Bubble_Sort(int _iArray[], int _iSize, CSortRule& Functor)
{
	for (int i = 0; i < _iSize; ++i)
	{
		for(int j = 0; j <_iSize - 1; ++j)
		{
			if (Functor(_iArray[j], _iArray[j + 1]))
				swap(_iArray[j], _iArray[j + 1]);
		}
	}
}


int main()
{

	/*CPlus		Functor;
	cout << Functor(10, 20) << endl;*/


	int		iArray[5] = { 5, 1, 2, 4, 3 };

	for (int i = 0; i < 5; ++i)
		cout << iArray[i] << "\t";

	cout << endl;
		
	CDescendingSort	DESCE(10);

	Bubble_Sort(iArray, 5, CDescendingSort(10));
	cout << "------------------------------------------------" << endl;

	for (int i = 0; i < 5; ++i)
		cout << iArray[i] << "\t";

	return 0;
}

#pragma region �ӽ� ��ü

////////////////////////////////�ӽ� ��ü////////////////////////
//// �ӽ� ��ü : �̸� ���� �ӽ� �޸� ������ �����Ǵ� ��ü
//class CTest
//{
//public:
//	CTest(char* pName)
//	{
//		strcpy_s(m_szName, sizeof(m_szName), pName);
//		cout << m_szName << " ������" << endl;
//	}
//	~CTest()
//	{
//		cout << m_szName << " �Ҹ���" << endl;
//	}
//
//private:
//	char		m_szName[32];
//};
//
//int main()
//{
//	CTest		Test("�Ϲ� ��ü");
//
//	cout << "-------------�ӽ� ��ü ���� ��------------------" << endl;
//
//	CTest("�ӽ� ��ü");
//
//	cout << "-------------�ӽ� ��ü �Ҹ� �Ϸ�------------------" << endl;
//
//	return 0;
//}

#pragma endregion �ӽ� ��ü

#pragma endregion �Լ� ��ü

// string Ŭ����  =, +, == ���� �����غ���