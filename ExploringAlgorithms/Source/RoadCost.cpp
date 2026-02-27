#include "RoadCost.h"
#include <cassert>
#include "Dir.h"


RoadCost::RoadCost() :
	cells_{ {}, UNKNOWN_COST }
{
}

RoadCost::~RoadCost()
{
}

bool RoadCost::HasCost(const Vec2Int _pos)
{
	return cells_.At(_pos) != UNKNOWN_COST;
}

int RoadCost::GetCost(const Vec2Int _pos)
{
	assert(cells_.At(_pos) != UNKNOWN_COST
		&& "コスト不明のセルが参照されました。");

	return cells_.At(_pos);
}

void RoadCost::SetCostUnitCell(const int _cost, const Vec2Int _pos)
{
	int minCost{ UNKNOWN_COST };
	for (int d = 0; d < DIR_MAX; d++)
	{
		Vec2Int checkPos{ _pos + DIR_VEC[d] };

		int checkCost{ cells_.At(checkPos) };
		if (checkCost == UNKNOWN_COST)
		{
			continue;  // コスト不明なら無視
		}

		if (minCost == UNKNOWN_COST  // まだ最小コストが見つかっていない または
			|| checkCost < minCost)  // 最小コストだった
		{
			minCost = checkCost;
		}
	}

	assert(minCost != UNKNOWN_COST
		&& "上下左右4近傍がコスト不明の独立状態です。");

	cells_.At(_pos) = minCost + _cost;  // 最小の隣のコストにプラスしてセルのコスト
}

void RoadCost::SetCost(const int _cost, const Vec2Int _pos)
{
	cells_.At(_pos) = _cost;
}

void RoadCost::Reset(const Vec2Int _size)
{
	cells_ = CellSheet{ _size, UNKNOWN_COST };
}

const int RoadCost::UNKNOWN_COST{ -1 };
