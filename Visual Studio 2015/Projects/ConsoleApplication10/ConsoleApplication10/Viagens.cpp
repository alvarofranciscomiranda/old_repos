#include "Viagens.h"

Viagens::Viagens(string tipo, string destino, Data &data, double preco)
{
	this->tipo = tipo;
	this->destino = destino;
	this->data = data;
	this->preco = preco;
}
