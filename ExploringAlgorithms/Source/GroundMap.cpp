#include "GroundMap.h"
#include "RoadCellType.h"
#include <cassert>


namespace
{
	static const Vec2Int MAP_SIZE{ 30, 15 };
	static const std::string TILE_IMAGE_FILE_PATH[TILE_MAX]
	{
		"Data/TileWall.png",
		"Data/TileGround.png",
		"Data/TileWater.png",
		"Data/TileLava.png",
	};
	static const int TILE_IMAGE_WIDTH{ 32 };
}

GroundMap::GroundMap() :
	cellSheet_{ MAP_SIZE, RoadCellType::ROAD_COST_0 },
	offset_{ 16, 16 },
	tileWidth_{ 32, 32 },
	hTileImages_{}
{
	for (int i = 0; i < TILE_MAX; i++)
	{
		hTileImages_[i] = LoadGraph(TILE_IMAGE_FILE_PATH[i].c_str());
		assert(hTileImages_[i] > 0
			&& "タイル画像ファイルの読み込みに失敗");
	}
}

GroundMap::~GroundMap()
{
}

void GroundMap::Update()
{
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		Vec2Int mousePos{};
		GetMousePoint(&mousePos.x, &mousePos.y);

		Vec2Int selectTile
		{
			(mousePos.x) / tileWidth_.x,
			(mousePos.y) / tileWidth_.y
		};
		
		int setRoadCellType{ RoadCellType::ROAD_COST_0 };
		if (CheckHitKey(KEY_INPUT_1))
		{
			setRoadCellType = RoadCellType::WALL;
		}
		else if (CheckHitKey(KEY_INPUT_2))
		{
			setRoadCellType = RoadCellType::ROAD_COST_1;
		}
		else if (CheckHitKey(KEY_INPUT_3))
		{
			setRoadCellType = RoadCellType::ROAD_COST_2;
		}

		if (!cellSheet_.IsOutSide(selectTile))
		{
			cellSheet_.At(selectTile) = setRoadCellType;
		}
	}

	Vec2Int size{ cellSheet_.GetSize() };
	Vec2Int pos{};
	for (pos.y = 0; pos.y < size.y; pos.y++)
	{
		for (pos.x = 0; pos.x < size.x; pos.x++)
		{
			if (0 < pos.x && pos.x < size.x - 1
				&& 0 < pos.y && pos.y < size.y - 1)
			{
				continue;
			}

			cellSheet_.At(pos) = RoadCellType::WALL;
		}
	}
}

void GroundMap::Draw()
{
	const Vec2Int SIZE{ cellSheet_.GetSize() };

	static const double ANGLES[]
	{
		DX_TWO_PI * 0,
		DX_TWO_PI * 0.25,
		DX_TWO_PI * 0.5,
		DX_TWO_PI * 0.75,
	};

	Vec2Int pos{};
	for (pos.y = 0; pos.y < SIZE.y; pos.y++)
	{
		for (pos.x = 0; pos.x < SIZE.x; pos.x++)
		{
			const int HANDLE{ hTileImages_.at(cellSheet_.At(pos) - TILE_NUM_OFFSET) };

			int random{ rand() % 8 };
			DrawRotaGraph(
				pos.x * tileWidth_.x + offset_.x,
				pos.y * tileWidth_.y + offset_.y,
				tileWidth_.x / TILE_IMAGE_WIDTH,
				ANGLES[random % 4],
				HANDLE,
				TRUE,
				random % 2,
				random > 4
			);
		}
	}
}

Vec2Int GroundMap::GetDrawPosition(Vec2Int _worldPos)
{
	return
	{
		_worldPos.x + offset_.x,
		_worldPos.y + offset_.y,
	};
}

double GroundMap::GetExtendRate() const
{
	return tileWidth_.x / TILE_IMAGE_WIDTH;
}

Vec2Int GroundMap::GetTilePosition(Vec2Int _position)
{
	return
	{
		_position.x / tileWidth_.x,
		_position.y / tileWidth_.y,
	};
}

bool GroundMap::IsWall(Vec2Int _tilePosition)
{
	if (cellSheet_.IsOutSide(_tilePosition))
	{
		return true;  // 範囲外なら問答無用で壁
	}
	return cellSheet_.At(_tilePosition) == RoadCellType::WALL;
}
