#include "stdafx.h"
#include "Student.h"

CStudent::CStudent()
{
	memset(&m_tInfo, 0, sizeof(INFO));
	//****2022 �� string �ʱ�ȭ�� �ϳ��̻��� ���ڰ��־�� ���� ��뿡�� ������ ����
	m_tInfo.strName = "�������� string";
}

CStudent::~CStudent()
{
}

void CStudent::Input_Data()
{
	cout << "�̸� �Է� : ";
	cin >> m_tInfo.strName;
	cout << "���� �Է� : ";
	cin >> m_tInfo.iKor;

	cout << "���� �Է� : ";
	cin >> m_tInfo.iEng;

	cout << "���� �Է� : ";
	cin >> m_tInfo.iMath;

	m_tInfo.iTotal = m_tInfo.iKor + m_tInfo.iEng + m_tInfo.iMath;
	m_tInfo.fAver = static_cast<float>(m_tInfo.iTotal) / 3.f;
}

void CStudent::Output_Data()
{
	cout << "-----------------------------" << endl;
	cout << "�̸� : " << m_tInfo.strName << endl;
	cout << "���� : " << m_tInfo.iKor << endl;
	cout << "���� : " << m_tInfo.iEng << endl;
	cout << "���� : " << m_tInfo.iMath << endl;
	cout << "���� : " << m_tInfo.iTotal << endl;
	cout << "��� : " << m_tInfo.fAver << endl;
}
