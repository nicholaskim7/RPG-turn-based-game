#include <iostream>
#include <string>
#include "Archer.h"

using namespace std;


Archer::Archer(string name_, string race_, string occupation_, int health_, int energy_) : Character(name_, race_, occupation_, health_), energy(energy_)
{}


int Archer::getStamina() const
{
	return energy;
}


void Archer::setStamina(int stamina_)
{
	energy = stamina_;
}


int Archer::addWeapon(string weapName_, int weapDamage_, int weapStaminaCost_)
{
	if (numArrows == 3)
	{
		cout << "Arrow limit reached!" << endl;
	}
	else
	{

		arrows[numArrows].arrowType = weapName_;
		arrows[numArrows].arrowDamage = weapDamage_;
		arrows[numArrows].energyCost = weapStaminaCost_;
		numArrows++;
	}

	return numArrows;
}


void Archer::nextWeapon()
{
	selectedArrow++;
	if (selectedArrow == numArrows) {
		selectedArrow = 0;
	}
	cout << getName() << " swapped weapon and ended turn." << endl;
}


void Archer::attack(Character* target_)
{
	if (numArrows == 0)
		cout << "This archer has no arrows!" << endl;
	else if (energy < arrows[selectedArrow].energyCost)
		cout << "Insufficient energy points!" << endl;
	else
	{

		cout << getName() << " attacked " << target_->getName() << " with a " << arrows[selectedArrow].arrowType << " arrow, dealing " << arrows[selectedArrow].arrowDamage << " damage." << endl;
		target_->setHealth(target_->getHealth() - arrows[selectedArrow].arrowDamage);
		setStamina(getStamina() - arrows[selectedArrow].energyCost);
	}
}

void Archer::Save() {
	
}

void Archer::print()
{
	Character::print();
	cout << "Energy: " << getStamina() << endl;
	cout << "Arrows: " << endl;
	for (int i = 0; i < numArrows; i++)
	{
		cout << arrows[i].arrowType << " Dmg: " << arrows[i].arrowDamage << " EnergyCost: " << arrows[i].energyCost << endl;
	}
}