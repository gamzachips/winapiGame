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
	for (list<Object*>::iterator it = _objects.begin(); it != _objects.end(); it++)
	{
		delete* it;
		*it = nullptr;
	}
}

void StageScene::Init()
{
	{
		Ball* ball = new Ball;
		_objects.push_back(ball);
	}

	{
		TilemapObject* tilemapObject = new TilemapObject();
		Tilemap* tilemap = new Tilemap();
		tilemap->LoadTilemap("Tilemap0");
		tilemapObject->SetTilemap(tilemap);
		_objects.push_back(tilemapObject);
	}
}

void StageScene::Update()
{
	for (list<Object*>::iterator it = _objects.begin(); it != _objects.end(); it++)
	{
		(*it)->Update();
	}
}

void StageScene::Render(HDC hdc)
{
	for (list<Object*>::iterator it = _objects.begin(); it != _objects.end(); it++)
	{
		(*it)->Render();
	}
}
