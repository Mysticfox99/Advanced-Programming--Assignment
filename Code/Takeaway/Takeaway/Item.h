#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

class Item
{
protected:
	//Create the variables
	int calories = 0;
	string name;
	float price = 0;

public:
	//Function rounding that will round a chosen variable to a chosen amount of decimal places.
	string rounding(float round, int num);
	//Function toString that prints the Main Course items.
	virtual string toString(); //This function is virtual to make the the shareable and 2-4-1 display.
	//Virtual function getTfo to get the twoforone value from the appetiser class.
	virtual bool getTfo();
	
	string getName(); //Function getName to get the name of the item to use in order class
	float getPrice(); //Function getPrice to get price of the item to use in order class
	
};

