#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;


struct ITEM
{
	string seller = "";
	string itemName = "";
	float price = 0;
	string description = "";
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

string checkAcc(string username,string password) {
	ifstream myfile("acc.txt");
	string line[20];
	int counter=0,checkCounter=0;
	if (myfile.is_open())
	{
		while (myfile.good())
		{
			getline(myfile, line[0], ',');
			if (line[0]==username)
			{
				getline(myfile, line[1], ',');
				if (line[1]==password)
				{
					getline(myfile, line[2], ',');
					return line[2];
				}
				else
				{

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
void login() {
	string username, password;
	char character;
	cout << "Do you have existing account[Y/N]: ";
	cin >> character;
	if (character=='Y')
	{
		cout << "Username: ";
		cin >> username;
		cout <<endl<< "Password: ";
		cin >> password;
		cout<<checkAcc(username, password);
	}
	else
	{
		
	}
}
void Menu() {
	char input;
	bool whileCheck = true;
	cout << "Menu:" << endl << "1. Login" << endl << "2. Register" << endl << "3. Show Offers";
	cin >> input;
	while (whileCheck)
	{
		switch (input)
		{
		case '1':
			login();
			whileCheck = false;
			break;
		case '2':
			whileCheck = false;
			break;
		case '3':
			whileCheck = false;
			break;
		default:
			break;
		}
	}
}
void login() {
	string username, password;
	char character;
	cout << "Do you have existing account[Y/N]: ";
	cin >> character;
	cout << endl;
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
	}
	else
	{

	}
}
void Menu() {
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
			login();
			whileCheck = false;
			break;
		case '2':
			whileCheck = false;
			break;
		case '3':
			whileCheck = false;
		case '9':
			whileCheck = false;
			break;
		default:
			break;
		}
	}
}
void createItem(ITEM* items, int& orderCount, ITEM newItem)
{
	items[orderCount] = newItem;
	orderCount++;	
}



void initItems(ITEM* items, int& itemCount) 
{
	createItem(items, itemCount, { "Gosho", "Bathroom tiles", 12.35, "the price is for m / sq" });
	createItem(items, itemCount, { "Alex", "Mouse Pad", 21.45, "35x45" });
	createItem(items, itemCount, { "Pesho", "LG TV", 769.99, "42 inches"});
	createItem(items, itemCount, { "Penka", "T-Shirt", 9.99, "XL size "});
	createItem(items, itemCount, { "Nelina", "White Mercedes", 6829, "Year of manufacture: 1997 "});
	createItem(items, itemCount, { "Milko", "Chickens", 20, "One chicken- 20 bgn "});
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
	//Menu();
	return 0;
}