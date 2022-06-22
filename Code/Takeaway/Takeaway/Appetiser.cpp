#include "Appetiser.h"

//Implementing the Appetiser object with parameters and defining the parameters
Appetiser::Appetiser(string name, float price, int calories, string aShareable, string aTwoForOne) {

	//Push back the information into the variables
	this->name = name;
	this->price = price;
	this->calories = calories;

	if (aShareable == "y") {
		shareable = true;
		
	}
	if (aTwoForOne == "y") {
		twoForOne = true;		
	}
}

string Appetiser::toString()
{
	//statement that displays if the item is shareable
	string share = shareable ? " (shareable)" : "";
	//statement that displays if the item is 2-4-1
	string tfo = twoForOne ? " (2-4-1)" : "";

	//Display  the Appetiser items
	string appdisplay;
	appdisplay += name + ": \x9C" + rounding(price, 2) + ", " + to_string(calories) + " cal" + share + tfo + "\n";
	return appdisplay;
}

//getTfo function gets implemented to return twoforone
bool Appetiser::getTfo()
{
	return twoForOne;
}




