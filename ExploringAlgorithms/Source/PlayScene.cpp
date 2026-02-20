#include "PlayScene.h"
#include "Maze.h"
#include "CellSheetPainter.h"
#include "MazeLoader.h"
#include "../Library/SceneManager.h"
#include <cassert>

#include "AStar.h"
#include "Dijkstra.h"
#include "BFS.h"


struct Players
{
	enum : int
	{
		BFS,
		DIJKSTRA,
		ASTAR,
		MAX,
	};
};

static const std::string_view PLAYER_NAMES[]
{
	"BFS",
	"ダイクストラ",
	"A*",
};
static int playerNumber{ Players::MAX };

static const int NAME_VIEW_FONT_SIZE{ 72 };
static const unsigned int NAME_VIEW_COLOR{ 0xffffff };

static AlgorithmPlayer::Config PLAY_CONFIG{ 1.0f / 60.0f, 0.1f };

PlayScene::PlayScene()
{
	new CellSheetPainter{ 30 };

	Maze* pMaze{ new Maze{} };

	MazeLoader loader{ *pMaze };
	assert(loader.TryLoad("./MapData/MapData.txt"));

	playerNumber++;
	if (playerNumber >= Players::MAX)
	{
		playerNumber = 0;
	}

	switch (playerNumber)
	{
	case Players::BFS:
		new BFS{ PLAY_CONFIG, *pMaze };
		break;
	case Players::DIJKSTRA:
		new Dijkstra{ PLAY_CONFIG, *pMaze };
		break;
	case Players::ASTAR:
		new AStar{ PLAY_CONFIG, *pMaze };
		break;
	default:
		assert(false && "知らないプレイヤーヤ！");
		break;
	}
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		SceneManager::ChangeScene("TITLE");
	}
}

void PlayScene::Draw()
{
	int screenSizeX{};
	int screenSizeY{};
	GetDrawScreenSize(&screenSizeX, &screenSizeY);

	const char* pDrawString{ PLAYER_NAMES[playerNumber].data() };

	SetFontSize(NAME_VIEW_FONT_SIZE);
	int stringSizeX{};
	int stringSizeY{};
	int stringLines{};
	GetDrawFormatStringSize(
		&stringSizeX,
		&stringSizeY,
		&stringLines,
		pDrawString);

	int drawBeginX{ (screenSizeX - stringSizeX) / 2 };
	int drawBeginY{ (screenSizeY - stringSizeY) / 2 };

	DrawFormatString(
		drawBeginX,
		drawBeginY,
		NAME_VIEW_COLOR,
		pDrawString);

	SetFontSize(DEFAULT_FONT_SIZE);
}
