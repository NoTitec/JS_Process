#pragma once
class Character;
class CStore;
class CInventory;

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
	Character* m_pPlayer;
	CInventory* m_pInventory;
	CStore* m_pStore;
};
