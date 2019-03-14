#include <iostream>
#include <stdlib.h>
#include "Item.h"
#include "ItemList.h"

using namespace std;

int menuSelection(void);

int main()
{
    int select;
    Item obj;
    ItemList item;
    string option;
    int cnt=0;

    item.readFile(obj, item);// Read from the file function call

    do{
        select = menuSelection();
        switch(select)
        {
            case 1:
                do{

                        obj.addItem(obj);
                        cnt++;

                        cout<<"\nDo you want to add another Item? [Y/N]"; // To ask user if they want to enter another item
                        getline(cin>>ws, option);

                }while(option == "Y" || option == "y" || option == "Yes");
                break;

            case 2:
                cout<<item.getCount()<<endl;
                item.printItem(obj, cnt); // Print List function call
                break;

            case 3:
                item.findItemID(obj); //Find by ID function call
                break;

            case 4:
                item.findItemName(obj); //Find by name function call
                break;

            case 5:
                item.writeFile(); //Function to save data to file
                cout<<"Good Bye!"<<endl;
                break;
            default:
                cout<<"Error: Invalid selection. Please try again!"<<endl;
        }
    }while(select !=5);

    return 0;
}

int menuSelection(void)
{

    int select;

    cout<<"\t\tInventory Management System Menu"<<endl;
    cout<<"1. Add new item"<<endl;
    cout<<"2. Print item list"<<endl;
    cout<<"3. Find item by ID"<<endl;
    cout<<"4. Find item by name"<<endl;
    cout<<"5. Quit"<<endl;
    cout<<"Select:_";
    cin>>select;
    return select;
}

/*
Write a menu driven application in C++ which will print the following Inventory Management System Menu
repeatedly until the Quit option is selected.

Inventory Management System Menu
1.	Add new item
2.	Print item list
3.	Find item by ID
4.	Find item by name
5.	Quit
Select: _
*/

/*
Note:
	Menu should repeatedly prompt to the user until the Quit option is selected by the user.
	Create data class for item and a container class for item list.
    (Similar to the student registration program you did in previous assignment).
	Use dynamic memory allocation to maintain the item list.
	Use file to store the items inventory information. You can create a .txt file to store the items.
    Hint: When user selects to quit, persist all item information in a .txt file.
    To make it easier to read this file on startup, store each item on a separate line.
    When your program starts again read the .txt file and load all item information back into your container class.
*/
