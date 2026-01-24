#include "AStarPlayer.h"
#include <cmath>
#include "Dig/DungeonViewer.h"
#include "RoadPainter.h"


AStarPlayer::AStarPlayer(
	RoadPainter& _pRoadPainter,
	DungeonViewer& _pDungeonViewer,
	const Vec2Int _startPos,
	const Vec2Int _goalPos):
	q_{},
	roadPainter_{ _pRoadPainter },
	dungeonViewer_{ _pDungeonViewer },
	startPos_{ _startPos },
	goalPos_{ _goalPos }
{
	q_.push({ .cost = 0, .pos = startPos_ });
}

void AStarPlayer::Step()
{
	enum DIRECTION
	{
		DOWN,
		UP,
		LEFT,
		RIGHT,
		MAX
	};
	const Vec2Int DIR[MAX]
	{
		{ 0, 1 },
		{ 0, -1 },
		{ -1, 0 },
		{ 1, 0 },
	};

	const auto [cost, pos]{ q_.top() };

	Goto(pos);

	for (int dir{ DOWN }; dir < MAX; dir++)
	{
		Vec2Int toPos{ pos.Add(DIR[dir]) };

		if (dungeonViewer_.IsWall(toPos.x, toPos.y))
		{
			continue;  // 壁なら候補に追加しない
		}

		if (roadPainter_.IsPainted(toPos))
		{
			continue;  // 既に済みだから追加しない
		}

		// A* の式はここだ！
		float totalCost{ GetCostHeuristic(toPos) + GetCostDistance(toPos) };
		
		q_.push({ .cost = totalCost, .pos = toPos });
		Plan(toPos);
	}

	q_.pop();


}

void AStarPlayer::Goto(const Vec2Int _at)
{
	roadPainter_.Add(_at, PaintType::PT_CHECKED);
}

void AStarPlayer::Plan(const Vec2Int _at)
{
	roadPainter_.Add(_at, PaintType::PT_NEXT);
}

float AStarPlayer::GetCostHeuristic(const Vec2Int _pos)
{
	return GetDistance(goalPos_, _pos);
}

float AStarPlayer::GetCostDistance(const Vec2Int _pos)
{
	return GetDistance(startPos_, _pos);
}

float AStarPlayer::GetDistance(const Vec2Int _a, const Vec2Int _b)
{
	// いったんマンハッタン距離
	return static_cast<float>(std::sqrtf((_b.x - _a.x) * (_b.x - _a.x) + (_b.y - _a.y) * (_b.y - _a.y)));
}
