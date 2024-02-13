#include "Line.h"


Line::Line(unsigned int id, unsigned int frequency, vector<string> busStopList, vector<int> timesList){
	this->id = id;
	this->frequency = frequency;
	this->busStopList = busStopList;
	this->timesList = timesList;
}

Line::Line()
{
}

////////////////
// get methods
////////////////

unsigned int Line::getId() const{
  return id;
}

unsigned int Line::getFrequency() const{
	return frequency;
}

vector<string> Line::getBusStops() const{
  return busStopList;
}

vector<int> Line::getTimings() const{
  return this->timesList;
}

////////////////
// set methods
////////////////

void Line::setId(int id){
	this->id = id;
}

void Line::setFrequency(int frequency){
	this->frequency = frequency;
}

void Line::setBusStopList(vector<string> busStops){
	this->busStopList = busStops;
}

void Line::setTimings(vector<int> timesList){
	this->timesList = timesList;
}



////////////////
// other methods
////////////////

void Line::addBusStops(string busStop){
	this->busStopList.push_back(busStop);
}

void Line::addBusStops(int timeStop){
	this->timesList.push_back(timeStop);
}

