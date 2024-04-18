#pragma once
#include "stdafx.h"

//한가지요소 활용이면 레퍼런스반환, 두가지이상의 결합으로 새로운 객체필요하면 객체반환??

class Mystring
{
public:
	Mystring(): m_string(nullptr) {};
	Mystring(const char* pName);

	Mystring(const Mystring& rhs);
	~Mystring() { delete[]m_string; m_string = nullptr; }

public:
	Mystring& operator =(const Mystring& Right);
	Mystring operator +(const Mystring& Right);
	bool operator ==(const Mystring& Right);
public:
	void		PrintN() { printf("%s\n", m_string); }

private:
	char* m_string;
};

