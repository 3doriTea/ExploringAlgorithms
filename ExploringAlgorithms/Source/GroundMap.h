#pragma once
#include "../Library/GameObject.h"
#include "CellSheet.h"
#include <array>


enum : size_t
{
	TILE_WALL,
	TILE_GROUND,
	TILE_WATER,
	TILE_LAVA,
	TILE_MAX
};

static constexpr size_t TILE_COUNT{ TILE_MAX };

static const int TILE_NUM_OFFSET{ -1 };


class GroundMap : public GameObject
{
public:
	GroundMap();
	~GroundMap();

	void Update() override;
	void Draw() override;

	Vec2Int GetDrawPosition(Vec2Int _worldPos);

	double GetExtendRate() const;

	Vec2Int GetTilePosition(Vec2Int _position);
	bool IsWall(Vec2Int _tilePosition);

	Vec2Int GetTileWidth() const { return tileWidth_; }

private:
	CellSheet cellSheet_;
	Vec2Int offset_;
	Vec2Int tileWidth_;

	std::array<int, TILE_COUNT> hTileImages_;
};
