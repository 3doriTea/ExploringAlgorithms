#pragma once
#include "../Library/GameObject.h"
#include "CellSheet.h"


class PainterColorMap;

/// <summary>
/// セルシートの内容を描画する
/// </summary>
class CellSheetPainter : public GameObject
{
public:
	CellSheetPainter();
	~CellSheetPainter();

	void Update() override;
	void Draw() override;

	/// <summary>
	/// セルシートを描画する
	/// </summary>
	/// <param name="_cellSheet"></param>
	/// <param name="_painterColorMap"></param>
	void Paint(const CellSheet& _cellSheet, const PainterColorMap& _painterColorMap);

private:
	CellSheet colorCellSheet_;  // カラーセルシート
};
