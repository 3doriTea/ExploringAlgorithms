#include "AlgorithmPlayer.h"
#include "IMazeViewer.h"
#include "CheckCellType.h"
#include "CellSheetPainter.h"
#include "PainterColorMap.h"


AlgorithmPlayer::AlgorithmPlayer(const Config& _config, IMazeViewer& _mazeView) :
	mazeView_{ _mazeView },
	config_{ _config },
	initialized_{ false },
	completed_{ false },
	timeLeftSec_{},
	checkedSheet_{ _mazeView.GetSize() }
{
}

void AlgorithmPlayer::Update()
{
	if (completed_)
	{
		return;  // 完了済みなら無視
	}

	timeLeftSec_ -= config_.deltaTimeSec;
	if (timeLeftSec_ > 0)
	{
		return;  // ステップ時間が来てないなら無視
	}
	timeLeftSec_ += config_.stepIntervalSec;

	if (!initialized_)
	{
		Init();  // 最初の1ステップは初期化ターン
		initialized_ = true;
	}
	else
	{
		completed_ = Step();
	}
}

void AlgorithmPlayer::Draw()
{
	CellSheetPainter* pPainter{ FindGameObject<CellSheetPainter>() };
	pPainter->Paint(
		checkedSheet_,
		PainterColorMap{}
		.Reset()
		.Set(CheckCellType::CHECKED, 0x00ff00)
		.Set(CheckCellType::FRONTIER, 0x001000)
	);
}

bool AlgorithmPlayer::GetIsWall(const Vec2Int _pos)
{
	return mazeView_.GetIsWall(_pos);
}

Vec2Int AlgorithmPlayer::GetGoalPos()
{
	return mazeView_.GetGoalPos();
}

Vec2Int AlgorithmPlayer::GetStartPos()
{
	return mazeView_.GetStartPos();
}

bool AlgorithmPlayer::TrySetChecked(const Vec2Int _pos)
{
	if (checkedSheet_.At(_pos) == CheckCellType::FRONTIER)
	{
		checkedSheet_.At(_pos) = CheckCellType::CHECKED;
		return true;
	}
	else
	{
		return false;
	}
}

bool AlgorithmPlayer::TrySetFrontier(const Vec2Int _pos)
{
	if (checkedSheet_.At(_pos) == CheckCellType::UNCHECKED)
	{
		checkedSheet_.At(_pos) = CheckCellType::FRONTIER;
		return true;
	}
	else
	{
		return false;
	}
}

