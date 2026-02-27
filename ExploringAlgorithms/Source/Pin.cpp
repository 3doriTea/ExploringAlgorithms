#include "Pin.h"


namespace
{
	static const float ANIM_TOTAL_TIME{ 0.5f };
	static const float MAX_RADIUS{ 30.0f };
	static const int BACK_GROUND_COLOR{ 0x000000 };
	static const int MARGINE{ 3 };
}

Pin::Pin(const std::string& _ownerName, const int _color) :
	timeLeft_{ ANIM_TOTAL_TIME },
	radius_{},
	color_{ _color },
	ownerName_{ _ownerName }
{
}

Pin::~Pin()
{
}

void Pin::Update()
{
	timeLeft_ -= Time::DeltaTime();
	while (timeLeft_ <= 0.0f)
	{
		timeLeft_ += ANIM_TOTAL_TIME;
	}

	radius_ = sinf(GetAnimRatio() * DX_PI_F) * MAX_RADIUS;
}

void Pin::Draw()
{
	DrawCircle(pos_.x, pos_.y, static_cast<int>(radius_), color_);

	if (IsTouch())
	{
		Vec2Int size{};
		GetDrawStringSize(&size.x, &size.y, nullptr, ownerName_.c_str(), ownerName_.size());

		DrawBox(
			pos_.x - MARGINE,
			pos_.y - MARGINE,
			pos_.x + size.x + MARGINE,
			pos_.y + size.y + MARGINE,
			BACK_GROUND_COLOR,
			TRUE);

		DrawString(pos_.x, pos_.y, ownerName_.c_str(), color_);
	}
}

bool Pin::IsTouch() const
{
	int mouseX{};
	int mouseY{};

	GetMousePoint(&mouseX, &mouseY);

	int diffX{ mouseX - pos_.x };
	int diffY{ mouseY - pos_.y };
	float dist{ sqrtf(diffX * diffX + diffY * diffY) };

	return dist <= radius_;
}

float Pin::GetAnimRatio() const
{
	return timeLeft_ / ANIM_TOTAL_TIME;
}
