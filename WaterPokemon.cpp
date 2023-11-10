#include "WaterPokemon.h"

void WaterPokemon::Initialise()
{
	params.resistances.push_back(base_resist);
	params.weaknesses.push_back(base_weakness);
}