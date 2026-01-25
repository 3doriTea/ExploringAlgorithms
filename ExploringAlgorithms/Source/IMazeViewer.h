#pragma once
#include "Vec2Int.h"


/// <summary>
/// 迷路の読み取り専用インタフェース
/// </summary>
class IMazeViewer
{
public:
	inline IMazeViewer() {}
	inline virtual ~IMazeViewer() {}

	/// <summary>
	/// 道を通るコストを取得
	/// </summary>
	/// <param name="_pos">道の座標</param>
	/// <returns>コスト値</returns>
	virtual int GetRoadCost(const Vec2Int _pos) = 0;
	/// <summary>
	/// 壁であるか取得
	/// </summary>
	/// <param name="_pos">道の座標</param>
	/// <returns>壁である true / false</returns>
	virtual bool GetIsWall(const Vec2Int _pos) = 0;
	/// <summary>
	/// 迷路のゴール地点を取得
	/// </summary>
	/// <returns>ゴール地点の座標</returns>
	virtual Vec2Int GetGoalPos() = 0;
	/// <summary>
	/// 迷路の開始地点を取得
	/// </summary>
	/// <returns>スタート地点の座標を取得</returns>
	virtual Vec2Int GetStartPos() = 0;
};
