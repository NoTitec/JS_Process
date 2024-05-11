#pragma once
// 해당 구조체들에 대한 추가 및 변경은 반드시 팀원들과 상의!

// Object의 중점, 크기
typedef struct tagInfo
{
	float fX;
	float fY;

	float fCX;
	float fCY;
} INFO;

// fX, fY 좌표만을 가진 구조체. Normalize 함수를 포함.
typedef struct Vec2
{
	float fX;
	float fY;

public:
	// 벡터의 크기(빗변) 을 구하는 함수.(피타고라스)
	float Length()
	{
		return sqrt((fX * fX) + (fY * fY));
	}
	// 벡터의 정규화 함수.
	Vec2& Normalize()
	{
		float fLength = Length();
		assert(!(fLength == 0.f));

		fX /= fLength;
		fY /= fLength;

		return *this;
	}

public:
	// Vec2 to Vec2 operator
	Vec2 operator +(Vec2& _Other)
	{
		return Vec2(fX + _Other.fX, fY + _Other.fY);
	}
	Vec2 operator -(Vec2& _Other)
	{
		return Vec2(fX - _Other.fX, fY - _Other.fY);
	}
	Vec2 operator *(Vec2& _Other)
	{
		return Vec2(fX * _Other.fX, fY * _Other.fY);
	}
	Vec2 operator /(Vec2& _Other)
	{
		return Vec2(fX / _Other.fX, fY / _Other.fY);
	}

	// Vec2 to POINT +, - operator
	Vec2 operator +(POINT& _Point)
	{
		return Vec2(fX + _Point.x, fY + _Point.y);
	}
	Vec2 operator -(POINT& _Point)
	{
		return Vec2(fX - _Point.x, fY - _Point.y);
	}

	// Vec2 to float * operator
	Vec2 operator *(float _fData)
	{
		return Vec2(fX * _fData, fY * _fData);
	}
	
public:
	Vec2()
		: fX()
		, fY()
	{}
	Vec2(float _fX, float _fY)
		: fX(_fX)
		, fY(_fY)
	{}
	Vec2(double _fX, double _fY)
		: fX((float)_fX)
		, fY((float)_fY)
	{}
	
};
