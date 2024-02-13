#ifndef PORTORIVERS_H
#define PORTORIVERS_H

#include<iostream>
#include<string>
#include<vector>

#include"Fornecedor.h"
#include"Cliente.h"

using namespace std;

class PortoRivers {
	vector<Fornecedor *> fornecedores;
	vector<ClienteRegistado *> clientesregistados;
	vector<ClientesOcasionais *> clientesocasionais;
};

#endif