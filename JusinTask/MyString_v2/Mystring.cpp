#include "Mystring.h"

Mystring::Mystring(const char* pName)
{
	int iLength = strlen(pName) + 1;
	m_string = new char[iLength];
	strcpy_s(m_string, iLength, pName);
}

Mystring::Mystring(const Mystring & rhs)
{
	int		iLength = strlen(rhs.m_string) + 1;
	m_string = new char[iLength];
	strcpy_s(m_string, iLength, rhs.m_string);

	cout << "���� ������ ȣ��" << endl;
}


Mystring Mystring::CopyTest(Mystring Right)
{
	cout << "��������� �׽�Ʈ �Լ�" << endl;
	Mystring temp(Right);
	return Right;
}

//���ڷ� ��������
Mystring& Mystring::operator=(const Mystring& Right)
{ 
	int len = strlen(Right.m_string) + 1;
	char* temp = new char[len];
	strcpy_s(temp, len, Right.m_string);
	delete[] m_string;
	m_string = nullptr;
	m_string = temp;
	return *this;
}

Mystring Mystring::operator+(Mystring& Right)
{
	int leftlen = strlen(this->m_string) + 1;
	int rightlen = strlen(Right.m_string) + 1;
	int newlen = leftlen + rightlen - 1;

	char* temp = new char[newlen];
	strcpy_s(temp, leftlen, this->m_string);
	strcat_s(temp, newlen, Right.m_string);
	Mystring newString(temp);
	//Mystring tempT(newString);
	SAFE_DELETE_ARRAY(temp);
	//��������� ȣ�� �� �ȵ�?????
	return newString;
}

bool Mystring::operator==(const Mystring& Right)
{
	if (!strcmp(this->m_string, Right.m_string))
		return true;
	else
		return false;
}
