#pragma once

#include <iostream>
#include <vector>

#include "Shift.h"


using namespace std;

class Bus {
private:
	unsigned int id;
	unsigned int orderInLine;
	unsigned int lineId;
	//vector<Shift> schedule;
public:
	Bus(unsigned int id, unsigned int line);
	Bus();
	// get methods
	unsigned int getId() const;
	unsigned int getBusOrderInLine() const;
	unsigned int getLineId() const;
	vector<Shift> getSchedule() const;
	// set methods
	void setId(unsigned int);
	void setOrderInLine(unsigned int);
	void setLineId(unsigned int);
	// other methods

};
