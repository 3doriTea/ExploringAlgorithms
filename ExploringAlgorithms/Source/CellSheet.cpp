#include "CellSheet.h"
#include <cassert>


CellSheet::CellSheet(const Vec2Int _size, const int _fillValue) :
	size_{ _size },
	flattened_{ std::vector<int>(_size.x * _size.y, _fillValue) }
{
}

CellSheet::~CellSheet()
{
}

bool CellSheet::IsOutSide(const Vec2Int _pos)
{
	int index{ _pos.x + _pos.y * size_.x };
	return index < 0 || flattened_.size() <= index;
}

int& CellSheet::At(const Vec2Int _pos)
{
	int index{ _pos.x + _pos.y * size_.x };

	assert(0 <= index && index < flattened_.size()
		&& "セルシートの範囲外にアクセスされます。");

	return flattened_.at(index);
}

int CellSheet::At(const Vec2Int _pos) const
{
	int index{ _pos.x + _pos.y * size_.x };

	assert(0 <= index && index < flattened_.size()
		&& "セルシートの範囲外にアクセスされます。");

	return flattened_.at(index);
}
