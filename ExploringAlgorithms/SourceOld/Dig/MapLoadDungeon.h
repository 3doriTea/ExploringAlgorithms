#pragma once
#include "Dungeon.h"
#include "../MapLoader.h"


/// <summary>
/// マップデータからダンジョンを生成する
/// </summary>
class MapLoadDungeon : public Dungeon
{
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="_mapLoader">読み込み済みのマップ</param>
	MapLoadDungeon(const MapLoader& _mapLoader);
	~MapLoadDungeon();

	/// <summary>
	/// ファイルからマップをロードして生成する
	/// </summary>
	void Generate() override;

private:
	const MapLoader& MAP_LOADER_;  // 参照するマップ
};
