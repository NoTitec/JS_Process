#pragma once
#define BLUEGREEN RGB(0, 94, 86)
#define G 9.8f
#define MAPCX 1600
#define MAPCY 600

typedef struct tagKJW_Frame
{
	int		iFrameStart;		// ��𿡼����� ����(�ε���)
	int		iFrameEnd;			// ������(�� �ε���)
	int		iMotion;			// � ���
	DWORD	dwSpeed;			// ��������Ʈ �ӵ�
	DWORD	dwTime;				// ��������Ʈ ��ȯ �ð�
	bool	bRepeat;			// �ݺ���� ����
}KJW_FRAME;