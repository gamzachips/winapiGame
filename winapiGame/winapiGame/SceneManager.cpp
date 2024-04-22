#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"
#include "EditScene.h"
#include "StageScene.h"
#include "InputManager.h"

SceneManager::~SceneManager()
{
	if (_scene)
	{
		delete _scene;
		_scene = nullptr;
	}
}

void SceneManager::Init()
{
}

void SceneManager::Update()
{
	if (_scene)
		_scene->Update();

	ChangeSceneByInput();
}

void SceneManager::Render(HDC hdc)
{
	if (_scene)
		_scene->Render(hdc);
}

void SceneManager::ChangeSceneByInput()
{
	if (InputManager::GetInstance()->GetButtonDown(KeyType::T))
	{
		if (_sceneType == SceneType::StageScene)
			ChangeScene(SceneType::EditScene);
		else if (_sceneType == SceneType::EditScene)
			ChangeScene(SceneType::StageScene);
	}
}

void SceneManager::ChangeScene(SceneType sceneType)
{
	if (_sceneType == sceneType) return;

	Scene* newScene = nullptr;

	switch (sceneType)
	{
	case SceneType::EditScene:
		newScene = new EditScene();
		break;
	case SceneType::StageScene:
		newScene = new StageScene();
		break;
	}

	delete _scene;

	_scene = newScene;
	_sceneType = sceneType;

	newScene->Init();
}
