#include "Maze.h"


int Maze::GetRoadCost(const Vec2Int _pos)
{
	if (cells_.At(_pos) == CellType::WALL)
	{
		return INT_MAX;  // Х«ВћГRГXГgВЌН≈Се
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
