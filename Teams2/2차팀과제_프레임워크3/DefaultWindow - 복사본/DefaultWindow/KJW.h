#pragma once
#define BLUEGREEN RGB(0, 94, 86)
#define G 9.8f
#define MAPCX 1600
#define MAPCY 600

typedef struct tagKJW_Frame
{
	int		iFrameStart;		// 어디에서부터 시작(인덱스)
	int		iFrameEnd;			// 어디까지(끝 인덱스)
	int		iMotion;			// 어떤 모션
	DWORD	dwSpeed;			// 스프라이트 속도
	DWORD	dwTime;				// 스프라이트 전환 시간
	bool	bRepeat;			// 반복재생 여부
}KJW_FRAME;