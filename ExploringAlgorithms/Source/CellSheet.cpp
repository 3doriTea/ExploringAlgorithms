#include "CellSheet.h"
#include <cassert>


CellSheet::CellSheet(const Vec2Int _size) :
	size_{ _size },
	flattened_{ std::vector<int>(_size.x * _size.y, 0) }
{
}

CellSheet::~CellSheet()
{
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
