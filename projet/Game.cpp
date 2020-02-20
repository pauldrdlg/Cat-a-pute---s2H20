//Used for cout and _message
#include <iostream>
#include <string>

//Used for delay
#include <thread>
#include <chrono>

//Used filed
#include "Vecteur.h"
#include "Message.h"
#include "Player.h"
#include "Game.h"


using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, 1000ms, s, h, etc.
using std::chrono::system_clock;

Game::Game(int numberOfPlayer) {
	srand(time(0));
};

Game::~Game() {
	delete _players;
}

void Game::makeGame(int numberOfPlayer) {
	
	_players = new Player * [numberOfPlayer];
	_numberOfPlayer = numberOfPlayer;
	
	if (_numberOfPlayer == 1) 
	{
		_makeSinglePlayerGame();
	}
	else 
	{
		_makeMultiPlayerGame();
	}
}

void Game::_makeSinglePlayerGame() {
	_players[0] = new Player;

	_askQuestion(_message.askNameSingle, _players[0]->name);

	for (int i = 0; i < _initSequenceLenght; i++) {
		_addNextSequence(_players[0]);
	}

	sleep_for(1000ms);
}

void Game::_makeMultiPlayerGame() {
	cout << _message.askNameMulti_1;
	for (int i = 0; i < _numberOfPlayer; i++) {
		_players[i] = new Player;
		_askQuestion(_message.askNameMulti_2 + _message.multiOrder[i] + _message.askNameMulti_3, _players[i]->name);

		cout << endl;
		for (int j = 0; j < _initSequenceLenght; j++) {
			_addNextSequence(_players[i]);
		}
		sleep_for(1000ms);
	}
}

void Game::mainMenu() {
	cout << _message.mainMenu;
}

void Game::play() {
	string playerAnswer;

	do {
		cout << _message.round << (_round + 1) << endl << endl;
		for (int i = 0; i < _numberOfPlayer; i++) {
			if (_players[i]->eliminated) continue;

			cout << _players[i]->name << _message.askIsReady << endl;

			do {} while (cin.get() != '\n');

			cout << _message.countDown;
			sleep_for(1000ms);

			for (int j = 3; j > 0; j--) {
				cout << j << "... ";
				sleep_for(1000ms);
			}

			cout << endl;

			for (int j = 0; j < _players[i]->sequence.qty(); j++) {
				char tmp = _players[i]->sequence.getElement(j);
				cout << tmp;
				cout << " ";
				sleep_for(1000ms);
			}

			_askQuestion(_message.askEnterAnswer, playerAnswer);

			if (_isPlayerAnswerGood(_players[i]->sequence, playerAnswer)) {
				_addNextSequence(_players[i]);
				cout << _message.goodAnswer;
			}
			else {
				_eleminatPlayer(_players[i]);
				cout << _message.eleminated;
			}
			sleep_for(1000ms);
		}
		_round++;
	} while (!_isGameOver());
};


bool Game::_isGameOver() {
	for (int i = 0; i < _numberOfPlayer; i++) {
		if (!_players[i]->eliminated) {
			return false;
		}
	}
	return true;
}

void Game::_addNextSequence(Player * player) {
	int sequenceOption;

	do {
		if (rand() % 2 == 1)
		{
			if (rand() % 2 == 1)
			{
				sequenceOption = 0;
			}
			else
			{
				sequenceOption = 1;
			}
		}
		else
		{
			if (rand() % 2 == 0)
			{
				sequenceOption = 2;
			}
			else
			{
				sequenceOption = 3;
			}
		}
	} while (sequenceOption == player->sequence.getElement(player->sequence.qty() - 1) && sequenceOption == player->sequence.getElement(player->sequence.qty() - 2));


	player->sequence.add(_sequenceOption[sequenceOption]);
};

bool Game::_isPlayerAnswerGood(Vecteur<char> & sequence, string answer) {

	if (answer.length() == sequence.qty() * 2 - 1) {
		for (int i = 0; i < sequence.qty(); i++) {
			if (sequence.getElement(i) != toupper(answer[i * 2])) {
				return false;
			}
		}
		return true;
	}
	return false;
}

void Game::_eleminatPlayer(Player * player) {
	player->eliminated = true;
	player->score = _round;
}

void Game::_askQuestion(string question, string & answer) {
	cout << question << endl;
	getline(cin >> ws, answer);
}