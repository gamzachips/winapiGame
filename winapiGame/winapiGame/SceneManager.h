#pragma once

class Scene;

class SceneManager
{
private:
	SceneManager() = default;
	~SceneManager();
public:
	static SceneManager* GetInstance()
	{
		static SceneManager _instance;
		return &_instance;
	}

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void ChangeSceneByInput();
	SceneType GetSceneType() { return _sceneType; }

public:
	void ChangeScene(SceneType sceneType);
private:
	Scene* _scene = nullptr;
	SceneType _sceneType = SceneType::None;
};

