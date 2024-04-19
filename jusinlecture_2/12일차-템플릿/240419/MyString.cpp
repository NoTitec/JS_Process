#include "stdafx.h"
#include "MyString.h"


CMyString::CMyString() : m_pString(nullptr), m_iSize(0)
{
}

CMyString::CMyString(char * pString)
{
	m_iSize = strlen(pString);

	m_pString = new char[m_iSize + 1];

	strcpy_s(m_pString, m_iSize + 1, pString);

}

CMyString::CMyString(const CMyString & rhs)
	: m_iSize(rhs.m_iSize)
{
	m_pString = new char[m_iSize + 1];
	strcpy_s(m_pString, m_iSize + 1, rhs.m_pString);
	cout << "복사생성자 호출" << endl;
}

CMyString::~CMyString()
{
	Release();
}

void CMyString::Release()
{
	SAFE_DELETE_ARRAY(m_pString);
}


CMyString& CMyString::operator=(CMyString& rString)
{
	Release();

	m_iSize = strlen(rString.m_pString);

	m_pString = new char[m_iSize + 1];

	strcpy_s(m_pString, m_iSize + 1, rString.m_pString);
	
	return *this;
}
CMyString& CMyString::operator=(char* pString)
{
	Release();

	m_iSize = strlen(pString);

	m_pString = new char[m_iSize + 1];

	strcpy_s(m_pString, m_iSize + 1, pString);

	return *this;
}

CMyString CMyString::operator+(CMyString & rString)
{
	int			iSize = m_iSize + strlen(rString.m_pString) + 1;

	char*		pStr = new char[iSize];

	strcpy_s(pStr, iSize, m_pString);
	strcat_s(pStr, iSize, rString.m_pString);

	CMyString		Result(pStr);

	SAFE_DELETE_ARRAY(pStr);

	return Result;
}

CMyString CMyString::operator+(char * pString)
{
	int			iSize = m_iSize + strlen(pString) + 1;

	char*		pStr = new char[iSize];

	strcpy_s(pStr, iSize, m_pString);
	strcat_s(pStr, iSize, pString);

	CMyString		Result(pStr);

	SAFE_DELETE_ARRAY(pStr);

	return Result;
}

bool CMyString::operator==(CMyString & rString)
{
	return !strcmp(m_pString, rString.m_pString);
}

bool CMyString::operator==(char * pString)
{
	return !strcmp(m_pString, pString);
}
