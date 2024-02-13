#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Line.h"
#include "Driver.h"


using namespace std;

class Company{
 private:
  string name;
  vector<Driver> drivers;
  vector<Line> lines;
 public:
	 Company(string name, string Driverfile, string Linefile);
  // metodos get
  string getName() const;
  // metodos set
  // outros metodos
  void Servicedistributor(); // funcao que implementa a afectacao de servico
};
