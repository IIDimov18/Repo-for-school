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
	int id=0;
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

int tokenize(string line, string* results, char delimiter) {
	string help, help1 = line;
	int counter = 0;
	for (int i = 0; i < help1.size(); i++)
	{
		if (help1[i] == delimiter)
		{
			results[counter++] = help;
			help = "";
		}
		help[i] = help1[i];
	}
	return counter;
}

void manageAccounts()
{
	int choice;
	ifstream myfile("acc.txt");
	string tokens[150], help;
	int counter = 0, checkCounter = 0;

	cout << "___________________________________________________" << endl;
	cout << endl;
	cout << "                1. Show all accounts" << endl;
	cout << "                2. Delete account" << endl;
	cout << "                3. Edit account" << endl;
	cout << "                4. Remove/Add Admin\n" << endl;
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
	case 2:
		/*cout << "Name of user: ";
		cin >> help;*/
		if (myfile.is_open())
		{
			string line;
			while (!myfile.eof())
			{
				string line((istreambuf_iterator<char>(myfile)),
					(istreambuf_iterator<char>()));
				tokenize(line, tokens, ',');
				cout << tokens;
			}
		}
	case 3:

		break;
	default:
		break;
	}
	myfile.close();
}
void manageOffers() {

}

//************************************************************************************

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
			adminMenu(); return false;
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

void createItem(ITEM* items, int& orderCount, ITEM newItem)
{
	items[orderCount] = newItem;
	orderCount++;
}

void initItems(ITEM* items, int& itemCount)
{
	createItem(items, itemCount, { "Gosho", "Bathroom tiles", 12.35, "the price is for m / sq" });
	createItem(items, itemCount, { "Alex", "Mouse Pad", 21.45, "35x45" });
	createItem(items, itemCount, { "Pesho", "LG TV", 769.99, "42 inches" });
	createItem(items, itemCount, { "Penka", "T-Shirt", 9.99, "XL size " });
	createItem(items, itemCount, { "Nelina", "White Mercedes", 6829, "Year of manufacture: 1997 " });
	createItem(items, itemCount, { "Milko", "Chickens", 20, "One chicken- 20 bgn " });
	createItem(items, itemCount, { "John", "Fridge", 178, "2x1" });
	createItem(items, itemCount, { "Miroslav", "Leather", 25, "25 bgn for 1 meter" });
	createItem(items, itemCount, { "Ivan", "Turkeys", 35, "35 bgn for 1 turkey" });
	createItem(items, itemCount, { "Martin", "Pillow", 15, "15 bgn for 1 pillow" });
}

void writeInFile(ITEM* item, int itemCount)
{
	ofstream data;
	data.open("data.txt");
	for (int i = 0; i < itemCount; i++)
	{
		data << item[i].itemName << "|" << item[i].seller << "|" << item[i].price << "|" << item[i].description << endl;
	}
	data.close();
}


//************************************************************************************
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

string getIdFromFile()
{
	string line;
	ifstream myfile("id.txt");
	while (getline(myfile, line))
	{
		return line;
	}
	myfile.close();
}

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

void updateItem(ITEM * items, ITEM newItem, int& itemCount, int& maxId) {
	int index = getItemIndexById(items, itemCount, maxId);
	items[index] = newItem;
}

void deleteItem(ITEM * items, int& itemCount, int id) {

	int index = getItemIndexById(items, itemCount, id);
	for (int i = index; i < itemCount - 1; i++)
	{
		items[i] = items[i + 1];
	}
	itemCount--;
}

ITEM getItemById(ITEM * items, int& itemCount, int id)
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

/*void initItemsInArray(ITEM* items, int& itemCount, int& maxId)
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
} */


int main()
{
	int itemCount = 0;
	ITEM items[200];
	initItems(items, itemCount);
	writeInFile(items, itemCount);
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
