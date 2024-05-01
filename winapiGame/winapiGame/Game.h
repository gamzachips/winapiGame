#pragma once
#include <Windows.h>
class Game
{
public:
	Game();
	~Game();

public:
	void Init(HWND hwnd);
	void FixedUpdate();
	void Update();
	void Render();

private:
	HWND _hwnd = {};
	HDC _hdc = {};

private:
	RECT _rect;
	HDC _hdcBack = {};
	HBITMAP _bmpBack = {};

	float _fixedTimer = 0.f;
};

