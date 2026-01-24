#include <iostream>
#include "DiggingDungeon.h"
#include <stack>

DiggingDungeon::~DiggingDungeon()
{
}

void DiggingDungeon::Generate()
{
	Dungeon::Generate();  // •Ç‚Æ‚©‰ŠúÝ’è

	FillAllTile(TileType::Wall);

	struct Vec2
	{
		int x;
		int y;

		static Vec2 Add(const Vec2 _a, const Vec2 _b)
		{
			return { _a.x + _b.x, _a.y + _b.y };
		}
		static Vec2 Dot(const Vec2 _v, const int _k)
		{
			return { _v.x * _k, _v.y * _k };
		}
	};

	enum Direction
	{
		UP,
		DOWN,
		LEFT,
		RIGHT,
		MAX,
	};

	const Vec2 DIR_TO_VEC[Direction::MAX]
	{
		{ 0, +1 },
		{ 0, -1 },
		{ -1, 0 },
		{ +1, 0 },
	};

	// 2‚Â‰œ‚Ü‚Å•Ç‚Å‚ ‚é‚©
	auto CheckDoubleWall
	{
		[this](const Vec2 _pos, const Vec2 _dir) -> bool
		{
			Vec2 d1{ Vec2::Add(_pos, Vec2::Dot(_dir, 1)) };
			Vec2 d2{ Vec2::Add(_pos, Vec2::Dot(_dir, 2)) };
			if (GetTile(d1.x, d1.y) != TileType::Wall)
			{
				return false;
			}

			if (GetTile(d2.x, d2.y) != TileType::Wall)
			{
				return false;
			}

			return true;
		}
	};

	static auto GetD1
	{
		[](const Vec2 _pos, const Vec2 _dir) -> Vec2
		{
			return Vec2::Add(_pos, Vec2::Dot(_dir, 1));
		}
	};
	static auto GetD2
	{
		[](const Vec2 _pos, const Vec2 _dir) -> Vec2
		{
			return Vec2::Add(_pos, Vec2::Dot(_dir, 2));
		}
	};

	auto Digging
	{
		[this](const Vec2 _pos, const Vec2 _dir) -> void
		{
			Vec2 d1{ GetD1(_pos, _dir) };
			Vec2 d2{ GetD2(_pos, _dir) };

			SetTile(TileType::None, d1.x, d1.y);
			SetTile(TileType::None, d2.x, d2.y);
		}
	};

	std::stack<Vec2> st{};

	Vec2 beginPos
	{
		random_.NextInt((GetWidth() - 1) / 2) * 2 + 1,
		random_.NextInt((GetHeight() - 1) / 2) * 2 + 1,
	};

	st.push(beginPos);

	while (!st.empty())
	{
		int dirOffset{ random_.NextInt(3) };
		for (int dirIndex = 0; dirIndex < MAX; dirIndex++)
		{
			int dir = (dirIndex + dirOffset) % MAX;
			if (CheckDoubleWall(st.top(), DIR_TO_VEC[dir]))
			{
				// 2‚Âæ‚Ü‚Å•Ç‚È‚çŒ@‚é
				Digging(st.top(), DIR_TO_VEC[dir]);
				
				Vec2 d2{ GetD2(st.top(), DIR_TO_VEC[dir]) };
				st.push(d2);  // Œ@‚Á‚Äi‚Þ
				break;
			}

			// ÅŒã‚Ü‚ÅŒ@‚ç‚È‚©‚Á‚½ == ‘S•ûˆÊ“¹‚¾I
			if (dirIndex == MAX - 1)
			{
				st.pop();  // ‚È‚ç1‚Â–ß‚é
			}
		}
	}

	SetTile(TileType::Start, 1, 1);
	SetTile(TileType::Goal, GetWidth() - 2, GetHeight() - 2);
}
