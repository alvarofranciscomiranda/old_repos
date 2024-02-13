#include<iostream>
#include<string>
#include<vector>

#include"Viagens.h"

using namespace std;

class Fornecedor {
	string nome;
	int NIF;
	string morada;
	vector<Viagens *> viagens;
	
public:
	Fornecedor(string nome, int NIF, string morada, vector<Viagens> viagens);
};

