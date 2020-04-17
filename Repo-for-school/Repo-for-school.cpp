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


int main()
{
	int itemCount = 0;
	int maxId = 1;
	ITEM items[200];
}