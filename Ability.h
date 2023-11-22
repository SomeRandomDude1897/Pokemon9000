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
/* Выходит, что у тебя все способности не делают ничего
 * особенного и отличаются только типом и уроном? А как ты
 * поступишь, если придется ввести статусные эффекты? 
 * Сделаешь наследника этого класса и заведешь вектор
 * способностей со статусными эффектами? А потом надо будет
 * добавить еще какую-то особенность, то еще один вектор? 
 * И так далее. Нужен какой-то общий интерфейс, удобный для
 * использования и расширения */
class Ability
{
public:
	void Initialise(std::string, int level);
	std::string GetName();
	/* А если кто-то опечатается при вводе в json типа
	 *, то никаких преимуществ у покемона за счет него не 
	 * будет? Чтобы такого не случилось, такие вещи стоит делать
	 * enum class */
	std::string GetType();
	std::vector<std::string> GetDescriptions();
	std::pair<std::vector<int>, std::vector<int>>  GetDamage();
	ability_params params;
};

