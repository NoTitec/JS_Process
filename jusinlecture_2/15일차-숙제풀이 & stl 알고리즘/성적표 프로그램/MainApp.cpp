#include "stdafx.h"
#include "MainApp.h"

CMainApp::CMainApp()
{
}

CMainApp::~CMainApp()
{
	Release();
}

void CMainApp::Initialize()
{
	for (int i = 0; i < 3; ++i)
	{
		CStudent*		pStudent = new CStudent;
		pStudent->Input_Data();

		m_vecStu.push_back(pStudent);
	}
}

void CMainApp::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		cout << "1. 입력 2. 출력 3. 검색 4. 삭제 5. 종료 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Add_Data();
			break;
		case 2:
			Print_Data();
			break;

		case 3:
			Search_Data();
			break;
		case 4:
			Delete_Data();
			break;

		case 5:
			return;

		}

		system("pause");
	}
}

void CMainApp::Release()
{
	//for (size_t i = 0; i < m_vecStu.size(); ++i)
	//{
	//	Safe_Delete<CStudent*>(m_vecStu[i]);
	//}

	//for_each(m_vecStu.begin(), m_vecStu.end(), Safe_Delete<CStudent*>);
	
	//for-each문은 3번째 인자 매개변수를 자동으로 넣나?
	for_each(m_vecStu.begin(), m_vecStu.end(), tagDelete());

	m_vecStu.clear();
	vector<CStudent*>().swap(m_vecStu);
}

void CMainApp::Add_Data()
{
	cout << "추가할 학생 수를 입력하세요 : ";
	int iInput(0);
	cin >> iInput;

	for (int i = 0; i < iInput; ++i)
	{
		CStudent*	pStudent = new CStudent;
		m_vecStu.push_back(pStudent);
		m_vecStu.back()->Input_Data();
		//이렇게 짜는 경우가 있지만 문제소지있음
		//m_vecStu[i]->Input_Data();
				
		//pStudent->Input_Data();
		//m_vecStu.push_back(pStudent);
	}
}

void CMainApp::Print_Data()
{
	for (vector<CStudent*>::iterator	iter = m_vecStu.begin();
		iter != m_vecStu.end(); ++iter)
	{
		(*iter)->Output_Data();
	}
}

void CMainApp::Search_Data()
{
	string	strFindName = "";

	cout << "찾는 학생의 이름을 입력하세요 : ";
	cin >> strFindName;

	for (vector<CStudent*>::iterator iter = m_vecStu.begin();
		iter != m_vecStu.end(); ++iter)
	{
		if (strFindName == (*iter)->Get_Info().strName)
		{
			(*iter)->Output_Data();
			break;
		}
	}

}

void CMainApp::Delete_Data()
{
	string	strFindName = "";

	cout << "찾는 학생의 이름을 입력하세요 : ";
	cin >> strFindName;

	for (vector<CStudent*>::iterator iter = m_vecStu.begin();
		iter != m_vecStu.end(); )
	{
		if (strFindName == (*iter)->Get_Info().strName)
		{

			//Safe_Delete<CStudent*>(*iter);
			tagDelete()(*iter);
			iter = m_vecStu.erase(iter);
			break;
		}
		else
			++iter;
	}
}
