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

	_objects.Clear();
}

void EditScene::Init(HWND hwnd)
{

	{
		//Create Tilemap
		TilemapObject* tilemapObject = new TilemapObject();
		Tilemap* tilemap = new Tilemap();
		tilemap->LoadTilemap("Tilemap", SceneManager::GetInstance()->GetStageNum());
		tilemapObject->SetTilemap(tilemap);
		_objects.PushBack(tilemapObject);
	}
}

void EditScene::Update()
{
	for (List<Object*>::Iterator it = _objects.Begin(); it != _objects.End(); ++it)
	{
		(*it)->Update();
	}
}

void EditScene::Render(HDC hdc)
{
	for (List<Object*>::Iterator it = _objects.Begin(); it != _objects.End(); ++it)
	{
		(*it)->Render(hdc);
	}
	WCHAR buffer[30];
	swprintf_s(buffer, 30, L"~Edit Scene %d ~", SceneManager::GetInstance()->GetStageNum());
	::TextOut(hdc, 1300, 30, buffer, 15);
}
