#pragma once

#include "Status.h"

//����ü �ɹ����� �ʱ�ȭ�� ������ �̴ϼȶ������� ����??

class CPlayer 
{
public:
	enum JOBINDEX{WARRIOR=1,WIZARD,THIEF};

public:
	CPlayer() : m_tInfo{"",0,0} {}
	~CPlayer();

public:
	void Take_Damage(int iAttack);
	int Get_Attak();
	int Get_Hp();
	void Set_Hp(int hp);
public:
	void SelectJob();
	void Render() const;

private:
	INFO m_tInfo;
};

