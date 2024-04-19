#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"
#include "DevScene.h"
#include "StageScene.h"

void SceneManager::Init()
{
}

void SceneManager::Update()
{
	if (_scene)
		_scene->Update();
}

void SceneManager::Render(HDC hdc)
{
	if (_scene)
		_scene->Render(hdc);
}

void SceneManager::ChangeScene(SceneType sceneType)
{
	if (_sceneType == sceneType) return;

	Scene* newScene = nullptr;

	switch (sceneType)
	{
	case SceneType::DevScene:
		newScene = new DevScene();
		break;
	case SceneType::GameScene:
		newScene = new StageScene();
		break;
	}

	delete _scene;

	_scene = newScene;
	_sceneType = sceneType;

	newScene->Init();
}
