#pragma once
#include "Vec2Int.h"


/// <summary>
/// 4近傍方向の種類
/// </summary>
enum DIR_TYPE
{
	DIR_UP,
	DIR_DOWN,
	DIR_RIGHT,
	DIR_LEFT,
	DIR_MAX,
};

/// <summary>
/// 4近傍の単位ベクトル
/// </summary>
static const Vec2Int DIR_VEC[DIR_MAX]
{
	{ 0, -1 },
	{ 0, 1 },
	{ 1, 0 },
	{ -1, 0 },
};
