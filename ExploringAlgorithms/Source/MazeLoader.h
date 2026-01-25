#pragma once
#include "IncludingFileSystem.h"
#include "Vec2Int.h"


class Maze;

/// <summary>
/// 迷路を読み込むやつ
/// </summary>
class MazeLoader
{
public:
	MazeLoader(Maze& _maze);
	~MazeLoader();

	/// <summary>
	/// 試しに読み込む
	/// </summary>
	/// <param name="_mazeFile">ファイルパス</param>
	/// <returns>読み込みに成功 true / false</returns>
	bool TryLoad(const fs::path& _mazeFile);

private:
	/// <summary>
	/// セルの読み込み
	/// </summary>
	/// <param name="_c">セルの文字</param>
	/// <param name="_pos">セルの座標</param>
	void LoadCell(const char _c, const Vec2Int _pos);

	/// <summary>
	/// セルの文字 to セルの値
	/// </summary>
	/// <param name="_c">セルの文字</param>
	/// <returns>迷路の値</returns>
	int CellCharToValue(const char _c);

private:
	Maze& maze_;  // 読み込む迷路
};
