#include "pch.h"
#include "TilemapActor.h"
#include "Tilemap.h"
#include "InputManager.h"

TilemapActor::TilemapActor()
{
}

TilemapActor::~TilemapActor()
{
}

void TilemapActor::Init()
{
}

void TilemapActor::Update()
{
	TickPicking();
}

void TilemapActor::Render(HDC hdc)
{
	if (_tilemap == nullptr)
		return;
	if (_showDebug == false)
		return;

	const Vector2DInt mapSize = _tilemap->GetMapSize();
	const int32 tileSize = _tilemap->GetTileSize();

	vector<vector<Tile>>& tiles = _tilemap->GetTiles();
	
	for (int y = 0; y < GWinSizeY / TILE_SIZEY; y++)
	{
		for (int x = 0; x < GWinSizeX / TILE_SIZEX; x++)
		{
			if (y < 0 || y >= mapSize.y)
				continue;
			if (x < 0 || x >= mapSize.x)
				continue;

			switch (tiles[y][x].type)
			{
			case TileType::None:
				break;
			case TileType::Wall:
				Utils::DrawRect(hdc, { (float)x * TILE_SIZEX, (float)y * TILE_SIZEY }, TILE_SIZEX, TILE_SIZEY);
				break;
			default:
				break;
			}

		}
	}
}

void TilemapActor::TickPicking()
{
	if (InputManager::GetInstance()->GetButtonDown(KeyType::LeftMouse))
	{
		POINT mousePos = InputManager::GetInstance()->GetMousePos();
		int32 mouseX = mousePos.x / TILE_SIZEX;
		int32 mouseY = mousePos.y / TILE_SIZEY;

		Tile* tile = _tilemap->GetTileAt({ mouseX, mouseY });
		if (tile)
		{
			tile->type = (TileType)(((int)(tile->type) + 1) % (int)(TileType::Count));
		}
	}
}
