#pragma once
#include "Player.h"

enum STATE
{
	STOP,
	GO,
	TURN,
	STATE_END
};

class CSunPlayer : public CPlayer
{
public:
	CSunPlayer();
	virtual ~CSunPlayer();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	void Sun_Key_Input();
	void RotZ();
	bool Equals(float fLhs, float fRhs)
	{
		const static float fEPSION = 0.5f;
		return fabs(fLhs - fRhs) < fEPSION ? true : false;
	}
	void Input_Mouse();
	void Go_Straight();
	/*D3DXVECTOR3 m_vLocalPosinLook;

	D3DXVECTOR3 m_vWorldPosinLook;*/
	float m_fPosinRotAngle=0.f;

};

