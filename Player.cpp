#include "Player.h"
#include "FirePokemon.h"
#include "WaterPokemon.h"

std::map <std::string, std::string> pokemon_types = {
{"charmander", "fire"},
	{"bulbasaurus", "water"}
};

void Player::AddPokemon(std::string pokemon_name)
{
	// ����� �� ����� ������ ��� �������� � �������������� ��� ����� ������� ���������������� ���������� Pokemon, ������� ��� � ������ ����� �� ����� ��������
	if (pokemon_types[pokemon_name] == "fire")
	{
		/* Это все должно быть в конструкторе покемона, а то у тебя тут 
		 * 4 раза одно и то же самое */
		FirePokemon* new_pokemon = new FirePokemon();
		new_pokemon->Load(pokemon_name, false);
		new_pokemon->Initialise();
		new_pokemon->Heal();
		new_pokemon->SetInventoryID(GetPokemonAmount());
		owned_pokemons.push_back(new_pokemon);
	}
	if (pokemon_types[pokemon_name] == "water")
	{
		WaterPokemon* new_pokemon = new WaterPokemon();
		new_pokemon->Load(pokemon_name, false);
		new_pokemon->Initialise();
		new_pokemon->Heal();
		new_pokemon->SetInventoryID(GetPokemonAmount());
		owned_pokemons.push_back(new_pokemon);
	}
	if (pokemon_types[pokemon_name] == "air")
	{
		AirPokemon* new_pokemon = new AirPokemon();
		new_pokemon->Load(pokemon_name, false);
		new_pokemon->Initialise();
		new_pokemon->Heal();
		new_pokemon->SetInventoryID(GetPokemonAmount());
		owned_pokemons.push_back(new_pokemon);
	}
	if (pokemon_types[pokemon_name] == "earth")
	{
		EarthPokemon* new_pokemon = new EarthPokemon();
		new_pokemon->Load(pokemon_name, false);
		new_pokemon->Initialise();
		new_pokemon->Heal();
		new_pokemon->SetInventoryID(GetPokemonAmount());
		owned_pokemons.push_back(new_pokemon);
	}
}
int Player::GetPokemonAmount()
{
	return owned_pokemons.size();
}
/* Почему тут возвращается такой указатель? Тут либо что-то с 
 * названиями не так, либо с возвращаемым значением */
PokemonBattle* Player::GetCurrentPokemon()
{
	return &current_pokemon;
}
std::string Player::GetPokemons()
{
	std::string output;
	if (current_pokemon.GetName() == "")
	{
		output += "You did not choose a pokemon!\n";
	}
	else
	{
		output += "Current Chosen Pokemon:  " + current_pokemon.GetName() + " " + std::to_string(current_pokemon.GetLevel()) + " lvl \n";
	}
	int c = 0;
	output += "Pokemons:\n";
	for (int i = 0; i < owned_pokemons.size(); i++)
	{
		c++;
		output += std::to_string(c) + " : " + owned_pokemons[i]->GetName() + " lvl " + std::to_string(owned_pokemons[i]->GetLevel()) + "  HP: " +
			std::to_string(owned_pokemons[i]->GetHp()) + " / " + std::to_string(owned_pokemons[i]->GetMaxHp()) +
			"  SP: " + std::to_string(owned_pokemons[i]->GetSp()) + " / " + std::to_string(owned_pokemons[i]->GetMaxSp()) + "\n";
	}
	
	if (c == 0)
	{
		output = "You do not have any pokemons currently\n";
	}
	else
	{
		output += std::to_string(c+1) + " : go back\n";
	}
	return output;
}
/* А почему оно нужно? */
void Player::ReloadPokemons()
{
	for (int i = 0; i < owned_pokemons.size(); i++)
	{
		if (owned_pokemons[i]->GetInventoryID() == current_pokemon_id)
		{
			owned_pokemons[i]->SetHp(current_pokemon.GetHp());
			owned_pokemons[i]->SetSp(current_pokemon.GetSp());
			owned_pokemons[i]->SetExperience(current_pokemon.GetExperience());
			return;
		}
	}
}
void Player::SetPokemonActive(int pokemon_number)
{
	if (pokemon_number <= owned_pokemons.size())
	{
		PokemonBattle newpokemon;
		current_pokemon_id = owned_pokemons[pokemon_number - 1]->GetInventoryID();
		newpokemon.LoadParams(owned_pokemons[pokemon_number - 1]->ExportParams(), owned_pokemons[pokemon_number - 1]->GetHp(), owned_pokemons[pokemon_number - 1]->GetSp());
		newpokemon.SetExperience(owned_pokemons[pokemon_number - 1]->GetExperience());
		current_pokemon = newpokemon;
	}
	return;
}
void Player::HealPokemons()
{
	if (current_pokemon.GetName() != "")
	{
		current_pokemon.Heal();
	}
	
	for (int i = 0; i < owned_pokemons.size(); i++)
	{
		owned_pokemons[i]->Heal();
	}
}