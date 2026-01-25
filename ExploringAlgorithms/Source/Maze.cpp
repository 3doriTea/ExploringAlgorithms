#include "Maze.h"


void Maze::SetRoad(const int _value, const Vec2Int _pos)
{
	cells_.At(_pos) = _value;
}

int Maze::GetRoadCost(const Vec2Int _pos)
{
	if (cells_.At(_pos) == CellType::WALL)
	{
		return INT_MAX;  // ï«ÇÃÉRÉXÉgÇÕç≈ëÂ
	}
	else
	{
		return cells_.At(_pos);
	}
}

bool Maze::GetIsWall(const Vec2Int _pos)
{
	return cells_.At(_pos) == CellType::WALL;
}
