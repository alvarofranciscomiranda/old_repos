#ifndef DATA_H
#define DATA_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Data {
	int dia;
	string mes;
	int ano;
public:
	Data();
	Data(int dia, string mes, int ano);
	int operator-(Data &p);
	int getdia();
	string getmes();
	int getano();
};

#endif

