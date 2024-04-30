// 240422.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
//static 함수 템플릿(static 붙은건 메모리 공유)
template<typename T>
T		Func(T Number)
{
	static T Temp = 0;
	 
	Temp += Number;

	return Temp;
}

//클래스 템플릿은 어디까지나 템플릿이지 클래스가아니다
//일반 템플릿 맴버변수는 내부 초기화 문장
// static 맴버변수는 초기화시 T CObj<T>:: 필요, 그리고 각 템플릿인스턴스가 static가질수 있으므로
// 각인스턴스타입에대해 명시적 초기화 제공해야함, 초기화구문은 반드시 클래스 외부에 위치해야함
template<typename T>
class CObj
{
public:
	CObj();
	CObj(T X, T Y) : m_X(X), m_Y(Y) {  }
	~CObj();

public:
	void	Render() { cout << m_X << "\t" << m_Y << endl; }
	T		Add(T a, T b)
	{
		return a + b;
	}

	T		FuncSum(T Number)
	{
		m_Sum += Number;		

		return m_Sum;
	}
	
private:
	T			m_X;
	T			m_Y;
	static		T		m_Sum;
};
//인자 초기화
template<typename T>
T CObj<T>::m_Sum;
//생성자
template<typename T>
CObj<T>::CObj(){}
//소멸자
template<typename T>
CObj<T>::~CObj() {}

// char* 에 대한 특수화 템플릿 클래스
template<>
class CObj<char*>
{
public:
	CObj() : m_data(nullptr) {}
	CObj(const char* strings) {
		int length = strlen(strings)+1;
		char* Temp = new char[length];
		strcpy_s(Temp, length, strings);
		m_data = Temp;
	}
	~CObj() {
		delete[] m_data;
	}
public:

	char*		Add(char* a, char*	 b)
	{
		int iLength = strlen(a) + strlen(b);

		char*	pString = new char[iLength + 1];

		strcpy_s(pString, iLength + 1, a);
		strcat_s(pString, iLength + 1, b);
		delete[] m_data;  // 기존 데이터 삭제
		m_data =pString;  // 새 데이터 할당
		return pString;
	}
	void Render()
	{
		cout << m_data << endl;
	}
private:
	char* m_data;
};

//상속시 템플릿임을 명시해야함
template<typename T>
class CPlayer : public CObj<T>
{};

//일반 템플릿
template<typename T1, typename T2>
class CTest {};

// 부분 특수화 예 1
template<>
class CTest<int, char*> {};

// 부분 특수화 예 2
template<typename T>
class CTest<T, char*> {};


int main()
{
	/*CObj<char*> CharObj("initial");
	CharObj.Render();
	char str1[] = "Hello ";
	char str2[] = "World!";
	cout << "First Add: " << CharObj.Add(str1, str2) << endl;*/

	//CObj<int>		IntObj(10, 20);
	////IntObj.Render();

	//IntObj.FuncSum(100);

	//CObj<int>		IntObj2(50, 60);

	//cout << IntObj2.FuncSum(200) << endl;


	//CObj<float>		FloatObj(1.1f, 22.f);
	//FloatObj.Render();


	//템플릿에서 static 작동방식 예
	Func<int>(10);
	Func<float>(11.2f);
	
	cout << Func<int>(20) << endl;
	cout << Func<float>(22.f) << endl;

    return 0;
}

