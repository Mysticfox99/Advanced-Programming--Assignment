/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for "Takeaway" assignment
Autumn 2020

Written by James Brown

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */

#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");
	// Create an order object
	Order order = Order();

	while (userCommand != "exit")
	{
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		string command = parameters[0];

		if (command.compare("menu") == 0) {
			cout << menu.toString();
		}
		else if (command.compare("add") == 0)
		{
			
			//For loop so the user can add multiple items at once			
			for (int i = 1; i < parameters.size(); i++)
			{
				Item* choice = menu.GetVector()[stoi(parameters[i]) - 1]; // you need to instantiate this using the menu object!
				order.add(choice);
			}	
			
			// You may also wish to implement the ability to add multiple items at once!
			// e.g. add 1 5 9 
		}
		else if (command.compare("remove") == 0)
		{
			for (int i = 1; i < parameters.size(); i++)
			{
				//For loop so the user can remove multiple items at once
				Item* choice = order.GetVector()[stoi(parameters[i]) - 1]; // you need to instantiate this using the menu object!
				order.remove(choice);
			}

		}
		else if (command.compare("checkout") == 0)
		{
			cout << order.toString() << endl;
			
			cout << "Do you want to place your order ?\n "
				"Type 'y' to confirm, or 'n' to go back and modify it." << endl;
			char confirmation;
			cin >> confirmation;
			if (confirmation == 'n')
			{
				cout << "You can now add or remove items!" << endl;
				
			}
			else if (confirmation == 'y')
			{
					
				order.printReceipt();
				break;
			}
			else
			{				
				cout << "You can now add more items!" << endl;
			}
			cin.ignore();
		}
		
		
		else if (command.compare("help") == 0)
		{
			//Display the help menu
			cout << "menu - display the menu to the user\n"
				"add [INDEX] -add an item to the order by numeric index in the menu (starting at 1)\n"
				"remove [INDEX] -remove item from order by numeric index in the order (starting at 1)\n"
				"checkout -display the items in the user’s order, the price, and discount savings\n"
				"help-display a help menu for the user with the available options\n"
				"exit -terminate the program gracefully" << endl;
		}

		parameters.clear();

	}

	cout << "Press any key to quit...";
	std::getchar();
}
