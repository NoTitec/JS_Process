#include <iostream>

using namespace std;


	//void		Func		()		// �Լ� �����
   // ��ȯŸ��		�Լ� �̸�		�Ű� ����, �Ķ����, ���ڰ�
	//{
		// �Լ� ��ü, ���Ǻ�, �ڵ� ��	
	//}

void	Render();		// �Լ� �����
void	Draw(int _iDst);
int		Get_Number();
int		Add(int _iTmp, int _iSrc);

int main()
{
	//Render();		// �Լ� ȣ�� ������
	
	//Draw(100);
	//int	iSrc(200);
	//Draw(iSrc);

	//cout << Get_Number() << endl;
	// Draw(Get_Number());
	// cout << Add(10, Get_Number()) << endl;

	/////////////////////////////////////////////////

	// int	iNumber(300);
	// Draw(iNumber);		// call by value
	// cout << iNumber << endl;

	cout << Get_Number() << endl;

	return 0;
}

void	Render()		// �Լ� ���Ǻ�
{
	cout << "hello world" << endl;
}

void	Draw(int _iDst)		// �Ű� ����(stack)
{
	//cout << _iDst << endl;

	_iDst += 50;
}
int		Get_Number()
{
	int		iTmp(500);		// ���� ����(stack)

	return iTmp;
	//return	500;
}
int		Add(int _iTmp, int _iSrc)
{
	return _iTmp + _iSrc;
}