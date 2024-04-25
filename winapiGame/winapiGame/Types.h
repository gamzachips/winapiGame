#pragma once

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;

struct Vector2D
{
	float x, y;

	void operator+=(Vector2D other)
	{
		x += other.x;
		y += other.y;
	}

	Vector2D operator*(float f)
	{
		Vector2D temp = *this;
		temp.x *= f;
		temp.y *= f;
		return temp;
	}
};

struct Vector2DInt
{
	int x, y;
};


