#pragma once
#include "../Library/GameObject.h"
#include "Vec2Int.h"


class Pin : public GameObject
{
public:
	Pin(const std::string& _ownerName, const int _color);
	~Pin();

	void Update() override;
	void Draw() override;

	bool IsTouch() const;

	float GetAnimRatio() const;

	void SetPosition(const Vec2Int _position) { pos_ = _position; }

private:
	int color_;       // 色
	Vec2Int pos_;     // ピンの座標
	float radius_;    // 半径
	float timeLeft_;  // 残りタイム
	std::string ownerName_;  // ピン所有者の名前
};
