#include "CellSheetPainter.h"
#include "CellSheet.h"
#include "PainterColorMap.h"
#include "PainterNumberConfig.h"


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
	auto& valueToColor{ _painterColorMap.cellValueToColor_ };

	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			int value{ _cellSheet.At({ x, y }) };

			if (valueToColor.count(value) == 0)
			{
				continue;  // ŠÜ‚Ü‚ê‚Ä‚¢‚È‚¢‚È‚ç“h‚ç‚È‚¢
			}

			uint32_t color{ valueToColor.at(value)};
			Vec2Int begin{ config_.cellWidth * x, config_.cellWidth * y };
			Vec2Int end{ config_.cellWidth * (x + 1), config_.cellWidth * (y + 1) };

			DrawBox(begin.x, begin.y, end.x, end.y, color, TRUE);
		}
	}
}

void CellSheetPainter::Paint(const CellSheet& _cellSheet, const PainterNumberConfig& _config)
{
	Vec2Int size{ _cellSheet.GetSize() };
	
	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			int value{ _cellSheet.At({ x, y }) };

			if (_config.expr_(value))
			{
				continue;  // ŠÜ‚Ü‚ê‚Ä‚¢‚È‚¢‚È‚ç“h‚ç‚È‚¢
			}

			Vec2Int begin{ config_.cellWidth * x, config_.cellWidth * y };
			int textSizeX{};
			int textSizeY{};
			int lineCount{};
			GetDrawFormatStringSize(&textSizeX, &textSizeY, &lineCount, "%d", value);
		
			Vec2Int drawPos
			{
				begin.x + (config_.cellWidth - textSizeX) / 2,
				begin.y + (config_.cellWidth - textSizeY) / 2
			};

			DrawFormatString(drawPos.x, drawPos.y, _config.textColor_, "%d", value);
		}
	}
}
