#include "Battle.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdlib.h>

void Battle::Initialise(Pokemon* player_pokemon_in, Pokemon enemy_pokemon_in)
{
	player_pokemon = player_pokemon_in;
	enemy_pokemon = enemy_pokemon_in;
}

int CheckErrorPlayerInput(std::string error_message)
{
	system("cls");
	std::cout << error_message;
	std::cout << "1 : Go Back\n";
	std::string inp;
	std::cin >> inp;
	if (inp == "1")
	{
		return 0;
	}
	else
	{
		return CheckErrorPlayerInput(error_message);
	}
}

int Battle::CheckBattleStatus()
{
	if (player_pokemon->GetHp() == 0 || flee_battle)
	{
		return 0;
	}
	else if (enemy_pokemon.GetHp() == 0)
	{
		return 1;
	}
	return 2;
}

std::string GetPlayerActions(Pokemon* player_pokemon)
{
	int c = 0;
	std::string result = "";
	std::vector<Ability> abilities_loaded = player_pokemon->GetAbilities();
	for (int i = 0; i < abilities_loaded.size(); i++)
	{
		c++;
		result += std::to_string(c) + " : " + abilities_loaded[i].GetName() + '\n';
	}
	result += std::to_string(c+1) + " : Flee\n";
	return result;
}

int GetPlayerInput()
{
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
	if (awaited_action > 0)
	{
		return awaited_action;
	}
	return -1;
}

void Battle::Strike(int action_number, Pokemon* attacker, Pokemon* defender)
{
	system("cls");
	std::string strike_comment = attacker->Attack(defender, action_number);
	std::cout << strike_comment;
	std::cout << "enter any key to continue\n";
}

void Battle::MakePlayerTurn()
{
	while (true)
	{
		std::cout << GetPlayerActions(player_pokemon);
		std::vector<Ability> abilities_loaded = player_pokemon->GetAbilities();
		int player_input = GetPlayerInput();
		if (player_input <= abilities_loaded.size())
		{
			Strike(player_input - 1, player_pokemon, &enemy_pokemon);
			std::cin.get(); // если я вызываю cin.get() один раз, то оно не работает, почему так
			std::cin.get();
			break;
		}
		else if (player_input == abilities_loaded.size() + 1)
		{
			flee_battle = true;
			break;
		}
	}
}

void Battle::MakeEnemyTurn()
{
	std::vector<Ability> abilities_loaded = enemy_pokemon.GetAbilities();
	Strike(rand() % abilities_loaded.size(), &enemy_pokemon, player_pokemon);
	std::cin.get();
}

int Battle::BattlePhase()
{
	int turn_count = 0;
	while (true)
	{
		turn_count++;
		int battle_status = CheckBattleStatus();
		if (battle_status == 2)
		{
			system("cls");
			std::cout << "Turn Number " << (turn_count+1)/2 << '\n';
			std::cout << "Player's " << player_pokemon->GetName() << " lvl " << player_pokemon->GetLevel() << " hp: " << player_pokemon->GetHp() << " / " << player_pokemon->GetMaxHp() << '\n';
			std::cout << "Enemy " << enemy_pokemon.GetName() << " lvl " << enemy_pokemon.GetLevel() << " hp: " << enemy_pokemon.GetHp() << " / " << enemy_pokemon.GetMaxHp() << '\n';
			if (turn_count % 2 == 1)
			{
				MakePlayerTurn();
			}
			else
			{
				MakeEnemyTurn();
			}
		}
		else
		{
			return battle_status;
		}
	}
}

int Battle::StartPhase()
{
	
	bool start_battle_flag = true;
	std::string error_message;
	if (player_pokemon->GetName() == "")
	{
		error_message = "You forgot to choose a pokemon!\n";
		start_battle_flag = false;
	}
	else if (player_pokemon->GetHp() == 0)
	{
		error_message = "Chosen Pokemon is not feeling good enough to fight!\n";
		start_battle_flag = false;
	}
	if (start_battle_flag == false)
	{
		return CheckErrorPlayerInput(error_message);
	}
	return 1;
}

BattleState Battle::EndPhase(int result)
{
	system("cls");
	if (result == 1)
	{
		std::cout << "Victory" << '\n';
		int start_level = player_pokemon->GetLevel();
		int dropped_experience = (enemy_pokemon.GetDroppedExperience()/3) * enemy_pokemon.GetLevel();
		player_pokemon->SetExperience(player_pokemon->GetExperience() + dropped_experience);
		if (start_level < player_pokemon->GetLevel())
		{
			std::cout << "Hooray!! Your " << player_pokemon->GetName() << " has evolved to level " << player_pokemon->GetLevel() << "!!\n";
		}
		std::cout << "Would you like to catch " << enemy_pokemon.GetName() << "?\n1 : Yes\n2 : No\n";
		int res = 0;
		while (true)
		{
			res = GetPlayerInput();
			if (res == 1)
			{
				return BattleState::WINANDTAKEPOKEMON;
			}
			if (res == 2)
			{
				return BattleState::WINLEAVEPOKEMON;
			}
		}
	}
	else
	{
		std::cout << "Defeat\nPress Any Key to continue\n";
		std::cin.get();
	}
	return BattleState::LOSE;
}

BattleState Battle::Begin()
{
	system("cls");

	if (StartPhase() == 0)
	{
		return BattleState::LOSE;
	}
	return EndPhase(BattlePhase());
}