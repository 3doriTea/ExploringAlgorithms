#include "RouteViewer.h"
#include "PainterColorMap.h"
#include "CellSheetPainter.h"
#include <stack>

enum MARK
{
	M_NONE,  // 歩かなかった
	M_WALK,  // 歩いた
	M_CHECKED,
};

RouteViewer::RouteViewer(const CellSheet* _pCellSheet) :
	pCellSheet_{ _pCellSheet },
	route_{ _pCellSheet->GetSize(), M_NONE }
{
	using Cost = int;
	using Pos = Vec2Int;

	std::stack<std::pair<Cost, Pos>> st{};

	Vec2Int pos{ pCellSheet_->GetSize() + Vec2Int{ -2, -2 } };
	// ゴール地点の値を取得
	int cost{ pCellSheet_->At(pos) };
	st.push({ cost, pos });
	route_.At(pos) = M_WALK;

	enum DIR_TYPE
	{
		DIR_UP,
		DIR_DOWN,
		DIR_RIGHT,
		DIR_LEFT,
		DIR_MAX,
	};

	static const Vec2Int DIR_VEC[DIR_MAX]
	{
		{ 0, -1 },
		{ 0, 1 },
		{ 1, 0 },
		{ -1, 0 },
	};

	while (!st.empty())
	{
		// 先頭を取り出して消す
		auto& [cost, pos] { st.top() };
		st.pop();

		for (int dir = DIR_UP; dir < DIR_MAX; dir++)
		{
			Vec2Int nextPos{ pos + DIR_VEC[dir] };  // 次に確認する座標
			
			if (route_.IsOutSide(nextPos) ||
				route_.At(nextPos) != M_NONE)
			{  // 次にいく地が未開の地ではないなら無視
				continue;
			}

			int requestCost{ cost - 1 };  // 理想のコスト
			if (pCellSheet_->At(nextPos) >= 0 &&
				pCellSheet_->At(nextPos) <= requestCost)
			{
				st.push({ pCellSheet_->At(nextPos), nextPos });
				route_.At(nextPos) = M_WALK;
			}
		}
	}

	SetDrawOrder(-10000);
}

RouteViewer::~RouteViewer()
{
}

void RouteViewer::Update()
{

}

void RouteViewer::Draw()
{
	CellSheetPainter* pPainter{ FindGameObject<CellSheetPainter>() };
	pPainter->Paint(
		route_,
		PainterColorMap{}
		.Reset()
		.Set(M_WALK, 0xff00ff),
		[](Vec2Int begin, Vec2Int end, uint32_t color)
		{
			DrawBox(begin.x, begin.y, end.x, end.y, color, FALSE, 4);
		}
	);
}
