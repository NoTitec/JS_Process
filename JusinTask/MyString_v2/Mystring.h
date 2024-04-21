#pragma once
#include "stdafx.h"
#define		SAFE_DELETE_ARRAY(p) if(p) { delete []p; p = nullptr;}
//한가지요소 활용이면 레퍼런스반환, 두가지이상의 결합으로 새로운 객체필요하면 객체반환??

class Mystring
{
public:
	Mystring(): m_string(nullptr) {};
	Mystring(const char* pName);

	Mystring(const Mystring& rhs);
	~Mystring() { delete[]m_string; m_string = nullptr; }

public:
	Mystring CopyTest(Mystring Right);
public:
	Mystring& operator =(const Mystring& Right);
	Mystring operator+(Mystring& Right);
	bool operator ==(const Mystring& Right);
public:
	void		PrintN() { printf("%s\n", m_string); }

private:
	char* m_string;
};

