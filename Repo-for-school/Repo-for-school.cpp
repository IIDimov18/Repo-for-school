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

/********* Iliyan is working here (Data layer)***********/












/********* Iliyan is working here (Data layer)***********/


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
	ITEM items[200];
	//initItems(items, itemCount);
	//writeInFile(items, itemCount);
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
