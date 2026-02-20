#include "AStar.h"
#include <cmath>
#include "CellSheetPainter.h"
#include "PainterNumberConfig.h"
#include "RouteViewer.h"

void AStar::Init()
{
	roadCost_.Reset(GetSize());
	roadCost_.SetCost(0, GetStartPos());

	queue_.push(ToCostAndPos(GetStartPos()));
	TrySetFrontier(GetStartPos());
}

bool AStar::Step()
{
	if (IsCompleted())
	{
		return true;
	}

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
			CostAndPos costAndPos{ ToCostAndPos(frontier) };
			queue_.push(costAndPos);

			if (costAndPos.pos == GetGoalPos())
			{
				new RouteViewer{ &roadCost_.GetRefCellSheet() };
				return true;  // ゴールに到着したなら探索終了
			}
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
