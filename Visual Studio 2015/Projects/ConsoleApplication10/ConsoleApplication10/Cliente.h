#include<iostream>
#include<string>
#include<vector>

using namespace std; 

class ClienteRegistado {
	string nome;
	int pontos;
public:
	ClienteRegistado(string nome, int pontos);
	string getnome();
	bool addpontos(int pontos);
	bool subpontos(int pontos);
};

class ClientesOcasionais {
	string nome;
public:
	ClientesOcasionais(string nome);
	string getnome();
};


