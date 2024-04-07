#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer()
{
	m_iAttack = 100;
}

void CPlayer::Render()
{
	cout << m_iAttack << endl;
}