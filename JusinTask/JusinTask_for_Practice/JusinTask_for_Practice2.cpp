#include <iostream>

using namespace std;
// 2. ���Ǳ� ����
/*
- �������� �Է¹ް� �׻� �ܾ��� ����Ѵ�
- �޴��� 1. �ݶ�(100��) 2. ���̴�(200��) 3. ȯŸ(300��) 4. ��ȯ
- �ش� ����� �����Ͽ� ���� ��, "xx ���� �Ϸ�"�� ���
- ��, �������� ������ ��� �ܾ��� �����մϴ� ���
- 4���� ������ "�Ž��� ���� <�ܾ�>�Դϴ�" ��� ��, ���α׷� ����
*/
int main()
{
	int iMoney(0);
	int iInput(0);

	cout << "�������� �Է��ϼ���" << endl;
	cin >> iMoney;

	//while �� �������� bool���� ���������� ��
	while (true)
	{
		//���� �ܼ�â ���� �����
		system("cls");

		cout << "�ܾ� : "<<iMoney<<" ";
		cout << "�޴� 1. �ݶ�(100) 2. ���̴�(200��) 3. ȯŸ(300��) 4. ��ȯ" << endl;
		//���Ű������� Ȯ������ ������ �ӽ����庯��
		int iTmpMoney(iMoney);

		cin >> iInput;
		if (iInput == 4)
		{
			cout << "�Ž������� " << iMoney << "�Դϴ�";
			break;
		}
		else if (iInput == 1)
		{
			//������ �������� ����Ѱ��
			if ((iTmpMoney -= 100)>=0)
			{
				cout << "�ݶ� ���� �Ϸ�"<<endl;
				iMoney-=100;
			}
			//�׷��� �������
			else
			{
				cout << "�ܾ��� �����մϴ�";
			}
		}
		else if (iInput == 2)
		{
			if ((iTmpMoney -= 200) >= 0)
			{
				cout << "���̴� ���� �Ϸ�" << endl;
				iMoney -= 200;
			}
			//�׷��� �������
			else
			{
				cout << "�ܾ��� �����մϴ�";
			}
		}
		else if (iInput == 3)
		{
			if ((iTmpMoney -= 300) >= 0)
			{
				cout << "ȯŸ ���� �Ϸ�" << endl;
				iMoney -= 300;
			}
			//�׷��� �������
			else
			{
				cout << "�ܾ��� �����մϴ�";
			}
		}
		else
		{
			cout << "�߸��� �޴��� �����ϼ̽��ϴ�";
		}
		//cout << iInput << endl;
		//Ű�� ��������� ���α׷��� �Ͻ�����
		system("pause");
	}
	return 0;
}