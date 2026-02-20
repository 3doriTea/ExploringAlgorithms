#pragma once
#include "AlgorithmPlayer.h"
#include <queue>
#include "RoadCost.h"


class BFS : public AlgorithmPlayer
{
public:
	using AlgorithmPlayer::AlgorithmPlayer;
	inline ~BFS() {}

	void Init() override;
	bool Step() override;

	void Draw(CellSheetPainter* _pPainter) override;

	/// <summary>
	/// 候補地のコストを取得する
	/// </summary>
	/// <returns>候補地のコスト(四近傍の最低コスト + 1)</returns>
	int GetFrontierCost(const Vec2Int _pos);
private:
	std::queue<Vec2Int> queue_;  // 解決に使うキュー
	RoadCost roadCost_;          // 移動コストの情報

	bool onceFinished_;  // 探索終了フラグ
};
