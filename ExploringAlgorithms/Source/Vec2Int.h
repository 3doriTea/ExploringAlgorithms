#pragma once

struct Vec2Int
{
	int x;
	int y;

	inline Vec2Int Mul(const int _v) const
	{
		return { x * _v, y * _v };
	}
	inline Vec2Int Add(const Vec2Int _other) const
	{
		return { x + _other.x, y + _other.y };
	}
};
