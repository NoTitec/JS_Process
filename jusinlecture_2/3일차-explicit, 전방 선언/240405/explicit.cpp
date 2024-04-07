#include "stdafx.h"

class CObj
{
public:
	CObj(int _iA)
	{
		m_iA = _iA;		
	}

public:
	void	Render() { cout << m_iA << endl; }

private:
	int		m_iA;	
};

int main()
{
	CObj		Obj = { 100 };

	Obj.Render();

	return 0;
}