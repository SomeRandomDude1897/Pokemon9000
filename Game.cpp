#include <iostream>
#include "Game.h"
#include "Scene.h"
#include <stdlib.h>
#include "SceneAction.h"
#include <fstream>
#include "Battle.h"


Player* Game::GetPlayer()
{
	return &player;
}

Scene* Game::GetCurrentScene()
{
	return current_scene;
}

void Game::Act(SceneAction* action)
{
	// Функция отрисовки у меня находится в классе Game, поэтому если без такого возвращаемого значения делать, то приходится передавать в Action ссылку на Game, что нельзя сделать тк кольцевое включение классов
	bool go_to_next_scene = action->Activate(&player);
	if (go_to_next_scene)
	{
		Scene scene;
		scene.Load(action->GetNextScene());
		DrawScene(&scene);
	}
	else
	{
		DrawScene(current_scene);
	}
}

void Game::DrawScene(Scene* scene)
{
	system("cls");
	std::cout << scene->GetText() << '\n';
	std::vector<SceneAction*> temp_actions = scene->GetActions();
	if (scene->GetInGameFlag())
	{
		temp_actions.push_back(OpenInventoryAction);
	}
	current_scene = scene;
	for (int i = 0; i < temp_actions.size(); i++)
	{
		std::cout << i + 1 << " : " << temp_actions[i]->GetText() << '\n';
	}
	std::string player_input;
	int awaited_action = 0;
	std::cin >> player_input;
	bool has_non_numeric = false;
	std::vector<char> allowed_symbols = { '0', '1', '2','3', '4', '5', '6', '7', '8', '9' };
	for (int i = 0; i < player_input.size(); i++)
	{
		if (std::find(allowed_symbols.begin(), allowed_symbols.end(), player_input[i]) == std::end(allowed_symbols))
		{
			has_non_numeric = true;
			break;
		}
	}
	if (has_non_numeric == false)
	{
		awaited_action = std::stoi(player_input);
	}
	if (awaited_action > 0 && awaited_action <= temp_actions.size())
	{
		Act(temp_actions[awaited_action - 1]);
	}
	else
	{
		DrawScene(scene);
	}
}
void Game::Start()
{
	OpenInventoryAction = new ShowInventoryAction();
	OpenInventoryAction->Initialise("See owned Pokemons", "show_inventory", "", "");
	Scene start_scene;
	start_scene.Load("start_scene");
	DrawScene(&start_scene);
}
void Game::DebugStart() // просто для удобства разработки
{

}