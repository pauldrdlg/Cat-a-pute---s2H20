#pragma once

#include <iostream>
#include <fstream>
#include "Vecteur.h"
#include "Player.h"
#include <fstream>

using namespace std;

class Sauvegarder
{
public:
	void sauvegarder(Vecteur<Player> &sauvegarde);
	Vecteur<Player>& lire();
};

