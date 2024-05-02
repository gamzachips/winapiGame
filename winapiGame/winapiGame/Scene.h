#pragma once

class Object;

class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void Init(HWND hwnd) abstract;
	virtual void Update();
	virtual void Render(HDC hdc) abstract;

	void DestroyObject(Object* object);

protected:
	List<Object*> _objects;
};

