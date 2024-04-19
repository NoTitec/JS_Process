#pragma once
#define		SAFE_DELETE_ARRAY(p) if(p) { delete []p; p = nullptr;}

class CMyString
{
public:
	CMyString();
	CMyString(const char* pString);
	CMyString(const CMyString& rhs);
	~CMyString();

public:
	const char* Get_String()
	{
		if (m_pString)
			return m_pString;

		return "";
	}

	void			Release();

public:
	CMyString& operator =(const CMyString& rString);
	CMyString& operator =(char* pString);

	CMyString		operator +(CMyString& rString);
	CMyString		operator +(char* pString);

	bool			operator ==(CMyString& rString);
	bool			operator ==(char* pString);

private:
	char* m_pString;
	int			m_iSize;
};
