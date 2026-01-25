#pragma once


/// <summary>
/// ƒZƒ‹‚ÌŽí—Þ
/// </summary>
struct CellType
{
	enum : int
	{
		WALL = -1,
		ROAD_COST_0 = 0,
		ROAD_COST_1 = 1,
		ROAD_COST_2 = 2,
		// ...
	};
};
