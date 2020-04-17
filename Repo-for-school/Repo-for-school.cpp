#include <iostream>
#include <string>
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

/* void initItems()
{

}
*/


int main()
{
	int itemCount = 0;
	int maxId = 1;
	ITEM items[200];
}