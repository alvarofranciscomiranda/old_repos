#include "Barco.h"

//Construtores
Barco::Barco() {}

Barco::Barco(int lotacao, int preco_uso)
	: lotacao(lotacao), preco_uso(preco_uso) {
	this->vagas = lotacao;
}

Barco::Barco(string tipo, int lotacao, int preco_uso)
	: tipo(tipo), lotacao(lotacao), preco_uso(preco_uso) {
	this->vagas = lotacao;
}

//get functions
string Barco::getTipo() const {
	return this->tipo;
}

int Barco::getVagas() const {
	return this->vagas;
}

int Barco::getLotacao() const {
	return this->lotacao;
}

int Barco::getPreco_uso() const {
	return this->preco_uso;
}

//set functions
void Barco::setTipo(string tipo) {
	this->tipo = tipo;
}

void Barco::setVagas(int vagas) {
	this->vagas = vagas;
}

void Barco::setLotacao(int lotacao) {
	this->lotacao = lotacao;
}

void Barco::setPreco_uso(int preco_uso) {
	this->preco_uso = preco_uso;
}

//Diferentes tipos de Barco
Iate::Iate(int lotacao, int preco_uso)
	:Barco(lotacao, preco_uso) {
	this->setTipo("Iate");
}

Barco_Rebelo::Barco_Rebelo(int lotacao, int preco_uso)
	: Barco(lotacao, preco_uso) {
	this->setTipo("Barco_Rebelo");
}

Veleiro::Veleiro(int lotacao, int preco_uso)
	: Barco(lotacao, preco_uso) {
	this->setTipo("Veleiro");
}
