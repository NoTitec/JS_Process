#include "MyString.h"
#include "stdafx.h"

MyString::MyString(const char* pName)
{
	int iLength = strlen(pName) + 1;
	//�����Ҵ�
	m_string = new char[iLength];
	strcpy_s(m_string, iLength, pName);
	cout << "���ڿ� ���� ������ ȣ��" << endl;
}

MyString::MyString(const MyString& rhs)
{
	//�⺻ ��������ڴ� �Ʒ� �ּ�ó����� �ɹ������� �ܼ� 1:1 ���Կ����ϴ½����� �����Ǿ�����
		//m_pName = rhs.m_pName;

		// ���� ���� ������ ��
	int		iLength = strlen(rhs.m_string) + 1;
	m_string = new char[iLength];
	strcpy_s(m_string, iLength, rhs.m_string);

	cout << "���� ������ ȣ��" << endl;
}

MyString& MyString::operator=(const MyString& Right)
{
	int len = strlen(Right.m_string) + 1;
	char* temp = new char[len];
	strcpy_s(temp, len, Right.m_string);
	m_string = temp;
	return *this;
	cout << "=������ ȣ��" << endl;
}

MyString MyString::operator+(const MyString& Right)
{
	int leftlen = strlen(this->m_string) + 1;
	int rightlen = strlen(Right.m_string) + 1;
	int newlen = leftlen + rightlen - 1;

	char* temp = new char[newlen];
	strcpy_s(temp, leftlen, this->m_string);
	strcat_s(temp, newlen, Right.m_string);
	MyString newString(temp);
	delete[] temp;
	temp = nullptr;
	return newString;
	cout << "+������ ȣ��" << endl;
}


