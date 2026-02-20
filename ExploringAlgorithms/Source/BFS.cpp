#include "BFS.h"
#include "RouteViewer.h"
#include "CellSheetPainter.h"
#include "PainterNumberConfig.h"


void BFS::Init()
{
	roadCost_.Reset(GetSize());
	roadCost_.SetCost(0, GetStartPos());

	queue_.push(GetStartPos());
	TrySetFrontier(GetStartPos());

	onceFinished_ = false;
}

bool BFS::Step()
{
	if (queue_.empty())
	{
		// 探索終了したら onceだけ実行
		if (onceFinished_ == false)
		{
			onceFinished_ = true;
			new RouteViewer{ &roadCost_.GetRefCellSheet() };
		}
		return true;  // スタックが空なら探索完了
	}

	Vec2Int drop{ queue_.front() };
	queue_.pop();

	TrySetChecked(drop);

	for (int d = 0; d < DIR_MAX; d++)
	{
		// 候補座標
		Vec2Int frontier{ drop + DIR_VEC[d] };
		if (GetIsWall(frontier))
		{
			continue;  // 壁なら無視
		}

		if (TrySetFrontier(frontier))
		{
			roadCost_.SetCostUnitCell(GetFrontierCost(frontier), frontier);
			queue_.push(frontier);
		}
	}

	return false;
}

void BFS::Draw(CellSheetPainter* _pPainter)
{
	_pPainter->Paint(
		roadCost_.GetRefCellSheet(),
		PainterNumberConfig{}
			.Reset()
			.SetIgnore([](int value) { return value == -1; })
			.SetTextColor(0x000000)
	);
}

int BFS::GetFrontierCost(const Vec2Int _pos)
{
	int minCost{ 0 };
	for (int dir = 0; dir < DIR_MAX; dir++)
	{
		Vec2Int neighborPos{ _pos + DIR_VEC[dir] };
		if (roadCost_.HasCost(neighborPos))
		{
			int cost{ roadCost_.GetCost(neighborPos) };
			minCost = min(minCost, cost);
		}
		else
		{
			continue;  // チェックする隣りのセルがコスト無いなら無視
		}
	}

	return minCost + 1;
}
