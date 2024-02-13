#include <iostream>
#include <string>
#include <iomanip>	
#include <math.h>
#include <vector>
#include <fstream>
#include <stdlib.h> 

using namespace std;

struct lane
{
	int linhaID;
	int circfreq;
	vector <string> Paragens;
	vector <int> TempoViagem;
};

struct driver
{
	string name;
	int driverID;
	int hoursPerday;
	int hoursPerweek;
	int restTime;
};

vector <driver> driversList;
vector <lane> laneList;
string lanefileName;
string driversfileName;

void openlaneFile();
void opendriversFile();
void menuPrincipal();
void gestaoLinhas();
void gestaoCondutores();
void informacao();
void apagarLinha();
void addLinha();
void apagarCondutor();
void addCondutor();
void modLinha();
void modCondutor();
void saveLanefile();
void saveDriversfile();

int main()
{
	ifstream laneFile;
	ifstream driversFile;

	openlaneFile();
	opendriversFile();


	menuPrincipal();


	laneFile.close();
	driversFile.close();

	return 0;
}

//_______Abrir os ficheiros________

void openlaneFile()
{
	string line;
	lane lane;
	ifstream laneFile;

	cout << "Nome do ficheiro das linhas " << endl;
	cin >> lanefileName;
	laneFile.open(lanefileName);
	while (laneFile.fail())
	{
		cout << "Erro ao abrir o ficheiro!" << endl;
		cout << "Nome do ficheiro das linhas " << endl;
		cin >> lanefileName;
		cin.ignore();
		laneFile.open(lanefileName);
	}

	while (!laneFile.eof())
	{
		getline(laneFile, line);
		lane.linhaID = stoi(line.substr(0, line.find(';')));
		line = line.substr(line.find(';') + 2);
		lane.circfreq = stoi(line.substr(0, line.find(';') - 1));
		line = line.substr(line.find(';') + 2);
		while (line.find(',') < line.find(';'))
		{
			lane.Paragens.push_back(line.substr(0, line.find(',')));
			line = line.substr(line.find(',') + 2);
		}
		lane.Paragens.push_back(line.substr(0, line.find(';')));
		line = line.substr(line.find(';') + 1);

		for (unsigned int i = 0; i < lane.TempoViagem.size(); i++)
		{
			lane.TempoViagem.push_back(stoi(line.substr(0, line.find(','))));
			line = line.substr(line.find(',') + 2);
		}

		lane.TempoViagem.push_back(stoi(line));
		laneList.push_back(lane);

	}

	laneFile.close();
}

void opendriversFile()
{
	string line;
	driver driver;
	ifstream driversFile;

	cout << "Nome do ficheiro dos condutores " << endl;
	cin >> driversfileName;
	cin.ignore();
	driversFile.open(driversfileName);
	while (driversFile.fail())
	{
		cout << "Erro ao abrir o ficheiro!" << endl;
		cout << "Nome do ficheiro dos condutores " << endl;
		cin >> driversfileName;
		driversFile.open(driversfileName);
	}

	while (!driversFile.eof())
	{
		getline(driversFile, line);
		driver.driverID = stoi(line.substr(0, line.find(';')));
		line = line.substr(line.find(';') + 2);
		driver.name = line.substr(0, line.find(';') - 1);
		line = line.substr(line.find(';') + 2);
		driver.hoursPerday = stoi(line.substr(0, line.find(';')));
		line = line.substr(line.find(';') + 2);
		driver.hoursPerweek = stoi(line.substr(0, line.find(';')));
		line = line.substr(line.find(';') + 2);
		driver.restTime = stoi(line);
		driversList.push_back(driver);
	}
	driversFile.close();
}
//_________Menu_____________

void menuPrincipal()
{
	char l;
	cout << "O que pretende fazer?" << endl;
	cout << "a) Gerir as Linhas" << endl;
	cout << "b) Gerir os Condutores" << endl;
	cout << "c) Visualizar Informacao" << endl;
	cin >> l;
	cin.ignore();
	while (l<'a' || l>'c')
	{
		cout << "Entrada invalida!" << endl;
		cin >> l;
		cin.ignore();
	}
	if (l == 'a')
	{
		gestaoLinhas();
	}
	if (l == 'b')
		gestaoCondutores();
	if (l == 'c')
		informacao();
}

void gestaoLinhas()
{
	char l;
	cout << "a) Apagar linhas " << endl;
	cout << "b) Acrescentar linhas " << endl;
	cout << "c) Modificar linha " << endl;
	cin >> l;
	cin.ignore();
	while (l<'a' || l>'c')
	{
		cout << "Entrada invalida!" << endl;
		cin >> l;
		cin.ignore();
	}
	if (l == 'a')
		apagarLinha();
	if (l == 'b')
		addLinha();
	if (l == 'c')
		modLinha();
}

void gestaoCondutores()
{
	int l;
	cout << "a) Apagar Condutor " << endl;
	cout << "b) Acrescentar Condutor " << endl;
	cout << "c) Modificar Condutor " << endl;
	cin >> l;
	cin.ignore();
	while (l<'a' || l>'c')
	{
		cout << "Entrada invalida!" << endl;
		cin >> l;
		cin.ignore();
	}
	if (l == 'a')
		apagarCondutor();
	if (l == 'b')
		addCondutor();
	if (l == 'c')
		modCondutor();
}

void informacao()
{

}

//_______Gestao_das_linhas__________
void apagarLinha()
{
	int laneID;
	bool valid = false;


	while (!valid)
	{
		cout << "Introduz o ID da linha : ";
		cin >> laneID;
		cin.ignore();
		for (unsigned int i = 0; i < (laneList.size()); i++)
		{

			if (laneID == laneList.at(i).linhaID)
			{
				laneList.erase(laneList.begin() + i);
				valid = true;
				break;
			}
			valid = false;
		}
	}

}

void addLinha()
{
	lane lane;
	string paragens;
	int tempo;
	bool valid = false;


	cout << "Introduz os parametros da linha : " << endl;
	while (!valid)
	{
		cout << "ID da linha:" << endl;
		cin >> lane.linhaID;
		cin.ignore();
		for (unsigned int i = 0; i < laneList.size(); i++)
		{
			if (lane.linhaID == laneList.at(i).linhaID)
			{
				cout << "Essa linha ja existe! " << endl;
				valid = false;
				break;
			}
			valid = true;
		}
	}

	cout << "Frequecia :" << endl;
	cin >> lane.circfreq;
	cin.ignore();

	cout << "Paragens :" << endl;
	while (1)
	{
		getline(cin, paragens);
		cin.ignore();
		if (paragens == "0")
		{
			break;
		}
		lane.Paragens.push_back(paragens);
	}
	cout << "Tempo de Viagem :" << endl;
	while (lane.TempoViagem.size() < (lane.Paragens.size() - 1))
	{
		cin >> tempo;
		cin.ignore();
		lane.TempoViagem.push_back(tempo);
	}
	laneList.push_back(lane);
}

void modLinha()
{
	lane lane;
	string paragens;
	int tempo;
	bool valid = false;


	cout << "Introduz os parametros da linha : " << endl;
	while (!valid)
	{
		cout << "ID da linha:" << endl;
		cin >> lane.linhaID;
		cin.ignore();
		for (unsigned int i = 0; i < laneList.size(); i++)
		{
			if (lane.linhaID == laneList.at(i).linhaID)
			{
				cout << "Frequencia de circulacao:" << endl;
				cin >> laneList.at(i).circfreq;
				cout << "Paragens (escrever 0 quando quiser parar de adicionar) : ";
				while (1)
				{
					getline(cin, paragens);
					if (paragens == "0")
					{
						break;
					}
					laneList.at(i).Paragens.push_back(paragens);
				}

				cout << "Tempos de viagem: ";
				while (laneList.at(i).TempoViagem.size() < (laneList.at(i).Paragens.size() - 1))
				{
					cin >> tempo;
					laneList.at(i).TempoViagem.push_back(tempo);
				}
				valid = true;
				break;
			}
			valid = false;
		}
	}

}

//_______Gestao_dos_Condutores________

void apagarCondutor()
{
	int driverID;
	bool valid = false;

	while (!valid)
	{
		cout << "Introduz o ID do condutor : ";
		cin >> driverID;
		cin.ignore();

		for (unsigned int i = 0; i < (driversList.size()); i++)
		{
			if (driverID == driversList.at(i).driverID)
			{
				driversList.erase(driversList.begin() + i);
				valid = true;
				break;
			}
			valid = false;
		}
	}

}

void addCondutor()
{
	driver driver;
	string nome;
	bool valid = false;


	cout << "Introduz os parametros do condutor: " << endl;
	while (!valid)
	{
		cout << "ID da linha:" << endl;
		cin >> driver.driverID;
		cin.ignore();
		for (unsigned int i = 0; i < driversList.size(); i++)
		{
			if (driver.driverID == driversList.at(i).driverID)
			{
				cout << "Essa linha ja existe! " << endl;
				valid = false;
				break;
			}
			valid = true;
		}
	}
	cin.ignore();
	cout << "Nome do Condutor :" << endl;
	getline(cin, driver.name);

	cout << "Horas de trabalho por dia :" << endl;
	cin >> driver.hoursPerday;

	cout << "Horas de trabalho por semana :" << endl;
	cin >> driver.hoursPerweek;

	cout << "Horas de descanso :" << endl;
	cin >> driver.restTime;

	driversList.push_back(driver);
}

void modCondutor()
{

	int IDdriver;
	bool valid = false;

	cout << "ID da linha:" << endl;
	cin >> IDdriver;
	cin.ignore();
	while (!valid)
	{
		for (unsigned int i = 0; i < driversList.size(); i++)
		{
			if (IDdriver == driversList.at(i).driverID)
			{
				cout << "Nome do Condutor: " << endl;
				getline(cin, driversList.at(i).name);
				cout << "Horas de trabalho por dia:" << endl;
				cin >> driversList.at(i).hoursPerday;
				cout << "Horas de trabalho por semana:" << endl;
				cin >> driversList.at(i).hoursPerweek;
				cout << "Horas de descanso" << endl;
				cin >> driversList.at(i).restTime;
				valid = true;
				break;
			}
			valid = false;
		}
	}
	cout << "Condutor alterado!" << endl;
}

void saveLanefile()
{
	string line;
	ofstream laneOutfile;

	laneOutfile.open(lanefileName);

	for (unsigned int i = 0; i < laneList.size(); i++)
	{
		if (i == (laneList.size() - 1))
		{
			line = to_string(laneList.at(i).linhaID);
			line = line + " ; ";
			line = line + to_string(laneList.at(i).circfreq);
			line = line + " ; ";

			for (unsigned int j = 0; j < (laneList.at(i).Paragens.size() - 1); j++)
			{
				line = line + laneList.at(i).Paragens.at(j);
				line = line + ", ";
			}

			line = line + laneList.at(i).Paragens.at(laneList.at(i).Paragens.size() - 1);
			line = line + "; ";

			for (unsigned int j = 0; j < laneList.at(i).TempoViagem.size() - 1; j++)
			{
				line = line + to_string(laneList.at(i).TempoViagem.at(j));
				line = line + ", ";
			}

			line = line + to_string(laneList.at(i).TempoViagem.at(laneList.at(i).TempoViagem.size() - 1));

			laneOutfile << line;
		}
		else
		{
			line = to_string(laneList.at(i).linhaID);
			line = line + " ; ";
			line = line + to_string(laneList.at(i).circfreq);
			line = line + " ; ";

			for (unsigned int j = 0; j < (laneList.at(i).Paragens.size() - 1); j++)
			{
				line = line + laneList.at(i).Paragens.at(j);
				line = line + ", ";
			}

			line = line + laneList.at(i).Paragens.at(laneList.at(i).Paragens.size() - 1);
			line = line + "; ";

			for (unsigned int j = 0; j < laneList.at(i).TempoViagem.size() - 1; j++)
			{
				line = line + to_string(laneList.at(i).TempoViagem.at(j));
				line = line + ", ";
			}

			line = line + to_string(laneList.at(i).TempoViagem.at(laneList.at(i).TempoViagem.size() - 1));

			laneOutfile << line << endl;

		}
	}
	laneOutfile.close();
}

void saveDriversfile()
{
	string line;
	ofstream driversOutfile;
	driversOutfile.open(driversfileName);

	for (unsigned int i = 0; i < driversList.size(); i++)
	{

		if (i == (driversList.size() - 1))
		{
			line.clear();
			line = to_string(driversList.at(i).driverID);
			line = line + " ; ";
			line = line + driversList.at(i).name;
			line = line + " ; ";
			line = line + to_string(driversList.at(i).hoursPerday);
			line = line + " ; ";
			line = line + to_string(driversList.at(i).hoursPerweek);
			line = line + " ; ";
			line = line + to_string(driversList.at(i).restTime);

		}
		else
		{
			line.clear();
			line = to_string(driversList.at(i).driverID);
			line = line + " ; ";
			line = line + driversList.at(i).name;
			line = line + " ; ";
			line = line + to_string(driversList.at(i).hoursPerday);
			line = line + " ; ";
			line = line + to_string(driversList.at(i).hoursPerweek);
			line = line + " ; ";
			line = line + to_string(driversList.at(i).restTime);
			line = line + "\n";

		}

		driversOutfile << line;

	}

	driversOutfile.close();
}