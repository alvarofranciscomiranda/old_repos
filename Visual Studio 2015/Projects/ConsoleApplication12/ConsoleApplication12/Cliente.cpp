#include "Cliente.h"


Cliente::Cliente(string nome, string morada) {
	this->nome = nome;
	this->morada = morada;
}

string Cliente::getNome() const {
	return nome;
}

void Cliente::setNome(string nome) {
	this->nome = nome;
}

string Cliente::getMorada() const {
	return morada;
}

void Cliente::setMorada(string morada) {
	this->morada = morada;
}

void Cliente::imprimeDados() const {
	cout << "Nome: " << nome << endl;
	cout << "Morada: " << morada << endl;
}

//Se imprime aqui é porque é ocasional
void Cliente::imprimePontos() const {
	cout << "Cliente sem pontos, é cliente ocasional." << endl;
}

//Clientes Registados
ClienteRegistado::ClienteRegistado(string nome, string morada, int pontos) :Cliente(nome, morada)
{
	this->pontos = pontos;
}

bool ClienteRegistado::addpontos(int pontos)
{
	this->pontos += pontos;
	return true;
}

bool ClienteRegistado::subpontos(int pontos)
{
	this->pontos -= pontos;
	return true;
}

int ClienteRegistado::getPontos(int pontos) {
	return pontos;
}

void ClienteRegistado::imprimePontos() const {
	cout << "O cliente " << nome << "tem " << pontos << "acumulados" << endl;
}

void ClienteRegistado::imprimeDados() const {
	cout << "Nome: " << nome << endl;
	cout << "Morada: " << morada << endl;
	cout << "Pontos: " << pontos << endl;
}
