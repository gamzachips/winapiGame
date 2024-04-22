#include "pch.h"
#include "EditScene.h"
#include "Ball.h"
#include "TilemapObject.h"
#include "ResourceManager.h"
#include "Tilemap.h"

EditScene::EditScene()
{
	
}

EditScene::~EditScene()
{
	_tilemapObject->GetTilemap()->SaveTilemap("Tilemap0");

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

void EditScene::Init()
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

void EditScene::Update()
{
	_ball->Update();
	_tilemapObject->Update();
}

void EditScene::Render(HDC hdc)
{
	_ball->Render(hdc);
	_tilemapObject->Render(hdc);

	::TextOut(hdc, 1300, 30, L"~Edit Scene~", 12);
}
