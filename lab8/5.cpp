/*Write a program for transaction processing that write and read object randomly
 to and from a random access file so that user can add, update, delete and 
 display the account information (account-number, last-name, first-name, 
 total-balance).*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;
const int MAX = 15;

class Customer
{
private:
    char firstName[MAX];
    char lastName[MAX];
    char accNumber[MAX];
    char totalBalance[MAX];
public:
    Customer()
    {
        strcpy(firstName, " ");
        strcpy(lastName, " ");
        strcpy(accNumber, " ");
        strcpy(totalBalance, " ");
    }
    void getData()
    {
        cout<<"First name: ";
        cin>>firstName;
        cout<<"Last name: ";
        cin>>lastName;
        cout<<"Account number: ";
        cin>>accNumber;
        cout<<"Total balance: ";
        cin>>totalBalance;
    }
    void showData()
    {
        cout<<setw(MAX)<<firstName<<setw(MAX)<<lastName<<setw(MAX)<<accNumber<<setw(MAX)<<totalBalance<<endl;
    }
};

int main()
{
    int choice;
    cout<<"1. Add record"<<endl<<"2. Update record"<<endl<<"3. Delete record"<<endl<<"4. Display record"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    fstream file;
    switch(choice)
    {
        case 1:
            {
                Customer c;
                c.getData();
                file.open("customer.txt", ios::app | ios::binary);//append mode
                file.write(reinterpret_cast<char *>(&c), sizeof(c));
                file.close();
                break;
            }
        case 2:
            {
                Customer c;
                int numberOfRecords, recordNumber;
                file.open("customer.txt", ios::binary | ios::in);
                file.seekg(0, ios::end);
                numberOfRecords = file.tellg() / sizeof(Customer);
                cout<<"There are total "<<numberOfRecords<<" records."<<endl
                    <<"Enter the record number to be updated: ";
                cin>>recordNumber;
                file.read(reinterpret_cast<char *>(&c), sizeof(c));
                c.getData();
                file.close();

                file.open("customer.txt", ios::binary | ios::app);
                file.seekp((recordNumber-1) * sizeof(Customer));
                file.write(reinterpret_cast<char *>(&c), sizeof(c));
                file.close();
                break;
            }
        case 3:
            {
                Customer c, c1;
                int numberOfRecords, recordNumber;
                file.open("customer.txt", ios::binary | ios::in);
                file.seekg(0, ios::end);
                numberOfRecords = file.tellg() / sizeof(Customer);
                cout<<"There are total "<<numberOfRecords<<" records."<<endl
                    <<"Enter the record number to be deleted: ";
                cin>>recordNumber;
                file.read(reinterpret_cast<char *>(&c), sizeof(c));
                c = c1; //copy constructor
                file.close();

                file.open("customer.txt", ios::binary | ios::app);
                file.seekp((recordNumber-1) * sizeof(Customer));
                file.write(reinterpret_cast<char *>(&c), sizeof(c));
                file.close();
                break;
            }
        case 4:
            {
                int numberOfRecords;
                file.open("customer.txt", ios::binary | ios::in);
                file.seekg(0, ios::end);
                numberOfRecords = file.tellg() / sizeof(Customer);
                file.seekg(0, ios::beg);
                Customer *c = new Customer[numberOfRecords];
                for(int i=0; i<numberOfRecords; i++)
                {
                    file.read(reinterpret_cast<char *>(&c[i]), sizeof(c[i]));
                }
                cout<<setw(MAX)<<left<<"First name"<<setw(MAX)<<left<<"Last name"<<setw(MAX)<<left<<"Account number"<<setw(MAX)<<left<<"Total balance"<<endl;
                for(int i=0; i<numberOfRecords; i++)
                {
                    c[i].showData();
                }
                file.close();
                delete[] c;
            }
    }
    return 0;
}