#include <iostream>;
#include <string>;
#include <vector>;
#include <fstream>;
#include <iomanip>;
#include "Line.h";
#include "Driver.h";
#include "Bus.h";
#include "Shift.h";
#include <math.h>; 

using namespace std;

vector<Line> line_vetor;
vector<Driver> driver_vetor;
vector<Bus> bus_vetor;
string line_fileName;
string driver_fileName;
vector<int> times_List;
vector<int> timesListMod;
vector<string> busStop_List;
vector<string> busStopListMod;
vector<int> bus_perline;

void separateline() {
	string line2;
	ifstream linefile;
	vector<string> busStopList;
	vector<int> timesList;

	cout << "Name of line file " << endl;
	cin >> line_fileName;
	cin.ignore();
	linefile.open(line_fileName);

	/*line_fileName = "line.txt";
	linefile.open(line_fileName);*/

	while (linefile.fail())
	{
		cerr << "Error in opening file!" << endl;
		cout << "Name of line file" << endl;
		cin >> line_fileName;
		cin.ignore();
		linefile.open(line_fileName);
	}
	while (!linefile.eof())
	{
		Line line;
		getline(linefile, line2);

		line.setId(stoi(line2.substr(0, line2.find(';'))));
		line2 = line2.substr(line2.find(';') + 2);

		line.setFrequency(stoi(line2.substr(0, line2.find(';') - 1)));
		line2 = line2.substr(line2.find(';') + 2);

		while (line2.find(',') < line2.find(';'))
		{
			busStopList.push_back(line2.substr(0, line2.find(',')));
			line2 = line2.substr(line2.find(',') + 2);
		}
		busStopList.push_back(line2.substr(0, line2.find(';')));
		line2 = line2.substr(line2.find(';') + 2);

		line.setBusStopList(busStopList);
		busStopList.clear();

		while (line2.size() > 2)
		{
			timesList.push_back(stoi(line2.substr(0, line2.find(','))));
			line2 = line2.substr(line2.find(',') + 2);
		}
		timesList.push_back(stoi(line2.substr(0, 2)));
		line.setTimings(timesList);
		timesList.clear();

		line_vetor.push_back(line);
	}
	linefile.close();
}

void separatedriver() {
	string line;
	ifstream driverfile;

	cout << "Name of driver file " << endl;
	cin >> driver_fileName;
	cin.ignore();
	driverfile.open(driver_fileName);

	/*driver_fileName = "driver.txt";
	driverfile.open(driver_fileName);*/

	while (driverfile.fail())
	{
		cerr << "Error in opening file!" << endl;
		cout << "Name of driver file" << endl;
		cin >> driver_fileName;
		cin.ignore();
		driverfile.open(driver_fileName);
	}

	while (!driverfile.eof())
	{
		Driver driver;
		getline(driverfile, line);

		driver.setId(stoi(line.substr(0, line.find(';'))));
		line = line.substr(line.find(';') + 2);

		driver.setName(line.substr(0, line.find(';') - 1));
		line = line.substr(line.find(';') + 2);

		driver.setMaxHours(stoi(line.substr(0, line.find(';'))));
		line = line.substr(line.find(';') + 2);

		driver.setMaxWeekWorkingTime(stoi(line.substr(0, line.find(';'))));
		line = line.substr(line.find(';') + 2);

		driver.setMinRestTime(stoi(line));
		driver_vetor.push_back(driver);
	}
	driverfile.close();
}

void save_linefile() {
	string line;
	ofstream lineoutfile;

	lineoutfile.open(line_fileName);

	for (int i = 0; i < line_vetor.size(); i++)
	{
		if (i == (line_vetor.size() - 1))
		{
			line = to_string(line_vetor.at(i).getId());
			line = line + " ; ";

			line = line + to_string(line_vetor.at(i).getFrequency());
			line = line + " ; ";

			for (int p = 0; p < (line_vetor.at(i).getBusStops().size() - 1); p++)
			{
				line = line + line_vetor.at(i).getBusStops().at(p);
				line = line + ", ";
			}
			line = line + line_vetor.at(i).getBusStops().at(line_vetor.at(i).getBusStops().size() - 1);
			line = line + "; ";

			for (int p = 0; p < (line_vetor.at(i).getTimings().size() - 1); p++)
			{
				line = line + to_string(line_vetor.at(i).getTimings().at(p));
				line = line + ", ";
			}
			line = line + to_string(line_vetor.at(i).getTimings().at(line_vetor.at(i).getTimings().size() - 1));

			lineoutfile << line;
		}
		else
		{
			line = to_string(line_vetor.at(i).getId());
			line = line + " ; ";

			line = line + to_string(line_vetor.at(i).getFrequency());
			line = line + " ; ";

			for (int p = 0; p < (line_vetor.at(i).getBusStops().size() - 1); p++)
			{
				line = line + line_vetor.at(i).getBusStops().at(p);
				line = line + ", ";
			}
			line = line + line_vetor.at(i).getBusStops().at(line_vetor.at(i).getBusStops().size() - 1);
			line = line + "; ";

			for (int p = 0; p < (line_vetor.at(i).getTimings().size() - 1); p++)
			{
				line = line + to_string(line_vetor.at(i).getTimings().at(p));
				line = line + ", ";
			}
			line = line + to_string(line_vetor.at(i).getTimings().at(line_vetor.at(i).getTimings().size() - 1));

			lineoutfile << line << endl;
		}
	}
	lineoutfile.close();
}

void save_driverfile() {
	string line;
	ofstream driveroutfile;

	driveroutfile.open(driver_fileName);

	for (size_t i = 0; i < driver_vetor.size(); i++)
	{
		if (i == (driver_vetor.size() - 1))
		{
			line = to_string(driver_vetor.at(i).getId());
			line = line + " ; ";

			line = line + driver_vetor.at(i).getName();
			line = line + " ; ";

			line = line + to_string(driver_vetor.at(i).getShiftMaxDuration());
			line = line + " ; ";

			line = line + to_string(driver_vetor.at(i).getMaxWeekWorkingTime());
			line = line + " ; ";

			line = line + to_string(driver_vetor.at(i).getMinRestTime());

			driveroutfile << line;
		}
		else
		{
			line = to_string(driver_vetor.at(i).getId());
			line = line + " ; ";

			line = line + driver_vetor.at(i).getName();
			line = line + " ; ";

			line = line + to_string(driver_vetor.at(i).getShiftMaxDuration());
			line = line + " ; ";

			line = line + to_string(driver_vetor.at(i).getMaxWeekWorkingTime());
			line = line + " ; ";

			line = line + to_string(driver_vetor.at(i).getMinRestTime());

			driveroutfile << line << endl;
		}
	}
	driveroutfile.close();
}

void delete_line()
{
	int laneID;
	bool valid = false;


	while (!valid)
	{
		cout << "Introduce line ID : ";
		cin >> laneID;
		cin.ignore();
		for (unsigned int i = 0; i < (line_vetor.size()); i++)
		{

			if (laneID == line_vetor.at(i).getId())
			{
				line_vetor.erase(line_vetor.begin() + i);
				valid = true;
				break;
			}
			valid = false;
		}
	}

}

void add_line()
{
	Line line;
	string paragens;
	int tempo;
	int id;
	int freq;
	bool valid = false;


	cout << "Introduce line parameters : " << endl;
	while (!valid)
	{
		cout << "Line ID:" << endl;
		cin >> id;
		cin.ignore();
		line.setId(id);
		
		for (unsigned int i = 0; i < line_vetor.size(); i++)
		{
			if (line.getId() == line_vetor.at(i).getId())
			{
				cout << "Existing line! " << endl;
				valid = false;
				break;
			}
			valid = true;
		}
	}

	cout << "Frequency :" << endl;
	cin >> freq;
	cin.ignore();
	line.setFrequency(freq);

	cout << "Stops (Write 0 to end) :" << endl;

	while (1)
	{
		getline(cin, paragens);
		if (paragens == "0")
		{
			break;
		}
		busStop_List.push_back(paragens);
		line.setBusStopList(busStop_List);
	}
	cout << "Trip time :" << endl;
	while (times_List.size() < (line.getBusStops().size() - 1))
	{
		cin >> tempo;
		cin.ignore();
		times_List.push_back(tempo);
		line.setTimings(times_List);
	}
	line_vetor.push_back(line);
}

void mod_line()
{
	Line line;
	string paragens;
	int id;
	int freq;
	int tempo;
	bool valid = false;


	cout << "Introduce line parameters : " << endl;
	while (!valid)
	{
		cout << "Line ID:" << endl;
		cin >> id;
		cin.ignore();
		line.setId(id);
		for (unsigned int i = 0; i < line_vetor.size(); i++)
		{
			if (line.getId() == line_vetor.at(i).getId())
			{
				for (unsigned int i = 0; i < (line_vetor.size()); i++)
				{

					if (id == line_vetor.at(i).getId())
					{
						line_vetor.erase(line_vetor.begin() + i);
						valid = true;
						break;
					}
					valid = false;
				}

				cout << "Frequency :" << endl;
				cin >> freq;
				line.setFrequency(freq);
				cin.ignore();

				cout << "Stops(Write 0 to end) :" << endl;
				cin.ignore();
				while (1)
				{
					getline(cin, paragens);
					if (paragens == "0")
					{
						break;
					}
					busStopListMod.push_back(paragens);
					line.setBusStopList(busStopListMod);
				}
				cout << "Trip time :" << endl;
				while (timesListMod.size() < (line.getBusStops().size() - 1))
				{
					cin >> tempo;
					cin.ignore();
					timesListMod.push_back(tempo);
					line.setTimings(timesListMod);
				}
				line_vetor.push_back(line);

				valid = true;
				break;
			}
			valid = false;
		}
	}

}

void delete_driver()
{
	int driverID;
	bool valid = false;

	while (!valid)
	{
		cout << "ID of driver you want to delete : ";
		cin >> driverID;
		cin.ignore();

		for (unsigned int i = 0; i < (driver_vetor.size()); i++)
		{
			if (driverID == driver_vetor.at(i).getId())
			{
				driver_vetor.erase(driver_vetor.begin() + i);
				valid = true;
				break;
			}
			valid = false;
		}
	}

}

void add_driver()
{
	Driver driver;
	string nome;
	int id;
	int maxHourstime;
	int maxWeekWorkingTime;
	int minRestTime;
	bool valid = false;

	while (!valid)
	{
		cout << "Driver ID:" << endl;
		cin >> id;
		driver.setId(id);

		cin.ignore();
		for (unsigned int i = 0; i < driver_vetor.size(); i++)
		{
			if (driver.getId() == driver_vetor.at(i).getId())
			{
				cout << "Existing driver! " << endl;
				valid = false;
				break;
			}
			valid = true;
		}
	}
	cin.ignore();
	cout << "Driver name :" << endl;
	getline(cin, nome);
	driver.setName(nome);
	cout << "Work hours per day :" << endl;
	cin >> maxHourstime;
	driver.setMaxHours(maxHourstime);

	cout << "Work hours per week :" << endl;
	cin >> maxWeekWorkingTime;
	driver.setMaxWeekWorkingTime(maxWeekWorkingTime);

	cout << "Rest hours :" << endl;
	cin >> minRestTime;
	driver.setMinRestTime(minRestTime);

	driver_vetor.push_back(driver);
}

void mod_driver()
{
	Driver driver;
	string nome;
	int id;
	int maxHourstime;
	int maxWeekWorkingTime;
	int minRestTime;
	bool valid = false;

	cout << "Line ID:" << endl;
	cin >> id;
	cin.ignore();
	while (!valid)
	{
		for (unsigned int i = 0; i < driver_vetor.size(); i++)
		{
			if (id == driver_vetor.at(i).getId())
			{
				for (unsigned int i = 0; i < (driver_vetor.size()); i++)
				{
					if (id == driver_vetor.at(i).getId())
					{
						driver_vetor.erase(driver_vetor.begin() + i);
						valid = true;
						break;
					}
					valid = false;
				}
				driver.setId(id);
				cout << "Driver's name: " << endl;
				getline(cin, nome);
				driver.setName(nome);
				cout << "Work hours per day:" << endl;
				cin >> maxHourstime;
				driver.setMaxHours(maxHourstime);
				cout << "Work hours per week:" << endl;
				cin >> maxWeekWorkingTime;
				driver.setMaxWeekWorkingTime(maxWeekWorkingTime);
				cout << "Rest hours" << endl;
				cin >> minRestTime;
				driver.setMinRestTime(minRestTime);
				valid = true;
				break;
			}
			valid = false;
		}
	}
	driver_vetor.push_back(driver);
	cout << "Driver changed!" << endl;
}

void stop_schedule() {
	string stop;
	int cicle1 = 0;
	int cicle2 = 0;
	int minutes1 = 480;
	int minutes2 = 480;
	int hour_m = 480;
	int n_bus1 = 0, n_bus2 = 0;
	int x = 0;
	bool valid = false;

	while (!valid)
	{
		cout << "Introduce the stop you want to see the schedule" << endl;
		getline(cin, stop);

		for (int i = 0; i < line_vetor.size(); i++)
		{
			for (int p = 0; p < line_vetor.at(i).getBusStops().size(); p++)
			{
				if (stop == line_vetor.at(i).getBusStops().at(p))
				{
					valid = true;
					break;
				}
			}
		}
		cin.clear();
	}


	for (int i = 0; i < line_vetor.size(); i++)
	{
		int cicle1 = 0;
		int cicle2 = 0;
		int minutes1 = 480;
		int minutes2 = 480;
		int hour_m = 480;
		int n_bus1 = 0, n_bus2 = 0;
		int x = 0;
		for (int v = 0; v < line_vetor.at(i).getTimings().size(); v++)
		{
			cicle1 += (line_vetor.at(i).getTimings().at(v) * 2);
		}
		cicle2 = cicle1;
		vector<string> Stops = line_vetor.at(i).getBusStops();

		for (int p = 0; p < Stops.size(); p++)
		{

			if (Stops.at(p) == stop)
			{
				cout << "Line: " << line_vetor.at(i).getId() << endl;
				cout << "Direction -> " << line_vetor.at(i).getBusStops().back() << endl;

				for (int k = 0; k < p; k++)
				{
					minutes1 += line_vetor.at(i).getTimings().at(k);
				}
				while (hour_m < 1380) {
					cout << setfill('0') << setw(2);
					cout << (minutes1 / 60) % 24 << ":";
					cout << setfill('0') << setw(2);
					cout << minutes1 % 60 << "\t";
					minutes1 += line_vetor.at(i).getFrequency();
					hour_m += line_vetor.at(i).getFrequency();
					n_bus1++;
				}
				cout << endl;
				cout << "Direction -> " << line_vetor.at(i).getBusStops().at(0) << endl;
				minutes2 += cicle2;
				for (int k = 0; k < p; k++) {
					minutes2 -= line_vetor.at(i).getTimings().at(k);
				}

				while (n_bus1 > n_bus2) {

					cout << setfill('0') << setw(2);
					cout << (minutes2 / 60) % 24 << ":";
					cout << setfill('0') << setw(2);
					cout << minutes2 % 60 << "\t";
					minutes2 += line_vetor.at(i).getFrequency();
					n_bus2++;
				}
				cout << endl;
			}
		}
	}
}

void line_schedule1() {
	unsigned int id;
	bool valid = false;
	int cicle1 = 0;
	int cicle2 = 0;
	int minutes1 = 480;
	int minutes2 = 480;
	int hour_m = 480;
	int n_bus1 = 0, n_bus2 = 0;
	int x = 0;

	while (!valid)
	{
		cout << "Line ID:";
		cin >> id;
		cin.ignore();

		for (unsigned int i = 0; i < line_vetor.size(); i++)
		{
			if (id == line_vetor.at(i).getId())
			{
				valid = true;
				break;
			}
			valid = false;
		}
	}


	for (int i = 0; i < line_vetor.size(); i++)
	{
		int cicle1 = 0;
		int cicle2 = 0;
		int minutes1 = 480;
		int minutes2 = 480;
		int hour_m = 480;
		int n_bus1 = 0, n_bus2 = 0;
		int x = 0;
		for (int v = 0; v < line_vetor.at(i).getTimings().size(); v++)
		{
			cicle1 += (line_vetor.at(i).getTimings().at(v) * 2);
		}
		cicle2 = cicle1;
		vector<string> Stops = line_vetor.at(i).getBusStops();

		if (line_vetor.at(i).getId() == id)
		{
			for (int p = 0; p < Stops.size(); p++)
			{

				for (int b = 0; b < p; b++)
				{
					minutes1 += line_vetor.at(i).getTimings().at(b);
				}

				while (x < 1)
				{
					minutes2 = minutes1;
					x += 1;
				}

				cout << "Direction -> " << line_vetor.at(i).getBusStops().back() << endl;
				cout << line_vetor.at(i).getBusStops().at(p) << endl;
				while (hour_m < 1380) {
					cout << setfill('0') << setw(2);
					cout << (minutes1 / 60) % 24 << ":";
					cout << setfill('0') << setw(2);
					cout << minutes1 % 60 << "\t";
					minutes1 += line_vetor.at(i).getFrequency();
					hour_m += line_vetor.at(i).getFrequency();
					n_bus1++;
				}
				cout << endl;
				cout << "Direction -> " << line_vetor.at(i).getBusStops().at(0) << endl;

				minutes2 += cicle2;
				for (int k = 0; k < p; k++) {
					minutes2 -= line_vetor.at(i).getTimings().at(k);
				}

				while (n_bus1 > n_bus2) {

					cout << setfill('0') << setw(2);
					cout << (minutes2 / 60) % 24 << ":";
					cout << setfill('0') << setw(2);
					cout << minutes2 % 60 << "\t";
					minutes2 += line_vetor.at(i).getFrequency();
					n_bus2++;
				}
				cout << endl << endl;

				minutes1 = 480;
				minutes2 = 480;
				cicle2 = cicle1;
				hour_m = 480;
			}
		}
	}
}

void stop_in_line() {
	string stop;
	bool valid = false;

	while (!valid)
	{
		cout << "Introduce the stop you want to see the schedule" << endl;
		getline(cin, stop);

		for (int i = 0; i < line_vetor.size(); i++)
		{
			for (int p = 0; p < line_vetor.at(i).getBusStops().size(); p++)
			{
				if (stop == line_vetor.at(i).getBusStops().at(p))
				{
					valid = true;
					break;
				}
			}
		}
		cin.clear();
	}

	valid = false;
	for (int i = 0; i < line_vetor.size(); i++) {
		vector<string> Stops = line_vetor.at(i).getBusStops();
		cout << Stops.at(0) << " -> " << Stops.back() << endl;

		for (int p = 0; p < Stops.size(); p++) {

			if (Stops.at(p) == stop) {
				valid = true;
			}
		}

		if (valid) {
			cout << "This stop belong to this line" << endl;
		}
		else {
			cout << "This stop doesn't belong to this line" << endl;
		}
		valid = false;
		cout << endl;
	}
}

void stops_route() {
	string stop1, stop2, stop3;
	int pos1 = 0;
	int pos2 = 0;
	int pos3 = 0;
	int pos4 = 0;
	int v1 = 0;
	int v2 = 0;
	bool valid = false;
	vector<Line> linhas_iniciais;
	vector<Line> linhas_finais;

	vector<Line> linha1e2same;
	vector<Line> linha1diferent;
	vector<Line> linha2diferent;
	int option;

	while (!valid)
	{
		cout << "Introduce the first stop :" << endl;
		getline(cin, stop1);

		for (int i = 0; i < line_vetor.size(); i++)
		{
			for (int p = 0; p < line_vetor.at(i).getBusStops().size(); p++)
			{
				if (stop1 == line_vetor.at(i).getBusStops().at(p))
				{
					valid = true;
					break;
				}
			}
		}
		cin.clear();
	}
	valid = false;
	while (!valid)
	{
		cout << "Introduce the second stop: " << endl;
		getline(cin, stop2);

		for (int i = 0; i < line_vetor.size(); i++)
		{
			for (int p = 0; p < line_vetor.at(i).getBusStops().size(); p++)
			{
				if (stop2 == line_vetor.at(i).getBusStops().at(p))
				{
					valid = true;
					break;
				}
			}
		}
		cin.clear();
	}
	valid = false;

	for (int i = 0; i < line_vetor.size(); i++) {
		vector<string> Stops = line_vetor.at(i).getBusStops();

		for (int p = 0; p < Stops.size(); p++) {
			if (Stops.at(p) == stop1) {
				linhas_iniciais.push_back(line_vetor.at(i));
			}
			if (Stops.at(p) == stop2) {
				linhas_finais.push_back(line_vetor.at(i));
			}
		}
	}

	for (int i = 0; i < linhas_iniciais.size(); i++)
	{
		for (int p = 0; p < linhas_finais.size(); p++)
		{
			if (linhas_iniciais.at(i).getId() == linhas_finais.at(p).getId())
			{
				linha1e2same.push_back(line_vetor.at(i));
			}
		}
	}

	if (linha1e2same.size() > 0)
	{
		for (int i = 0; i < linha1e2same.size(); i++)
		{
			for (int p = 0; p < linha1e2same.at(i).getBusStops().size(); p++)
			{
				if (linha1e2same.at(i).getBusStops().at(p) == stop1)
				{
					pos1 = p;
				}
				if (linha1e2same.at(i).getBusStops().at(p) == stop2)
				{
					pos2 = p;
				}

				if (pos1 < pos2)
				{
					while (pos1 < pos2)
					{
						cout << linha1e2same.at(i).getBusStops()[pos1] << endl;
						cout << linha1e2same.at(i).getTimings().at(pos1) << endl;
						pos1 += 1;
					}
					cout << linha1e2same.at(i).getBusStops()[pos1] << endl;
				}
				if (pos2 < pos1)
				{
					while (pos2 < pos1)
					{
						cout << linha1e2same.at(i).getBusStops()[pos1] << endl;
						pos1 -= 1;
						cout << linha1e2same.at(i).getTimings().at(pos1) << endl;

					}
					cout << linha1e2same.at(i).getBusStops()[pos1] << endl;
				}

			}
		}
	}
	pos1 = 0;
	pos2 = 0;
	
	for (int i = 0; i < linhas_iniciais.size(); i++)
	{
		for (int j = 0; j < linhas_iniciais.at(i).getBusStops().size(); j++)
		{
			for (int k = 0; k < linhas_finais.size(); k++)
			{
				for (int l = 0; l < linhas_finais.at(k).getBusStops().size(); l++)
				{
					/*cout << linhas_iniciais.at(i).getBusStops().at(j) << "->" << linhas_finais.at(k).getBusStops().at(l) << endl;*/
					if (linhas_iniciais.at(i).getBusStops().at(j) == stop1)
					{
						pos1 = j;
					}
					
					if (linhas_iniciais.at(k).getBusStops().at(l) == stop2)
					{
						pos4 = l;
					}

					if (linhas_iniciais.at(i).getBusStops().at(j) == linhas_finais.at(k).getBusStops().at(l))
					{
						pos2 = j;
						v1 = i;
						pos3 = l;
						v2 = k;
					}
				}
			}
		}
	}

	if (pos1 > pos2)
	{
		for (int i = pos1; i < pos2; i++)
		{
			cout << linhas_iniciais.at(v1).getBusStops().at(i);
			cout << linhas_iniciais.at(v1).getTimings().at(i);
		}
		cout << linhas_iniciais.at(v1).getBusStops()[pos2];
	}

	if (pos2 < pos1) {
		for (int i = pos2; i > pos1; i--)
		{
			cout << linhas_iniciais.at(v1).getBusStops().at(i);
			cout << linhas_iniciais.at(v1).getTimings().at(i);
			
		}
		cout << linha1e2same.at(v1).getBusStops()[pos1];

	}
}

void numberOfBus()
{
	for (int i = 0; i < line_vetor.size(); i++)
	{
		int cicle = 0;
		int frequency = 0;
		float bus;

		vector<int> Stops = line_vetor.at(i).getTimings();
		for (int p = 0; p < Stops.size(); p++)
		{
			cicle += Stops.at(p);
		}
		frequency = line_vetor.at(i).getFrequency();
		cicle *= 2;
		bus = cicle / (frequency + 1);
		ceil(bus);
		bus_perline.push_back(bus);
	}
}

void create_buses() {
	int n = 0;
	int id = 1;
	for (int i = 0; i < bus_perline.size(); i++) {
		while (n < bus_perline.at(i)) {
			Bus bus;
			n++;
			bus.setId(id);
			id++;
			bus.setOrderInLine(n);
			bus.setLineId(line_vetor.at(i).getId());
			bus_vetor.push_back(bus);
		}
		n = 0;
	}
}

void bus_info() {
	bool valid = false;
	int id;
	while (!valid)
	{
		cout << "Bus ID:";
		cin >> id;
		cin.ignore();

		for (unsigned int i = 0; i < bus_vetor.size(); i++)
		{
			if (id == bus_vetor.at(i).getId())
			{
				cout << "Bus ID: " << bus_vetor.at(i).getId() << endl;
				cout << "Line Id : " << bus_vetor.at(i).getLineId() << endl;
				cout << "Order in Line: " << bus_vetor.at(i).getBusOrderInLine() << endl;
				valid = true;
				break;
			}
			valid = false;
		}
	}

}

void menu() {
	int option1, option2 = 0, option3 = 0, option4 = 0;

	cout << "Select your option:\n";
	cout << "1: Manage lines \n";
	cout << "2: Manage drivers\n";
	cout << "3: See information\n";

	do
	{
		cin >> option1;
	} while (option1 < 1 || option1 > 3);

	/*system("Pause");*/
	system("cls");

	switch (option1)
	{
	case 1:
		cout << "Select your option:\n";
		cout << "1: Add line \n";
		cout << "2: Remove line \n";
		cout << "3: Change line \n";
		do
		{
			cin >> option2;
		} while (option2 < 1 || option2 > 3);
		break;
	case 2:
		cout << "Select your option:\n";
		cout << "1: Add driver \n";
		cout << "2: Remove driver \n";
		cout << "3: Change line \n";
		do
		{
			cin >> option3;
		} while (option3 < 1 || option3 > 3);
		break;
	case 3:
		cout << "Select your option:\n";
		cout << "1: See a stop schedule\n";
		cout << "2: See a line schedule\n";
		cout << "3: See which lines contain that stop \n";
		cout << "4: See a bus information \n";
		cout << "5: Time calculator and route between two stops \n";
		do
		{
			cin >> option4;
		} while (option4 < 1 || option4 > 5);
		break;

	default:
		break;
	}

	/*system("Pause");*/
	system("cls");

	if (option2 > 0)
	{
		switch (option2) {
		case 1:
			add_line();
			break;
		case 2:
			delete_line();
			break;
		case 3:
			mod_line();
			break;
		}
	}

	if (option3 > 0)
	{
		switch (option3) {
		case 1:
			add_driver();
			break;
		case 2:
			delete_driver();
			break;
		case 3:
			mod_driver();
			break;
		}
	}

	if (option4 > 0)
	{
		switch (option4) {
		case 1:
			stop_schedule();
			break;
		case 2:
			line_schedule1();
			break;
		case 3:
			stop_in_line();
			break;
		case 4:
			bus_info();
			break;
		case 5:
			stops_route();
			break;
		}
	}
}

int main() {
	separateline();
	separatedriver();
	numberOfBus();
	create_buses();

	menu();
	save_linefile();
	save_driverfile();
	return 0;
}
