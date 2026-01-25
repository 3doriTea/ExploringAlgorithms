#include "Maze.h"
#include "CellSheetPainter.h"
#include "PainterColorMap.h"
#include "RoadCellType.h"
#include "MarkCellType.h"


Maze::Maze() :
	mazeCells_{ {} },
	markCells_{ {} },
	startPos_{},
	goalPos_{}
{
}

Maze::~Maze()
{
}

void Maze::Draw()
{
	CellSheetPainter* pPainter{ FindGameObject<CellSheetPainter>() };
	pPainter->Paint(
		mazeCells_,
		PainterColorMap{}
		.Reset()
		.Set(RoadCellType::WALL, 0x0000ff)
	);

	pPainter->Paint(
		mazeCells_,
		PainterColorMap{}
		.Reset()
		.Set(MarkCellType::START, 0xff0000)
		.Set(MarkCellType::GOAL, 0xff00ff)
	);
}

Vec2Int Maze::GetSize() const
{
	return mazeCells_.GetSize();
}

void Maze::ResetAndFill(const Vec2Int _size, int _fillValue)
{
	mazeCells_ = CellSheet{ _size, _fillValue };
	markCells_ = CellSheet{ _size, NULL };
}

void Maze::SetStart(const Vec2Int _pos)
{
	startPos_ = _pos;
	markCells_.At(_pos) = MarkCellType::START;
}

void Maze::SetGoal(const Vec2Int _pos)
{
	goalPos_ = _pos;
	markCells_.At(_pos) = MarkCellType::GOAL;
}

void Maze::SetRoad(const int _value, const Vec2Int _pos)
{
	mazeCells_.At(_pos) = _value;
}

int Maze::GetRoadCost(const Vec2Int _pos)
{
	if (mazeCells_.At(_pos) == RoadCellType::WALL)
	{
		return INT_MAX;  // ï«ÇÃÉRÉXÉgÇÕç≈ëÂ
	}
	else
	{
		return mazeCells_.At(_pos);
	}
}

bool Maze::GetIsWall(const Vec2Int _pos)
{
	return mazeCells_.At(_pos) == RoadCellType::WALL;
}
