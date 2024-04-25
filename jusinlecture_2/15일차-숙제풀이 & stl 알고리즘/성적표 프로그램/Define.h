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

//ȣ�����Ҷ� �����ڷ� �Ű������� �ִ� ������ �Լ������Ϳ����� ����
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