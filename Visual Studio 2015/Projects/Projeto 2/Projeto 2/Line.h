#pragma once

#include <iostream>
#include <string>
#include <vector>



using namespace std;

class Line{
 private:
  unsigned int id;
  unsigned int frequency;
  vector<string> busStopList;
  vector<int> timesList;
 public:
	 Line(unsigned int id, unsigned int frequency, vector<string> busStopList, vector<int> timesList);
	 Line();
  // metodos get
  unsigned int getId() const;
  unsigned int getFrequency() const;
  vector<string> getBusStops() const;
  vector<int> getTimings() const;
  // set methods
  void setId(int id);
  void setFrequency(int frequency);
  void setBusStopList(vector<string> busStopList);
  void setTimings(vector<int> timesList);
  // other methods
  void addBusStops(string busStop);
  void addBusStops(int timeStops);
};
