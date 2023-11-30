#include "Player.h"
#include <iostream>
#pragma once

class SceneAction
{
public:
	void Initialise(std::string text_in, std::string type_in, std::string  parameter_in, std::string next_scene_in);
	std::string GetText();
	std::string GetType();
	std::string GetSpecific();
	std::string GetNextScene();
	virtual bool Activate(Player* player);
protected:
	std::string text;
	std::string type; // ?
	std::string parameter;
	std::string next_scene;
};