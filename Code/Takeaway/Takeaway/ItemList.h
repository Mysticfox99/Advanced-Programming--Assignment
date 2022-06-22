#pragma once

#include "Item.h"
#include "Appetiser.h"
#include "Beverage.h"
#include "MainCourse.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream> 


class ItemList
{
protected:
	//Create a protected vector of items that stores all the items from menu.csv
	vector<Item*> items;

public:			
	//Pure virtual function toString that gets overwritten
	virtual string toString() = 0;
	//GetVector function declared to get the items vector so takeaway.cpp can access it
	vector<Item*> GetVector();
};

