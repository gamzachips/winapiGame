#include "pch.h"
#include "DevScene.h"
#include "Ball.h"
#include "TilemapActor.h"
#include "ResourceManager.h"
#include "Tilemap.h"

DevScene::DevScene()
{
	
}

DevScene::~DevScene()
{
}

void DevScene::Init()
{
	{
		_ball = new Ball;
	}
	
	{
		_tilemapActor = new TilemapActor();

		Tilemap* tilemap = ResourceManager::GetInstance()->CreateTilemap();
		tilemap->SetMapSize({ 63, 43 });
		_tilemapActor->SetTilemap(tilemap);
		_tilemapActor->SetShowDebug(true);
	}
}

void DevScene::Update()
{
	_ball->Update();
	_tilemapActor->Update();
}

void DevScene::Render(HDC hdc)
{
	_ball->Render(hdc);
	_tilemapActor->Render(hdc);
}
