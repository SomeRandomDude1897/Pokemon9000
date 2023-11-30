#include "Pokemon.h"
#include "json.hpp"
#include <random>
#include <fstream>
using json = nlohmann::json;


int Pokemon::GetInventoryID() const
{
	return inventory_id;
}

int Pokemon::GetExperience() const
{
	return current_experience;
}

void Pokemon::SetExperience(int exp)
{
	current_experience = exp;
	for (int i = 0; i < 5; i++)
	{
		if (level_cap[i] > current_experience)
		{
			current_level = i + 1;
			return;
		}
	}
	current_level = 5;
}

std::string Pokemon::GetName()
{
	return params.pokemon_name;
}
pokemon_params Pokemon::ExportParams() const
{
	return params;
}

std::vector<Ability> Pokemon::GetAbilities() const
{
	std::vector<Ability> abilities;
	for (int i = 0; i < params.abilities.size(); i++)
	{
		if (params.abilities.at(i).GetParams().min_level <= current_level)
		{
			abilities.push_back(params.abilities[i]);
		}
	}
	return abilities;
}

std::string Pokemon::GetType() const
{
	return params.pokemon_type;
}

std::vector<std::string> Pokemon::GetResistances() const
{
	return params.resistances;
}

std::vector<std::string> Pokemon::GetWeaknesses() const
{
	return params.weaknesses;
}

int Pokemon::GetMaxHp() const
{
	return params.hp_levels[current_level-1];
}

int Pokemon::GetMaxSp() const
{
	return params.sp_levels[current_level-1];
}

int Pokemon::GetDroppedExperience() const
{
	return params.dropped_experience;
}

int Pokemon::GetSp() const
{
	return current_sp;
}

int Pokemon::GetLevel() const
{
	return current_level;
}

int Pokemon::GetHp() const
{
	return current_hp;
}

std::vector<float> loadHp(json data)
{
	std::vector<float> hp_levels;
	for (int i = 0; i < data["hp_levels"].size(); i++)
	{
		hp_levels.push_back((float) data["hp_levels"][i]);
	}
	return hp_levels;
}
std::vector<float> loadSp(json data)
{
	std::vector<float> sp_levels;
	for (int i = 0; i < data["hp_levels"].size(); i++)
	{
		sp_levels.push_back((float)data["hp_levels"][i]);
	}
	return sp_levels;
}
std::vector<std::string> loadResist(json data)
{
	std::vector<std::string> resist;
	for (int i = 0; i < data["resistances"].size(); i++)
	{
		resist.push_back(data["resistances"][i]);
	}
	return resist;
}
std::vector < std::string > loadWeakness(json data)
{
	std::vector<std::string> weakness;
	for (int i = 0; i < data["weaknesses"].size(); i++)
	{
		weakness.push_back(data["weaknesses"][i]);
	}
	return weakness;
}
std::vector<Ability> loadAbilities(json data)
{
	std::vector<Ability> abils;
	for (int i = 0; i < data["abilities"].size(); i++)
	{
		Ability abil;
		abil.Initialise(data["abilities"][i]["name"], data["abilities"][i]["level"]);
		abils.push_back(abil);
	}
	return abils;
}
void Pokemon::Heal()
{
	current_hp = params.hp_levels[current_level-1];
	current_sp = params.sp_levels[current_level-1];
}
void Pokemon::TakeDamage(int damage)
{
	current_hp -= damage;
	if (current_hp < 0)
	{
		current_hp = 0;
	}
}
void Pokemon::Load(std::string filename, bool is_feral)
{
	std::ifstream f("pokemon\\" + filename + ".json");
 	json data = json::parse(f);
	
	pokemon_params parameters;
	parameters.pokemon_name = data["name"];
	parameters.pokemon_type = data["type"];
	if (is_feral == true)
	{
		int min_level_temp = data["encounter_level_min"];
		int max_level_temp = data["encounter_level_max"];
		current_level = min_level_temp + rand() % (max_level_temp - min_level_temp);
	}
	else
	{
		current_level = 1;
	}
	
	
	parameters.evolution_chance = data["evolution_chance"];
	parameters.evolve_level = data["evolution_level"];
	parameters.evolve_number = data["evolve_number"];
	parameters.dropped_experience = data["experience"];
	
	parameters.hp_levels = loadHp(data);
	parameters.sp_levels = loadSp(data);
	
	parameters.abilities = loadAbilities(data);
	parameters.weaknesses = loadWeakness(data);
	parameters.resistances = loadResist(data);
	params = parameters;
}