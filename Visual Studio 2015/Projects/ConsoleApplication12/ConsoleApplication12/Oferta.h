#ifndef OFERTA_H
#define OFERTA_H

#include <iostream>
#include <string>
#include <vector>

#include "Data.h"
#include "Barco.h"
#include "Destino.h"

using namespace std;

class Oferta {
private:
	Barco barco;
	vector<Destino> destinos;
	Data data;
	int preco;
public:
	Oferta();
	Oferta(Barco barco, Data data);

	Barco getCruzeiro();
	vector<Destino> getDestinos();
	Data getData();
	int getPreco();

	void setBarco(Barco barco);
	void setData(Data data)
		void setDestino(Destino destino);
	void setPreco();


#endif /* oferta_h */
