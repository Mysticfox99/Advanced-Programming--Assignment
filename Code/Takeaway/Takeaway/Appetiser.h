#pragma once
#include "Item.h"
class Appetiser : public Item{
	private:
		//Create private variables for the Appetisers
		bool shareable = false; 
		bool twoForOne = false;

	public:
		//Declare Appetiser object with the parameters that match the Appetiser requirments 
		Appetiser(string name, float price, int calories, string aShareable, string aTwoForOne);
		//toString function to display Appetiser objects
		string toString();
		//getTfo function so Item class can access twoforone
		bool getTfo();

};

