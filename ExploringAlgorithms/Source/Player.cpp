#include "Player.h"
#include "Dig/DungeonViewer.h"


Player::Player(DungeonViewer& _pDungeonViewer, IDataList<Cell*>* _pResolution) :
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
			.pNeighbor = { nullptr },
			.pos_ = { -1, -1 },
		});
	pResolution_->In(&cells_[PosToIndex({ 1, 1 })]);

	for (int y = 0; y < mapSize_.y; y++)
	{
		for (int x = 0; x < mapSize_.x; x++)
		{
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

	// ‹ß–T‚ÌƒZƒ‹ŽQÆ‚ðÝ’è‚·‚é
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

Player::~Player()
{
}

void Player::Update()
{
	
}

void Player::Draw()
{
	roadPainter_.Draw();

	/*const int WIDTH{ 5 };
	for (int i = 0; i < cells_.size(); i++)
	{
		DrawBox(cells_[i].pos_.x * WIDTH, cells_[i].pos_.y * WIDTH, (cells_[i].pos_.x + 1) * WIDTH, (cells_[i].pos_.y + 1) * WIDTH,
			cells_[i].isWall_ ? 0xff00ff : 0xff0000, TRUE);
	}*/
}

void Player::Step()
{
	if (pResolution_->Empty())
	{
		return;
	}

	Cell& currentCell{ *pResolution_->Out() };

	roadPainter_.Add(currentCell.pos_);

	currentCell.checked_ = true;
	for (int d = 0; d < DIRECTION::MAX; d++)
	{
		if (currentCell.pNeighbor[d] && !currentCell.pNeighbor[d]->checked_ && !currentCell.pNeighbor[d]->isWall_)
		{
			roadPainter_.Add(currentCell.pNeighbor[d]->pos_, PT_NEXT);
			pResolution_->In(currentCell.pNeighbor[d]);  // ->pNeighbor[d]
		}
	}
}

int Player::PosToIndex(const Vec2Int _pos)
{
	return _pos.x + _pos.y * mapSize_.x;
}

Vec2Int Player::IndexToPos(const int _index)
{
	return Vec2Int{ .x = _index % mapSize_.x, .y = _index / mapSize_.x };
}
