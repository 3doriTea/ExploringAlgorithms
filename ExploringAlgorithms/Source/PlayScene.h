#pragma once
#include "../Library/SceneBase.h"
#include "Dig/DiggingDungeon.h"
#include "Dig/DungeonViewer.h"
#include "Dig/MapLoadDungeon.h"
#include "IDataList.h"
#include "CellInfo.h"


class Player;
class AStarPlayer;

/// <summary>
/// ゲームプレイのシーンを制御する
/// </summary>
class PlayScene : public SceneBase
{
private:
	enum SEARCH_TYPE : int
	{
		ST_BFS,
		ST_DFS,
		ST_MAX,
	};

public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;

private:
	//DiggingDungeon dungeon_;
	MapLoader mapLoader_;
	Dungeon* pDungeon_;
	DungeonViewer* pViewer_;
	float timeLeft_;
	//Player* pPlayer_;
	AStarPlayer* pPlayer_;
	IDataList<Cell*>* pCellData_;

	static int playCount_;
};
