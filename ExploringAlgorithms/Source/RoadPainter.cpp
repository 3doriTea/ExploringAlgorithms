#include "RoadPainter.h"
#include "DxLib.h"
#include "Dig/DungeonViewer.h"

RoadPainter::RoadPainter()
{
}

RoadPainter::~RoadPainter()
{
}

void RoadPainter::Draw()
{
	const int WALL_SIZE{ DungeonViewer::WALL_SIZE };
	for (auto& history : history_)
	{
		int x{ history.pos.x };
		int y{ history.pos.y };
		DrawBox(x * WALL_SIZE, y * WALL_SIZE, (x + 1) * WALL_SIZE, (y + 1) * WALL_SIZE, history.color, TRUE);
	}
}

void RoadPainter::Add(const Vec2Int _pos, const PaintType _paintType)
{
	switch (_paintType)
	{
	case PT_NEXT:
		history_.emplace_back(_pos, 0x00ffff);
		break;
	case PT_CHECKED:
	default:
		history_.emplace_back(_pos, 0x0000ff);
		break;
	}
}

bool RoadPainter::IsPainted(const Vec2Int _pos) const
{
	for (auto& [pos, color] : history_)
	{
		if (pos.x == _pos.x && pos.y == _pos.y)
		{
			return true;
		}
	}
	return false;
}
