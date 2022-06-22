#include "Beverage.h"
//Implementing the Beverage object with parameters and defining the parameters
Beverage::Beverage(string name, float price, int calories, int volume, float abv)
{
	this->name = name;
	this->price = price;
	this->calories = calories;
	this->volume = volume;
	this->abv = abv;
}

//isAlcoholic function implemented to figure out if item is alcoholic or not.
bool Beverage::isAlcoholic(float num)
{
	//If item is alcohol
	if (num > 0)
	{
		return true;
	}
	//If item is not alcohol
	else
	{
		return false;
	}	
}

string Beverage::toString()
{
	string abvdisplay;
	//If statement that displays the abv content if item is alcoholic
	if (isAlcoholic(abv))
	{
		abvdisplay = ", " + rounding(abv, 1) + "% abv";			
	}
	//Display  the Beverage items
	string bevdisplay;
	bevdisplay += name + ": \x9C" + rounding(price, 2) + ", " + to_string(calories) + "cal (" + to_string(volume) + "ml" + abvdisplay + ")\n";
	return bevdisplay;
}


