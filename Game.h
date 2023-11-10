#include <iostream>
#include "Scene.h"
#include "SceneAction.h"
#include "Ability.h"
#include "Player.h"
#include <string>
#include <vector>
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

