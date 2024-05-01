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
	void Init(HWND hwnd);
	void Update();
	void Render(HDC hdc);
	void ChangeSceneByInput();
	void EndScene();
	SceneType GetSceneType() { return _sceneType; }
	Scene* GetScene() { return _scene; }

public:
	void ChangeScene(SceneType sceneType);
	int GetStageNum() { return _stageNum; }
	void GoToNextStage() { _stageNum = min(_stageNum + 1, _finalStageNum); }
private:
	HWND _hwnd = {};
	Scene* _scene = nullptr;
	SceneType _sceneType = SceneType::None;
	bool _endFlag = false;

	int _finalStageNum = 2;
	int _stageNum = 0;
};

