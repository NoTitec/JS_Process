#include "stdafx.h"
#include "Student.h"


CStudent::CStudent()
{
	m_pInfo = nullptr;
	m_iSize = 0;
}

CStudent::~CStudent()
{
	Release();
}

void CStudent::Initialize()
{
	
}

void CStudent::Release()
{
	SAFE_DELETE_ARRAY(m_pInfo);
}

void CStudent::Input_Data()
{
	int		iInput = 0;

	cout << "�Է��� �л� ���� �����ϼ��� : ";
	cin >> iInput;

	if(nullptr == m_pInfo)	// ���� �Է�
		m_pInfo = new INFO[iInput];

	else	// �߰� �Է�
	{
		INFO*	pNewInfo = new INFO[iInput + m_iSize];

		memcpy(pNewInfo, m_pInfo, sizeof(INFO) * m_iSize);

		Release();	// ���� �迭 ����

		m_pInfo = pNewInfo;
	}

	for (int i = m_iSize; i < iInput + m_iSize; ++i)
	{
		cout << "�̸� �Է� : ";
		cin >> m_pInfo[i].szName;

		cout << "���� �Է� : ";
		cin >> m_pInfo[i].iKor;

		cout << "���� �Է� : ";
		cin >> m_pInfo[i].iEng;

		cout << "���� �Է� : ";
		cin >> m_pInfo[i].iMath;

		m_pInfo[i].iTotal = m_pInfo[i].iKor + m_pInfo[i].iEng + m_pInfo[i].iMath;
		m_pInfo[i].fAver = (float)m_pInfo[i].iTotal / 3.f;
	}

	m_iSize += iInput;
}

void CStudent::Output_Data()
{
	for (int i = 0; i < m_iSize; ++i)
	{
		cout << "--------------------------------" << endl;
		cout << "�̸� : " << m_pInfo[i].szName << endl;
		cout << "���� : " << m_pInfo[i].iKor << endl;
		cout << "���� : " << m_pInfo[i].iEng << endl;
		cout << "���� : " << m_pInfo[i].iMath << endl;
		cout << "���� : " << m_pInfo[i].iTotal << endl;
		cout << "��� : " << m_pInfo[i].fAver << endl;
	}

}
