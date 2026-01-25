#pragma once
#include "CellSheet.h"
#include "IMazeViewer.h"
#include "CellType.h"


class Maze : public IMazeViewer
{
public:
	Maze();
	~Maze();

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
	inline void SetStart(const Vec2Int _pos) { startPos_ = _pos; }
	/// <summary>
	/// 迷路のゴール地点をセットする
	/// </summary>
	/// <param name="_pos">迷路のゴール地点</param>
	inline void SetGoal(const Vec2Int _pos) { goalPos_ = _pos; }

	int GetRoadCost(const Vec2Int _pos) override;
	bool GetIsWall(const Vec2Int _pos) override;
	inline Vec2Int GetGoalPos() override { return goalPos_; }
	inline Vec2Int GetStartPos() override { return startPos_; }

private:
	CellSheet cells_;   // 迷路情報
	Vec2Int startPos_;  // 迷路の開始地点
	Vec2Int goalPos_;
	// 迷路のゴール地点
};
