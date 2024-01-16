#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include "Character.h"
#include "Archer.h"
#include "Soldier.h"

using namespace std;

class Game {

private:
	Character* opponents[2];
	int currentTurn;
	int numOpponents;
	bool oppType[2];

public:
	Game();
	void RemoveOpponent(int index);
	void AddOpponent(Soldier* s);
	void AddOpponent(Archer* a);
	int NextTurn();
	void AttackOpp();
	void Skip();
	void Save();
	
	void nextWeap();
	void Print();
	int getOpponents() { return numOpponents; }
	int getTurn() { return currentTurn; }
	//void setOppType(int in, bool sol);
	//bool isOppSol(int in);
};

#endif