/*Write a program to demonstrate the use of different ios flags
and functions to format the output. Create a program to generate
the bill invoice of a department store by using different formatting.*/

#include <iostream>
#include <iomanip>

using namespace std;
const int NAME = 25;
const int PRICE = 12;

class Purchase
{
private:
    char itemName[NAME];
    float price;

public:
    void getPurchasedItem()
    {
        cout << "Enter the item name: ";
        cin.ignore(); // to ignore the newline character
        cin.getline(itemName, NAME);
        cout << "Enter the price: ";
        cin >> price;
    }
    void displayPurchasedItem()
    {
        cout.setf(ios::left, ios::adjustfield);
        cout.width(NAME);
        cout << itemName;
        cout.flags(ios::showpoint | ios::fixed | ios::right);
        cout.precision(2);
        cout.width(PRICE);
        cout << price << endl;
    }
};

int main()
{
    int numberOfItems, i = 0;
    cout << "Enter the number of items: ";
    cin >> numberOfItems;
    Purchase *p = new Purchase[numberOfItems];
    while (i < numberOfItems)
    {
        cout << "Item " << i + 1 << endl;
        p[i].getPurchasedItem();
        i++;
    }
    i = 0;
    cout << endl
         << "Please wait while the bill is being generated..." << endl<<endl;
    cout << setw(NAME) << setiosflags(ios::left) << "Item Name" << setw(PRICE) << setiosflags(ios::right) << "Price" << endl;
    while (i < numberOfItems)
    {
        p[i].displayPurchasedItem();
        i++;
    }
    delete[] p;
    return 0;
}

/*setprecision(n) applies to the entire number, not the fractional part.
You need to use the fixed-point format to make it apply to the fractional part:
setiosflags(ios::fixed)*/