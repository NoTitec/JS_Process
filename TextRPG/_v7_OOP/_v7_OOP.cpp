#include "stdafx.h"
#include "CMainGame.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CMainGame MainGame;

	// ��� ������ ���� �����ϴ� �Լ�(�ʱ�ȭ)
	if (MainGame.Initialize())
	{
		// �� �����Ӹ��� �����͸� �����ϴ� �Լ�
		MainGame.Update();
	}

	cout << "��������" << endl;
	return 0;
}