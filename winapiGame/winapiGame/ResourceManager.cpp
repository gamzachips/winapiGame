#include "pch.h"
#include "ResourceManager.h"
#include "Tilemap.h"

Tilemap* ResourceManager::CreateTilemap()
{
	if (_tilemap == nullptr)
	{
		_tilemap = new Tilemap();
	}
	return _tilemap;
}
