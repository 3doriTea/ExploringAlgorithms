#pragma once
#include "Vec2Int.h"


struct CostAndPos
{
	float cost;
	Vec2Int pos;
};

constexpr auto CostAndPosCompare = [](CostAndPos a, CostAndPos b)
	{
		return a.cost > b.cost;
	};
