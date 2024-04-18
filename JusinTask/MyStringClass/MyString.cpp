#include "MyString.h"
#include "stdafx.h"

MyString::MyString(const char* pName)
{
	int iLength = strlen(pName) + 1;
	//동적할당
	m_string = new char[iLength];
	strcpy_s(m_string, iLength, pName);
	cout << "문자열 인자 생성자 호출" << endl;
}

MyString::MyString(const MyString& rhs)
{
	//기본 복사생성자는 아래 주석처럼모든 맴버변수를 단순 1:1 대입연산하는식으로 구현되어있음
		//m_pName = rhs.m_pName;

		// 깊은 복사 생성의 예
	int		iLength = strlen(rhs.m_string) + 1;
	m_string = new char[iLength];
	strcpy_s(m_string, iLength, rhs.m_string);

	cout << "복사 생성자 호출" << endl;
}

MyString& MyString::operator=(const MyString& Right)
{
	int len = strlen(Right.m_string) + 1;
	char* temp = new char[len];
	strcpy_s(temp, len, Right.m_string);
	m_string = temp;
	return *this;
	cout << "=연산자 호출" << endl;
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
	cout << "+연산자 호출" << endl;
}


