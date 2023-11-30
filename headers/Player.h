#include <vector>
#include <string>
#include "AirPokemon.h"
#include "EarthPokemon.h"
#include "FirePokemon.h"
#include "WaterPokemon.h"

#pragma once
class Player
{
public:
	void AddPokemon(std::string pokemon_name);
	void HealPokemons();
	void PutCurrentPokemonBack();
	std::string GetPokemons();
	int GetPokemonAmount();
	void SetPokemonActive(int pokemon_number);
	Pokemon* GetCurrentPokemon();


	
private:
	Pokemon* current_pokemon;
	std::vector<Pokemon*> owned_pokemons = {};
	int level = 1;
	int current_pokemon_id = -1;
};