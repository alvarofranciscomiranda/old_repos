#include "menu.h"
#include <iostream>

using namespace std;

int initialMenu() {

	int aux;

	cout << "MENU" << endl;
	cout << "Select on of the following options : " << endl;
	cout << "1 - Fornecedores" << endl;
	cout << "2 - Clientes" << endl;
	cout << "3 - Ofertas" << endl;
	cout << "4 - Viagens" << endl;
	cout << "5 - Reservas" << endl;
	cout << "6 - Pontos" << endl;
	cout << "7 - Sair" << endl;

	cin >> aux;
	return aux;
}

void chama() {
	bool sair = false;
	int aux_chama;
	while (!sair) {
		aux_chama = initialMenu();

		if (aux_chama == 1) {
			cout << string(100, '\n');
			menuForn();
		}
		else if (aux_chama == 2) {
			cout << string(100, '\n');
			menuCli();
		}
		else if (aux_chama == 3) {
			cout << string(100, '\n');
			menuOfe();
		}
		else if (aux_chama == 4) {
			cout << string(100, '\n');
			menuViagens();
		}
		else if (aux_chama == 5) {
			cout << string(100, '\n');
			menuRes();
		}
		else if (aux_chama == 6) {
			cout << string(100, '\n');
			menuPon();
		}
		else if (aux_chama == 7)
			break;

		else {
			cout << "Opcao inválida" << endl;
			cout << string(30, '\n');
			initialMenu();
		}
	}
}

//tentar guardar isto tudo em ficheiros

void menuForn() {
	cout << "Informação sobre fornecedores" << endl;

	//opcao 1 add fornecedor
	//opcao 2 remove fornecedor
	//opcao 3 criar um ficheiro onde guarda tudo (para nao se perder sempre que corre) e apresenta por id?
}

void menuCli() {
	cout << "Informação sobre cliente" << endl;

	//opcao 1 add cliente
	//opcao 2 remove cliente
	//opcao 3 edita tipo cliente registado ou nao
	//opcao 4 mostra clientes
}

void menuOfe() {
	cout << "Ofertas" << endl;
	//opcao 1 ver ofertas
	//opcao 2 ver tipos (iate, rabelo, veleiro) por nome (mostrar lotação)
	//opcao 3 ver destinos por nome
	//opcao 4 add barcos de tipo
	//opcao 5 add destino a barco
}

void menuViagens() {
	//op1 show viagens
	//op2 insere viagem
	//op3 remove viagem

}

void menuRes() {
	//op1 add reserva
	//op2 cancela reserva
}

void menuPon() {
	//op1 show pontos cliente de nome x
}
