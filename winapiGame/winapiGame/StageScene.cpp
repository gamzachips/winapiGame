#include "pch.h"
#include "StageScene.h"
#include "Ball.h"
#include "TilemapObject.h"
#include "ResourceManager.h"
#include "Tilemap.h"
#include "Block.h"
#include "NormalBlock.h"
#include "CrackedBlock.h"

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
		//Craete Tilemap
		TilemapObject* tilemapObject = new TilemapObject();
		Tilemap* tilemap = new Tilemap();
		tilemap->LoadTilemap("Tilemap0");
		tilemapObject->SetTilemap(tilemap);
		//_objects.push_back(tilemapObject);

		//Create Blocks
		Tile (*tiles)[TILEMAP_SIZEX] = tilemapObject->GetTilemap()->GetTiles();
		for (int y = 0; y < TILEMAP_SIZEY; y++)
		{
			for (int x = 0; x < TILEMAP_SIZEX; x++)
			{
				switch (tiles[y][x].type)
				{
					case TileType::Normal:
					{
						NormalBlock* block = new NormalBlock({ TILE_SIZE,TILE_SIZE });
						Vector2D pos = {x * TILE_SIZE + TILE_SIZE/2, y * TILE_SIZE + TILE_SIZE / 2 };
						block->SetPos(pos);
						_objects.push_back(block);
					}
					case TileType::Cracked:
					{

					}
				}
			}
		}
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
		(*it)->Render(hdc);
	}
}
