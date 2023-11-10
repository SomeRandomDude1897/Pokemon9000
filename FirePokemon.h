#include "Pokemon.h"

#pragma once

class FirePokemon : public Pokemon
{
public:
	void Initialise();
private:
	std::string base_resist = "fire";
	std::string base_weakness = "water";
};