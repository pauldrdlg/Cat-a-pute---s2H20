#ifndef PLAYER_H
#define PLAYER_H

#include "Vecteur.h";

struct Player {
	string name;
	int score = 0;
	bool eliminated = false;
	Vecteur<char> sequence;
};
#endif