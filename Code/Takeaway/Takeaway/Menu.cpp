#include "Menu.h"

//Menu function implementated that opens and reads the file
Menu::Menu(string file)
{	
	ifstream menufile(file); //opens the file
	string itemline; //Variable created that will store lines of the file
	if (!menufile) //Outputs a warning if file is not found
	{
		cout << "Sorry the file " << file << " was not found." << endl;
	}

	//While loop that gets the line in the file
	while (getline(menufile, itemline))
	{
	
		vector<string> TempVect; //Temporary vector to store the contents of the file
		stringstream ss(itemline); //Reads the itemline string and sets it to a string argument
		string itemword; //Variable created to store words in the lines.
		//While loop that gets the words in the line
		while (getline(ss, itemword, ','))
		{
			TempVect.push_back(itemword); //Push the words from the file into the temporary vector.
		}
		//If statements to check the type of item which then creates a new object based on the type of item and stores the information about the item
		//The objects are pushed back to the items vector
		if (TempVect[0] == "a")
		{
			Item* appobj = new Appetiser(TempVect[1], stof(TempVect[2]), stoi(TempVect[3]), TempVect[4], TempVect[5]);
			items.push_back(appobj);
			//delete appobj; deletes appobj for memory management but items dont show up in tostring
			
		}

		else if (TempVect[0] == "b")
		{
			Item* bevobj = new Beverage(TempVect[1], stof(TempVect[2]), stoi(TempVect[3]), stoi(TempVect[6]), stof(TempVect[7]));
			items.push_back(bevobj);	
			//delete bevobj;
		}

		else if (TempVect[0] == "m")
		{		
			Item* macobj = new MainCourse(TempVect[1], stof(TempVect[2]), stoi(TempVect[3]));
			items.push_back(macobj);
			//delete macobj;
		}
	}	
	
	menufile.close();
}
//toString function to print out the menu
string Menu::toString()
{
	string displayapp, displaymain, displaybev;

	//For loop that iterates through item and determined type
	for (int i = 0; i < items.size(); i++)
	{
		//If statements that compares items specifications to type
		if (typeid(*items[i]) == typeid(Appetiser))
		{	
			displayapp += "(" + to_string(i + 1) + ") " + items[i]->toString();
		}

		else if (typeid(*items[i]) == typeid(MainCourse))
		{
			displaymain += "(" + to_string(i + 1) + ") " + items[i]->toString();	
		}

		else if (typeid(*items[i]) == typeid(Beverage))
		{
			displaybev += "(" + to_string(i + 1) + ") " + items[i]->toString();
		}
	}
	//Prints out the items
	return "----------------Appetisers----------------\n" + displayapp + 
		  "----------------Main dishes----------------\n" + displaymain +
		  "----------------Beverages----------------\n"   + displaybev;
	

}



