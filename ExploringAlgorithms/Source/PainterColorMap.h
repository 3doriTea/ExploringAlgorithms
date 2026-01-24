#pragma once
#include <map>
#include <cstdint>


/// <summary>
/// セルシートを描画する色の組み合わせマップ
/// </summary>
class PainterColorMap
{
	friend class CellSheetPainter;
public:
	using Color = uint32_t;

	/// <summary>
	/// リセットする
	/// </summary>
	/// <returns></returns>
	PainterColorMap& Reset();

	/// <summary>
	/// マップに値をセットする
	/// </summary>
	/// <param name="_value">セルの値</param>
	/// <param name="_color">描画する色</param>
	/// <returns></returns>
	PainterColorMap& Set(const int _value, const Color _color);

private:
	std::map<int, Color> cellValueToColor_;  // セルの値 to 色
};
