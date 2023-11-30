#include "Pokemon.h"
#pragma once
class EarthPokemon : public Pokemon
{
public:
	EarthPokemon(std::string name, int inventory_amount);
private:
	std::string base_resist = "EARTH";
	std::string base_weakness = "WATER";
};

