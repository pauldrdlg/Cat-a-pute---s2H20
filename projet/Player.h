#ifndef PLAYER_H
#define PLAYER_H

#include "Vecteur.h";
#include <string>

struct Player {
	std::string name;
	int score = 0;
	bool eliminated = false;
	Vecteur<char> sequence;
};
#endif