#include "Pokemon.h"

#pragma once
class WaterPokemon: public Pokemon
{
public:
	void Initialise();
private:
	std::string base_resist = "water";
	std::string base_weakness = "earth";
};