#include"Data.h"

using namespace std;

Data::Data(int dia, string mes, int ano) {

	this->ano = ano;

	vector<string> meses{ "janeiro", "fevereiro", "marco", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro" };
	bool mesvalido = false;

	for (unsigned int i = 0; i < meses.size(); i++)
	{
		if (mes == meses.at(i))
		{
			this->mes = mes;
			mesvalido = true;
		}
	}

	if (!mesvalido)
	{
		throw exception("Not a valid month \n");
	}

	int maxdias;

	if (mes == "janeiro" || mes == "marco" || mes == "maio" || mes == "junho" || mes == "agosto" || mes == "outubro" || mes == "dezembro")
		maxdias = 31;

	if (mes == "abril" || mes == "junho" || mes == "setembro" || mes == "novembro")
		maxdias = 30;

	if (mes == "fevereiro" && ano % 4 == 0)
		maxdias = 29;
	else
		maxdias = 28;

	if (dia < maxdias)
		this->dia = dia;
	else
		throw exception("Not a valid day \n");
}


//devolve a diferença em dias entre duas datas
int Data::operator-(Data & p)
{
	if (p.mes == this->mes)
	{
		return this->dia - p.getdia();
	}

	int indice;
	vector<string> meses{ "janeiro", "fevereiro", "marco", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro" };
	
	for (unsigned int i = 0; i < meses.size(); i++)
	{
		if (p.getmes() == meses.at(i))
		{
			indice = i;
		}
	}

	if (indice == 1 || indice == 3 || indice == 5 || indice == 7 || indice == 8 || indice == 10 || indice == 12)
		return 31 - p.getdia() + this->dia;

	if (indice == 4 || indice == 6 || indice == 9 || indice == 11)
		return 30 - p.getdia() + this->dia;
	
	if(indice == 2 && p.getano() % 4 == 0)
		return 29 - p.getdia() + this->dia;
	else
		return 28 - p.getdia() + this->dia;
}


int Data::getdia()
{
	return this->dia;
}

string Data::getmes()
{
	return this->mes;
}

int Data::getano()
{
	return this->ano;
}
