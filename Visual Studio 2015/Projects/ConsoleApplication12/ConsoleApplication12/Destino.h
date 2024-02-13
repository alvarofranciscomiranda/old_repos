#ifndef DESTINO_H
#define DESTINO_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Destino {
	string nome;
	int distancia;
public:
	Destino();
	Destino(string nome, int distancia);
	string getDestino();
	int getDistancia();
	void setDestino(string nome);
	void setDistancia(int distancia);

};

#endif