#include <iostream>
#include <ctime>

//well512 ���� �������� Ŭ����
class Well512Random
{
	enum
	{
		DIFFER_VALUE = 100,
	};

private:
	unsigned long state[16];
	unsigned int index;
public:
	explicit Well512Random()
	{
		//�õ尪 �ڵ� ����
		index = 0;
		unsigned int s = static_cast<unsigned int>(time(NULL));
		for (int i = 0; i < 16; i++)
		{
			state[i] = s;
			s += s + DIFFER_VALUE;
		}
	}

	~Well512Random() {}

	unsigned int GetValue()
	{
		unsigned int a, b, c, d;

		a = state[index];
		c = state[(index + 13) & 15];
		b = a ^ c ^ (a << 16) ^ (c << 15);
		c = state[(index + 9) & 15];
		c ^= (c >> 11);
		a = state[index] = b ^ c;
		d = a ^ ((a << 5) & 0xda442d24U);
		index = (index + 15) & 15;
		a = state[index];
		state[index] = a ^ b ^ d ^ (a << 2) ^ (b << 18) ^ (c << 28);

		return state[index];
	}
	unsigned int GetValue(unsigned int nMinValue, unsigned int nMaxValue)
	{
		return nMinValue + (GetValue() % (nMaxValue - nMinValue));
	}
};

using namespace std;
// 3. Ȧ¦ ����

//- �� ���帶�� ������ �̿��Ͽ� ������ ���� ����, ȭ�鿡 ����϶�
//- ������ ������ 1~10 ���� �� �ϳ��� �ݺ��� ������ �߻�
// Ȧ������ ¦������ �������� ����
//- 1. Ȧ�� 2. ¦�� 3. ����
//- �� 5���带 �ǽ��ϰ� ������ ����� ������ '�� �� �� ��' ���

//���� Ƚ�� ���� ����
int iVictoryCount(0);
int iDefeatCount(0);


int main()
{
	Well512Random random;

	int iRound(1);
	int iMenu(0);
	//5���� �ݺ�
	while (iRound <= 5)
	{
		//���� ��������� ���
		cout << iRound << "����" << endl;
		// Ȧ������ ¦������ �������� �Է¹޾� ����
		cout << "1. Ȧ�� 2. ¦�� 3. ����" << endl;
		cin >> iMenu;
		//1~10������ ���� ����
		unsigned int iRandomnumber = random.GetValue(1, 10);

		switch (iMenu)
		{
			//Ȧ����� ����
		case 1:
			cout << "�������� " << iRandomnumber << "�Դϴ�" << endl;
			if ((iRandomnumber % 2) == 1)
			{
				++iVictoryCount;
				cout << "�������ϴ�!\n" << endl;
			}
			else
			{
				++iDefeatCount;
				cout << "Ʋ�Ƚ��ϴ�.. �������� ���� �� ���� �̴ϴ�!!\n" << endl;
			}
			break;
			//¦����� ����
		case 2:
			cout << "�������� " << iRandomnumber << "�Դϴ�" << endl;
			if ((iRandomnumber % 2) == 0)
			{
				++iVictoryCount;
				cout << "�������ϴ�!\n" << endl;
			}
			else
			{
				++iDefeatCount;
				cout << "Ʋ�Ƚ��ϴ�.. �������� ���� �� ���� �̴ϴ�!!\n" << endl;
			}
			
			break;
			//���α׷� ����
		case 3:
			//�ݺ��� Ż������ �����
			iRound = 5;
			break;
		default :
			cout << "�߸��� �Է��Դϴ�\n" << endl;
			break;
		}
		//���� ����
		iRound++;
	}

	//���� ���� �� ��� �������� ���
	cout << iVictoryCount << "�� " << iDefeatCount << "��" << endl;
	return 0;
}