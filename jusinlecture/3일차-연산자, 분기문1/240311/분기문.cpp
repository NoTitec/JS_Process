#include <iostream>

using namespace std;

int main()
{
	// if, switch, goto

#pragma region goto��

	/*goto	Jump;

	cout << 1 << endl;

Jump :

	cout << 2 << endl;*/

#pragma endregion goto��


#pragma region if��

	/*if (���ǽ�)
	{
		�ڵ� ��(�ڵ� ������)
	}*/
	
	if (0)
	{
		int		iTest(100);

		cout << "hello world" << endl;
		//cout << iTest << endl;
	}

	else if (1)			// if�� ���� ������ ���� ������ �б⸦ �ϰ����� �� ���, else if�� ��쿡 ���� ���� ���� ���� �� �ִ�.
	{
		int		iTest2(100);
		cout << "hello jusin" << endl;
	}

	else			// if�� �� �ݴ�� �����ϴ� ����(�ݵ�� if�� ���� �־�� ��� ����)
	{
		//iTest = 200;
		cout << "world hello" << endl;
		//cout << iTest << endl;
	}
	
#pragma endregion if��

	return 0;
}

/*
��� ���� ���� ������ �ο��ϴ� ���α׷�

90���̻� 100�� ������ ��� 'a����'
80���̻� 90�� �̸��� ��� 'b����'
70���̻� 80�� �̸��� ��� 'c����'
60���̻� 70�� �̸��� ��� 'd����'
�������� 'f����'

*/