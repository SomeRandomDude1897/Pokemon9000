#include "BattleSceneAction.h"
#include "Battle.h"

bool BattleSceneAction::Activate(Player* player)
{	
	PokemonBattle new_pokemon;
	new_pokemon.Load(parameter, true);
	Battle new_battle;
	player->GetCurrentPokemon()->ReloadStats();
	new_pokemon.ReloadStats();
	new_pokemon.Heal();
	new_battle.Initialise(player->GetCurrentPokemon(), new_pokemon);
	int battle_result = new_battle.Begin();
	player->ReloadPokemons();
	if (battle_result == 1)
	{
		return 1;
	}
	else if (battle_result == 2)
	{
		player->AddPokemon(parameter);
		return 1;
	}
	else
	{
		return 0;
	}
}