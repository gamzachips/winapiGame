#pragma once
#include "Scene.h"


class EditScene : public Scene
{
public:
	EditScene();
	virtual ~EditScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

};

