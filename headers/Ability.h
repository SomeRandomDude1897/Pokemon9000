#pragma once
#include <iostream>
#include <vector>

enum class AbilityType
{
	FIRE,
	WATER,
	AIR,
	EARTH,
	NONE
};

class AbilityInterface
{
public:
	virtual void Initialise(std::string, int) = 0;
	virtual std::string GetName() = 0;
	virtual std::string GetType() = 0;
	virtual std::vector<std::string> GetDescriptions() = 0;
	virtual std::pair<std::vector<int>, std::vector<int>>  GetDamage() = 0;
};

struct ability_params
{
	std::string name;
	std::vector<std::string> attack_descriptions;
	AbilityType type;
	std::vector<int> min_damage;
	std::vector<int> max_damage;
	int min_level;
};

class Ability : AbilityInterface
{
public:
	void Initialise(std::string, int level);
	std::string GetName();
	std::string GetType();
	std::vector<std::string> GetDescriptions();
	std::pair<std::vector<int>, std::vector<int>>  GetDamage();
	const ability_params &GetParams() const;
private:
	ability_params params;
};
