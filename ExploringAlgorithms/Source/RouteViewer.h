#pragma once
#include "../Library/GameObject.h"
#include "CellSheet.h"


/// <summary>
/// 最適なルートを表示するやつ
/// </summary>
class RouteViewer : public GameObject
{
public:
	RouteViewer(const CellSheet* _pCellSheet);
	~RouteViewer();

	/// <summary>
	/// 更新
	/// </summary>
	void Update() override;

	/// <summary>
	/// 描画
	/// </summary>
	void Draw() override;

private:
	const CellSheet* pCellSheet_;

};
