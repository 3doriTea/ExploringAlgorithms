#pragma once
#include "AlgorithmPlayer.h"
#include <stack>


class DFS : public AlgorithmPlayer
{
public:
	using AlgorithmPlayer::AlgorithmPlayer;
	inline ~DFS() {}

	void Init() override;
	bool Step() override;

private:
	std::stack<Vec2Int> stack_;
};
