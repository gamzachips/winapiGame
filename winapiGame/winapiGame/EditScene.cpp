#include "pch.h"
#include "EditScene.h"
#include "Ball.h"
#include "TilemapObject.h"
#include "ResourceManager.h"
#include "Tilemap.h"
#include "SceneManager.h"

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
		//Create Tilemap
		TilemapObject* tilemapObject = new TilemapObject();
		Tilemap* tilemap = new Tilemap();
		tilemap->LoadTilemap("Tilemap", SceneManager::GetInstance()->GetStageNum());
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
	WCHAR buffer[30];
	swprintf_s(buffer, 30, L"~Edit Scene %d ~", SceneManager::GetInstance()->GetStageNum());
	::TextOut(hdc, 1300, 30, buffer, 15);
}
