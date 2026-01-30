#pragma once
#include "CellSheet.h"

class RoadCost
{
public:
	RoadCost();
	~RoadCost();

	int GetCost(const Vec2Int _pos);
	/// <summary>
	/// 1つのセルに対するコスト
	/// </summary>
	/// <param name="_cost">1つのセルにセットするコスト</param>
	/// <param name="_pos">セルの座標</param>
	void SetCostUnitCell(const int _cost, const Vec2Int _pos);
	/// <summary>
	/// セルのコストを設定する
	/// </summary>
	/// <param name="_cost">セルのコスト</param>
	/// <param name="_pos">セルの座標</param>
	void SetCost(const int _cost, const Vec2Int _pos);

	/// <summary>
	/// コスト表をリセットする
	/// </summary>
	/// <param name="_size">シートのサイズ</param>
	void Reset(const Vec2Int _size);

	/// <summary>
	/// セルシートを参照する
	/// </summary>
	/// <returns>const 参照</returns>
	const CellSheet& GetRefCellSheet() const { return cells_; }

private:
	CellSheet cells_;
	static const int UNKNOWN_COST;
};
