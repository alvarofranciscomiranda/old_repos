#include "Oferta.h"

Oferta::Oferta() {}

Oferta::Oferta(Barco barco, Data data) {
	this->barco = barco;
	this->data = data;
	this->destinos = nullptr;
}

Barco Oferta::getCruzeiro() {
	return this->barco;
}

vector<Destino> Oferta::getDestinos() {
	return this->destinos;
}

Data Oferta::getData() {
	return this->data;
}

int Oferta::getPreco() {
	return this->preco;
}

void Oferta::setBarco(Barco barco)
{

}


void Oferta::setDestino(Destino destino)
{
}

void Oferta::setPreco()
{
}
