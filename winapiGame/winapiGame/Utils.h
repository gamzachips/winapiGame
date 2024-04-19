#pragma once
#include <windows.h>
#include <string>
using namespace std;

class Utils
{
public:
	//temp
	static void DrawText(HDC hdc, Vector2D pos, const wstring& str);

	static void DrawRect(HDC hdc, Vector2D pos, int32 w, int32 h);

	static void DrawCircle(HDC hdc, Vector2D pos, int32 radius);

	static void DrawLine(HDC hdc, Vector2D from, Vector2D to);
};

