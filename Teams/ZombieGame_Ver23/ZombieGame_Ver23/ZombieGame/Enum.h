#pragma once

enum OBJ_ID
{
	OBJ_TURRET,
	OBJ_PLAYER,
	OBJ_BULLET,
	OBJ_BOSS_BULLET,
	OBJ_GRENADE,
	OBJ_ZOMBIE,
	OBJ_ITEM,
	OBJ_BULLET_ITEM,
	OBJ_BOMB,
	OBJ_BARRIER,
	OBJ_BOSS_ZOMBIE,
	OBJ_END
};

enum OBJ_ITEM_TYPE
{
	OBJ_ITEM_DRUG,
	OBJ_ITEM_BARRIER,
	OBJ_ITEM_PORTAL,
	OBJ_ITEM_TYPE_END
};

enum OBJ_ZOMBIE_TYPE
{
	OBJ_LIGHT_ZOMBIE,
	OBJ_MIDDLE_ZOMBIE,
	OBJ_HEAVY_ZOMBIE,
	OBJ_ZOMBIE_END
};
enum BOSSPATTERN
{
	FOURDIRECTIONS,
	FOLLOWBULLET,

	END_PATTERN
};
enum STAGE_STATE
{
	FIRST_STAGE,
	SECOND_STAGE,
	THIRD_STAGE,
	STAGE_STATE_END
};

enum PLAYER_STATE
{
	PLAYER_DASH,
	PLAYER_BARRIER,
	PLAYER_REBOUND,

	PLAYER_END
};

enum SCENE_TYPE
{
	MAIN_MENU_SCENE,
	MAIN_GAME_SCENE,
	GAME_OVER_SCENE,
	BOSS_GAME_SCENE,
	BOSS_ENTRANCE_SCENE,
	SCENE_TYPE_END
};

enum BULLET_TYPE
{
	NORMAL_BULLET,
	SHOTGUN_BULLET,
	GRENADE_BULLET,
	BULLET_END
};