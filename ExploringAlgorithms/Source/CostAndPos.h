#pragma once
#include "Vec2Int.h"


/// <summary>
/// コストと座標
/// </summary>
struct CostAndPos
{
	float cost;
	Vec2Int pos;
};

/// <summary>
/// コストの比較
/// </summary>
constexpr auto CostAndPosCompare = [](CostAndPos a, CostAndPos b)
	{
		return a.cost > b.cost;
	};
