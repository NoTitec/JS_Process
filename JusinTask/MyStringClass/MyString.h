#pragma once
class MyString
{
public:
	MyString() {};
	MyString(const char* pName);
	

	//복사생성자 재정의
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

