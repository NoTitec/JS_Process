#include "stdafx.h"
#include "Student.h"

CStudent::CStudent()
{
	memset(&m_tInfo, 0, sizeof(INFO));
	//****2022 는 string 초기화시 하나이상의 문자가있어야 추후 사용에도 문제가 없음
	m_tInfo.strName = "개쓰레기 string";
}

CStudent::~CStudent()
{
}

void CStudent::Input_Data()
{
	cout << "이름 입력 : ";
	cin >> m_tInfo.strName;
	cout << "국어 입력 : ";
	cin >> m_tInfo.iKor;

	cout << "영어 입력 : ";
	cin >> m_tInfo.iEng;

	cout << "수학 입력 : ";
	cin >> m_tInfo.iMath;

	m_tInfo.iTotal = m_tInfo.iKor + m_tInfo.iEng + m_tInfo.iMath;
	m_tInfo.fAver = static_cast<float>(m_tInfo.iTotal) / 3.f;
}

void CStudent::Output_Data()
{
	cout << "-----------------------------" << endl;
	cout << "이름 : " << m_tInfo.strName << endl;
	cout << "국어 : " << m_tInfo.iKor << endl;
	cout << "영어 : " << m_tInfo.iEng << endl;
	cout << "수학 : " << m_tInfo.iMath << endl;
	cout << "총점 : " << m_tInfo.iTotal << endl;
	cout << "평균 : " << m_tInfo.fAver << endl;
}
