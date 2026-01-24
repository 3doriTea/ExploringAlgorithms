#pragma once
#include <stdexcept>
#include "../Library/GameObject.h"
#include "Vec2Int.h"
#include "RoadPainter.h"
#include "IDataList.h"
#include "CellInfo.h"

class DungeonViewer;

class DijkstraPlayer : public GameObject
{
public:
	DijkstraPlayer(DungeonViewer& _pDungeonViewer, IDataList<Cell*>* _pResolution);
	~DijkstraPlayer();

	void Update() override {}
	void Draw() override;

	void Step();

	/// <summary>
	/// 座標をインデクスに変換する
	/// </summary>
	/// <param name="_pos">座標</param>
	/// <returns>インデクス</returns>
	int PosToIndex(const Vec2Int _pos);
	/// <summary>
	/// インデクスを座標に変換する
	/// </summary>
	/// <param name="_index">インデクス</param>
	/// <returns>座標</returns>
	Vec2Int IndexToPos(const int _index);

	/// <summary>
	/// コンプリートしたか
	/// </summary>
	/// <returns>コンプリートした true / false</returns>
	inline bool IsComplete() { return pResolution_->Empty(); }

private:
	DungeonViewer& pDungeonViewer_;
	RoadPainter roadPainter_;

	Vec2Int mapSize_;
	std::vector<Cell> cells_;
	//std::queue<Cell*> resolution_;
	IDataList<Cell*>* pResolution_;
};
