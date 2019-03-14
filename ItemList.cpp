#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include "ItemList.h"
#include "Item.h"

using namespace std;

//Constructor--Initial allocation of the class object
ItemList::ItemList()
{
    curAllocation=5;
    itemList=new Item[curAllocation];
    count=0;
}
//Destructor
ItemList::~ItemList()
{
    delete[] itemList;
}

//Dynamic memory allocation
void ItemList::addItem(Item& obj)
{
    if(count < curAllocation)
    {
        itemList[count]=obj;
        ++count;
    }
    else
    {
        Item *temp = itemList;
        itemList = new Item[curAllocation*2];
        curAllocation=curAllocation*2;
        for(int i=0; i<count; i++)
        {
            itemList[i]=temp[i];
        }
        delete[] temp;
    }

    setCount(count);

//    cout<<"\nThe Item details are: \n"<<endl;
//	cout<<"Item ID: "<<obj.getId()<<endl;
//	cout<<"Item Name: "<<obj.getName()<<endl;
//	cout<<"Item Cost: "<<obj.getCost()<<endl;
//	cout<<"Item Quantity: "<<obj.getQuantity()<<endl;

}

//Function to print items calling Item class
void ItemList::printItem(Item& obj, int& cnt)
{
    cout<<"calling item function"<<endl;
    cout<<cnt;
    for(int i=0; i<cnt; ++i)
    {
        itemList[i].printItems(obj);
    }
}

//To find by ID
void ItemList::findItemID(Item& obj)
{
    int id;

    cout<<"Enter the Item ID to be found: "<< endl;
    cin>>id;

    for(int i=0; i<count; i++)
    {
        if(itemList[i].getId()==id)
        {
            cout<<"The Item details are: \n";
            itemList[i].printItems(obj);
            break;
        }

        else if (i >= count -1 && itemList[i].getId() != id)
        {
            cout<<"Error: Item not Found!"<<endl;
            break;
        }
    }
}

//To find by name
void ItemList::findItemName(Item& obj)
{
    string name;
    cout<<"Enter the name to be searched: "<<endl;
    getline(cin>>ws, name);

    for(int i=0; i<count;i++)
    {
        if(itemList[i].getName()==name)
        {
            cout<<"The Item details are: \n";
            itemList[i].printItems(obj);
            break;
        }
        else if(i >= count -1 && itemList[i].getName() != name)
        {
            cout<<"Error: Item not found!"<<endl;
            break;
        }
    }
}

//Writing to file
void ItemList::writeFile()
{
    ofstream myOut;
    myOut.open("InventoryList.txt", ios::app);
    for (int i=0; i<count; ++i)
    {
        myOut<<"hello";
        cout<<itemList[i].getId();
        myOut<<itemList[i].getId()<<endl;
        myOut<<itemList[i].getName()<<endl;
        myOut<<itemList[i].getCost()<<endl;
        myOut<<itemList[i].getQuantity()<<endl;
    }
    myOut.close();
}

//Read all the details from the file
void ItemList::readFile(Item pobj, ItemList pitem)
{
    unsigned short tid;
    string tname;
    float tcost;
    int tquantity;

    ifstream myOut;
    myOut.open("InventoryList.txt", ios::in);
    if (!myOut.is_open())
    {
        cout<<"Error: File not found"<<endl;
    }
    else
    {
        for(;;)
        {
            myOut>>tid;
            pobj.setId(tid);
            myOut.ignore();
            getline(myOut, tname);
            pobj.setName(tname);
            myOut>>tcost;
            pobj.setCost(tcost);
            myOut>>tquantity;
            pobj.setQuantity(tquantity);

            if (myOut.good())
            {
                Item(tid, tname, tcost, tquantity);
                pitem.addItem(pobj);
            }
            else if(myOut.eof())
            {
                break;
            }
        }
    }
    myOut.close();
}
