#pragma once
#include "Dungeon.h"
#include "Randomer.h"

/// <summary>
/// 穴掘り法によるダンジョン生成
/// </summary>
class DiggingDungeon : public Dungeon
{
public:
	using Dungeon::Dungeon;
	~DiggingDungeon();

	/// <summary>
	/// 穴掘り法でダンジョンを生成する
	/// </summary>
	void Generate() override;

private:
	Randomer random_;
};
