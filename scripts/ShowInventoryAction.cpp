#include "ShowInventoryAction.h"
#include <stdlib.h>

bool ShowInventoryAction::Activate(Player* player)
{
	while (true)
	{
		system("cls");
		std::cout << player->GetPokemons();
		std::string player_input;
		int inventory_choise = 0;
		std::cin >> player_input;
		bool has_non_numeric = false;
		std::vector<char> allowed_symbols = { '0', '1', '2','3', '4', '5', '6', '7', '8', '9' };
		for (int i = 0; i < player_input.size(); i++)
		{
			if (std::find(allowed_symbols.begin(), allowed_symbols.end(), player_input[i]) == std::end(allowed_symbols))
			{
				has_non_numeric = true;
				break;
			}
		}
		if (has_non_numeric == false && std::stoi(player_input) > 0 && std::stoi(player_input) <= player->GetPokemonAmount() + 1)
		{
			inventory_choise = std::stoi(player_input);
			player->SetPokemonActive(inventory_choise);
			return 0;
		}
	}
}