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

		cout << "1. �Է� 2. ��� 3. �˻� 4. ���� 5. ���� : ";
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
	
	//for-each���� 3��° ���� �Ű������� �ڵ����� �ֳ�?
	for_each(m_vecStu.begin(), m_vecStu.end(), tagDelete());

	m_vecStu.clear();
	vector<CStudent*>().swap(m_vecStu);
}

void CMainApp::Add_Data()
{
	cout << "�߰��� �л� ���� �Է��ϼ��� : ";
	int iInput(0);
	cin >> iInput;

	for (int i = 0; i < iInput; ++i)
	{
		CStudent*	pStudent = new CStudent;
		m_vecStu.push_back(pStudent);
		m_vecStu.back()->Input_Data();
		//�̷��� ¥�� ��찡 ������ ������������
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

	cout << "ã�� �л��� �̸��� �Է��ϼ��� : ";
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

	cout << "ã�� �л��� �̸��� �Է��ϼ��� : ";
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
