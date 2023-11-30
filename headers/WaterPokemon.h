#include "Pokemon.h"

#pragma once
class WaterPokemon: public Pokemon
{
public:
	WaterPokemon(std::string name, int inventory_amount);
private:
	std::string base_resist = "WATER";
	std::string base_weakness = "EARTH";
};