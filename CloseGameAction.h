#include "SceneAction.h"
#pragma once

class CloseGameAction : public SceneAction
{
	bool Activate(Player* player);
};