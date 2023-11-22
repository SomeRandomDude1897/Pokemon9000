#include "Ability.h"
#include <string>
#include <vector>
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;


std::string Ability::GetName()
{
	return params.name;
}

std::string Ability::GetType()
{
	return params.type;
}
std::pair<std::vector<int>, std::vector<int>> Ability::GetDamage()
{
 	return std::make_pair(params.min_damage, params.max_damage);
}

std::vector<std::string> Ability::GetDescriptions()
{
	return params.attack_descriptions;
}

std::vector<std::string> load_desriptions(json data)
{
	std::vector<std::string> descriptions;
	for (int i = 0; i < data["attack_descriptions"].size(); i++)
	{
		descriptions.push_back(data["attack_descriptions"][i]);
	}
	return descriptions;
}
/* Я так понимаю, тут столько значений, потому что столько уровней.
 * Это не то чтобы очевидно. Потом, почему нельзя было сделать какую-то
 * формулу, которая бы в зависимости от уровня покемона просто получала
 * нужное значение? */
std::vector<int> load_min_damage(json data)
{
	std::vector <int> min_damage;
	for (int i = 0; i < data["min_damage"].size(); i++)
	{
		min_damage.push_back(data["min_damage"][i]);
	}
	return min_damage;
}

std::vector<int> load_max_damage(json data)
{
	std::vector <int> max_damage;
	for (int i = 0; i < data["max_damage"].size(); i++)
	{
		max_damage.push_back(data["max_damage"][i]);
	}
	return max_damage;
}


void Ability::Initialise(std::string filename, int level)
{
	std::ifstream f("abilities\\" + filename + ".json");
	
	json data = json::parse(f);
	
	params.name = data["name"];
	params.type = data["type"];
	params.min_level =  level;
	params.attack_descriptions = load_desriptions(data);
	params.max_damage = load_max_damage(data);
	params.min_damage = load_min_damage(data);
	
	
}

