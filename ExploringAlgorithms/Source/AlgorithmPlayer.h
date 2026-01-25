#pragma once
#include "../Library/GameObject.h"
#include "CellSheet.h"


class IMazeViewer;

class AlgorithmPlayer : public GameObject
{
public:
	struct Config
	{
		float deltaTimeSec;     // フレーム間時間秒
		float stepIntervalSec;  // 1ステップの間隔秒
	};

public:
	AlgorithmPlayer(const Config& _config, IMazeViewer& _mazeView);
	inline virtual ~AlgorithmPlayer() {}

	void Update() override final;
	void Draw() override final;

	virtual void Init() = 0;
	virtual bool Step() = 0;

	int GetRoadCost(const Vec2Int _pos) const;
	bool GetIsWall(const Vec2Int _pos);
	Vec2Int GetGoalPos();
	Vec2Int GetStartPos();
	Vec2Int GetSize() const;
	/// <summary>
	/// 確認済みセルをセットする
	/// </summary>
	/// <param name="_pos">セルの座標</param>
	/// <returns>セットに成功 true / false</returns>
	bool TrySetChecked(const Vec2Int _pos);
	/// <summary>
	/// 候補セルをセットする
	/// </summary>
	/// <param name="_pos">セルの座標</param>
	/// <returns>セットに成功 true / false</returns>
	bool TrySetFrontier(const Vec2Int _pos);

private:
	bool initialized_;
	bool completed_;
	float timeLeftSec_;
	Config config_;
	IMazeViewer& mazeView_;
	CellSheet checkedSheet_;  // チェックするセルシート
};
