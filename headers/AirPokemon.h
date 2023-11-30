#include "Pokemon.h"
#pragma once
class AirPokemon : public Pokemon
{
public:
	AirPokemon(std::string name, int inventory_amount);
private:
	std::string base_resist = "EARTH";
	std::string base_weakness = "WATER";
};