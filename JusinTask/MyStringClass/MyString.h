#pragma once
class MyString
{
public:
	MyString() {};
	MyString(const char* pName);
	

	//��������� ������
	MyString(const MyString& rhs);
	~MyString() { delete[]m_string; m_string = nullptr; }

public:
	MyString& operator =(const MyString& Right);
	MyString operator +(const MyString& Right);
	
public:
	void		PrintN() { printf("%s\n", m_string); }

private:
	char* m_string;
};

