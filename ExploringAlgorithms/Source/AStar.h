#pragma once
#include "AlgorithmPlayer.h"
#include <queue>
#include "CellSheet.h"

struct CostAndPos
{
	float cost;
	Vec2Int pos;
};

constexpr auto CostAndPosCompare = [](CostAndPos a, CostAndPos b)
	{
		return a.cost > b.cost;
	};

class AStar : public AlgorithmPlayer
{
public:
	using AlgorithmPlayer::AlgorithmPlayer;
	inline ~AStar() {}

	void Init() override;
	bool Step() override;

private:
	CostAndPos ToCostAndPos(const Vec2Int _pos);

	float G(const Vec2Int _pos);
	float H(const Vec2Int _pos);

	/// <summary>
	/// 簡易的な予想距離を取得する
	/// </summary>
	/// <returns></returns>
	static float GetDistance(const Vec2Int _a, const Vec2Int _b);

private:
	CellSheet costSheet_;  // 移動コストの情報

	std::priority_queue<
		CostAndPos,
		std::vector<CostAndPos>,
		decltype(CostAndPosCompare)> queue_;
};
