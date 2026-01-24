#include "DungeonViewer.h"
#include <iostream>
#include <cassert>
#include "Dungeon.h"
#include "DxLib.h"

int DungeonViewer::WALL_SIZE{ 30 };

DungeonViewer::DungeonViewer(const Dungeon& _dungeon) :
	dungeon_{ _dungeon }
{
}

DungeonViewer::~DungeonViewer()
{
}

void DungeonViewer::View()
{
	for (int y = 0; y < dungeon_.GetHeight(); y++)
	{
		for (int x = 0; x < dungeon_.GetWidth(); x++)
		{
			switch (dungeon_.GetTile(x, y))
			{
			case Dungeon::TileType::Wall:
				DrawBox(x * WALL_SIZE, y * WALL_SIZE, (x + 1) * WALL_SIZE, (y + 1) * WALL_SIZE, 0x00ff00, TRUE);
				break;
			case Dungeon::TileType::None:
				break;  // 何もないなら道
			case Dungeon::TileType::Start:
				DrawBox(x * WALL_SIZE, y * WALL_SIZE, (x + 1) * WALL_SIZE, (y + 1) * WALL_SIZE, 0xff0000, TRUE);
				break;
			case Dungeon::TileType::Goal:
				DrawBox(x * WALL_SIZE, y * WALL_SIZE, (x + 1) * WALL_SIZE, (y + 1) * WALL_SIZE, 0xffff00, TRUE);
				break;
			default:
				break;
			}
		}
		std::cout << std::endl;
	}
}

bool DungeonViewer::IsWall(const int _x, const int _y)
{
	return dungeon_.GetTile(_x, _y) == Dungeon::TileType::Wall;
}

int DungeonViewer::GetCost(const int _x, const int _y)
{
	int cost{ static_cast<int>(dungeon_.GetTile(_x, _y)) - static_cast<int>(Dungeon::TileType::_0) };
	
	if (cost < 0)
	{
		cost = INT_MAX;
	}
	//assert(cost >= 0 && "指定したタイルが床ではないためコスト計算できない");
	
	return cost;
}

Vec2Int DungeonViewer::GetSize() const
{
	return { dungeon_.GetWidth(), dungeon_.GetHeight() };
}
