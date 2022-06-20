#pragma once
#include "Item.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <sstream>


using namespace std;

class ItemList
{
	protected:
		vector<Item*> items;

	public:				
		
		virtual void toString() = 0;

};

