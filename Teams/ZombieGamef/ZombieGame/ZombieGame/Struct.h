#pragma once
// �ش� ����ü�鿡 ���� �߰� �� ������ �ݵ�� ������� ����!

// Object�� ����, ũ��
typedef struct tagInfo
{
	float fX;
	float fY;

	float fCX;
	float fCY;
} INFO;

// fX, fY ��ǥ���� ���� ����ü. Normalize �Լ��� ����.
typedef struct Vec2
{
	float fX;
	float fY;

public:
	// ������ ũ��(����) �� ���ϴ� �Լ�.(��Ÿ���)
	float Length()
	{
		return sqrt((fX * fX) + (fY * fY));
	}
	// ������ ����ȭ �Լ�.
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
