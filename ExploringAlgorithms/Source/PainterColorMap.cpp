#include "PainterColorMap.h"
#include <cassert>


PainterColorMap& PainterColorMap::Reset()
{
	cellValueToColor_.clear();

	return *this;
}

PainterColorMap& PainterColorMap::Set(const int _value, const Color _color)
{
	assert(cellValueToColor_.count(_value) == 0 && "ä˘Ç…í«â¡Ç≥ÇÍÇƒÇ¢Ç‹Ç∑ÅB");

	cellValueToColor_.insert({ _value, _color });

	return *this;
}
