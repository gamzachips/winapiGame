#pragma once
#include "Scene.h"

class EndingScene : public Scene
{
public:
	EndingScene();
	virtual ~EndingScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
};

