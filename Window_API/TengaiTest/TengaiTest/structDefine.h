#pragma once
#include "stdafx.h"
typedef struct tagInfo
{
	float	fX;		// ���� X
	float	fY;		// ���� Y

	float	fCX;	// ���� ������
	float	fCY;	// ���� ������

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
	int		iFrameStart;		// ��𿡼����� ����(�ε���)
	int		iFrameEnd;			// ������(�� �ε���)
	int		iMotion;			// � ���
	DWORD	dwSpeed;			// ��������Ʈ �ӵ�
	DWORD	dwTime;				// ��������Ʈ ��ȯ �ð�
	bool	bRepeat;			// �ݺ� �ִϸ��̼� Ȯ�� ����
}FRAME;
