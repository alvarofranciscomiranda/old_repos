#include "Cliente.h"


//Clientes Registados
ClienteRegistado::ClienteRegistado(string nome, int pontos)
{
	this->nome = nome;
	this->pontos = pontos;
}

string ClienteRegistado::getnome()
{
	return this->nome;
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


//Clientes Ocasionais
ClientesOcasionais::ClientesOcasionais(string nome)
{
	this->nome = nome;
}

string ClientesOcasionais::getnome()
{
	return this->nome;
}
