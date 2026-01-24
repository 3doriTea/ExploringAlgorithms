#include "Dungeon.h"

Dungeon::Dungeon(const int _width, const int _height) :
	width_{ _width },
	height_{ _height },
	tiles_(_width * _height, TileType::None)
{
}

Dungeon::~Dungeon()
{
}

void Dungeon::Generate()
{
	ResetOuterWall();
	ResetPillarWall();
}

const Dungeon::TileType Dungeon::GetTile(const int _x, const int _y) const
{
	if (_x < 0 || width_ <= _x || _y < 0 || height_ <= _y)
	{
		return TileType::None;  // ”ÍˆÍŠO‚È‚ç‰½‚à‚È‚µ
	}

	const int INDEX{ _x + width_ * _y };
	return tiles_[INDEX];
}

void Dungeon::SetTile(const TileType _type, const int _x, const int _y)
{
	const int INDEX{ _x + width_ * _y };
	tiles_[INDEX] = _type;
}

void Dungeon::ResetOuterWall()
{
	for (int x = 0; x < width_; x++)
	{
		for (int y = 0; y < height_; y++)
		{
			if (x == 0 || x == width_ - 1 || y == 0 || y == height_ - 1)
			{
				SetTile(TileType::Wall, x, y);
			}
		}
	}
}

void Dungeon::ResetPillarWall()
{
	for (int x = 0; x < width_; x++)
	{
		for (int y = 0; y < height_; y++)
		{
			if (x % 2 == 0 && y % 2 == 0)
			{
				SetTile(TileType::Wall, x, y);
			}
		}
	}
}

void Dungeon::FillAllTile(const TileType _type)
{
	for (int x = 0; x < width_; x++)
	{
		for (int y = 0; y < height_; y++)
		{
			SetTile(_type, x, y);
		}
	}
}
