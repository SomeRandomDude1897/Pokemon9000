#include <iostream>
#include <vector>

struct ability_params
{
	std::string name;
	std::vector<std::string> attack_descriptions;
	std::string type;
	std::vector<int> min_damage;
	std::vector<int> max_damage;
	int min_level;
};

#pragma once
class Ability
{
public:
	void Initialise(std::string, int level);
	std::string GetName();
	std::string GetType();
	std::vector<std::string> GetDescriptions();
	std::pair<std::vector<int>, std::vector<int>>  GetDamage();
	ability_params params;
};

