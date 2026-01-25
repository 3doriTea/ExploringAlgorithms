#pragma once
#include "AlgorithmPlayer.h"

class AStr : public AlgorithmPlayer
{
public:
	using AlgorithmPlayer::AlgorithmPlayer;
	inline ~AStr() {}

	void Step() override;

private:

};
