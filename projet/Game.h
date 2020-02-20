#ifndef GAME_H
#define GAME_H

//Used filed
#include "Player.h"
#include "Message.h"
#include "Game.h"

class Game {
private:
	Player ** _players;
	int _numberOfPlayer;
	int _round = 0;
	int _initSequenceLenght = 3;
	int _sequenceOptionLength = 4;
	Message _message;

	char _sequenceOption[4] = { 'Q', 'W', 'E', 'R' };

	bool _isGameOver();
	bool _isPlayerAnswerGood(Vecteur<char> & sequence, string answer);
	void _addNextSequence(Player * player);
	void _eleminatPlayer(Player * player);
	void _askQuestion(string question, string & answer);
	void _makeSinglePlayerGame();
	void _makeMultiPlayerGame();
public:
	Game(int numberOfPlayer);
	~Game();
	void makeGame(int numberOfPlayer);
	void mainMenu();
	void play();
};

#endif
