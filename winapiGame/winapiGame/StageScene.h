#pragma once
#include "Scene.h"


class StageScene : public Scene
{
public:
	StageScene();
	virtual ~StageScene();

	virtual void Init(HWND hwnd) override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;


};

