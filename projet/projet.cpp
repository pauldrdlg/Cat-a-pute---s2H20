#include "Game.h"
#include "Sauvegarder.h"
#include "Vecteur.h"
#include "Player.h"

int main()
{
	
	Game g(1);
	g.play();
	return 0;
	/*
	Sauvegarder sauv;
	Vecteur<Player> *ss = new Vecteur<Player>;

	Player *player = new Player;

	player->name = "Paul";
	player->score = 300;

	ss->add(*player);

	sauv.sauvegarder(*ss);
	return 0;*/
}
