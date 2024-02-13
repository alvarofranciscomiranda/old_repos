#include "Bus.h"
#include "Shift.h"

Bus::Bus(unsigned int id, unsigned int line) {
	this->orderInLine = id;              
	this->lineId = line;
}

Bus::Bus() 
{
}



////////////////////////////////
// get methods
///////////////////////////////
unsigned int Bus::getId() const
{
	return id;
}

unsigned int Bus::getBusOrderInLine() const {
	return orderInLine;
}


unsigned int Bus::getLineId() const {
	return lineId;
}

//vector<Shift> Bus::getSchedule() const {
//	return schedule;
//}




//////////////////////////////
// metodos set
/////////////////////////////

void Bus::setId(unsigned int id){
	this->id = id;
}

void Bus::setOrderInLine(unsigned int orderinline) {
	this->orderInLine = orderinline;
}

void Bus::setLineId(unsigned int lineid) {
	this->lineId = lineid;
}

////////////////////////////
// outher methods
///////////////////////////
