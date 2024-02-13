#include "Destino.h"

//construtores
Destino::Destino() {}

Destino::Destino(string nome, int distancia)
	:nome(nome), distancia(distancia) {
}

//get functions
string Destino::getDestino() {
	return this->nome;
}

int Destino::getDistancia() {
	return this->distancia;
}

//set functions
void Destino::setDestino(string nome) {
	this->nome = nome;
}

void Destino::setDistancia(int distancia) {
	this->distancia = distancia;
}
