#pragma once

class CPlayer;
class CField;

class MainGame
{
public:
	MainGame();
	~MainGame();

public:
	void Initialize();
	void Update();
	void Release();

private:
	CPlayer* m_pPlayer;
	CField* m_pField;
};

