#include "AI.h"
#include "GroundMap.h"
#include <cassert>
#include "Dir.h"


namespace
{
	static const std::string IMAGE_FILE_PATH{ "Data/Enemy.png" };
}

AI::AI():
	status
	{
		.walkSpeed = 3.0f
	},
	pin_{ "AI目的地", 0xff0000 },
	angle_{},
	pos_{ 64, 64 }
{
	hImage_ = LoadGraph(IMAGE_FILE_PATH.c_str());
	assert(hImage_ > 0 && "敵画像読み込みに失敗");

	SetDrawOrder(-1000);
}

AI::~AI()
{
}

void AI::Update()
{
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		GetMousePoint(&targetPos_.x, &targetPos_.y);
		pin_.SetPosition(targetPos_);

		if (CheckHitKey(KEY_INPUT_F))
		{
			pos_ = targetPos_;
		}
	}

	double diffX{ static_cast<double>(targetPos_.x - pos_.x) };
	double diffY{ static_cast<double>(targetPos_.y - pos_.y) };

	double angle{ atan2(diffY, diffX) };

	angle_ = angle;

	pos_.x += static_cast<float>(cos(angle_)) * status.walkSpeed;
	pos_.y += static_cast<float>(sin(angle_)) * status.walkSpeed;

	GroundMap* pMap{ FindGameObject<GroundMap>() };
	if (pMap)
	{
		Vec2Int tileWith{ pMap->GetTileWidth() };

		Vec2Int tilePos{ pMap->GetTilePosition(pos_) };
		
		// 自分のいるタイルが壁なら、半分行っているか行っていないかで押し出す処理

		if (pMap->IsWall(tilePos + DIR_VEC[DIR_UP])
			&& pMap->)
		{

		}

		/*if (pMap->IsWall(tilePos))
		{
			if (tilePos.x < tileWith.x / 2)
			{
				pos_.x = (pos_.x / tileWith.x) * tileWith.x - 2;
			}
			else
			{
				pos_.x = (pos_.x / tileWith.x) * tileWith.x + 1;
			}
			if (tilePos.y < tileWith.y / 2)
			{
				pos_.y = (pos_.y / tileWith.y) * tileWith.y - 1;
			}
			else
			{
				pos_.y = (pos_.y / tileWith.y) * tileWith.y + 1;
			}
		}*/

		/*if (((pos_.y % tileWith.y) < tileWith.y / 2 &&
			pMap->IsWall(tilePos + DIR_VEC[DIR_UP])) ||
			((pos_.y % tileWith.y) > tileWith.y / 2 &&
				pMap->IsWall(tilePos + DIR_VEC[DIR_DOWN])))
		{
			pos_.y = (pos_.y / tileWith.y) * tileWith.y;
		}

		if (((pos_.x % tileWith.x) < tileWith.x / 2 &&
			pMap->IsWall(tilePos + DIR_VEC[DIR_LEFT])) ||
			((pos_.x % tileWith.x) > tileWith.x / 2 &&
				pMap->IsWall(tilePos + DIR_VEC[DIR_RIGHT])))
		{
			pos_.x = (pos_.x / tileWith.x) * tileWith.x;
		}*/
	}
}

void AI::Draw()
{
	GroundMap* pMap{ FindGameObject<GroundMap>() };
	if (pMap)
	{
		Vec2Int drawPos{ pMap->GetDrawPosition(pos_) };

		DrawRotaGraph(
			drawPos.x,
			drawPos.y,
			pMap->GetExtendRate(),
			angle_,
			hImage_,
			TRUE);
	}
}
