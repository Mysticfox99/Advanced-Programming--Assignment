#include "Order.h"

//Add functions implemented which allows user to add items to their order based on index in menu
string Order::add(Item* choice)
{   
	cout << choice->getName() << " added to order!" << endl;
	items.push_back(choice);
	total += choice->getPrice();	
	
	return string();
}
//Remove functions implemented which allows user to remove items to their order based on index in order
string Order::remove(Item* choice)
{
	cout << choice->getName() << " removed from order!" << endl;
	total -= choice->getPrice();
	//Findchoice finds the chosen item and removes it from the order
	auto findchoice = find(items.begin(), items.end(), choice);
	items.erase(findchoice);
	
	return string();
}

//calculateTotal functions implemented which look if twoforone is true and calculates the savings.
float Order::calculateTotal(float savings)
{	
	bool tfo = false;
	float price = 0;
	int counter = 0; // counter to check if two items are twoforone
	for (int i = 0; i < items.size(); i++)
	{	
		//Gets the twoforone and price from items
		tfo = items[i]->getTfo();
		price = items[i]->getPrice();
		//Add to counter if item is twoforone
		if (tfo == true) 
		{
			counter++;
		}
		//When two twoforitems are found, it calculates the savings.
		if (counter == 2)
		{
			bool a = true;
			if (tfo && a)
			{
				savings += (price * 2) - (price);
				counter = 0;
			}
		}
	}
	
	return savings;
}
//toString functions implemented that outputs the order to the user
string Order::toString()
{	
	string menu;
	//Push back the items that the user selected into menu
	for (int i = 0; i < items.size(); i++)
	{
		menu += "(" + to_string(i + 1) + ") " + items[i]->toString();
	}
	//Get the savings and calculate the total after savings were calculated
	float savings = 0;
	savings = calculateTotal(savings);
	float newtotal = total - savings;
	//Add savings made and total to menu string
	menu += "\nSavings made: \x9C" + items[0]->rounding(savings,2);
	menu += "\nTotal: \x9C" + items[0]->rounding(newtotal, 2);
	return "===== Checkout =====\n" + menu ;
	

		
}
//printReceipt functions to output toString into a Receipt.txt file
void Order::printReceipt()
{
	ofstream outputFile{ "Receipt.txt" };
	outputFile << toString();
	outputFile.close();
}


