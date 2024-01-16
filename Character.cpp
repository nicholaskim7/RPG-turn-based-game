#include <iostream>
#include <string>
#include "character.h"

using namespace std;

// constructor
Character::Character(string name_, string race_, int health_) : name(name_), race(race_), health(health_)
{}
Character::Character(string name_, string race_, string type_, int health_) : name(name_), race(race_), type(type_), health(health_)
{}

// getter functions
string Character::getName() const
{
	return name;
}


string Character::getRace() const
{
	return race;
}

int Character::getHealth() const
{
	return health;
}

string Character::getType() const
{
	return type;
}

// setter functions
void Character::setHealth(int health_)
{
	health = health_;
}

void Character::setName(string name_)
{
	name = name_;
}


void Character::setRace(string race_)
{
	race = race_;
}


void Character::setType(string type_) {
	type = type_;
}


void Character::print()
{
	cout << "Character Status: " << endl;
	cout << "Type: " << type << endl;
	cout << "Name: " << name << endl;
	cout << "Race: " << race << endl;
	cout << "Health: " << health << endl;
}