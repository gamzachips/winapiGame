#pragma once
#include "Object.h"

class Tilemap;

class TilemapObject : public Object
{
public:
	TilemapObject();
	virtual ~TilemapObject();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void TickPicking();

	void SetTilemap(Tilemap* tilemap) { _tilemap = tilemap; }
	Tilemap* GetTilemap() { return _tilemap; }

protected:
	Tilemap* _tilemap = nullptr;
};

