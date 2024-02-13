#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include <iostream>
#include <string>
#include <vector>

#include"Viagens.h"

using namespace std;

class Fornecedor {
	string nome;
	int nif;
	string morada;
	vector<Ofertas *> ofertas;
	;

public:
	Fornecedor();
	Fornecedor(string nome, int NIF, string morada, vector<Ofertas> ofertas);
	void setNome(string nome);
	void setNif(int nif);
	void setMorada(string morada);
	string getNome();
	int getNif();
	string getMorada();
	/*tem que ser um vector porque muda consoante a percentagem de lugares ocupados*/
	void getFornecedores(istream &isV);

};

#endif
