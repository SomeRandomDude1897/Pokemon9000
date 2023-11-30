#include "Scene.h"
#include "GoToSceneAction.h"
#include "CloseGameAction.h"
#include "BattleSceneAction.h"
#include "HealAction.h"
#include "GetPokemonAction.h"
#include <iostream>
#include <stdlib.h> 
#include <fstream>
#include <vector>
#include "json.hpp"
using json = nlohmann::json;


void Scene::Initialise(std::string text_in, std::string type_in, std::vector<SceneAction*> actions_in)
{
	text = text_in;
	type = type_in;
	actions = actions_in;
}

void Scene::Load(std::string filename)
{
	std::ifstream f("scenes\\" + filename + ".json");
	json data = json::parse(f);

	text = data["text"];
	type = data["type"];
	in_game_scene = data["in_game_scene"];

	
	
	for (int i = 0; i < data["actions"].size(); i++)
	{
		std::string action_text = data["actions"][i]["text"];
		std::string action_type = data["actions"][i]["type"];
		std::string parameter = data["actions"][i]["parameter"];
		std::string action_next_scene = data["actions"][i]["next_scene"];
		if (action_type == "go_to_scene")
		{
			GoToSceneAction* new_action = new GoToSceneAction();
			new_action->Initialise(action_text, action_type, parameter, action_next_scene);
			actions.push_back(new_action);
		}
		else if (action_type == "close_game")
		{
			CloseGameAction* new_action = new CloseGameAction();
			new_action->Initialise(action_text, action_type, parameter, action_next_scene);
			actions.push_back(new_action);
		}
		else if (action_type == "get_pokemon")
		{
			GetPokemonAction* new_action = new GetPokemonAction();
			new_action->Initialise(action_text, action_type, parameter, action_next_scene);
			actions.push_back(new_action);
		}
		else if (action_type == "battle")
		{
			BattleSceneAction* new_action = new BattleSceneAction();
			new_action->Initialise(action_text, action_type, parameter, action_next_scene);
			actions.push_back(new_action);
		}
		else
		{
			HealAction* new_action = new HealAction();
			new_action->Initialise(action_text, action_type, parameter, action_next_scene);
			actions.push_back(new_action);
		}

	}
	
}
bool Scene::GetInGameFlag()
{
	return in_game_scene;
}

std::string Scene::GetText()
{
	return text;
}
std::vector<SceneAction*> Scene::GetActions()
{
	return actions;
}