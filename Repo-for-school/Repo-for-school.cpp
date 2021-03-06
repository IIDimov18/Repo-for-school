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
	bool accManagmentMenu = true, userExist = false;
	while (accManagmentMenu)
	{
		userExist = false;
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
							else
							{
								userExist = false;
							}
						}
					}
					if (!userExist)
					{
						cout << "This user doesn't exist, nothing happened" << endl;
						myfile.close();
						remove("acc.txt");
						tmpFile.close();
						rename("accTmp.txt", "acc.txt");

					}
					else
					{
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
								userExist = true;
							}
						}
					}
					if (!userExist)
					{
						cout << "This user doesn't exist, nothing happened" << endl;
						myfile.close();
						remove("acc.txt");
						tmpFile.close();
						rename("accTmp.txt", "acc.txt");

					}
					else
					{
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
								userExist = true;
							}
						}
					}
					if (!userExist)
					{
						cout << "This user doesn't exist, nothing happened" << endl;
						myfile.close();
						remove("acc.txt");
						tmpFile.close();
						rename("accTmp.txt", "acc.txt");

					}
					else
					{
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

bool Menu();

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

void deleteItem(int id) {
	fstream data("items.txt");
	ofstream dataTmp("itemsTmp.txt");
	string line, tokens[10];
	bool offerExist = true;
	if (data.is_open())
	{
		while (!data.eof())
		{
			getline(data, line);
			if (line != "")
			{
				tokenize(line, tokens, '|');
				if (id != atoi(tokens[0].c_str())) {

					if (dataTmp.is_open())
					{

						dataTmp << tokens[0] << "|" << tokens[1] << "|" << tokens[2] << "|" << tokens[3] << "|" << tokens[4] << "|" << tokens[5] << "|" << endl;
					}
				}
				else
				{
					offerExist = true;
				}
			}
		}
		if (!offerExist)
		{
			cout << "There is no offer with this id, nothing happened" << endl;
			data.close();
			remove("items.txt");
			dataTmp.close();
			rename("itemsTmp.txt", "items.txt");
		}
		else
		{
			data.close();

			if (remove("items.txt") != 0) {
				cerr << "A wild error appeared: ";
			}
			else {
				cout << "Deleting offer 50% done!" << endl;
			}

			dataTmp.close();

			if (rename("itemsTmp.txt", "items.txt") != 0)
			{
				cerr << "A wild error appeared : ";
			}
			else
			{
				cout << "Deleting offer done!!!!" << endl;
			}
		}
	}
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
bool showItemsMenu();
bool Menu();

void sortItemsMenu(ITEM* items, int& itemCount)
{
	int choice;
	float temp;
	float minPrice = 0, maxPrice = 0;
	bool showMenu = true;


	while (showMenu)
	{
		cout << "Criterias" << endl;
		cout << "1. Items with price lower than what you entered" << endl;
		cout << "2. Items with price higher than waht you entered" << endl;
		cout << "3. Price diapason" << endl;
		cout << "4. Ascending Price" << endl;
		cout << "5. Descending Price" << endl;
		cout << "9. Go Back" << endl;
		cin >> choice;

		switch (choice)
		{
			case 1:
				cout << "Max Price: ";
				cin >> maxPrice;
				for (int i = 0; i < itemCount; i++)
				{
					if (items[i].isAproved == 1 && items[i].price <= maxPrice)
					{
						cout << "\nItem id: " << items[i].id << endl;
						cout << "Item name: " << items[i].itemName << endl;
						cout << "Price: " << items[i].price << endl;
						cout << "Seller: " << items[i].seller << endl;
						cout << "Descriprion: " << items[i].description << endl;
					}
				}

				break;
			case 2:
				cout << "Min Price: ";
				cin >> minPrice;
				for (int i = 0; i < itemCount; i++)
				{
					if (items[i].isAproved == 1 && items[i].price >= minPrice)
					{
						cout << "\nItem id: " << items[i].id << endl;
						cout << "Item name: " << items[i].itemName << endl;
						cout << "Price: " << items[i].price << endl;
						cout << "Seller: " << items[i].seller << endl;
						cout << "Descriprion: " << items[i].description << endl;
					}
				}

				break;
			case 3:
				cout << "Min Price: ";
				cin >> minPrice;
				cout << "Max Price: ";
				cin >> maxPrice;
				for (int i = 0; i < itemCount; i++)
				{
					if (items[i].isAproved == 1 && items[i].price >= minPrice && items[i].price <= maxPrice)
					{
						cout << "\nItem id: " << items[i].id << endl;
						cout << "Item name: " << items[i].itemName << endl;
						cout << "Price: " << items[i].price << endl;
						cout << "Seller: " << items[i].seller << endl;
						cout << "Descriprion: " << items[i].description << endl;
					}
				}

				break;
			case 4:

				for (int i = 0; i < itemCount; i++)
				{
					for (int j = i + 1; j < itemCount; j++)
					{
						if (items[i].price > items[j].price)
						{
							temp = items[i].price;
							items[i].price = items[j].price;
							items[j].price = temp;
						}
					}
				}

				for (int i = 0; i < itemCount; i++)
				{
					if (items[i].isAproved == 1)
					{
						cout << "\nItem id: " << items[i].id << endl;
						cout << "Item name: " << items[i].itemName << endl;
						cout << "Price: " << items[i].price << endl;
						cout << "Seller: " << items[i].seller << endl;
						cout << "Descriprion: " << items[i].description << endl;
					}
				}

				break;
			case 5:

				for (int i = 0; i < itemCount; i++)
				{
					for (int j = i + 1; j < itemCount; j++)
					{
						if (items[i].price < items[j].price)
						{
							temp = items[i].price;
							items[i].price = items[j].price;
							items[j].price = temp;
						}
					}
				}

				for (int i = 0; i < itemCount; i++)
				{
					if (items[i].isAproved == 1)
					{
						cout << "\nItem id: " << items[i].id << endl;
						cout << "Item name: " << items[i].itemName << endl;
						cout << "Price: " << items[i].price << endl;
						cout << "Seller: " << items[i].seller << endl;
						cout << "Descriprion: " << items[i].description << endl;
					}
				}


				break;
			case 9:
				showMenu = false;
				showItemsMenu();
				break;

		}
	}
}

void editOrderMenu()
{
	fstream itemsTxt("items.txt");
	ofstream itemsTmp("itemsTmp.txt");
	string line, tokens[8], id, help;
	int choice;
	bool offerExist = false;
	cout << "Id of the offer you want to edit: ";
	cin >> id;
	cout << "What you want to change: " << endl;
	cout << "1. Item Name" << endl;
	cout << "2. Price" << endl;
	cout << "3. Description" << endl;
	cout << "Your choice: ";
	cin >> choice;
	if (itemsTxt.is_open())
	{
		while (!itemsTxt.eof())
		{
			getline(itemsTxt, line);
			if (line != "")
			{
				tokenize(line, tokens, '|');
				if (tokens[0] == id)
				{
					switch (choice)
					{
						case 1:
							cout << "The new name of the item: ";
							cin >> help;
							itemsTmp << tokens[0] << "|" << help << "|" << tokens[2] << "|" << tokens[3] << "|" << tokens[4] << "|" << tokens[5] << "|" << endl;
							offerExist = true;
							break;
						case 2:
							cout << "The new price: ";
							cin >> help;
							itemsTmp << tokens[0] << "|" << tokens[1] << "|" << help << "|" << tokens[3] << "|" << tokens[4] << "|" << tokens[5] << "|" << endl;
							offerExist = true;
							break;
						case 3:
							cout << "The new description: ";
							cin >> help;
							itemsTmp << tokens[0] << "|" << tokens[1] << "|" << tokens[2] << "|" << tokens[3] << "|" << help << "|" << tokens[5] << "|" << endl;
							offerExist = true;
							break;
						default:
							break;
					}
				}
				else
				{
					itemsTmp << tokens[0] << "|" << tokens[1] << "|" << tokens[2] << "|" << tokens[3] << "|" << tokens[4] << "|" << tokens[5] << "|" << endl;
				}
			}
		}
		itemsTxt.close();
		itemsTmp.close();
		if (!offerExist)
		{
			cout << "There is no offer with that id." << endl;
			remove("items.txt");
			rename("itemsTmp.txt", "items.txt");
		}
		else
		{
			if (remove("items.txt") == 0)
			{
				cout << "Editing offer 50% done!" << endl;
			}
			else
			{
				cout << "A wild error appeared!" << endl;
			}
			if (rename("itemsTmp.txt", "items.txt") == 0)
			{
				cout << "Editing offer done!" << endl;
			}
			else
			{
				cout << "A wild error appeared!" << endl;
			}
		}
	}
}

void deleteItemMenu()
{
	int id;
	cout << "ID of the offer you want to delete: ";
	cin >> id;
	deleteItem(id);
}

void showAprovedOffers(ITEM* items, int& itemCount)
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

void aproveRecordMenu(ITEM* items, int& itemCount)
{
	int id;
	cout << "Enter Id to aprove: ";
	cin >> id;

}

void showAllOffers(ITEM* items, int& itemCount)
{

	for (int i = 0; i < itemCount; i++)
	{

		cout << "\nid: " << items[i].id << endl;
		cout << "Item Name: " << items[i].itemName << endl;
		cout << "Price: " << items[i].price << endl;
		cout << "Seller Name: " << items[i].seller << endl;
		cout << "Description: " << items[i].description << endl;
		cout << "Is Aproved:" << items[i].isAproved << endl;
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

void approveOffer(int id) {
	ifstream items("items.txt");
	ofstream itemsTmp("itemsTmp.txt");
	string line, tokens[6];
	bool offerExist = false;
	if (items.is_open())
	{
		while (!items.eof()) {
			getline(items, line);
			tokenize(line, tokens, '|');
			if (id == atoi(tokens[0].c_str()) && tokens[5] != "1")
			{
				offerExist = true;
				itemsTmp << id << "|" << tokens[1] << "|" << tokens[2] << "|" << tokens[3] << "|" << tokens[4] << "|" << "1" << "|" << endl;
			}
			else
			{
				itemsTmp << tokens[0] << "|" << tokens[1] << "|" << tokens[2] << "|" << tokens[3] << "|" << tokens[4] << "|" << tokens[5] << "|" << endl;
			}
		}
		items.close();
		itemsTmp.close();
		if (offerExist)
		{
			if (remove("items.txt") == 0)
			{
				cout << "Approving offer 50% done" << endl;
			}
			else
			{
				cerr << "A wild error appeared: " << endl;
			}
			if (rename("itemsTmp.txt", "items.txt") == 0)
			{
				cout << "Approving offer done!!!" << endl;
			}
			else
			{
				cerr << "A wild error appeared: " << endl;
			}
		}
		else
		{
			cout << "There is no offer with that id or the offer was already approved. Nothing happened." << endl;
			remove("items.txt");
			rename("itemsTmp.txt", "items.txt");
		}
	}
}

void manageOffersMenu() {
	ITEM items[150], newItem[1];
	int itemCount = 0, maxID, idForApprove;
	itemCount = inputDataInArray(items);
	maxID = atoi(getIdFromFile().c_str());
	bool offersMenu = true;
	while (offersMenu)
	{
		cout << "\n1. Show all offers" << endl;
		cout << "2. Add offer:" << endl;
		cout << "3. Delete offer:" << endl;
		cout << "4. Edit offer" << endl;
		cout << "5. Aprove offer" << endl;
		cout << "9. Go back" << endl;
		cout << "Your choice: ";
		int choice;
		cin >> choice;

		switch (choice)
		{
			case 1:
				showAllOffers(items, itemCount);
				break;
			case 2:
				addOfferMenu(items, itemCount, maxID);
				break;
			case 3:
				deleteItemMenu();
				break;
			case 4:
				editOrderMenu();
				break;
			case 5:
				cout << "Type the ID of the offer you want to approve: ";
				cin >> idForApprove;
				approveOffer(idForApprove);
				break;
			case 9:
				offersMenu = false;
				adminMenu();
		}
	}
}

void buyOffer() {
	string line, tokens[10], string, adress, name, id;;
	fstream items("items.txt");
	ofstream requests("requests.txt", ios::app);
	bool itemExist = false;
	cout << "ID of the product you want to buy: ";
	cin >> id;
	cout << "Adress: ";
	cin.ignore();
	getline(cin, adress);
	cout << "Name: ";
	cin >> name;
	if (items.is_open())
	{
		while (!items.eof())
		{
			getline(items, line);
			tokenize(line, tokens, '|');
			if (tokens[0] == id && tokens[5] == "1")
			{
				itemExist = true;
				requests << "Sent to " << name << "!!! Adress: " << adress << "!!! Item name : " << tokens[1] << "!!! Item price: " << tokens[2] << "!!! Item description: " << tokens[4] << "\n";
			}
		}
		items.close();
		if (itemExist)
		{
			cout << "Your purchase was succesful. The item will be sent to your adress. You will pay by cash on delivery. Thank you for your purchase" << endl;
			deleteItem(atoi(id.c_str()));
		}
		else
		{
			cout << "There is no item for selling with such an ID" << endl;
		}
	}
}

bool showItemsMenu()
{
	ITEM items[150];
	int itemCount = 0, maxID;
	itemCount = inputDataInArray(items);
	maxID = atoi(getIdFromFile().c_str());
	char input;
	bool OfferMenu = true;
	while (OfferMenu)
	{
		cout << "___________________________________________________\n" << endl;
		cout << endl;
		cout << "\n   |=========== Welcome to our shop ===========|\n" << endl;
		cout << endl;
		cout << "                       Menu:\n" << endl;
		cout << "                 1. Show all offers" << endl;
		cout << "                 2. Show Items By Criterias" << endl;
		cout << "                 3. Buy offers" << endl;
		cout << "                 4. Add offers" << endl;
		cout << "                 9. Back\n\n";
		cout << "\nChoose an option: ";
		cin >> input;
		cout << endl;

		switch (input)
		{
			case '1':
				showAprovedOffers(items, itemCount);
				break;
			case '2':
				sortItemsMenu(items, itemCount);
				break;
			case '3':
				buyOffer();
				break;
			case '4':
				addOfferMenu(items, itemCount, maxID);
				break;
			case '9':
				OfferMenu = false;
				Menu();
				break;
			default: while (input != '1' && input != '2' && input != '3' && input != '9')
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
			manageOffersMenu(); return false;
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
	showItemsMenu();
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

			showItemsMenu();
		}
	}
	else if (character == 'N')
	{
		cout << "Please first register before login!" << endl;
		Register();
	}
}

bool Menu() {
	char input;
	bool whileCheck = true;

	cout << "\n|============== Welcome to DigiBitak ==============|\n" << endl;
	cout << endl;
	cout << "                       Menu:\n" << endl;
	cout << "                   1. Login" << endl;
	cout << "                   2. Register" << endl;
	cout << "                   9. Exit\n\n";
	cout << "\nChoose an option: ";
	cin >> input;
	cout << endl;

	while (whileCheck)
	{
		switch (input)
		{
			case 'k':
				showItemsMenu();
				return false;
				break;
			case '1':
				login(); return false;
				break;
			case '2':
				Register(); return true;
				break;
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
	system("color 03");

	Menu();

	return 0;
}
