// 240422.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
//static �Լ� ���ø�(static ������ �޸� ����)
template<typename T>
T		Func(T Number)
{
	static T Temp = 0;
	 
	Temp += Number;

	return Temp;
}

//Ŭ���� ���ø��� �������� ���ø����� Ŭ�������ƴϴ�
//�Ϲ� ���ø� �ɹ������� ���� �ʱ�ȭ ����
// static �ɹ������� �ʱ�ȭ�� T CObj<T>:: �ʿ�, �׸��� �� ���ø��ν��Ͻ��� static������ �����Ƿ�
// ���ν��Ͻ�Ÿ�Կ����� ����� �ʱ�ȭ �����ؾ���, �ʱ�ȭ������ �ݵ�� Ŭ���� �ܺο� ��ġ�ؾ���
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
//���� �ʱ�ȭ
template<typename T>
T CObj<T>::m_Sum;
//������
template<typename T>
CObj<T>::CObj(){}
//�Ҹ���
template<typename T>
CObj<T>::~CObj() {}

// char* �� ���� Ư��ȭ ���ø� Ŭ����
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
		delete[] m_data;  // ���� ������ ����
		m_data =pString;  // �� ������ �Ҵ�
		return pString;
	}
	void Render()
	{
		cout << m_data << endl;
	}
private:
	char* m_data;
};

//��ӽ� ���ø����� ����ؾ���
template<typename T>
class CPlayer : public CObj<T>
{};

//�Ϲ� ���ø�
template<typename T1, typename T2>
class CTest {};

// �κ� Ư��ȭ �� 1
template<>
class CTest<int, char*> {};

// �κ� Ư��ȭ �� 2
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


	//���ø����� static �۵���� ��
	Func<int>(10);
	Func<float>(11.2f);
	
	cout << Func<int>(20) << endl;
	cout << Func<float>(22.f) << endl;

    return 0;
}

