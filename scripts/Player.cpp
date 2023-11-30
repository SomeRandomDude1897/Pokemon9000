#include "Player.h"
#include "FirePokemon.h"
#include "WaterPokemon.h"

std::map <std::string, std::string> pokemon_types = {
{"charmander", "fire"},
	{"bulbasaurus", "water"}
};

void Player::AddPokemon(std::string pokemon_name)
{
	if (pokemon_types[pokemon_name] == "fire")
	{
		FirePokemon* new_pokemon = new FirePokemon(pokemon_name, GetPokemonAmount());
		owned_pokemons.push_back(new_pokemon);
	}
	if (pokemon_types[pokemon_name] == "water")
	{
		WaterPokemon* new_pokemon = new WaterPokemon(pokemon_name, GetPokemonAmount());
		owned_pokemons.push_back(new_pokemon);
	}
	if (pokemon_types[pokemon_name] == "air")
	{
		AirPokemon* new_pokemon = new AirPokemon(pokemon_name, GetPokemonAmount());
		owned_pokemons.push_back(new_pokemon);
	}
	if (pokemon_types[pokemon_name] == "earth")
	{
		EarthPokemon* new_pokemon = new EarthPokemon(pokemon_name, GetPokemonAmount());
		owned_pokemons.push_back(new_pokemon);
	}
	if (current_pokemon == 0)
	{
		current_pokemon = owned_pokemons[0];
	}
}
int Player::GetPokemonAmount()
{
	return owned_pokemons.size();
}
Pokemon* Player::GetCurrentPokemon()
{
	return current_pokemon;
}
std::string Player::GetPokemons()
{
	std::string output;
	if (current_pokemon->GetName() == "")
	{
		output += "You did not choose a pokemon!\n";
	}
	else
	{
		output += "Current Chosen Pokemon:  " + current_pokemon->GetName() + " " + std::to_string(current_pokemon->GetLevel()) + " lvl \n";
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
void Player::SetPokemonActive(int pokemon_number)
{
	if (pokemon_number <= owned_pokemons.size())
	{
		current_pokemon = owned_pokemons[pokemon_number-1];
	}
	return;
}
void Player::HealPokemons()
{
	if (current_pokemon->GetName() != "")
	{
		current_pokemon->Heal();
	}
	
	for (int i = 0; i < owned_pokemons.size(); i++)
	{
		owned_pokemons[i]->Heal();
	}
}