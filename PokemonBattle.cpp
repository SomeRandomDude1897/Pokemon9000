#include "PokemonBattle.h"

void PokemonBattle::LoadParams(pokemon_params params_in, int hp, int sp)
{
	params = params_in;
	current_hp = hp;
	current_sp = sp;
}
void PokemonBattle::ReloadStats()
{
	if (params.pokemon_name != "")
	{
		current_abilities.clear();
		for (int i = 0; i < params.abilities.size(); i++)
		{
			if (params.abilities[i].params.min_level <= current_level)
			{
				current_abilities.push_back(params.abilities[i]);
			}
		}
	}
}