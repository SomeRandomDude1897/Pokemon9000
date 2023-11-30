#include "Pokemon.h"

#pragma once

class FirePokemon : public Pokemon
{
public:
	FirePokemon(std::string name, int inventory_amount);
private:
	std::string base_resist = "FIRE";
	std::string base_weakness = "WATER";
};