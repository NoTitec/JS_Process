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

	cout << "입력할 학생 수를 기입하세요 : ";
	cin >> iInput;

	if(nullptr == m_pInfo)	// 최초 입력
		m_pInfo = new INFO[iInput];

	else	// 추가 입력
	{
		INFO*	pNewInfo = new INFO[iInput + m_iSize];

		memcpy(pNewInfo, m_pInfo, sizeof(INFO) * m_iSize);

		Release();	// 기존 배열 삭제

		m_pInfo = pNewInfo;
	}

	for (int i = m_iSize; i < iInput + m_iSize; ++i)
	{
		cout << "이름 입력 : ";
		cin >> m_pInfo[i].szName;

		cout << "국어 입력 : ";
		cin >> m_pInfo[i].iKor;

		cout << "영어 입력 : ";
		cin >> m_pInfo[i].iEng;

		cout << "수학 입력 : ";
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
		cout << "이름 : " << m_pInfo[i].szName << endl;
		cout << "국어 : " << m_pInfo[i].iKor << endl;
		cout << "영어 : " << m_pInfo[i].iEng << endl;
		cout << "수학 : " << m_pInfo[i].iMath << endl;
		cout << "총점 : " << m_pInfo[i].iTotal << endl;
		cout << "평균 : " << m_pInfo[i].fAver << endl;
	}

}
