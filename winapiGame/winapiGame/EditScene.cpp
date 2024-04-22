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

	for (list<Object*>::iterator it = _objects.begin(); it != _objects.end(); it++)
	{
		delete* it;
		*it = nullptr;
	}
}

void EditScene::Init()
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

void EditScene::Update()
{
	for (list<Object*>::iterator it = _objects.begin(); it != _objects.end(); it++)
	{
		(*it)->Update();
	}
}

void EditScene::Render(HDC hdc)
{
	for (list<Object*>::iterator it = _objects.begin(); it != _objects.end(); it++)
	{
		(*it)->Render(hdc);
	}
	::TextOut(hdc, 1300, 30, L"~Edit Scene~", 12);
}
