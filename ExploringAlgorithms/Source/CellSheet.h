#pragma once
#include "Vec2Int.h"
#include <vector>

/// <summary>
/// セルのシート
/// </summary>
class CellSheet
{
public:
	CellSheet(const Vec2Int _size);
	~CellSheet();

	/// <summary>
	/// セルの値を参照する
	/// </summary>
	/// <param name="_pos">セルの座標</param>
	/// <returns>セルの値参照</returns>
	int& At(const Vec2Int _pos);

	/// <summary>
	/// セルシートのサイズを取得
	/// </summary>
	/// <returns>サイズ xy</returns>
	Vec2Int GetSize() const { return size_; }

private:
	Vec2Int size_;                // サイズ
	std::vector<int> flattened_;  // 1次元配列で管理する数値
};

