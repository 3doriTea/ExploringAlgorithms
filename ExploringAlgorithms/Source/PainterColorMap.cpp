#include "PainterColorMap.h"
#include <cassert>


PainterColorMap& PainterColorMap::Reset()
{
	cellValueToColor_.clear();
}

PainterColorMap& PainterColorMap::Set(const int _value, const Color _color)
{
	assert(cellValueToColor_.count(_value) > 0 && "Šù‚É’Ç‰Á‚³‚ê‚Ä‚¢‚Ü‚·B");

	cellValueToColor_.emplace(_value, _color);
}
