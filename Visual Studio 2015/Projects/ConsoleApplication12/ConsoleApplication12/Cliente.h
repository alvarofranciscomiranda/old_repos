#ifndef CLIENTE_H
#define CLIENTE_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;
/**
* @brief Client class: has a name and a adress. There are two types of Clients (Ocasional and Registado) and so the Clients class is abstract.
*/
class Cliente {
protected:
	string nome;
	string morada;
	//reservas?
public:
	/**
	* @brief Client constructor
	*/
	Cliente();
	/**
	* @brief Client constructor
	* @param nome Nome do Cliente
	* @param morada Morada do cliente
	*/
	Cliente(string nome, string morada);
	/**
	* @return Client Name
	*/
	virtual string getNome() const;
	/**
	* @brief Sets Client Name
	* @param nome Client Name
	*/
	void setNome(string nome);
	/**
	* @return Client Adress
	*/
	virtual string getMorada() const;
	/**
	* @brief Sets Client Adress
	* @param morada Client Adress
	*/
	void setMorada(string morada);
	/**
	* @brief Prints Client Info
	*/
	void imprimeDados() const;
	/**
	* @brief Prints Client Points
	*/
	void imprimePontos() const;
};

/**
* @brief ClienteRegistado is a Client sub-class, of clients that are registed in the company.
*/

class ClienteRegistado : public Cliente {
private:
	unsigned int pontos;
public:
	/**
	* @brief ClientRegistado constructor
	*/
	ClienteRegistado(string nome, string morada, int pontos);
	/**
	* @brief Add Points to Registered Client
	* @param pontos Points to add
	*/
	bool addpontos(int pontos);
	/**
	* @brief Removes Points to Registered Client (Example: if a reservation is removed)
	* @param pontos Points to remove
	*/
	bool subpontos(int pontos);
	/**
	* @return ClienteRegistado Points
	*/
	int getPontos(int pontos);
	/**
	* @brief Prints Points
	*/
	void imprimePontos() const;
	/**
	* @brief Prints ClienteRegistado Info
	*/
	void imprimeDados() const;
	/**
	* @return type of ClienteRegistado
	*/
	bool typeRegistado() { return true; }
};

#endif
