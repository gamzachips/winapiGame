#pragma once

class Tilemap;

class ResourceManager
{
private:
	ResourceManager() = default;

public:
	static ResourceManager* GetInstance()
	{
		static ResourceManager _instance;
		return &_instance;
	}

	Tilemap* CreateTilemap();

private:
	Tilemap* _tilemap;
};

