#pragma once
#include "../Library/GameObject.h"


/// <summary>
/// ゴール時に表示するパネル
/// </summary>
class GoalPanel : public GameObject
{
public:
	GoalPanel();
	~GoalPanel();

	void Update() override;
	void Draw() override;

	/// <summary>
	/// 表示するコスト値をセットする
	/// </summary>
	/// <param name="_costValue">コスト値</param>
	inline void SetCostValue(const int _costValue) { costValue_ = _costValue; }
	/// <summary>
	/// 歩くタイルの数をセットする
	/// </summary>
	/// <param name="_tileCount">タイル数</param>
	inline void SetTileCount(const int _tileCount) { tileCount_ = _tileCount; }

private:
	float timeLeft_;  // 表示する残り時間
	int costValue_;   // コスト値
	int tileCount_;   // タイル数
	int hImage_;      // ゴールイメージ
};
