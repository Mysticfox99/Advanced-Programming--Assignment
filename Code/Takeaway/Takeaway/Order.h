#pragma once
#include "ItemList.h"

class Order : public ItemList
{	
	//Create the variables
	private:
		float total = 0;
public:
	//Add and remove functions declared
	string add(Item* choice);
	string remove(Item* choice);
	//calculateTotal functions declared
	float calculateTotal(float savings);
	//toString functions declared
	string toString();
	//printReceipt functions declared
	void printReceipt();
};

