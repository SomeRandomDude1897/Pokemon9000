#include "PokemonBattle.h"
#include "Ability.h"
#pragma once
class Battle
{
public:
	void Initialise(PokemonBattle* player_pokemon_in, PokemonBattle enemy_pokemon_in);
	int Begin();
private:
	PokemonBattle* player_pokemon;
	PokemonBattle enemy_pokemon;
	bool flee_battle = false;
	int StartPhase();
	int CheckBattleStatus();
	int BattlePhase();
	int EndPhase(int result);
	void MakePlayerTurn();
	void MakeEnemyTurn();
	void Strike(Ability action, PokemonBattle* attacker, PokemonBattle* defender);
};

