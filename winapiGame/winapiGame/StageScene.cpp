#include "pch.h"
#include "StageScene.h"
#include "Ball.h"
#include "TilemapObject.h"
#include "ResourceManager.h"
#include "Tilemap.h"

StageScene::StageScene()
{
}

StageScene::~StageScene()
{
	if (_ball)
	{
		delete _ball;
		_ball = nullptr;
	}
		
	if (_tilemapObject)
	{
		delete _tilemapObject;
		_tilemapObject = nullptr;
	}
}

void StageScene::Init()
{
	{
		_ball = new Ball;
	}

	{
		_tilemapObject = new TilemapObject();
		Tilemap* tilemap = new Tilemap();
		tilemap->LoadTilemap("Tilemap0");
		_tilemapObject->SetTilemap(tilemap);
	}
}

void StageScene::Update()
{
	_ball->Update();
	_tilemapObject->Update();
}

void StageScene::Render(HDC hdc)
{
	_ball->Render(hdc);
	_tilemapObject->Render(hdc);
}
