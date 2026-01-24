#pragma once
//#include 

/// <summary>
/// セルから見た方向
/// </summary>
enum DIRECTION
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	MAX
};

/// <summary>
/// セルの情報
/// </summary>
struct Cell
{
	bool checked_;  // 既にチェックしたセルか
	bool isWall_;  // セルが壁であるか
	int cost_{};  // セルへ移動するコスト
	
	Cell* pNeighbor[DIRECTION::MAX];  // 隣のセルのポインタ
	Vec2Int pos_;  // セルの座標
};
