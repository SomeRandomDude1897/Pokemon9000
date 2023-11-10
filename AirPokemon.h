#include "Pokemon.h"
#pragma once
class AirPokemon : public Pokemon
{
public:
	void Initialise();
private:
	std::string base_resist = "earth";
	std::string base_weakness = "water";
};