#include "stdafx.h"
#include "CMainGame.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CMainGame MainGame;

	// 멤버 변수의 값을 설정하는 함수(초기화)
	if (MainGame.Initialize())
	{
		// 매 프레임마다 데이터를 갱신하는 함수
		MainGame.Update();
	}

	cout << "게임종료" << endl;
	return 0;
}