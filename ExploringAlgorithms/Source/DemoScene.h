#pragma once
#include "../Library/SceneBase.h"

class DemoScene : public SceneBase
{
public:
	DemoScene();
	~DemoScene();

	void Update() override;
	void Draw() override;
};
