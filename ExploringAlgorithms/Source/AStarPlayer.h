#pragma once
#include "../Library/GameObject.h"
#include "Vec2Int.h"
#include <queue>

class DungeonViewer;
class RoadPainter;

struct CostAndPlan
{
	float cost;
	Vec2Int pos;
};

constexpr auto CostAndPlanCompare = [](CostAndPlan a, CostAndPlan b)
	{
		return a.cost > b.cost;
	};

class AStarPlayer : public GameObject
{
public:
	AStarPlayer(RoadPainter& _pRoadPainter, DungeonViewer& _pDungeonViewer, const Vec2Int _startPos, const Vec2Int _goalPos);
	~AStarPlayer() {}

	void Step();

	/// <summary>
	/// 進む
	/// </summary>
	/// <param name="_at">座標</param>
	void Goto(const Vec2Int _at);

	/// <summary>
	/// 候補
	/// </summary>
	/// <param name="_at">座標</param>
	void Plan(const Vec2Int _at);

	/// <summary>
	/// ゴール地点からの距離コストを取得する
	/// </summary>
	/// <param name="_pos"></param>
	/// <returns></returns>
	float GetCostHeuristic(const Vec2Int _pos);

	/// <summary>
	/// スタート地点からの距離コストを取得する
	/// </summary>
	/// <param name="_pos"></param>
	/// <returns></returns>
	float GetCostDistance(const Vec2Int _pos);

	/// <summary>
	/// 距離を取得する
	/// </summary>
	/// <returns></returns>
	static float GetDistance(const Vec2Int _a, const Vec2Int _b);

private:
	Vec2Int goalPos_;  // ゴール地点
	Vec2Int startPos_;  // 開始地点

	DungeonViewer& dungeonViewer_;
	RoadPainter& roadPainter_;
	std::priority_queue<
		CostAndPlan,
		std::vector<CostAndPlan>,
		decltype(CostAndPlanCompare)
	> q_;
};
