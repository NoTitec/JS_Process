#include "stdafx.h"
#include <windows.h>

class CObj
{
public:
	CObj() : m_iX(0), m_iY(0) {}
	CObj(int& _iX, int& _iY) : m_iX(_iX), m_iY(_iY) {}

public:
	void		Render() { cout << m_iX << "\t" << m_iY << endl; }

private:
	int		m_iX;
	int		m_iY;
};

CObj*	Create(int&& iX,  int&& iY)
{
	return new CObj(iX, iY);
}


class CMyArray
{
public:
	CMyArray() : m_pArray(nullptr), m_iSize(0){}
	CMyArray(int iSize) : m_pArray(new int[iSize]), m_iSize(iSize) {}
	//���� ������
	CMyArray(const CMyArray& rhs)
		: m_pArray(new int[rhs.m_iSize]), m_iSize(rhs.m_iSize)
	{
		memcpy(m_pArray, rhs.m_pArray, sizeof(int) * rhs.m_iSize);
	}
	//�̵� ������
	CMyArray (CMyArray&& rMove) noexcept
	{
		m_pArray = rMove.m_pArray;
		m_iSize  = rMove.m_iSize;

		// �̵� �� null�ʱ�ȭ : ������ ����
		rMove.m_pArray = nullptr;
	}



	~CMyArray()
	{
		if (m_pArray)
		{
			delete[] m_pArray;
			m_pArray = nullptr;
		}
	}

private:
	int*		m_pArray;
	int			m_iSize;
};


int main()
{
	// ���� ǥ����(���ٽ�) : ������ �ζ��� �Լ�

	// �����ڷ� ����ϴ� �Լ���ü�� ������(����)�� �����ϱ� ���� ������ ����
	
	// �Լ� ��ü�� ���� : �ۼ��� �������� ����, ��� ������ �Ϲ� �Լ����� ������ �����
	// ���ٽ��� ���� : �ۼ��� �����ϰ�, �������� �����.

	/////////////////////////////////////////////////////////////////////////

	// �⺻���� ���ٽ� ����

	// [] : ���� �Ұ���, ĸó�� �̶�� �θ�, �����Ϸ��� ���ٽ��̶�� ���� ����
	// () : �Ķ���� ������, �Ű� ������ ���� �޴� �Ϲ� �Լ��� ��ɰ� ����
	// {} : ���� ��ü, �Ϲ� �Լ��� ��ü�� ���� �ǹ�

	// []() { cout << "hello world" << endl; }();
	// [](int iData = 50) { cout << iData << endl; }();

	// ������ ��ȯ(��ȯ Ÿ�� ǥ�Ⱑ �����Ǿ� �ִٸ� �����Ϸ��� ���� �Լ� ��ü ���ο��� ���������� ��ȯ ���� �߷�)
	// int	iResult = [](int iDst, int iSrc) { return iDst + iSrc;  }(10, 20);

	// ����� ��ȯ�� ��
	// int	iResult = [](int iDst, int iSrc)-> int { return iDst + iSrc;  }(10, 20);
	// cout << iResult << endl;

	//  (ex1)
	//  vector<int>		vecInt{ 10, 20, 30 , 40, 50 };
	//  for_each(vecInt.begin(), vecInt.end(), [](int n) { cout << n << endl; });

	//  (ex2)
	//  vector<int>		vecInt{ 10, 20, 33, 40, 50 };
	//  
	//  auto iter = find_if(vecInt.begin(), vecInt.end(), 
	//  [](int n)->bool
	//  {
	//  	return 0 != n % 2;
	//  });
	//  
	//  cout << *iter << endl;

	//
	// (ex3)
	//vector<int>		vecInt{ 1, 2, 3, 4, 5 };
	// 
	// int iEvenSum(0), iOddSum(0);
	// 
	// for_each(vecInt.begin(), vecInt.end(), 
	//// [iEvenSum, iOddSum](int n)			// �� ���翡 ���� ĸó(const ������ �ο�) : �б� ���� �뵵�� ĸó
	//// [iEvenSum, iOddSum](int n) mutable	// �� ���翡 ���� ĸó(const ������ �ο� �Ǿ����� mutable�� ���� ����) : ���� �� ������ ������ �Ұ���
	//   [&iEvenSum, &iOddSum](int n)			// ���� ������ ���� ĸó : ���� �� ������ ����
	// {
	// 	if (0 == n % 2)
	// 		iEvenSum += n;
	// 
	// 	else
	// 		iOddSum += n;
	// });
	// 
	// cout << "¦�� �� : " << iEvenSum << endl;
	// cout << "Ȧ�� �� : " << iOddSum << endl;


	// R-Value ���۷��� 

	 int		iData(10);
	 int&	r = iData;
	 r = 20;
	 //int& rt = 2;
	 const int&	r2 = 10;
	// 
	// 
	 int&&	rr = 999;
	// 
	// cout << rr << endl;
	// 
	 rr = 200;
	// 
	// cout << rr << endl;

	 CObj* pPlayer = Create(100, 200);
	// pPlayer->Render();
	// delete pPlayer;

	// �̵� ������  

	CMyArray			Array1(100000000);
	// DWORD			dwTime = GetTickCount();

	CMyArray			Copy(Array1);
	CMyArray			Moving(std::move(Array1));

	// std::move : �Ű� ������ ���� ���� ����� r-value ���۷����� ĳ�������ִ� �Լ�
	// cout << GetTickCount() - dwTime << endl;


	// decltype Ű���� : �־��� ǥ������ Ÿ���� �����Ϸ��� ���� �߷��Ͽ� �����ϰԲ� �����ϴ� Ű����
	//�Ⱦ� �׳� auto��
	// int	iSrc(10);
	// decltype(iSrc)	iDst = 500;
	
	return 0;
}