#pragma once
#include "Item.h"
class Beverage : public Item
{
	//Create private variables for the Beverage
	private:
		float abv = 0;
		int volume = 0;

	public:
		//Declare Beverage object with the parameters that match the Beverage requirments
		Beverage(string name, float price, int calories, int volume, float abv);
		//toString function to display Appetiser objects
		string toString();
		//isAlcoholic function declared
		bool isAlcoholic(float num);
};

