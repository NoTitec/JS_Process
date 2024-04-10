#include "stdafx.h"

class CObj
{
	//접근지시자 private여서 외부에서 함부로 접근 못함
private:
	explicit CObj() : m_iA(0){	}
	~CObj() {}

public:
	void	Set_A(int _iA) { this->m_iA = _iA; }
	void	Render() { cout << this->m_iA << endl; }

	CObj*	Get_This()
	{
		return this;
	}

	//자기자신 소멸함수
	void	Destroy()
	{
		delete this;
	}
	//클래스 생성자를 전역함수로 제공
	static CObj*		Create()
	{
		CObj*		pObj = new CObj;

		return pObj;
	}

	CObj*	Clone()
	{
		return new CObj(*this);
	}

private:
	int		m_iA;
};

int main()
{
	// CObj	Temp;
	// 
	// cout << (&Temp) << endl;
	// cout << Temp.Get_This() << endl;
	// 
	// Temp.Get_This()->Set_A(100);
	// Temp.Get_This()->Render();
	// 
	// //Temp.Set_A(100);
	// //Temp.Render();
	// 
	// CObj	Src;
	// 
	// cout << (&Src) << endl;
	// cout << Src.Get_This() << endl;

	//Src.Set_A(200);
	//Src.Render();


	CObj*		pObj = CObj::Create();

	cout << pObj << endl;
	cout << pObj->Get_This() << endl;

	pObj->Destroy();

	return 0;
}