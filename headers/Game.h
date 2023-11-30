#include <iostream>
#include "Scene.h"
#include "Player.h"
#include "ShowInventoryAction.h"

#pragma once
class Game
{
public:
	void Start();
	void DebugStart();
	void Act(SceneAction* action);
	void DrawScene(Scene* scene);
	Player* GetPlayer();
	Scene* GetCurrentScene();
private:
	Player player;
	Scene* current_scene;
	ShowInventoryAction* OpenInventoryAction;
};

