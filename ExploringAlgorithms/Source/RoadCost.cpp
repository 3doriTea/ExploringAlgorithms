#include "RoadCost.h"

RoadCost::RoadCost() :
	cells_{ {} }
{
}

RoadCost::~RoadCost()
{
}

int RoadCost::GetCost(const Vec2Int _pos)
{
	return 0;
}

void RoadCost::SetCostUnitCell(const int _cost, const Vec2Int _pos)
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
}

void RoadCost::Reset(const Vec2Int _size)
{
	cells_ = CellSheet{ _size, -1 };
}
