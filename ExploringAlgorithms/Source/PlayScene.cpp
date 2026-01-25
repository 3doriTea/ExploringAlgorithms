#include "PlayScene.h"
#include "Maze.h"
#include "BFS.h"
#include "CellSheetPainter.h"
#include "MazeLoader.h"
#include <cassert>


PlayScene::PlayScene()
{
	new CellSheetPainter{ 30 };

	Maze* pMaze{ new Maze{} };

	MazeLoader loader{ *pMaze };
	assert(loader.TryLoad("./MapData/MapData.txt"));

	new BFS{ { 1.0f / 60.0f, 0.3f }, *pMaze };
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
}
