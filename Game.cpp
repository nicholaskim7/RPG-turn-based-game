#include <iostream>
#include <string>
#include <cstdlib>
#include "Game.h"
#include "Character.h"
#include <iostream>
#include <fstream>
using namespace std;

string filename = "savegame.txt";
ofstream output;

Game::Game() : currentTurn(0), numOpponents(0) {}


void Game::RemoveOpponent(int index)
{
	if (index < 0 || index >= numOpponents)
	{
		cout << "Invalid index!" << endl;
	}
	else
	{

		for (int i = index; i < numOpponents - 1; i++)
		{
			opponents[i] = opponents[i + 1];
		}

		numOpponents--;

	}
}


void Game::AddOpponent(Soldier* s)
{
	if (numOpponents == 2)
	{
		cout << "Character limit reached, please wait for the next game!" << endl;
	}
	else
	{
		opponents[numOpponents] = s;
		numOpponents++;
	}
}

void Game::AddOpponent(Archer* a)
{
	if (numOpponents == 2)
	{
		cout << "Character limit reached, please wait for the next game!" << endl;
	}
	else
	{
		opponents[numOpponents] = a;
		numOpponents++;
	}
}

int Game::NextTurn()
{
	if (currentTurn == 0)
	{
		currentTurn = currentTurn + 1;
	}
	else if (currentTurn == 1)
	{
		currentTurn = currentTurn - 1;
	}
	return currentTurn;

}

// testing
void Game::AttackOpp() {
	if (numOpponents != 2) {
		cout << "Need more players!" << endl;
	}
	else {
		if (currentTurn == 0) {
			opponents[0]->attack(opponents[1]);
			if (opponents[1]->getHealth() <= 0) {
				cout << opponents[0]->getName() << " wins!" << endl;
				exit(0);
			}
			cout << "---------------------" << endl;
			cout << opponents[1]->getName() << "'s turn." << endl;
			NextTurn();

		}
		else if (currentTurn == 1) {
			opponents[1]->attack(opponents[0]);
			if (opponents[0]->getHealth() <= 0) {
				cout << opponents[1]->getName() << " wins!" << endl;
				exit(0);
			}
			cout << "---------------------" << endl;
			cout << opponents[0]->getName() << "'s turn." << endl;
			NextTurn();
		}
	}
}

void Game::Skip() {
	if (currentTurn == 0) {
		if (opponents[0]->getType() == "Archer") {
			opponents[0]->setStamina(opponents[0]->getStamina() + 5);
			cout << opponents[0]->getName() << "skipped turn + 5 energy" << endl;
		}
		else if (opponents[0]->getType() == "Soldier") {
			opponents[0]->setStamina(opponents[0]->getStamina() + 5);
			cout << opponents[0]->getName() << "skipped turn + 5 stamina" << endl;
		}
		
		NextTurn();
	}
	else if (currentTurn == 1) {
		if (opponents[1]->getType() == "Soldier") {
			opponents[1]->setStamina(opponents[1]->getStamina() + 5);
			cout << opponents[1]->getName() << "skipped turn + 5 stamina" << endl;
		}
		else if (opponents[1]->getType() == "Archer") {
			opponents[1]->setStamina(opponents[1]->getStamina() + 5);
			cout << opponents[1]->getName() << "skipped turn + 5 energy" << endl;
		}
		NextTurn();
	}

}


void Game::nextWeap() {
	if (currentTurn == 0) {
		if (opponents[0]->getType() == "Archer") {
			opponents[0]->nextWeapon();
		}
		else if (opponents[0]->getType() == "Soldier") {
			opponents[0]->nextWeapon();
		}
		NextTurn();
	}
	else if (currentTurn == 1) {
		if (opponents[1]->getType() == "Archer") {
			opponents[1]->nextWeapon();
		}
		else if (opponents[1]->getType() == "Soldier") {
			opponents[1]->nextWeapon();
		}
		NextTurn();
	}
}

void Game::Save() {
	string filename;
	filename = "savegame.txt";
	ofstream output(filename);
	if (!output.is_open())
	{
		cout << "file not found!" << endl;
		exit(0);
	}
	output << opponents[0]->getType() << endl;
	output << opponents[0]->getName() << endl;
	output << opponents[0]->getRace() << endl;
	output << opponents[0]->getStamina() << endl;
	output << opponents[0]->getHealth() << endl;
	//output << opponents[0]->WEAPONINFO;
	output << endl;
	output << opponents[1]->getType() << endl;
	output << opponents[1]->getName() << endl;
	output << opponents[1]->getRace() << endl;
	output << opponents[1]->getStamina() << endl;
	output << opponents[1]->getHealth() << endl;
	output.close();
	//output << opponents[1]->WEAPONINFO;


	//if (opponents[0]->getType() == "Archer") {
		//for (int i = 0; i < opponents[0]->; i++)
		//{
		//	cout << arrows[i].arrowType << " Dmg: " << arrows[i].arrowDamage << " EnergyCost: " << arrows[i].energyCost << endl;
		//}
	//}

}



void Game::Print()
{
	for (int i = 0; i < numOpponents; i++)
	{
		opponents[i]->print();
		cout << endl;
	}
}