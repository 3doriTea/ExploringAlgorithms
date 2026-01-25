#include "CellSheetPainter.h"
#include "CellSheet.h"
#include "PainterColorMap.h"

CellSheetPainter::CellSheetPainter(const Config& _config) :
	config_{ _config }
{
}

CellSheetPainter::~CellSheetPainter()
{
}

void CellSheetPainter::Update()
{
}

void CellSheetPainter::Draw()
{
}

void CellSheetPainter::Paint(const CellSheet& _cellSheet, const PainterColorMap& _painterColorMap)
{
	Vec2Int size{ _cellSheet.GetSize() };
	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			uint32_t color{ _painterColorMap.cellValueToColor_.at(_cellSheet.At({ x, y }))};
			Vec2Int begin{ config_.cellWidth * x, config_.cellWidth * y };
			Vec2Int end{ config_.cellWidth * (x + 1), config_.cellWidth * (y + 1) };

			DrawBox(begin.x, begin.y, end.x, end.y, color, TRUE);
		}
	}
}
