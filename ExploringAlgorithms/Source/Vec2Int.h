#pragma once


/// <summary>
/// 2ŸŒ³ƒxƒNƒgƒ‹®”Œ^
/// </summary>
struct Vec2Int
{
	int x;
	int y;

	inline Vec2Int& operator*=(const int _v)
	{
		this->x *= _v;
		this->y *= _v;

		return *this;
	}

	inline Vec2Int& operator+=(const Vec2Int& _other)
	{
		this->x += _other.x;
		this->y += _other.y;

		return *this;
	}
};

Vec2Int operator+(Vec2Int _left, Vec2Int _right)
{
	return _left += _right;
}
