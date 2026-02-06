#pragma once
#include <functional>
#include "../Library/GameObject.h"
#include "CellSheet.h"


class PainterColorMap;
class PainterNumberConfig;

constexpr auto DEFAULT_ON_DRAW
{
	[](Vec2Int begin, Vec2Int end, uint32_t color)
	{
		DrawBox(begin.x, begin.y, end.x, end.y, color, TRUE);
	}
};

/// <summary>
/// セルシートの内容を描画する
/// </summary>
class CellSheetPainter : public GameObject
{
public:
	/// <summary>
	/// 描画の設定
	/// </summary>
	struct Config
	{
		Config(int _cellWidth) :
			cellWidth{ _cellWidth }
		{
		}

		int cellWidth;
	};
public:
	CellSheetPainter(const Config& _config);
	~CellSheetPainter();

	void Update() override;
	void Draw() override;

	/// <summary>
	/// セルシートを描画する
	/// </summary>
	/// <param name="_cellSheet">シート</param>
	/// <param name="_painterColorMap"></param>
	/// <param name="_onDraw">void(開始点, 終了点, 色)</param>
	void Paint(
		const CellSheet& _cellSheet,
		const PainterColorMap& _painterColorMap,
		const std::function<void(Vec2Int, Vec2Int, uint32_t)> _onDraw = DEFAULT_ON_DRAW);
	/// <summary>
	/// セルシートの値を描画する
	/// </summary>
	/// <param name="_cellSheet">シート</param>
	void Paint(const CellSheet& _cellSheet, const PainterNumberConfig& _config);

private:
	Config config_;
	//CellSheet colorCellSheet_;  // カラーセルシート
};
