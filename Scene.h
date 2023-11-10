#include "SceneAction.h"
#include <iostream>
#include <vector>

#pragma once
class Scene
{
public:
	void Load(std::string name);
	void Initialise(std::string text, std::string type, std::vector<SceneAction*> actions);
	bool GetInGameFlag();
	std::string GetText();
	std::vector<SceneAction*> GetActions();
private:
	std::string text;
	std::vector<SceneAction*> actions;
	std::string type;
	bool in_game_scene;
};