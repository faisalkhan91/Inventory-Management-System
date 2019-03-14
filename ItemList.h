#ifndef ITEMLIST_H_INCLUDED
#define ITEMLIST_H_INCLUDED

#include "Item.h"

class ItemList{
// Private Variables
private:
    Item * itemList;
    int count;
    int curAllocation;

// Public Variables
public:
    ItemList(); //Constructor
    ~ItemList(); // Destructor
    void addItem(Item& obj);
    void printItem(Item& obj, int& cnt);
    void findItemID(Item& obj);
    void findItemName(Item& obj);
    void writeFile();
    void readFile(Item pobj, ItemList pitem);
    void setCount(int count){this->count=count;};
    int getCount(){return count;};
};

#endif // ITEMLIST_H_INCLUDED
