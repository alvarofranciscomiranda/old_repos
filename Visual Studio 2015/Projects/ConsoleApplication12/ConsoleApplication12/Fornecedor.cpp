#include"Fornecedor.h"

Fornecedor::Fornecedor()
{}

Fornecedor::Fornecedor(string nome, int NIF, string morada, vector<Ofertas> ofertas) {
}

//Set functions
void Fornecedor::setNome(string nome) {
	this->nome = nome;
}

void Fornecedor::setNif(int nif) {
	this->nif = nif;
}

void Fornecedor::setMorada(string morada) {
	this->morada = morada;
}


//get functions
string Fornecedor::getNome() {
	return nome;
}

int Fornecedor::getNif() {
	return nif;
}



