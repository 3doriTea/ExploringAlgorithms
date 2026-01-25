#pragma once
#include "AlgorithmPlayer.h"
#include <stack>


class BFS : public AlgorithmPlayer
{
public:
	using AlgorithmPlayer::AlgorithmPlayer;
	inline ~BFS() {}

	void Init() override;
	void Step() override;

private:
	std::stack<Vec2Int> stack_;
};
