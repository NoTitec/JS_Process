#pragma once
class Character;
class CField;
class CStore;

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
	Character* m_Player;
	CField* m_pFiled;
	CStore* m_pStore;
};

