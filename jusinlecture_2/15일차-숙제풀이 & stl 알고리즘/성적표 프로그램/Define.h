#pragma once

typedef struct tagInfo
{
	string strName;
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAver;
	
}INFO;

template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

//호출을할때 조건자로 매개변수를 넣는 장점이 함수포인터에비해 좋음
struct tagDelete
{
	template<typename T>
	void	operator()(T& Temp)
	{
		if (Temp)
		{
			delete Temp;
			Temp = nullptr;
		}
	}
};