#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "Structures.h"

using namespace std;

/* ACCOUNTS */
string checkAcc(string username, string password)
{
	ifstream myfile("acc.txt");
	string line[20];
	int counter = 0, checkCounter = 0;
	if (myfile.is_open())
	{
		while (myfile.good())
		{
			getline(myfile, line[0], ',');
			if (line[0] == username)
			{
				getline(myfile, line[1], ',');
				if (line[1] == password)
				{
					getline(myfile, line[2], ',');

					return line[2];
				}
				else
				{
					cout << "Invalid password or username!" << endl;
				}
			}
			else
			{
				getline(myfile, line[3]);
			}
		}
		myfile.close();
	}
	cout << "Please try to loign again!" << endl;
	return "invalidAccount";
}

int tokenize(string line, string* results, char delimiter) {
	string help;
	int counter = 0, count = 0;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == delimiter)
		{
			results[counter++] = help;
			help = "";
			i++;
		}
		help += line[i];
	}
	return counter;
}
bool adminMenu();
void manageAccounts()
{
	int choice;
	ifstream myfile("acc.txt");
	ofstream tmpFile("accTmp.txt");
	string tokens[10], help, newUsername;
	int counter = 0, checkCounter = 0;
	string line;
	bool accManagmentMenu = true;
	while (accManagmentMenu)
	{
		cout << "___________________________________________________" << endl;
		cout << endl;
		cout << "                1. Show all accounts" << endl;
		cout << "                2. Delete account" << endl;
		cout << "                3. Edit username" << endl;
		cout << "                4. Remove/Add Admin" << endl;
		cout << "                9. Go back\n" << endl;
		cout << "Choose option: ";
		cin >> choice;

		cout << endl;

		switch (choice)
		{
			case 1:
				if (myfile.is_open())
				{
					while (myfile.good())
					{
						getline(myfile, tokens[0], ',');

						help = tokens[0];

						if (help == "") {}
						else
						{
							if (help[0] == '\n')
							{
								help.erase(0, 1);
							}
							cout << "          Username: " << help;

							getline(myfile, tokens[1], ',');
							getline(myfile, tokens[2], ',');

							cout << " | Admin: ";

							if (tokens[2] == "1")
							{
								cout << "True" << endl;
							}
							else
							{
								cout << "False" << endl;
							}
						}
					}
				}
				break;
			case 2:
				cout << "Name of user: ";
				cin >> help;

				if (myfile.is_open())
				{
					string line;
					while (!myfile.eof())
					{
						getline(myfile, line);

						if (line != "") {

							tokenize(line, tokens, ',');

							if (help != tokens[0]) {

								if (tmpFile.is_open())
								{
									counter = 2;
									tmpFile << tokens[counter] << "," << tokens[counter--] << "," << tokens[counter--] << "," << endl;
								}

							}
						}
					}
					myfile.close();
					if (remove("acc.txt") != 0) {
						cerr << "A wild error appeared: ";
					}
					else {
						cout << "Deleting account 50% done" << endl;
					}
					tmpFile.close();
					if (rename("accTmp.txt", "acc.txt") != 0)
					{
						cerr << "A wild error appeared : ";
					}
					else
					{
						cout << "Deleting account done!!!" << endl;
					}
				}
				break;
			case 3:
				cout << "Name of user: ";
				cin >> help;

				if (myfile.is_open())
				{
					string line;

					while (!myfile.eof())
					{
						getline(myfile, line);

						if (line != "") {
							tokenize(line, tokens, ',');

							if (help != tokens[0]) {

								if (tmpFile.is_open())
								{

									tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << endl;
								}

							}
							else
							{
								cout << "New username: ";
								cin >> newUsername;
								tmpFile << newUsername << "," << tokens[1] << "," << tokens[2] << "," << endl;
							}
						}
					}

					myfile.close();

					if (remove("acc.txt") != 0) {
						cerr << "A wild error appeared: ";
					}
					else {
						cout << "Editing username 50% done!" << endl;
					}

					tmpFile.close();

					if (rename("accTmp.txt", "acc.txt") != 0)
					{
						cerr << "A wild error appeared : ";
					}
					else
					{
						cout << "Editing username done!!!!" << endl;
					}
				}
				break;

			case 4:
				cout << "Name of user: ";
				cin >> help;
				if (myfile.is_open())
				{
					string line;

					while (!myfile.eof())
					{
						getline(myfile, line);

						if (line != "") {

							tokenize(line, tokens, ',');

							if (help != tokens[0]) {

								if (tmpFile.is_open())
								{

									tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << endl;
								}
							}
							else
							{
								if (tokens[2] == "1")
								{

									counter = 2;
									tmpFile << tokens[0] << "," << tokens[1] << "," << "0" << "," << endl;

								}
								else
								{

									counter = 2;
									tmpFile << tokens[0] << "," << tokens[1] << "," << "1" << "," << endl;

								}
							}
						}
					}

					myfile.close();

					if (remove("acc.txt") != 0) {
						cerr << "A wild error appeared: ";
					}
					else {
						cout << "Adding/Removing Admin 50% done!" << endl;
					}

					tmpFile.close();

					if (rename("accTmp.txt", "acc.txt") != 0)
					{
						cerr << "A wild error appeared : ";
					}
					else
					{
						cout << "Adding/Removing Admin done!!!!" << endl;
					}
				}
				break;

			case 9:
				myfile.close();
				accManagmentMenu = false;
				adminMenu();

				break;

			default:
				break;
		}
	}
	myfile.close();
}

void manageOffers() {

}

/* ACCOUNTS */


/* Functions for managing items */

void writeDataIntoFile(ITEM* items, int& itemCount)

{
	ofstream data;
	data.open("items.txt");
	for (int i = 0; i < itemCount; i++)
	{
		data << items[i].id << "|" << items[i].itemName << "|" << items[i].price << "|" << items[i].seller << "|" << items[i].description << "|" << 0 << "|" << endl;
	}
	data.close();

}

void insertItemInArray(ITEM* items, int& itemCount, ITEM newItem, int& maxId)
{
	newItem.id = maxId;
	items[itemCount] = newItem;
	itemCount++;
	maxId++;

	ofstream id;
	id.open("id.txt");
	id << maxId;

	writeDataIntoFile(items, itemCount);

}

string getIdFromFile()
{
	string line;
	ifstream myfile;
	myfile.open("id.txt");
	if (myfile.is_open()) {
		while (getline(myfile, line))
		{
			return line;
		}
		myfile.close();
	}
}

int getItemIndexById(ITEM* items, int& itemCount, int id)
{
	for (int i = 0; i < itemCount; i++)
	{
		if (items[i].id == id)
			return i;
	}

	return -1;
}

void updateItem(ITEM* items, ITEM newItem, int& itemCount, int& maxId) {
	int index = getItemIndexById(items, itemCount, maxId);
	items[index] = newItem;
}

void deleteItem(ITEM* items, int& itemCount, int id) {

	int index = getItemIndexById(items, itemCount, id);
	for (int i = index; i < itemCount - 1; i++)
	{
		items[i] = items[i + 1];
	}
	itemCount--;
}

ITEM getItemById(ITEM* items, int& itemCount, int id)
{
	int index = getItemIndexById(items, itemCount, id);
	return items[index];
}

int inputDataInArray(ITEM* items)
{
	fstream data;
	data.open("items.txt");
	string tokens[10];
	int counter = 0;

	if (data.is_open())
	{
		while (!data.eof())
		{
			for (int i = 0; i < 6; i++)
			{
				getline(data, tokens[i], '|');
			}
			items[counter].id = atoi(tokens[0].c_str());
			items[counter].itemName = tokens[1];
			items[counter].price = atoi(tokens[2].c_str());
			items[counter].seller = tokens[3];
			items[counter].description = tokens[4];
			items[counter].isAproved = atoi(tokens[5].c_str());
			counter++;
		}
	}
	else
	{
		cerr << "File cannot be open" << endl;
	}
	return counter;
}

//void initItemsInArray(ITEM * items, int& itemCount, int& maxId)
//{
//	insertItemInArray(items, itemCount, { "Gosho", "Bathroom tiles", 12.35, "the price is for m / sq" }, maxId);
//	insertItemInArray(items, itemCount, { "Alex", "Mouse Pad", 21.45, "35x45" }, maxId);
//	insertItemInArray(items, itemCount, { "Pesho", "LG TV", 769.99, "42 inches " }, maxId);
//	insertItemInArray(items, itemCount, { "Penka", "T-Shirt", 9.99, "XL size " }, maxId);
//	insertItemInArray(items, itemCount, { "Nelina", "White Mercedes", 6829, "Year of manufacture: 1997 " }, maxId);
//	insertItemInArray(items, itemCount, { "Milko", "Chickens", 20, "One chicken- 20 bgn " }, maxId);
//	insertItemInArray(items, itemCount, { "John", "Fridge", 178, "2x1" }, maxId);
//	insertItemInArray(items, itemCount, { "Miroslav", "Leather", 25, "25 bgn for 1 meter" }, maxId);
//	insertItemInArray(items, itemCount, { "Ivan", "Turkeys", 35, "35 bgn for 1 turkey" }, maxId);
//	insertItemInArray(items, itemCount, { "Martin", "Pillow", 15, "15 bgn for 1 pillow" }, maxId);
//}

/* Functions for managing items */


/* Menus */

void showAlloffers(ITEM* items, int& itemCount)
{

	for (int i = 0; i < itemCount; i++)
	{
		if (items[i].isAproved == 1)
		{
			cout << "\nid: " << items[i].id << endl;
			cout << "Item Name: " << items[i].itemName << endl;
			cout << "Price: " << items[i].price << endl;
			cout << "Seller Name: " << items[i].seller << endl;
			cout << "Description: " << items[i].description << endl;
		}

	}
}

void addOfferMenu(ITEM* items, int& itemCount, int& maxId)
{
	ITEM newItem;
	cin.ignore();
	cout << "\n Enter Item Name: ";
	getline(cin, newItem.itemName);
	cout << "Enter Price: ";
	cin >> newItem.price;
	cin.ignore();
	cout << "Enter Your Name: ";
	getline(cin, newItem.seller);
	cout << "Enter More Information About The Product: ";
	getline(cin, newItem.description);

	insertItemInArray(items, itemCount, newItem, maxId);
}

bool showItemsMenu(ITEM* items, int& itemCount, int& maxId)
{
	char input;

	cout << "___" << endl;
	cout << endl;
	cout << "\n   |=========== Wlcome to our shop ===========|\n" << endl;
	cout << endl;
	cout << "                       Menu:\n" << endl;
	cout << "                 1. Show all offers" << endl;
	cout << "                 2. Sort Items By Criterias" << endl;
	cout << "                 3. Buy offers" << endl;
	cout << "                 4. Add offers" << endl;
	cout << "                 9. Back\n\n";
	cout << "\nChoose an option: ";
	cin >> input;
	cout << endl;

	switch (input)
	{
		case '1':
			showAlloffers(items, itemCount);
			return true;
			break;
		case '2':
			return true;
			break;
		case '3': return true;
			break;
		case '4':
			addOfferMenu(items, itemCount, maxId);
			return true;
			break;
		case '9': return false;
			break;
		default: while (input != '1' && input != '2' && input != '3' && input != '9')
		{
			cout << "Invalid option, try again: ";
			cin >> input;
			cout << endl;
		}
			   break;
	}
	return true;
}

bool adminMenu()
{
	cout << "___________________________________________________\n" << endl;
	cout << endl;
	cout << "|============= Welcome to Admin menu =============|\n\n" << endl;

	int choice;
	cout << "                1. Manage accounts" << endl;
	cout << "                2. Manage Offers" << endl;
	cout << "                9. Exit\n" << endl;

	cout << "Choose option: ";
	cin >> choice;
	cout << endl;

	switch (choice)
	{
		case 1:
			manageAccounts(); return false;
			break;
		case 2:
			manageOffers(); return false;
			break;
		case 9: return false;

			break;
		default:  while (choice != '1' && choice != '2' && choice != '9')
		{
			cout << "Invalid option, try again: ";
			cin >> choice;
			cout << endl;
		}

			   break;
	}
	return true;
}

void Register() {
	ofstream myfile("acc.txt", ios::app);
	string username, password, c_password;
	cout << endl;

	cout << "___________________________________________________" << endl;
	cout << endl;
	cout << "               |===== Register =====|\n\n" << endl;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
	cout << "Confirm password: ";
	cin >> c_password;

	while (c_password != password)
	{
		cout << "\nInvalid confirm password, please enter confirm pass again: "; cin >> c_password;
	}

	cout << endl;
	myfile << endl << username << "," << password << ",0,";
	myfile.close();
}

void login() {
	string username, password, result = "invalidAccount";
	char character;
	cout << "Do you have existing account[Y/N]: ";
	cin >> character;
	cout << endl;

	while (character != 'Y' && character != 'N') {

		cout << "Invalid option, try again: ";
		cin >> character;

	}

	if (character == 'Y')
	{
		while (result == "invalidAccount")
		{
			cout << "___________________________________________________" << endl;
			cout << endl;
			cout << "               |===== LOGIN =====|\n\n" << endl;
			cout << "Username: ";
			cin >> username;
			cout << "Password: ";
			cin >> password;
			cout << endl;
			result = checkAcc(username, password);
		}
		if (checkAcc(username, password) == "1")
		{
			adminMenu();
		}
		else
		{
			//showItemsMenu();
		}
	}
	else if (character == 'N')
	{
		cout << "Please first register before login!" << endl;
		Register();
	}
}

bool Menu(ITEM* items, int& itemCount, int& maxId) {
	char input;
	bool whileCheck = true;

	cout << "\n|============== Welcome to OLX_2.0 ==============|\n" << endl;
	cout << endl;
	cout << "                       Menu:\n" << endl;
	cout << "                   1. Login" << endl;
	cout << "                   2. Register" << endl;
	cout << "                   3. Show Offers" << endl;
	cout << "                   9. Exit\n\n";
	cout << "\nChoose an option: ";
	cin >> input;
	cout << endl;

	while (whileCheck)
	{
		switch (input)
		{
			case 'k':
				showItemsMenu(items, itemCount, maxId);
				return false;
				break;
			case '1':
				login(); return false;
				break;
			case '2':
				Register(); return true;
				break;
			case '3':
				whileCheck = false;
			case '9':
				whileCheck = false;
				break;
			case 'A':
				adminMenu(); return false;
				break;
			default: while (input != '1' && input != '2' && input != '3' && input != '9' && input != 'k' && input != 'A')
			{
				cout << "Invalid option, try again: ";
				cin >> input;
				cout << endl;
			}
				   break;
		}
	}
	return true;
}

/* Menus */

int main()
{
	string stringID = getIdFromFile();
	int maxId = atoi(stringID.c_str());
	ITEM items[200];
	int itemCount = inputDataInArray(items);

	/*getline(cin, nov.itemName);
	cin >> nov.price;
	cin.ignore();
	getline(cin, nov.seller);
	getline(cin, nov.description);

	insertItemInArray(items, itemCount, nov, maxId);
	//initItemsInArray(items, itemCount,maxId);
	writeDataIntoFile(items, itemCount);

	/*string line;
	ifstream myfile("data.txt");
	if (myfile.is_open())
	{
		while (myfile.good())
		{
			getline(myfile, line);
			cout << line << endl;
		}
		myfile.close();
	}*/

	Menu(items, itemCount, maxId);
	return 0;
}
