/*
 * labirinth.cpp
 */

#include "Labirinth.h"

#include <iostream>
using namespace std;



Labirinth::Labirinth(int values[10][10])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			labirinth[i][j] = values[i][j];
}


void Labirinth::initializeVisited()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			visited[i][j] = false;
}




void  Labirinth::printLabirinth()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << labirinth[i][j] << " ";

		cout << endl;
	}
}


bool Labirinth::findGoal(int x, int y)
{
	initializeVisited();
	return findGoalRec(x,y);
}

bool Labirinth::findGoalRec(int x, int y)
{
	// out of bounds, is a wall or has been visited return false
	if(x < 0 || y < 0 || x > 10 || y > 10 || labirinth[x][y] == 0 || visited[x][y] == true)
		return false;

	// it puts true the visited on the actual position
	visited[x][y] = true;

	// if reches end return true
	if(labirinth[x][y] == 2){
		cout << "It reached the end" << endl;
		return true;
	}

	//recursive step
	return findGoalRec(x+1,y) || findGoalRec(x-1,y) || findGoalRec(x,y+1) || findGoalRec(x,y-1);
}


