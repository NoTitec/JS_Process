// 240416.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MainGame.h"

int main()
{
	CMainGame		MainGame;

	MainGame.Initialize();
	MainGame.Update();

    return 0;
}

