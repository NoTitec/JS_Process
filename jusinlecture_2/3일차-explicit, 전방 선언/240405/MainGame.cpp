#include "stdafx.h"
#include "MainGame.h"


CMainGame::CMainGame()
{
	m_pStudent = new CStudent;
	m_pStudent->Initialize();
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	
}

void CMainGame::Update()
{
	int		iInput(0);

	while (true)
	{
		system("cls");

		cout << "1. 입력 2. 출력 3. 종료 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			if(m_pStudent)
				m_pStudent->Input_Data();

			break;

		case 2:
			if(m_pStudent)
				m_pStudent->Output_Data();

			break;

		case 3:
			return;
		}

		system("pause");
	}
}

void CMainGame::Release()
{
	//m_pStudent->Release();

	SAFE_DELETE(m_pStudent);
}
