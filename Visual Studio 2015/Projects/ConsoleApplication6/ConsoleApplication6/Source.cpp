#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Line {
	int id;
	int frequency;
	vector<string> stop_sequecy;
	vector<int> trip_time;
};

struct Driver {
	int id;
	string name;
	int max_day;
	int max_week;
	int rest;
};

vector<Line> line_vetor;
vector<Driver> driver_vetor;
string line_fileName;
string driver_fileName;

void separateline() {
	string line2;
	ifstream linefile;

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

		line.id = stoi(line2.substr(0, line2.find(';')));
		line2 = line2.substr(line2.find(';') + 2);

		line.frequency = stoi(line2.substr(0, line2.find(';') - 1));
		line2 = line2.substr(line2.find(';') + 2);

		while (line2.find(',') < line2.find(';'))
		{
			line.stop_sequecy.push_back(line2.substr(0, line2.find(',')));
			line2 = line2.substr(line2.find(',') + 2);
		}
		line.stop_sequecy.push_back(line2.substr(0, line2.find(';')));
		line2 = line2.substr(line2.find(';') + 2);

		while (line2.size() > 2)
		{
			/*cout << line2 << "\n";*/
			line.trip_time.push_back(stoi(line2.substr(0, line2.find(','))));
			line2 = line2.substr(line2.find(',') + 2);

		}
		/*cout << line2.substr(0, 2) << endl;*/
		line.trip_time.push_back(stoi(line2.substr(0, 2)));
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

		driver.id = stoi(line.substr(0, line.find(';')));
		line = line.substr(line.find(';') + 2);

		driver.name = line.substr(0, line.find(';') - 1);
		line = line.substr(line.find(';') + 2);

		driver.max_day = stoi(line.substr(0, line.find(';')));
		line = line.substr(line.find(';') + 2);

		driver.max_week = stoi(line.substr(0, line.find(';')));
		line = line.substr(line.find(';') + 2);

		driver.rest = stoi(line);
		driver_vetor.push_back(driver);
	}
	driverfile.close();
}

void add_line() {
	/*Line line;
	string stops;
	int time, line_id;
	bool valid = false;

	cout << "Introduce line parameters: " << endl;
	while (!valid) {
		cout << "Line ID?" << endl;
		cin >> line_id;
		cin.ignore();
		for (int i = 0; i < line_vetor.size(); i++)
		{
			if (line_id == line_vetor.at(i).id)
			{
				cout << "Existing line!" << endl;
				valid = false;
				break;
			}
			valid = true;
		}
	}
	line.id = line_id;

	cout << "Frequency?" << endl;
	cin >> line.frequency;
	cin.ignore();

	cout << "Stops?(write 0 to stop)" << endl;
	while (1) {
		getline(cin, stops);
		cin.ignore();
		if (stops == "0")
		{
			break;
		}
		line.stop_sequecy.push_back(stops);
	}

	cout << "Trip time?" << endl;
	while (line.stop_sequecy.size() > line.trip_time.size() + 1)
	{
		cin >> time;
		cin.ignore();
		line.trip_time.push_back(time);
	}
	line_vetor.push_back(line);*/
}

void delete_line() {
	/*int line_id;
	bool valid = false;

	while (!valid) {
		cout << "Insert ID of line you want to delete:" << endl;
		cin >> line_id;
		cin.ignore();
		for (int i = 0; i < line_vetor.size(); i++)
		{
			if (line_id == line_vetor.at(i).id)
			{
				line_vetor.erase(line_vetor.begin() + i);
				valid = true;
				break;
			}
			valid = false;
		}
	}*/
}

void modify_line() {
	/*Line line;
	string stops;
	int time;
	bool valid = false;

	cout << "ID of modifying line?" << endl;
	cin >> line.id;
	cin.ignore();
	for (unsigned int i = 0; i < line_vetor.size(); i++)
	{
		if (line.id == line_vetor.at(i).id)
		{
			cout << "Frequency?" << endl;
			cin >> line_vetor.at(i).frequency;

			cout << "Stops?(write 0 to stop)" << endl;
			while (1)
			{
				getline(cin, stops);
				if (stops == "0") {
					break;
				}
				line_vetor.at(i).stop_sequecy.push_back(stops);
			}

			cout << "Trip times?" << endl;
			while (line_vetor.at(i).trip_time.size() < (line_vetor.at(i).stop_sequecy.size() - 2))
			{
				cin >> time;
				cin.ignore();
				line_vetor.at(i).trip_time.push_back(time);
			}
			valid = true;
			break;
		}
	}*/
}

void add_driver() {
	/*int driver_id;
	Driver driver;
	bool valid = false;

	cout << "Introduce parameters:" << endl;
	while (!valid)
	{
		cout << "Driver Id?" << endl;
		cin >> driver_id;
		cin.ignore();
		for (int i = 0; i < driver_vetor.size(); i++)
		{
			if (driver_vetor.at(i).id == driver_id)
			{
				cout << "Existing driver!" << endl;
				valid = false;
				break;
			}
			valid = false;
		}
	}
	cin.ignore();

	driver.id = driver_id;

	cout << "Driver name?" << endl;
	getline(cin, driver.name);

	cout << "Hours per day?" << endl;
	cin >> driver.max_day;

	cout << "Hours per week?" << endl;
	cin >> driver.max_week;

	cout << "Rest between turns?" << endl;
	cin >> driver.rest;

	driver_vetor.push_back(driver);*/
}

void delete_driver() {
	/*int driver_id;
	bool valid = false;

	while (!valid) {
		cout << "Insert ID of driver you want to delete:" << endl;
		cin >> driver_id;
		cin.ignore();
		for (int i = 0; i < driver_vetor.size(); i++)
		{
			if (driver_id == driver_vetor.at(i).id)
			{
				driver_vetor.erase(driver_vetor.begin() + i);
				valid = true;
				break;
			}
			valid = false;
		}
	}*/
}

void modify_driver() {
	/*int driver_id;
	bool valid = false;

	cout << "ID of modifying driver?" << endl;
	cin >> driver_id;
	cin.ignore();
	while (!valid) {
		for (int i = 0; i < driver_vetor.size(); i++)
		{
			if (driver_id == driver_vetor.at(i).id)
			{
				cout << "Driver name?" << endl;
				getline(cin, driver_vetor.at(i).name);

				cout << "Hours per day?" << endl;
				cin >> driver_vetor.at(i).max_day;

				cout << "Hours per week?" << endl;
				cin >> driver_vetor.at(i).max_week;

				cout << "Rest between turns?" << endl;
				cin >> driver_vetor.at(i).rest;

				valid = true;
				break;
			}
			valid = false;
		}
	}
	cout << "Driver modified" << endl;*/
}

void save_linefile() {
	string line;
	ofstream lineoutfile;

	lineoutfile.open(line_fileName);

	for (int i = 0; i < line_vetor.size(); i++)
	{
		if (i == (line_vetor.size() - 1))
		{
			line = to_string(line_vetor.at(i).id);
			line = line + " ; ";

			line = line + to_string(line_vetor.at(i).frequency);
			line = line + " ; ";

			for (int p = 0; p < (line_vetor.at(i).stop_sequecy.size() - 1); p++)
			{
				line = line + line_vetor.at(i).stop_sequecy.at(p);
				line = line + ", ";
			}
			line = line + line_vetor.at(i).stop_sequecy.at(line_vetor.at(i).stop_sequecy.size() - 1);
			line = line + "; ";

			for (int p = 0; p < (line_vetor.at(i).trip_time.size() - 1); p++)
			{
				line = line + to_string(line_vetor.at(i).trip_time.at(p));
				line = line + ", ";
			}
			line = line + to_string(line_vetor.at(i).trip_time.at(line_vetor.at(i).trip_time.size() - 1));

			lineoutfile << line;
		}
		else
		{
			line = to_string(line_vetor.at(i).id);
			line = line + " ; ";

			line = line + to_string(line_vetor.at(i).frequency);
			line = line + " ; ";

			for (int p = 0; p < (line_vetor.at(i).stop_sequecy.size() - 1); p++)
			{
				line = line + line_vetor.at(i).stop_sequecy.at(p);
				line = line + ", ";
			}
			line = line + line_vetor.at(i).stop_sequecy.at(line_vetor.at(i).stop_sequecy.size() - 1);
			line = line + "; ";

			for (int p = 0; p < (line_vetor.at(i).trip_time.size() - 1); p++)
			{
				line = line + to_string(line_vetor.at(i).trip_time.at(p));
				line = line + ", ";
			}
			line = line + to_string(line_vetor.at(i).trip_time.at(line_vetor.at(i).trip_time.size() - 1));

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
			line = to_string(driver_vetor.at(i).id);
			line = line + " ; ";

			line = line + driver_vetor.at(i).name;
			line = line + " ; ";

			line = line + to_string(driver_vetor.at(i).max_day);
			line = line + " ; ";

			line = line + to_string(driver_vetor.at(i).max_week);
			line = line + " ; ";

			line = line + to_string(driver_vetor.at(i).rest);

			driveroutfile << line;
		}
		else
		{
			line = to_string(driver_vetor.at(i).id);
			line = line + " ; ";

			line = line + driver_vetor.at(i).name;
			line = line + " ; ";

			line = line + to_string(driver_vetor.at(i).max_day);
			line = line + " ; ";

			line = line + to_string(driver_vetor.at(i).max_week);
			line = line + " ; ";

			line = line + to_string(driver_vetor.at(i).rest);

			driveroutfile << line << endl;
		}
	}
	driveroutfile.close();
}

//menu function
void menu() {
	int option1, option2 = 0, option3 = 0, option4 = 0;

	cout << "Select your option:\n";
	cout << "1: Manage lines \n";
	cout << "2: Manage drivers\n";
	cout << "3: See information\n";

	do
	{
		cin >> option1;
	} while (option1 < 1 || option1 > 9);

	switch (option1)
	{
	case 1:
		cout << "1: Add line \n";
		cout << "2: Remove line \n";
		cout << "3: Change line \n";
		do
		{
			cin >> option2;
		} while (option1 < 1 || option1 > 3);
		break;
	case 2:
		cout << "1: Add driver \n";
		cout << "2: Remove driver \n";
		cout << "3: Change line \n";
		do
		{
			cin >> option3;
		} while (option1 < 1 || option1 > 3);
		break;
	case 3:
		cout << "1: See a stop schedule\n";
		cout << "2: See a line schedule\n";
		cout << "3: See a drivers workload \n";
		cout << "4: See which lines contain that stop \n";
		cout << "5: See available drivers \n";
		cout << "6: Time calculator and route between two stops \n";
		cout << "7: See how many drivers are necessary for a line \n";
		do
		{
			cin >> option4;
		} while (option1 < 1 || option1 > 7);
		break;
	default:
		break;
	}

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
			modify_line();
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
			modify_driver();
			break;
		}
	}
}

int main() {
	/*separateline();*/
	separatedriver();

	//menu();

	/*save_linefile();*/
	/*save_driverfile();*/
}