#include "SceneAction.h"
#include <iostream>

void SceneAction::Initialise(std::string text_in, std::string type_in, std::string  parameter_in, std::string next_scene_in)
{
	text = text_in;
	type = type_in;
	parameter = parameter_in;
	next_scene = next_scene_in;
}
std::string SceneAction::GetText()
{
	return text;
}
std::string SceneAction::GetType()
{
	return type;
}
std::string SceneAction::GetSpecific()
{
	return parameter;
}
std::string SceneAction::GetNextScene()
{
	return next_scene;
}
bool SceneAction::Activate(Player* player)
{
	return 0;
}