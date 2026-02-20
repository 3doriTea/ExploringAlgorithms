#pragma once
#include "AlgorithmPlayer.h"
#include <queue>
#include "CellSheet.h"
#include "RoadCost.h"
#include "CostAndPos.h"


class Dijkstra : public AlgorithmPlayer
{
public:
	using AlgorithmPlayer::AlgorithmPlayer;
	inline ~Dijkstra() {}

	void Init() override;
	bool Step() override;

	void Draw(CellSheetPainter* _pPainter) override;

private:
	CostAndPos ToCostAndPos(const Vec2Int _pos);

	float G(const Vec2Int _pos);

	/// <summary>
	/// 簡易的な予想距離を取得する
	/// </summary>
	/// <returns></returns>
	static float GetDistance(const Vec2Int _a, const Vec2Int _b);

private:
	RoadCost roadCost_;  // 移動コストの情報

	std::priority_queue<
		CostAndPos,
		std::vector<CostAndPos>,
		decltype(CostAndPosCompare)> queue_;
};
