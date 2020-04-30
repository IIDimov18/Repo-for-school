#pragma once
#include<iostream>
using namespace std;


struct ITEM
{
	string seller = "";
	string itemName = "";
	float price = 0;
	string description = "";
	int id = 0;
	bool isAproved = false;
};

struct USER
{
	string username = "";
	string password = "";
	int countOfItemsForSell = 0;
	// ITEM itemsForSale[];
	int id = 0;
};
