#pragma once
#include "stdafx.h"
class CStudent
{
public:
	CStudent() : m_MathScore(0), m_EnglishScore(0) {}

public:
	inline void Render() {
		cout << "이름 : " << szName << endl;
		cout << "수학 점수 : " << m_MathScore << endl;
		cout << "영어 점수 : " << m_EnglishScore << endl;
	};
	inline void Set_MathScore(int iscore) { m_MathScore = iscore; };
	inline int Get_MathScore() { return m_MathScore; }
	inline void Set_EnglishScore(int iscore) { m_EnglishScore = iscore; };
	inline int Get_EnglishScore() { return m_EnglishScore; };
	inline void Set_Name(const char* szname) {
		strcpy_s(szName, sizeof(szName), szname);
	};
	inline const char* Get_Name() { return szName; };
public:

private:
	char szName[20];
	int m_MathScore;
	int m_EnglishScore;

};

