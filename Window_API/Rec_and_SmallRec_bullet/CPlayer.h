#pragma once
#include "Obj.h"
#include "Define.h"
#include "stdafx.h"
class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	//플레이어 생성위치 및 이동속도설정
	virtual void Initialize() override;
	//키설정 함수 호출과 새로 그려줄 rect 정보 업데이트
	virtual int Update() override;
	//플레이어 그리기
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

public:
	void Set_BulletList(list<CObj*>* pBulletList) { m_pBulletList = pBulletList; }
private:
	//키 입력 관리 함수
	void		Key_Input();
	//총알생성함수
	CObj* Create_Bullet(int dx, int dy);

private:
	list<CObj*>* m_pBulletList;
};

