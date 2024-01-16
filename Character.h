#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

using namespace std;

class Character {
private:
	string name;
	string race;
	string type = "";
	int health;

public:

	Character(string name_, string race_, string type_, int health_);
	Character(string name_, string race_, int health_);

	string getName() const;
	string getRace() const;
	string getType() const;
	int getHealth() const;

	void setName(string name_);
	void setRace(string race_);
	void setType(string type_);
	void setHealth(int health_);

	

	virtual int getStamina() const = 0;
	virtual void setStamina(int stamina_) = 0;

	//virtual void Save() = 0;

	virtual int addWeapon(string weapName_, int weapDamage_, int weapStaminiaCost_) = 0;
	virtual void nextWeapon() = 0;
	virtual void attack(Character* target_) = 0;
	virtual void print();

};


#endif