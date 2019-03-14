#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <string>

using namespace std;

class Item{
// Private Variables
private:
    unsigned short id;
    string name;
    float cost;
    int quantity;

//Public Variables
public:
    //Class Functions
    //Constructor for the Item
    Item();
    Item(unsigned short id, string name, float cost, int quantity);
    int addItem(Item& obj);
    void printItems(Item& obj);
    int findItemID();
    int findItemName();
    //Accessor Setters
    void setId(unsigned short id){this->id=id;};
    void setName(string name){this->name=name;};
    void setCost(float cost){this->cost=cost;};
    void setQuantity(int quantity){this->quantity=quantity;};
    //Accessor Getters
    unsigned short getId(){return id;};
    string getName(){return name;};
    float getCost(){return cost;};
    int getQuantity(){return quantity;};
};


#endif // ITEM_H_INCLUDED

/*
You’ve been asked to write a small menu driven inventory management system for a small convenient store.
Your application shall maintain the following item information.

Item information:
    Item ID – unsigned long
	Item name – string
	Item cost – float
	Quantity - int
*/
