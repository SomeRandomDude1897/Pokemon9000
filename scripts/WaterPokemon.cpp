#include "WaterPokemon.h"

WaterPokemon::WaterPokemon(std::string name, int inventory_amount)
{
	Load(name, false);
	params.resistances.push_back(base_resist);
	params.weaknesses.push_back(base_weakness);
	Heal();
	inventory_id = inventory_amount;
}
