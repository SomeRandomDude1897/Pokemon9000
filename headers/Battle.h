#include "Ability.h"
#include "Pokemon.h"


enum BattleState
{
	WINLEAVEPOKEMON,
	LOSE,
	WINANDTAKEPOKEMON
};

#pragma once
class Battle
{
public:
	void Initialise(Pokemon* player_pokemon_in, Pokemon enemy_pokemon_in);
	BattleState Begin();
private:
	Pokemon* player_pokemon;
	Pokemon enemy_pokemon;
	bool flee_battle = false;
	int StartPhase();
	int CheckBattleStatus();
	int BattlePhase();
	BattleState EndPhase(int result);
	void MakePlayerTurn();
	void MakeEnemyTurn();
	void Strike(int action, Pokemon* attacker, Pokemon* defender);
};

