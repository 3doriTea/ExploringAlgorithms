#include "DijkstraPlayer.h"
#include "Dig/DungeonViewer.h"


DijkstraPlayer::DijkstraPlayer(DungeonViewer& _pDungeonViewer, IDataList<Cell*>* _pResolution) :
	pDungeonViewer_{ _pDungeonViewer },
	roadPainter_{},
	cells_{},
	pResolution_{ _pResolution }
{
	SetDrawOrder(-100);

	mapSize_ = _pDungeonViewer.GetSize();
	cells_.resize(mapSize_.x * mapSize_.y, Cell
		{
			.checked_ = false,
			.isWall_ = false,
			.cost_ = 0,
			.pNeighbor = { nullptr },
			.pos_ = { -1, -1 },
		});

	for (int y = 0; y < mapSize_.y; y++)
	{
		for (int x = 0; x < mapSize_.x; x++)
		{
			cells_[PosToIndex({ x, y })].cost_ = _pDungeonViewer.GetCost(x, y);
			cells_[PosToIndex({ x, y })].isWall_ = _pDungeonViewer.IsWall(x, y);
			cells_[PosToIndex({ x, y })].pos_ = { x, y };
		}
	}

	const Vec2Int DIR[MAX]
	{
		{ 0, 1 },
		{ 0, -1 },
		{ -1, 0 },
		{ 1, 0 },
	};

	// 近傍のセル参照を設定する
	for (int y = 1; y < mapSize_.y - 1; y++)
	{
		for (int x = 1; x < mapSize_.x - 1; x++)
		{
			for (int d = 0; d < DIRECTION::MAX; d++)
			{
				cells_[PosToIndex({ x, y })].pNeighbor[d] = &cells_[PosToIndex(Vec2Int{ x, y }.Add(DIR[d]))];
			}
		}
	}
}

DijkstraPlayer::~DijkstraPlayer()
{
}

void DijkstraPlayer::Draw()
{
	roadPainter_.Draw();
}

void DijkstraPlayer::Step()
{
	// ダイクストラ法で頂点を再構築
	std::vector<int> p{};
	// 前の頂点

	// 昇順で取り出す

	// qが空になるまで繰り返す

	// q先頭の距離
}

int DijkstraPlayer::PosToIndex(const Vec2Int _pos)
{
	return _pos.x + _pos.y * mapSize_.x;
}

Vec2Int DijkstraPlayer::IndexToPos(const int _index)
{
	return Vec2Int{ .x = _index % mapSize_.x, .y = _index / mapSize_.x };
}
