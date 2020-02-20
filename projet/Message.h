#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

using namespace std;

struct Message {
	string askNameSingle = "Avant de commencer, je vais prendre votre nom:";
	string multiOrder[4] = { "premier", "deuxiexe", "troisieme", "quatrieme" };
	string askNameMulti_1 = "Avant de commencer, je vais prendre les noms de tous\n";
	string askNameMulti_2 = "Entrer le nom du ";
	string askNameMulti_3 = " joueur:";
	string round = "\nRonde: ";
	string askIsReady = ", c'est votre tour de jouer! Etes-vous pret? (Appuyer sur une ENTRER pour continuer)";
	string countDown = "La sequence a memoriser commencera dans... ";
	string askEnterAnswer = "\nEntrer la sequence en separant les caracteres d'espace:";
	string eleminated = "Vous n'avez pas rentre la bonne sequence! Vous etes elemine :(\n\n";
	string goodAnswer = "Vous avez eu la bonne reponse! Continuer comme ca :)\n\n";
	string mainMenu = "\nMENU PRINCIPAL\n1. Jouer en solo\n2. Jouer avec des \"amis\" (2-4)\n3. Voir la liste des meilleurs scores\n4. Quitter\nEntre le numero du menu: ";
	string mainMenuERROR_1 = "\nVous n'avez pas entre une option valide\n";
};
#endif
