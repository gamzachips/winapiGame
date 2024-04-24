#pragma once

enum class SceneType
{
	None,
	EditScene,
	StageScene
};

enum TILE_SIZE
{
	TILEMAP_SIZEX = 63,
	TILEMAP_SIZEY = 43,
	TILE_SIZE = 48
};

enum class ColliderType
{
	Box,
	Sphere
};

enum class CollisionLayer
{
	Ball,
	Block,
};
