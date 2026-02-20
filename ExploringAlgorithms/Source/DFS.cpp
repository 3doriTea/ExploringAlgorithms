#include "DFS.h"

void DFS::Init()
{
	stack_.push(GetStartPos());
	TrySetFrontier(GetStartPos());
}

bool DFS::Step()
{
	if (stack_.empty())
	{
		return true;  // スタックが空なら探索完了
	}

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

	return false;
}
