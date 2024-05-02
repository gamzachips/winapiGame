#include "pch.h"
#include "Scene.h"
#include "Object.h"
#include "InputManager.h"
#include "SceneManager.h"

Scene::Scene()
{
}

Scene::~Scene()
{
	for (List<Object*>::Iterator it = _objects.Begin(); it != _objects.End(); ++it)
	{
		delete* it;
		*it = nullptr;
	}
	_objects.Clear();
}

void Scene::Update()
{
	if (InputManager::GetInstance()->GetButtonDown(KeyType::ESC))
	{

		SceneManager::GetInstance()->RestartGame();
	}
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
