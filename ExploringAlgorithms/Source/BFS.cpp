#include "BFS.h"

void BFS::Init()
{
	stack_.push(GetStartPos());
	TrySetFrontier(GetStartPos());
}

void BFS::Step()
{
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

	Vec2Int drop{ stack_.top() };
	stack_.pop();

	TrySetChecked(drop);

	for (int d = 0; d < DIR_MAX; d++)
	{
		Vec2Int frontier{ drop + DIR_VEC[d] };
		if (GetIsWall(frontier))
		{
			continue;
		}

		if (TrySetFrontier(frontier))
		{
			stack_.push(frontier);
		}
	}

}
