#pragma once

#include <iostream>
#include <fstream>
#include "Vecteur.h"
#include "Player.h"

class Sauvegarder
{
public:
	Sauvegarder();
	~Sauvegarder();

private:
	Vecteur<Player> sauvegarde;
};

