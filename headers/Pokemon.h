#include <vector>
#include <map>
#include <string>
#include "Ability.h"

struct pokemon_params
{
	std::string pokemon_name;
	std::string pokemon_type;
	std::vector<float> hp_levels;
	std::vector<float> sp_levels;
	std::vector<Ability> abilities;
	int evolve_number;
	int evolution_chance;
	int evolve_level;
	std::vector<std::string> resistances;
	std::vector<std::string> weaknesses;
	int dropped_experience;
};

const int level_cap[5] = { 50, 100, 250, 700, 1500 };
const int max_pokemon_level = 5;

#pragma once
class Pokemon
{
public:
	void Load(std::string filename, bool is_feral);
	void Heal();
	pokemon_params ExportParams() const;
	std::vector<std::string> GetResistances() const;
	std::vector<std::string> GetWeaknesses() const;
	int GetHp() const;
	int GetMaxHp() const;
	int GetSp() const;
	int GetMaxSp() const;
	int GetLevel() const;
	int GetInventoryID() const;
	int GetExperience() const;
	int GetDroppedExperience() const;
	std::string GetType() const;
	void RandomiseLevel();
	void TakeDamage(int damage);
	std::vector<Ability> GetAbilities() const;
	std::string GetName();
	std::string Attack(Pokemon* defender, int action_number);
	friend class Battle;
	friend class Player;

protected:
	void SetExperience(int exp);
	pokemon_params params;
	int current_level = 1;
	int current_experience = 0;
	int current_hp = 0;
	int current_sp = 0;
	int encounter_lvl_min = 0;
	int encounder_lvl_max = 0;
	int inventory_id = -1;
};

