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
					cout << "Wrong password. Please try again";
				}
			}
			else
			{
				getline(myfile, line[3]);
				cout << "This username doesn't exist" << endl;
				login();
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
void createItem(ITEM* items, int& orderCount, ITEM newItem, int& maxId)
{
	newItem.id = maxId;
	items[orderCount] = newItem;

	orderCount++;
	maxId++;
}

int getItemIndexById(ITEM* items, int& itemCount, int id)
{
	for (int index = 0; index < itemCount; index++)
	{
		if (items[index].id == id) // check 
		{
			return index;
		}
	}

	return -1;
}

void initItems(ITEM* items, int& itemCount, int& maxId) 
{
	createItem(items, itemCount, { "Gosho", "Bathroom tiles", 12.35, "the price is for m / sq" }, maxId);
	createItem(items, itemCount, { "Alex", "Mouse Pad", 21.45, "35x45" }, maxId);
	createItem(items, itemCount, { "Pesho", "LG TV", 769.99, "42 inches " }, maxId);
	createItem(items, itemCount, { "Penka", "T-Shirt", 9.99, "XL size " }, maxId);
	createItem(items, itemCount, { "Nelina", "White Mercedes", 6829, "Year of manufacture: 1997 " }, maxId);
	createItem(items, itemCount, { "Milko", "Chickens", 20, "One chicken- 20 bgn " }, maxId);
	createItem(items, itemCount, { "John", "Fridge", 178, "2x1" }, maxId);
	createItem(items, itemCount, { "Miroslav", "Leather", 25, "25 bgn for 1 meter" }, maxId);
	createItem(items, itemCount, { "Ivan", "Turkeys", 35, "35 bgn for 1 turkey" }, maxId);
	createItem(items, itemCount, { "Martin", "Pillow", 15, "15 bgn for 1 pillow" }, maxId);
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
	int maxId = 1;
	ITEM items[200];
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