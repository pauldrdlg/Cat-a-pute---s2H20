#include "Sauvegarder.h"

void Sauvegarder::sauvegarder(Vecteur<Player> &sauvegarde)
{
	ofstream myFile;
	myFile.open(".//Sauvegarde.txt", ios_base::out);

	if(myFile.is_open())
	{
		for (int i = 0; i < sauvegarde.qty(); i++)
		{
			myFile << "Nom : " << sauvegarde.getElement(i).name << endl;
			myFile << "Score : " << sauvegarde.getElement(i).score << endl;
		}
	}
	else
	{
		throw exception("Impossible d'ouvrir le fichier en écriture!!");
	}
}

Vecteur<Player>& Sauvegarder::lire()
{
	Vecteur<Player> *joueurs = new Vecteur<Player>;

	return *joueurs;
}