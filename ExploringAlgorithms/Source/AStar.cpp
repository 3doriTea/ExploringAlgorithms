#include "AStar.h"
#include <cmath>
#include "CellSheetPainter.h"
#include "PainterNumberConfig.h"

void AStar::Init()
{
	roadCost_.Reset(GetSize());
	roadCost_.SetCost(0, GetStartPos());

	queue_.push(ToCostAndPos(GetStartPos()));
	TrySetFrontier(GetStartPos());
}

bool AStar::Step()
{
	enum DIR_TYPE
	{
		DIR_UP,
		DIR_DOWN,
		DIR_RIGHT,
		DIR_LEFT,
		DIR_MAX,
	};

	static const Vec2Int DIR_VEC[DIR_MAX]
	{
		{ 0, -1 },
		{ 0, 1 },
		{ 1, 0 },
		{ -1, 0 },
	};

	if (queue_.empty())
	{
		return true;  // スタックが空なら探索完了
	}

	auto [dropCost, dropPos]{ queue_.top() };
	queue_.pop();

	TrySetChecked(dropPos);

	for (int d = 0; d < DIR_MAX; d++)
	{
		Vec2Int frontier{ dropPos + DIR_VEC[d] };
		if (GetIsWall(frontier))
		{
			continue;
		}

		if (TrySetFrontier(frontier))
		{
			roadCost_.SetCostUnitCell(GetRoadCost(frontier) + 1, frontier);
			queue_.push(ToCostAndPos(frontier));
		}
	}

	return false;
}

void AStar::Draw(CellSheetPainter* _pPainter)
{
	_pPainter->Paint(
		roadCost_.GetRefCellSheet(),
		PainterNumberConfig{}
		.Reset()
		.SetIgnore([](int value) { return value == -1; })
		.SetTextColor(0x000000)
	);
}

CostAndPos AStar::ToCostAndPos(const Vec2Int _pos)
{
	CostAndPos costAndPos{};
	costAndPos.cost += G(_pos) + H(_pos);
	costAndPos.pos = _pos;

	return costAndPos;
}

float AStar::G(const Vec2Int _pos)
{
	return roadCost_.GetCost(_pos);
}

float AStar::H(const Vec2Int _pos)
{
	return GetDistance(_pos, GetGoalPos());
}

float AStar::GetDistance(const Vec2Int _a, const Vec2Int _b)
{
	// いったんマンハッタン距離
	return std::abs(_a.x - _b.x) + std::abs(_a.y - _b.y);
}
