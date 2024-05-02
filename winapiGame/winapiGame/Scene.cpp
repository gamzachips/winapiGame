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
	for (List<Object*>::Iterator it = _objects.Begin(); it != _objects.End(); ++it)
	{
		if (*it == object)
		{
			_objects.Erase(it);
			break;
		}
	}
}
