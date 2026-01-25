#pragma once
#include "CellSheet.h"
#include "IMazeViewer.h"
#include "RoadCellType.h"
#include "../Library/GameObject.h"


class Maze : public GameObject, public IMazeViewer
{
public:
	Maze();
	~Maze();

	void Draw() override;

	/// <summary>
	/// 迷路のサイズを取得する
	/// </summary>
	/// <returns>迷路のサイズ</returns>
	Vec2Int GetSize() const override;
	/// <summary>
	/// 迷路セル全体をリセットしつつ埋める
	/// </summary>
	/// <param name="_size">セルのサイズ</param>
	/// <param name="_fillValue">セルを埋める値</param>
	void ResetAndFill(const Vec2Int _size, int _fillValue);

	/// <summary>
	/// 迷路の開始地点をセットする
	/// </summary>
	/// <param name="_pos">迷路の開始地点</param>
	void SetStart(const Vec2Int _pos);
	/// <summary>
	/// 迷路のゴール地点をセットする
	/// </summary>
	/// <param name="_pos">迷路のゴール地点</param>
	void SetGoal(const Vec2Int _pos);
	/// <summary>
	/// 道の値をセットする
	/// </summary>
	/// <param name="_value">値</param>
	/// <param name="_pos">座標</param>
	void SetRoad(const int _value, const Vec2Int _pos);

	int GetRoadCost(const Vec2Int _pos) override;
	bool GetIsWall(const Vec2Int _pos) override;
	inline Vec2Int GetGoalPos() override { return goalPos_; }
	inline Vec2Int GetStartPos() override { return startPos_; }

private:
	CellSheet mazeCells_;   // 迷路情報
	CellSheet markCells_;   // マーカー情報
	Vec2Int startPos_;      // 迷路の開始地点
	Vec2Int goalPos_;       // 迷路のゴール地点
};
