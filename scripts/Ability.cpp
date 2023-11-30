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

const ability_params &Ability::GetParams() const
{
	return params;
}

std::string Ability::GetType()
{
	switch (params.type)
	{
	case AbilityType::AIR: return "AIR";
	case AbilityType::EARTH: return "EARTH";
	case AbilityType::FIRE: return "FIRE";
	case AbilityType::WATER: return "WATER";
	}
	return "NONE";
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

AbilityType AssignAbilityType(std::string type)
{
	if (type == "FIRE")
	{
		return AbilityType::FIRE;
	}
	else if (type == "WATER")
	{
		return AbilityType::WATER;
	}
	else if (type == "EARTH")
	{
		return AbilityType::EARTH;
	}
	else if (type == "AIR")
	{
		return AbilityType::AIR;
	}
	else
	{
		return AbilityType::NONE;
	}
}

void Ability::Initialise(std::string filename, int level)
{
	std::ifstream f("abilities\\" + filename + ".json");
	
	json data = json::parse(f);
	
	params.name = data["name"];
	params.type = AssignAbilityType(data["type"]);
	if (params.type == AbilityType::NONE)
	{
		return;
	}
	params.min_level =  level;
	params.attack_descriptions = load_desriptions(data);
	params.max_damage = load_max_damage(data);
	params.min_damage = load_min_damage(data);
}

