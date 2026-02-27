#pragma once
#include "../Library/GameObject.h"
#include "Vec2Int.h"
#include "Pin.h"


class AI : public GameObject
{
public:
	AI();
	~AI();

	void Update() override;
	void Draw() override;

private:
	Vec2Int targetPos_;
	double angle_;
	Vec2Int pos_;

	int hImage_;  // AIの画像

	struct Status
	{
		float walkSpeed;  // 歩くスピード
	} status;

	Pin pin_;  // 目的地ピン
};
