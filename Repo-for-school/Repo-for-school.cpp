#include <iostream>
#include <string>
using namespace std;


struct ITEMS
{
	string user;
	string itemName;
	float price;
	int quantity;
};


int kartof(int kartof) {
	return kartof;
}






















struct USER
{
	string username;
	string password;
	int countOfItemsForSell;
	ITEMS itemsForSale[];
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

int main()
{
	cout << "TEST";
}