#include "stdafx.h"

#define SAFE_DELETE(p) if(p) {delete p;p=nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p) {delete[] p;p=nullptr;}

class Mystring
{
public:
	void Render()
	{
		for (int i = 0; i < len; ++i)
		{
			cout << szstring[i];
		}
		cout << endl;
	}
	//=,+,==
public:
	Mystring() { szstring = nullptr; len = 0; }
	Mystring(const char* strings);
	Mystring(const Mystring& origin);
	~Mystring();
	//대입재정의
	// = 정의
	//origin 문자열을 깊은복사
	Mystring& operator =(const Mystring& origin)
	{
		SAFE_DELETE_ARRAY(szstring);
		int len = origin.len;
		char* temp = new char[len];
		strcpy_s(temp,len,origin.szstring);
		return *this;
	}
	Mystring operator +(const Mystring& RightMystring)
	{
		char* temp = new char[len+RightMystring.len-1];
		strcpy_s(temp, len, szstring);
		strcat_s(temp, len + RightMystring.len - 1, RightMystring.szstring);
		Mystring tempString(temp);
		SAFE_DELETE_ARRAY(temp);
		return tempString;
	}
private:
	char* szstring;
	int len;
};

Mystring::Mystring(const char* strings)
{
	len = strlen(strings) + 1;
	szstring = new char[len];
	strcpy_s(szstring,len ,strings);
}

Mystring::Mystring(const Mystring& origin)
{
	len = origin.len;
	szstring = new char[len];
	strcpy_s(szstring, len, origin.szstring);
}


Mystring::~Mystring()
{
	SAFE_DELETE_ARRAY(szstring);
}

int main()
{
	Mystring a="aaa";
	Mystring b="bbb";
	a=a+b;
	a.Render();
	
	return 0;
}