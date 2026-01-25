#include "Maze.h"
#include "CellSheetPainter.h"
#include "PainterColorMap.h"
#include "RoadCellType.h"


Maze::Maze() :
	cells_{ {} },
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
		cells_,
		PainterColorMap{}
			.Reset()
			.Set(RoadCellType::WALL, 0x0000ff));
}

Vec2Int Maze::GetSize() const
{
	return cells_.GetSize();
}

void Maze::ResetAndFill(const Vec2Int _size, int _fillValue)
{
	cells_ = CellSheet{ _size };
	for (int y = 0; y < _size.y; y++)
	{
		for (int x = 0; x < _size.x; x++)
		{
			cells_.At({ x, y }) = _fillValue;
		}
	}
}

void Maze::SetRoad(const int _value, const Vec2Int _pos)
{
	cells_.At(_pos) = _value;
}

int Maze::GetRoadCost(const Vec2Int _pos)
{
	if (cells_.At(_pos) == RoadCellType::WALL)
	{
		return INT_MAX;  // •Ç‚ÌƒRƒXƒg‚ÍÅ‘å
	}
	else
	{
		return cells_.At(_pos);
	}
}

bool Maze::GetIsWall(const Vec2Int _pos)
{
	return cells_.At(_pos) == RoadCellType::WALL;
}
