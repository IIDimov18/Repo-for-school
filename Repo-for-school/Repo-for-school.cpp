#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;
bool admin = false;
struct ITEM
{
	string seller = "";
	string itemName = "";
	float price = 0;
	string description = "";
	int id = 0;
};

struct USER
{
	string username = "";
	string password = "";
	int countOfItemsForSell = 0;
	// ITEM itemsForSale[];
	int id = 0;
};


/*int login() {
	int choice;
	string username, password;
	cout << "You need to login. Choose role you want to login with." << endl << "1) User" << endl << "2) Admin" << endl << "Your choice(answer with number):";
	cin >> choice;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
	switch (choice)
	{
	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}
	return 0;
}
*/
//Admincho,rootcho,1
//Admin1, root1, 0
//Admin2, root2, 1
//Admin3, root3, 0
//Admin4, root4, 1

//************************************************************************************

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
					cout << "Invalid account!" << endl;
				}
			}
			else
			{
				getline(myfile, line[3]);
			}
		}
		myfile.close();
	}
	return "DEF";
}

//************************************************************************************


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

//************************************************************************************

void manageAccounts() {
	int choice;
	ifstream myfile("acc.txt");
	string line[20], help;
	int counter = 0, checkCounter = 0;
	cout << "1. Show all accounts" << endl << "2. Delete account" << endl << "3. Edit account" << endl << "4. Remove/Add Admin" << endl << "Choice: " << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		if (myfile.is_open())
		{
			while (myfile.good())
			{
				getline(myfile, line[0], ',');
				help = line[0];
				if (help == "")
				{

				}
				else
				{
					if (help[0] == '\n')
					{
						help.erase(0, 1);
					}
					cout << "Username: " << help;
					getline(myfile, line[1], ',');
					getline(myfile, line[2], ',');
					cout << " Admin: ";
					if (line[2] == "1")
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
	default:
		break;
	}
	myfile.close();
}
void manageOffers() {

}

//************************************************************************************


void adminMenu()
{
	int choice;
	cout << "1. Manage Offers" << endl << "2. Manage accounts" << endl << "Choice";
	cin >> choice;
	switch (choice)
	{
	case 1:
		manageAccounts();
		break;
	case 2:
		manageOffers();
		break;
	default:

		break;
	}
}

//************************************************************************************

void login() {
	string username, password;
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
		cout << "___________________________________________________" << endl;
		cout << endl;
		cout << "               |===== LOGIN =====|\n\n" << endl;
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		cout << endl;
		cout << checkAcc(username, password);
		if (checkAcc(username, password) == "1")
		{

		}
	}
	else if (character == 'N')
	{
		cout << "Please first register before login!" << endl;
		Register();
	}
}

//************************************************************************************

bool Menu() {
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
			adminMenu();
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

//************************************************************************************

/********* Iliyan is working here ***********/



void insertItemInArray(ITEM* items, int& itemCount, ITEM newItem, int& maxId)
{
	newItem.id = maxId;
	items[itemCount] = newItem;
	itemCount++;
	maxId++;

	ofstream id;
	id.open("id.txt");
	id << maxId;

}

 /* void initItemsInArray(ITEM* items, int& itemCount, int& maxId)
{
	insertItemInArray(items, itemCount, { "Gosho", "Bathroom tiles", 12.35, "the price is for m / sq" },maxId);
	insertItemInArray(items, itemCount, { "Alex", "Mouse Pad", 21.45, "35x45" },maxId);
	insertItemInArray(items, itemCount, { "Pesho", "LG TV", 769.99, "42 inches " },maxId);
	insertItemInArray(items, itemCount, { "Penka", "T-Shirt", 9.99, "XL size " },maxId);
	insertItemInArray(items, itemCount, { "Nelina", "White Mercedes", 6829, "Year of manufacture: 1997 " },maxId);
	insertItemInArray(items, itemCount, { "Milko", "Chickens", 20, "One chicken- 20 bgn " },maxId);
	insertItemInArray(items, itemCount, { "John", "Fridge", 178, "2x1" },maxId);
	insertItemInArray(items, itemCount, { "Miroslav", "Leather", 25, "25 bgn for 1 meter" },maxId);
	insertItemInArray(items, itemCount, { "Ivan", "Turkeys", 35, "35 bgn for 1 turkey" },maxId);
	insertItemInArray(items, itemCount, { "Martin", "Pillow", 15, "15 bgn for 1 pillow" },maxId);
} 
*/

void writeDataIntoFile(ITEM* items, int& itemCount)
{
	ofstream data;
	data.open("items.txt", ios::app);

	for (int i = 0; i < itemCount; i++)
	{
		data << items[i].id << "|" << items[i].itemName << "|" << items[i].price << "|" << items[i].seller << "|" << items[i].description << "|" << endl;
	}

	data.close();

}

int getItemIndexById(ITEM* items, int& itemCount, int id)
{
	for (int i = 0; i < itemCount; i++)
	{
		if (items[i].id == id)
			return i;
	}

	return NULL;
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

/*int insertDataFromFileIntoArray(ITEM* items)
{
	short size;
	string line;
	ifstream myfile("item.txt");
	while (!myfile.eof())
	{
		getline(myfile, line);
		items[size++] = line;
	}
	myfile.close();
}
*/




/********* Iliyan is working here ***********/


//************************************************************************************

//void split(char character, string& arr,string stringToSplit) {
//	char help[30];
//	int counter = 0, arrCounter = 0;;
//	for (int i = 0; i < stringToSplit.length(); i++)
//	{
//		if (stringToSplit[i]==character)
//		{
//			arr[counter++] = help;
//		}
//		else
//		{
//			help[counter++] = stringToSplit[i];
//		}
//	}
//}

//************************************************************************************

int main()
{
	int itemCount = 0;
	int maxId = 1;
	ITEM items[200];
	initItemsInArray(items, itemCount, maxId);
	writeDataIntoFile(items, itemCount);

	/*ITEM nov;
	getline(cin, nov.itemName);
	cin >> nov.price;
	cin.ignore();
	getline(cin, nov.seller);
	getline(cin, nov.description);

	insertItemInArray(items, itemCount, nov);
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
	Menu();
	return 0;
}
