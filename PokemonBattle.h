#include "Pokemon.h"
#pragma once

class PokemonBattle : public Pokemon
{
public:
	void LoadParams(pokemon_params, int hp, int sp);
	void ReloadStats();
};

