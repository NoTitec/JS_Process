#pragma once
#include "stdafx.h"

//�Ѱ������ Ȱ���̸� ���۷�����ȯ, �ΰ����̻��� �������� ���ο� ��ü�ʿ��ϸ� ��ü��ȯ??

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

