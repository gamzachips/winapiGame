#include "pch.h"
#include "DevScene.h"
#include "Ball.h"

DevScene::DevScene()
{
	_ball = new Ball;
}

DevScene::~DevScene()
{
}

void DevScene::Init()
{
	
}

void DevScene::Update()
{
	_ball->Update();
}

void DevScene::Render(HDC hdc)
{
	_ball->Render(hdc);

}
