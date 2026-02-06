#include "PlayScene.h"
#include "Maze.h"
#include "CellSheetPainter.h"
#include "MazeLoader.h"
#include <cassert>

#include "AStar.h"
#include "BFS.h"


PlayScene::PlayScene()
{
	new CellSheetPainter{ 30 };

	Maze* pMaze{ new Maze{} };

	MazeLoader loader{ *pMaze };
	assert(loader.TryLoad("./MapData/MapData.txt"));

	new AStar{ { 1.0f / 60.0f, 0.1f }, *pMaze };
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
