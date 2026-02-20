#pragma once
#include "CellSheet.h"

class RoadCost
{
public:
	RoadCost();
	~RoadCost();

	/// <summary>
	/// セルがコストを持っているか取得
	/// </summary>
	/// <param name="_pos">セルの座標</param>
	/// <returns>持っている true / false</returns>
	bool HasCost(const Vec2Int _pos);

	/// <summary>
	/// <para>セルのコストを確実に取得する</para>
	/// <para>コストが無い可能性があるならHasCostでチェック！</para>
	/// </summary>
	/// <param name="_pos"></param>
	/// <returns></returns>
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
