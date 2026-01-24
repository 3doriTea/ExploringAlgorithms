#pragma once
#include <vector>

/// <summary>
/// ダンジョンのデータクラス
/// </summary>
class Dungeon
{
public:
	enum struct TileType : int
	{
		None,  // 道 (なにもなし)
		Wall,  // 壁
		Start,
		Goal,
		WeightZero,  // 重み
		_0,
		_1,
		_2,
		_3,
		_4,
		_5,
		_6,
		_7,
		_8,
		_9,
	};

public:
	Dungeon(const int _width, const int _height);
	~Dungeon();

public:
	virtual void Generate();

	/// <summary>
	/// 指定のタイルタイプを取得する
	/// </summary>
	/// <param name="_x"></param>
	/// <param name="_y"></param>
	/// <returns></returns>
	const TileType GetTile(const int _x, const int _y) const;

	/// <summary>
	/// 横幅を取得する
	/// </summary>
	/// <returns>横幅</returns>
	const int GetWidth() const { return width_; }
	/// <summary>
	/// 高さを取得する
	/// </summary>
	/// <returns>高さ</returns>
	const int GetHeight() const { return height_; }
protected:
	/// <summary>
	/// タイルをセットする
	/// </summary>
	/// <param name="_type">タイルの種類</param>
	/// <param name="_x"></param>
	/// <param name="_y"></param>
	void SetTile(const TileType _type, const int _x, const int _y);

	/// <summary>
	/// 必ず外側が壁であるようにリセットする
	/// </summary>
	void ResetOuterWall();
	/// <summary>
	/// 必ず奇数位置が壁であるようにリセットする
	/// </summary>
	void ResetPillarWall();

	/// <summary>
	/// 全部を埋める
	/// </summary>
	/// <param name="_type">埋めるタイル</param>
	void FillAllTile(const TileType _type);

private:
	std::vector<TileType> tiles_;  // タイルのデータ
	int width_;   // 横幅
	int height_;  // 高さ
};

