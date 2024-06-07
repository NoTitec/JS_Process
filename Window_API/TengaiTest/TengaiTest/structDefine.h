#pragma once
#include "stdafx.h"
typedef struct tagInfo
{
	float	fX;		// 중점 X
	float	fY;		// 중점 Y

	float	fCX;	// 가로 사이즈
	float	fCY;	// 세로 사이즈

}INFO;

typedef	struct tagLinePoint
{
	float	fX;
	float	fY;

	tagLinePoint() { ZeroMemory(this, sizeof(tagLinePoint)); }
	tagLinePoint(float _fX, float _fY) : fX(_fX), fY(_fY) {}

}LINEPOINT;

//typedef	struct tagLine
//{
//	tagLinePoint		tLeft;
//	tagLinePoint		tRight;
//
//	tagLine() { ZeroMemory(this, sizeof(tagLine)); }
//	tagLine(tagLinePoint& _tLeft, tagLinePoint& _tRight) : tLeft(_tLeft), tRight(_tRight) {}
//
//}LINE;

typedef struct tagFrame
{
	int		iFrameStart;		// 어디에서부터 시작(인덱스)
	int		iFrameEnd;			// 어디까지(끝 인덱스)
	int		iMotion;			// 어떤 모션
	DWORD	dwSpeed;			// 스프라이트 속도
	DWORD	dwTime;				// 스프라이트 전환 시간
	bool	bRepeat;			// 반복 애니메이션 확인 변수
}FRAME;
