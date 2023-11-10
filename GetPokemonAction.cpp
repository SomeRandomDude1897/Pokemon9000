#include "GetPokemonAction.h"

bool GetPokemonAction::Activate(Player* player)
{
	player->AddPokemon(parameter);
	return 1;
}