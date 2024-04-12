#include "stdafx.h"
#include "Character.h"
#include "CPlayer.h"
#include "MainGame.h"

int main()
{
	MainGame mainGame;

	mainGame.Initialize();
	mainGame.Update();
	return 0;
}