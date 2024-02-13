#ifndef BARCO_H
#define BARCO_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Barco {
	string tipo;
	int lotacao;
	int vagas;
	int preco_uso;

public:
	Barco();
	Barco(int lotacao, int preco_uso);
	Barco(string tipo, int lotacao, int preco_uso);
	string getTipo() const;
	int getVagas() const;
	int getLotacao() const;
	int getPreco_uso() const;
	void setTipo(string tipo);
	void setVagas(int vagas);
	void setLotacao(int lotacao);
	void setPreco_uso(int preco_uso);

};


class Iate : public Barco {

public:
	Iate(int lotacao, int preco_uso);
};


class Barco_Rebelo : public Barco {

public:
	Barco_Rebelo(int lotacao, int preco_uso);
};


class Veleiro : public Barco {

public:
	Veleiro(int lotacao, int preco_uso);
};
#endif

