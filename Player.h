#include <vector>
#include <string>
#include "AirPokemon.h"
#include "EarthPokemon.h"
#include "FirePokemon.h"
#include "WaterPokemon.h"
#include "PokemonBattle.h"

#pragma once
class Player
{
public:
	void AddPokemon(std::string pokemon_name);
	void HealPokemons();
	void ReloadPokemons();
	void PutCurrentPokemonBack();
	std::string GetPokemons();
	int GetPokemonAmount();
	void SetPokemonActive(int pokemon_number);
	PokemonBattle* GetCurrentPokemon();


	
private:
	/* Почему текущий покемон такого типа?? */
	PokemonBattle current_pokemon;
	std::vector<Pokemon*> owned_pokemons = {};
	int level = 1;
	int current_pokemon_id = -1;
};