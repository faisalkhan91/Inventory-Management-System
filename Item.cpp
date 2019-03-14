#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "Item.h"
#include "ItemList.h"

using namespace std;

//Constructor for Item

Item::Item()
{

}

Item::Item(unsigned short id, string name, float cost, int quantity)
{
    this->id=id;
    this->name=name;
    this->cost=cost;
    this->quantity=quantity;
}

int Item::addItem(Item& obj)
{
    ItemList item;

    unsigned short tid;
    string tname;
    float tcost;
    int tquantity;

    cout<<"Enter the Item ID: ";
    cin>>tid;
    setId(tid);

    cout<<"Enter the Item Name: ";
    getline(cin>>ws, tname);
    setName(tname);

    cout<<"Enter the Item Cost: ";
    cin>>tcost;
    setCost(tcost);

    cout<<"Enter the Item Quantity: ";
    cin>>tquantity;
    setQuantity(tquantity);

	cout<<"\nThe Item details are: \n"<<endl;
	cout<<"Item ID: "<<getId()<<endl;
	cout<<"Item Name: "<<getName()<<endl;
	cout<<"Item Cost: "<<getCost()<<endl;
	cout<<"Item Quantity: "<<getQuantity()<<endl;

	Item(tid, tname, tcost, tquantity);
	item.addItem(obj); //Calling the container class
}

//To print the Item details

void Item::printItems(Item& obj)
{
    cout<<"hello"<<endl;
    cout<<"Item ID: "<< setw(5)<<right<<obj.getId()<<endl;
    cout<<"Item Name: "<<setw(5)<<right<<obj.getName()<<endl;
    cout<<"Item Cost: "<<setprecision(6)<<setw(5)<<right<<obj.getCost()<<endl;
    cout<<"Item Quantity: "<<setw(5)<<right<<obj.getQuantity()<<endl;
}

/*
int Item::printItems()
{
    unsigned short tid;
    string tname;
    float tcost;
    int tquantity;

    cout<<"Item ID: ";
    getId();

    cout<<"Item Name: ";
    getName();

    cout<<"Item Cost: ";
    getCost();

    cout<<"Item Quantity: ";
    getQuantity();
}
*/
/*
int Item::findItemID(int& Fid)
{
    Fid=Item.getId();
    for(int i=0; i<count; ++i)
    {

    }
}

int Item::findItemName(string& Fname)
{
    Fname=
}
*/

/*
Following are the list of administrative functionality your application shall support initially:
1.	Add new item to the inventory. This function will be used to add a single new item into the inventory management system.
2.	Print all item information in the store - This function will be used to display all items in the inventory.
    When this option is selected system shall print Item ID, Item name, Item cost and quantity.
3.	Find item by ID – This function will be used to search item using an ID. If item exist print item information.
    If not display an error indicating item not found.
4.	Find item by name – This function will be used to search item using name. If item exist print item information.
    If not display an error indicating item not found.
*/
