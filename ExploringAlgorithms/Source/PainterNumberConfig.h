#pragma once
#include <functional>

using IgnoreExpr = std::function<bool(int)>;

const IgnoreExpr EMPTY_IGNORE_EXPR{ [](int _) -> bool { return false; } };

class PainterNumberConfig
{
	friend class CellSheetPainter;

public:
	PainterNumberConfig();

	PainterNumberConfig& Reset() { expr_ = EMPTY_IGNORE_EXPR; return *this; }
	PainterNumberConfig& SetIgnore(const IgnoreExpr& _expr) { expr_ = _expr; return *this; }
	PainterNumberConfig& SetTextColor(const unsigned int _textColor) { textColor_ = _textColor; return *this; }


private:
	IgnoreExpr expr_;
	unsigned int textColor_;
};
