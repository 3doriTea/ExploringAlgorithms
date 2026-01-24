#pragma once
#include <vector>
#include "Vec2Int.h"

enum PaintType
{
	PT_CHECKED,
	PT_NEXT,
};

class RoadPainter
{
private:
	struct PaintCell
	{
		Vec2Int pos;
		int color;
	};

public:
	RoadPainter();
	~RoadPainter();

	void Draw();
	void Add(const Vec2Int _pos, const PaintType _paintType = PaintType::PT_CHECKED);

	/// <summary>
	/// “h‚ç‚ê‚Ä‚¢‚é‚©æ“¾
	/// </summary>
	/// <param name="_pos">w’èÀ•W</param>
	/// <returns>“h‚ç‚ê‚Ä‚¢‚é true / false</returns>
	bool IsPainted(const Vec2Int _pos) const;

private:
	std::vector<PaintCell> history_;
};
