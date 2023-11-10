#include "HealAction.h"

bool HealAction::Activate(Player* player)
{
	player->HealPokemons();
	return 1;
}