#include "GoalPanel.h"

constexpr int* _{ nullptr };

namespace
{
	const std::string GOAL_PANEL_FILE{ "Data/Goal.png" };
	const POINT DRAW_POSITION{ 0, 0 };
	const POINT TEXT_OFFSET{ 0, 10 };
	const uint32_t TEXT_COLOR{ 0xFF0000 };
	const std::string TEXT_FORMAT
	{
		"歩くタイル数:%d\n"
		"歩くコスト値:%d\n"
	};
	const float SHOW_TOTAL_TIME{ 5.0f };
	const float EASE_IN_TIME{ 0.5f };
	const float EASE_OUT_TIME{ 0.5f };
}

GoalPanel::GoalPanel() :
	timeLeft_{ SHOW_TOTAL_TIME },
	costValue_{ -1 },
	tileCount_{ -1 },
	hImage_{ -1 }
{
	hImage_ = LoadGraph(GOAL_PANEL_FILE.c_str());
}

GoalPanel::~GoalPanel()
{
}

void GoalPanel::Update()
{
}

void GoalPanel::Draw()
{
	DrawGraph(DRAW_POSITION.x, DRAW_POSITION.y, hImage_, TRUE);

	int textOffsetY{};
	GetGraphSize(hImage_, _, &textOffsetY);

	DrawFormatString(DRAW_POSITION.x, DRAW_POSITION.y + textOffsetY, TEXT_COLOR, TEXT_FORMAT.c_str(), tileCount_, costValue_);
}
