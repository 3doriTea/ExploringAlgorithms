#pragma once
#include "../Library/GameObject.h"
#include "CellSheet.h"


class PainterColorMap;
class PainterNumberConfig;

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
	void Paint(const CellSheet& _cellSheet, const PainterColorMap& _painterColorMap);
	/// <summary>
	/// セルシートの値を描画する
	/// </summary>
	/// <param name="_cellSheet">シート</param>
	void Paint(const CellSheet& _cellSheet, const PainterNumberConfig& _config);

private:
	Config config_;
	//CellSheet colorCellSheet_;  // カラーセルシート
};
