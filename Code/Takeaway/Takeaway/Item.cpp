#include "Item.h"
#include <iomanip>

//Rounding function
string Item::rounding(float round, int num)
{	
	stringstream tmp; //create temporary variable that will store the rounded value.
	//Round the chosen variable to chosen decimal places and store contents in tmp.
	tmp << setprecision(num) << fixed << round;
	return tmp.str(); //return rounded value
}

//toString function
string Item::toString()
{
	string madisdisplay; // create variable that will display Main Course items.
	//Prints out the items in Main Course when user inputs menu.
	madisdisplay += name + ": \x9C" + rounding(price, 2) + ", " + to_string(calories) + "cal" + "\n";
	return madisdisplay; //Return Main Course items
}

//Virtual function getTfo
bool Item::getTfo()
{
	return bool();
}
//Function getName returns the name to be used in order class
string Item::getName()
{
	return name;
}
//Function getPrice returns the price to be used in order class
float Item::getPrice()
{
	return price;
}

