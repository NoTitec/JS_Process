#include <iostream>

using namespace std;

int main()
{
	// if, switch, goto

#pragma region goto문

	/*goto	Jump;

	cout << 1 << endl;

Jump :

	cout << 2 << endl;*/

#pragma endregion goto문


#pragma region if문

	/*if (조건식)
	{
		코드 블럭(코드 구현부)
	}*/
	
	if (0)
	{
		int		iTest(100);

		cout << "hello world" << endl;
		//cout << iTest << endl;
	}

	else if (1)			// if와 같은 조건을 갖고 세세한 분기를 하고자할 때 사용, else if는 경우에 따라 여러 개가 있을 수 있다.
	{
		int		iTest2(100);
		cout << "hello jusin" << endl;
	}

	else			// if와 정 반대로 동작하는 구문(반드시 if가 먼저 있어야 사용 가능)
	{
		//iTest = 200;
		cout << "world hello" << endl;
		//cout << iTest << endl;
	}
	
#pragma endregion if문

	return 0;
}

/*
평균 값을 토대로 학점을 부여하는 프로그램

90점이상 100점 이하인 경우 'a학점'
80점이상 90점 미만인 경우 'b학점'
70점이상 80점 미만인 경우 'c학점'
60점이상 70점 미만인 경우 'd학점'
나머지는 'f학점'

*/