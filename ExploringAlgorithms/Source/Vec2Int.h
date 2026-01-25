#pragma once


/// <summary>
/// 2ŸŒ³ƒxƒNƒgƒ‹®”Œ^
/// </summary>
struct Vec2Int
{
	Vec2Int() :
		Vec2Int{ 0, 0 }
	{
	}

	Vec2Int(const int _x, const int _y) :
		x{ _x },
		y{ _y }
	{
	}

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

inline Vec2Int operator+(Vec2Int _left, Vec2Int _right)
{
	return Vec2Int{ _left } += _right;
}
