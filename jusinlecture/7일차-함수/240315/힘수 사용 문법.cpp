#include <iostream>

using namespace std;

#pragma region �Լ� �����ε�

//void	Render();
//void	Render(int _iA);
////int		Render(int _iA);
//void	Render(float _fA);
//void	Render(int _iA, int _iB);
//
//int main()
//{
//	// �Լ� �����ε� : �Լ��� �̸��� ���� �� � �Լ��� ȣ���� �� �����ϴ� ����
//
//	// 1. �Լ��� �̸��� ���� ��, �Ű� ������ ������ ���� � �Լ��� ȣ���� �� ����
//	// 2. �Լ��� �̸��� ���� ��, �Ű� ������ �ڷ����� ���� � �Լ��� ȣ���� �� ����
//	// 3. �Լ� �����ε� ������ �Լ� �̸��� �Ű� ������ ���� ȣ��ȴ�. ��ȯ Ÿ���� �ٸ� ���� �����ε��� ������ ���� ����
//
//	//Render(3.14f);
//
//	//cout << Render(100) << endl;
//
//	return 0;
//}
//
//void	Render()
//{
//	cout << "hello world" << endl;
//}
//void	Render(int _iA)
//{
//	cout << _iA << endl;
//	cout << "hello _iA" << endl;
//}
///*
//int		Render(int _iA)
//{
//	return _iA;
//}*/
//
//void Render(float _fA)
//{
//	cout << _fA << endl;
//	cout << "hello _float" << endl;
//}
//void	Render(int _iA, int _iB)
//{
//	cout << "hello _iA and _iB" << endl;
//}

#pragma endregion �Լ� �����ε�

#pragma region default �Ű� ����

//void	Draw(int _iA = 100);				// �Լ� ���� ������ default �Ű� ������ ����
//void	Draw(int _iA, int _iB = 100);		// default �Ű� ������ �ݵ�� �� �����ʿ� �ִ� �������� �ʱ�ȭ ���� �����ؾ� �Ѵ�.
//											// default �Ű� ������ ����ϴ� ���� �����ε��� ���ؼ� �߸��� ���� ���¸� ������ �� ������ �����ؾ� �Ѵ�.
//int main()
//{
//	/*Draw(100);
//	Draw(100);
//	Draw(100);
//	Draw(200);
//	Draw(100);
//	Draw(100);*/
//
//	//Draw(200);
//	Draw(50);
//
//	return 0;
//}
//
//void	Draw(int _iA )
//{
//	cout << _iA << endl;
//}
//
//void	Draw(int _iA, int _iB)
//{
//	cout << _iA << "\t" << _iB << endl;
//}


#pragma endregion default �Ű� ����

#pragma region ��� �Լ�

void Recursive(int _iNumber);

int main()
{
	// ��� �Լ� : �Լ� �ڽ��� �����θ� �ٽ� ȣ���ϴ� ����
	// ���� : 

	Recursive(3);

	return 0;
}

void Recursive(int _iNumber)
{
	if (0 == _iNumber)			// ��� �Լ� Ż�� ����
		return;

	cout << "��� �Լ� ȣ��" << endl;

	Recursive(_iNumber - 1);
}

#pragma endregion ��� �Լ�
