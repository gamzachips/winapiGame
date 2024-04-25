#include "pch.h"
#include "Scene.h"
#include "Object.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::DestroyObject(Object* object)
{
	for (list<Object*>::iterator it = _objects.begin(); it != _objects.end();)
	{
		if (*it == object)
		{
			it = _objects.erase(it);
		}
		else
			++it;
	}
}
