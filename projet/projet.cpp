//Used for cout and _message
#include <iostream>
#include <string>
#include <conio.h>

//Used for delay
#include <thread>
#include <chrono>

//Used filed
#include "Vecteur.h"
#include "Menu.h"
#include "Player.h"


using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

<<<<<<< HEAD
template <typename T>
class Vecteur 
{
private:
	T * _ptrArray;
	int _capacity;
	int _qty;

	void expand();

public:
	Vecteur(int capacity = 1);
	~Vecteur();

	int qty();
	T getElement(int index);
	bool add(T element);
};

template<typename T>
Vecteur<T>::Vecteur(int capacity) 
{
	_capacity = capacity;
	_qty = 0;
	_ptrArray = new T[_capacity];
};

template<typename T>
Vecteur<T>::~Vecteur() 
{
	delete _ptrArray;
	_qty = 0;
};

template <typename T>
void Vecteur<T>::expand() 
{
	_capacity *= 2;
	T * tmp = new T[_capacity];

	for (int i = 0; i < _qty; i++) 
	{
		tmp[i] = _ptrArray[i];
	}

	delete _ptrArray;
	_ptrArray = tmp;
};

template <typename T>
int Vecteur<T>::qty() 
{
	return _qty;
};

template <typename T>
bool Vecteur<T>::add(T element) 
{
	if (_qty == _capacity) 
	{
		this->expand();
	}

	_ptrArray[_qty++] = element;
	return true;
};

template <typename T>
T Vecteur<T>::getElement(int index) 
{
	return (index >= 0 && index < _qty) ? _ptrArray[index] : NULL;
};

struct Message 
{
	string askNameSingle = "Avant de commencer, je vais prendre votre nom:\n";
	string multiOrder[4] = { "premier", "deuxiexe", "troisieme", "quatrieme" };
	string askNameMulti_1 = "Avant de commencer, je vais prendre les noms de tous\n";
	string askNameMulti_2 = "Entrer le nom du ";
	string askNameMulti_3 = " joueur:\n";
	string round = "\nRonde: ";
	string askIsReady = ", c'est votre tour de jouer! Etes-vous pret? (Appuyer sur une ENTRER pour continuer)";
	string countDown = "La sequence a memoriser commencera dans... ";
	string askEnterAnswer = "\nEntrer la sequence en separant les caracteres d'espace:\n";
	string eleminated = "Vous n'avez pas rentre la bonne sequence! Vous etes elemine :(\n";
	string goodAnswer = "Vous avez eu la bonne reponse! Continuer comme ca :)\n";
};

struct Player 
{
	string name;
	int score = 0;
	bool eliminated = false;
	Vecteur<char> sequence;
};

class Game 
{
=======
class Game {
>>>>>>> 136ae88515f5dd3c982d126ce3140435fe81a0cd
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

public:
	Game(int numberOfPlayer);
	void play();
};

Game::Game(int numberOfPlayer) 
{
	_players = new Player *[numberOfPlayer];
	_numberOfPlayer = numberOfPlayer;

	if (_numberOfPlayer == 1) 
	{
		_players[0] = new Player;
		cout << _message.askNameSingle;
		cin >> _players[0]->name;

		for (int i = 0; i < _initSequenceLenght; i++) 
		{
			_addNextSequence(_players[0]);
		}

		sleep_for(1000ms);
	}
	else 
	{
		cout << _message.askNameMulti_1;

		for (int i = 0; i < _numberOfPlayer; i++) 
		{
			cout << _message.askNameMulti_2 << _message.multiOrder[i] << _message.askNameMulti_3;
			cin >> _players[i]->name;
			cout << endl;

			for (int i = 0; i < _initSequenceLenght; i++) 
			{
				_addNextSequence(_players[i]);
			}

			sleep_for(1000ms);
		}
	}
};

void Game::play() 
{
	string playerAnswer;
<<<<<<< HEAD
	char doNothing;
	do 
	{
		string playerAnswer;
=======
	do {
>>>>>>> 136ae88515f5dd3c982d126ce3140435fe81a0cd
		cout << _message.round << (_round + 1) << endl << endl;

		for (int i = 0; i < _numberOfPlayer; i++) 
		{
			if (_players[i]->eliminated) continue;
			cout << _players[i]->name << _message.askIsReady;
			cout << _message.countDown;
			sleep_for(1000ms);

			for (int j = 3; j > 0; j--) 
			{
				cout << j << "... ";
				sleep_for(1000ms);
			}

			cout << endl;

			for (int j = 0; j < _players[i]->sequence.qty(); j++) 
			{
				char tmp = _players[i]->sequence.getElement(j);
				cout << tmp;
				cout << " ";
				sleep_for(1000ms);
			}

			_askQuestion(_message.askEnterAnswer, playerAnswer);

<<<<<<< HEAD
			if (_isPlayerAnswerGood(_players[i]->sequence, playerAnswer)) 
			{
				_eleminatPlayer(_players[i]);
				cout << _message.eleminated;
			}
			else 
			{
				_addNextSequence(_players[i]);
				cout << _message.goodAnswer;

				for (int j = 0; j < _players[i]->sequence.qty(); j++) 
				{
					char tmp = _players[i]->sequence.getElement(j);
					cout << tmp;
					cout << " ";
					sleep_for(1000ms);
				}
=======
			if (_isPlayerAnswerGood(_players[i]->sequence, playerAnswer)) {
				_addNextSequence(_players[i]);
				cout << _message.goodAnswer;
			}
			else {
				_eleminatPlayer(_players[i]);
				cout << _message.eleminated;
>>>>>>> 136ae88515f5dd3c982d126ce3140435fe81a0cd
			}
			sleep_for(1500ms);
		}
		_round++;
	} while (!_isGameOver());
};


bool Game::_isGameOver() 
{
	for (int i = 0; i < _numberOfPlayer; i++) 
	{
		if (!_players[i]->eliminated) 
		{
			return false;
		}
	}
	return true;
}

void Game::_addNextSequence(Player * player) 
{
	char option;
	option = _sequenceOption[0];
	player->sequence.add(option);
};

<<<<<<< HEAD
bool Game::_isPlayerAnswerGood(Vecteur<char> & sequence, string answer) 
{
	if (answer.length() / 2 == sequence.qty()) 
	{
		for (int i = 0; i < sequence.qty(); i++) 
		{
			if (sequence.getElement(i) != answer[i * 2]) 
			{
=======
bool Game::_isPlayerAnswerGood(Vecteur<char> & sequence, string answer) {

	if (answer.length() / 2 == sequence.qty()) {
		for (int i = 0; i < sequence.qty(); i++) {
			cout << answer[i * 2] << endl;
			cout << sequence.getElement(i) << endl;

			if (sequence.getElement(i) != answer[i * 2]) {
>>>>>>> 136ae88515f5dd3c982d126ce3140435fe81a0cd
				return false;
			}
		}
		return true;
	}
	return false;
}

void Game::_eleminatPlayer(Player * player) 
{
	player->eliminated = true;
	player->score = _round;
}

<<<<<<< HEAD
void Game::_askQuestion(string question, string & answer) 
{
	cout << question;
=======
void Game::_askQuestion(string question, string & answer) {
	cout << question << endl;
	std::cin.clear();
	std::cin.ignore();
>>>>>>> 136ae88515f5dd3c982d126ce3140435fe81a0cd
	cin >> answer;
}

int main()
{
	Game g(1);
	g.play();
	return 0;
}
