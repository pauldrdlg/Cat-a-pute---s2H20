#ifndef VECTEUR_H
#define VECTEUR_H
template <typename T>
class Vecteur {
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
Vecteur<T>::Vecteur(int capacity) {
	_capacity = capacity;
	_qty = 0;
	_ptrArray = new T[_capacity];
};

template<typename T>
Vecteur<T>::~Vecteur() {
	delete _ptrArray;
	_qty = 0;
};

template <typename T>
void Vecteur<T>::expand() {
	_capacity *= 2;
	T * tmp = new T[_capacity];
	for (int i = 0; i < _qty; i++) {
		tmp[i] = _ptrArray[i];
	}
	delete _ptrArray;
	_ptrArray = tmp;
};

template <typename T>
int Vecteur<T>::qty() {
	return _qty;
};

template <typename T>
bool Vecteur<T>::add(T element) {
	if (_qty == _capacity) {
		this->expand();
	}
	_ptrArray[_qty++] = element;
	return true;
};

template <typename T>
T Vecteur<T>::getElement(int index) {
	return (index >= 0 && index < _qty) ? _ptrArray[index] : NULL;
};
#endif
