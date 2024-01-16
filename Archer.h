#ifndef ARCHER_H
#define ARCHER_H

#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

struct arrow
{
	string arrowType;
	int arrowDamage;
	int energyCost;
};

class Archer : public Character
{
private:
	arrow arrows[3];
	int numArrows = 0;
	int energy = 0;
	int selectedArrow = 0;

public:

	Archer(string name_, string race_, string occupation_, int health_, int energy_);


	int getStamina() const;
	void setStamina(int stamina_);
	int addWeapon(string weapName_, int weapDamage_, int weapStaminaCost_);
	void nextWeapon();
	void attack(Character* target_);
	void print();
	void Save();
};


#endif