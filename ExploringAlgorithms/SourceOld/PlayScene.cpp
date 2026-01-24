#include "PlayScene.h"
#include "../Library/Time.h"
#include "Player.h"
#include "StackAndQueue.h"
#include "MapLoader.h"
#include "Dig/DiggingDungeon.h"
#include "Dig/MapLoadDungeon.h"
#include <cassert>

#include "AStarPlayer.h"

namespace
{
	const float SEARCH_INTERVAL{ 0.01f };
	const float TO_RELOAD_SCENE_TIME{ 3.0f };
}

int PlayScene::playCount_{ 0 };

PlayScene::PlayScene() :
	//dungeon_{ 43, 13 },
	timeLeft_{ SEARCH_INTERVAL },
	pViewer_{ nullptr },
	pPlayer_{ nullptr },
	pDungeon_{ nullptr },
	mapLoader_{}
{
	bool succeed{ mapLoader_.TryLoad("MapData/MapData.txt") };
	assert(succeed && "ƒ}ƒbƒv‚Ì“Ç‚Ýž‚Ý‚ÉŽ¸”s");

	pDungeon_ = new MapLoadDungeon{ mapLoader_ };
	pViewer_ = new DungeonViewer{ *pDungeon_ };

	//pDungeon_->Generate();
	if (playCount_ % ST_MAX == 0)
	{
		pCellData_ = static_cast<IDataList<Cell*>*>(new DataQueue<Cell*>{});
	}
	else
	{
		pCellData_ = static_cast<IDataList<Cell*>*>(new DataStack<Cell*>{});
	}

	playCount_++;
	pPlayer_ = new Player{ *pViewer_, pCellData_ };
	//pPlayer_ = new Player{ *pViewer_, pCellData_ };
}

PlayScene::~PlayScene()
{
	if (pCellData_)
	{
		delete pCellData_;
		pCellData_ = nullptr;
	}

	if (pDungeon_)
	{
		delete pDungeon_;
		pDungeon_ = nullptr;
	}

	if (pViewer_)
	{
		delete pViewer_;
		pViewer_ = nullptr;
	}
}

void PlayScene::Update()
{
	if (pPlayer_->IsComplete())
	{
		timeLeft_ -= Time::DeltaTime();
		if (timeLeft_ <= 0.0f)
		{
			SceneManager::ReloadScene();
		}

		return;
	}

	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
		return;
	}

	timeLeft_ -= Time::DeltaTime();
	{
		pPlayer_->Step();
		if (pPlayer_->IsComplete())
		{
			timeLeft_ += TO_RELOAD_SCENE_TIME;
		}
		else
		{
			timeLeft_ += SEARCH_INTERVAL;
		}
	}
}

void PlayScene::Draw()
{
	pViewer_->View();

	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}
