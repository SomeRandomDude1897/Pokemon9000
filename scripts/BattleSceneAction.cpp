#include "BattleSceneAction.h"
#include "Battle.h"

bool BattleSceneAction::Activate(Player* player)
{	
	Pokemon new_pokemon;
	new_pokemon.Load(parameter, true);
	Battle new_battle;
	new_pokemon.Heal();
	new_battle.Initialise(player->GetCurrentPokemon(), new_pokemon);
	BattleState battle_result = new_battle.Begin();
	if (battle_result == BattleState::WINLEAVEPOKEMON)
	{
		return 1;
	}
	else if (battle_result == BattleState::WINANDTAKEPOKEMON)
	{
		player->AddPokemon(parameter);
		return 1;
	}
	else
	{
		return 0;
	}
}