#include <iostream>
#include <ctime>

//well512 난수 생성위한 클래스
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
		//시드값 자동 생성
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
// 3. 홀짝 게임

//- 매 라운드마다 난수를 이용하여 무작위 수를 도출, 화면에 출력하라
//- 난수의 범위는 1~10 사이 중 하나를 반복할 때마다 발생
// 홀수일지 짝수일지 종료할지 선택
//- 1. 홀수 2. 짝수 3. 종료
//- 총 5라운드를 실시하고 마지막 라운드로 끝나면 '몇 승 몇 패' 출력

//승패 횟수 저장 변수
int iVictoryCount(0);
int iDefeatCount(0);


int main()
{
	Well512Random random;

	int iRound(1);
	int iMenu(0);
	//5라운드 반복
	while (iRound <= 5)
	{
		//현재 몇라운드인지 출력
		cout << iRound << "라운드" << endl;
		// 홀수일지 짝수일지 종료할지 입력받아 선택
		cout << "1. 홀수 2. 짝수 3. 종료" << endl;
		cin >> iMenu;
		//1~10사이의 난수 생성
		unsigned int iRandomnumber = random.GetValue(1, 10);

		switch (iMenu)
		{
			//홀수라고 예측
		case 1:
			cout << "랜덤수는 " << iRandomnumber << "입니다" << endl;
			if ((iRandomnumber % 2) == 1)
			{
				++iVictoryCount;
				cout << "맞혔습니다!\n" << endl;
			}
			else
			{
				++iDefeatCount;
				cout << "틀렸습니다.. 다음에는 맞힐 수 있을 겁니다!!\n" << endl;
			}
			break;
			//짝수라고 예측
		case 2:
			cout << "랜덤수는 " << iRandomnumber << "입니다" << endl;
			if ((iRandomnumber % 2) == 0)
			{
				++iVictoryCount;
				cout << "맞혔습니다!\n" << endl;
			}
			else
			{
				++iDefeatCount;
				cout << "틀렸습니다.. 다음에는 맞힐 수 있을 겁니다!!\n" << endl;
			}
			
			break;
			//프로그램 종료
		case 3:
			//반복문 탈출조건 만들기
			iRound = 5;
			break;
		default :
			cout << "잘못된 입력입니다\n" << endl;
			break;
		}
		//라운드 증가
		iRound++;
	}

	//게임 종료 후 몇승 몇패인지 출력
	cout << iVictoryCount << "승 " << iDefeatCount << "패" << endl;
	return 0;
}