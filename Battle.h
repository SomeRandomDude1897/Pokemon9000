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
	/* Почему один по указателю, другой по ссылке? Просто опять-таки,
	 * вы пишите ядро, оно предполагает расширение. Если бы вдруг пришлось
	 * вводить мультиплеер, то это пришлось бы менять, да и вообще много кода.
	 */
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

