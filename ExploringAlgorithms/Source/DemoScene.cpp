#include "DemoScene.h"
#include "GroundMap.h"
#include "AI.h"


DemoScene::DemoScene()
{
	new GroundMap{};
	new AI{};
}

DemoScene::~DemoScene()
{
}

void DemoScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T))
	{
		SceneManager::ChangeScene("TITLE");
	}
}

void DemoScene::Draw()
{
}
