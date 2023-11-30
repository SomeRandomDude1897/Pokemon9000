#include <stdlib.h>
#include "CloseGameAction.h"

bool CloseGameAction::Activate(Player* player)
{
	exit(0);
	return 0;
}