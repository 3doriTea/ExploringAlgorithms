#pragma once
#include "../Vec2Int.h"

class Dungeon;

class DungeonViewer
{
public:
	DungeonViewer(const Dungeon& _dungeon);
	~DungeonViewer();

	void View();
	bool IsWall(const int _x, const int _y);
	int GetCost(const int _x, const int _y);

	/// <summary>
	/// ダンジョンのサイズを取得する
	/// </summary>
	/// <returns>(幅, 高さ)</returns>
	Vec2Int GetSize() const;

public:
	static int WALL_SIZE;

private:
	const Dungeon& dungeon_;
};
