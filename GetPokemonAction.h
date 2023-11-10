#pragma once
#include "SceneAction.h"
#include "Game.h"
class GetPokemonAction : public SceneAction
{
	bool Activate(Player* player);
};