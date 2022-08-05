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
        cout << "First name: ";
        cin >> firstName;
        cout << "Last name: ";
        cin >> lastName;
        cout << "Account number: ";
        cin >> accNumber;
        cout << "Total balance: ";
        cin >> totalBalance;
    }
    void showData()
    {
        cout << setw(MAX) << firstName << setw(MAX) << lastName << setw(MAX) << accNumber << setw(MAX) << totalBalance << endl;
    }
};

int main()
{
    int choice;
    char choiceChar = 'y';
    fstream file;
    while (choiceChar == 'y' || choiceChar == 'Y')
    {
        cout << "1. Add record" << endl
             << "2. Update record" << endl
             << "3. Delete record" << endl
             << "4. Display record" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                Customer c;
                c.getData();
                file.open("customer.txt", ios::app | ios::binary); // append mode
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
                cout << "There are total " << numberOfRecords << " records." << endl
                    << "Enter the record number to be updated: ";
                cin >> recordNumber;
                fstream tempFile;
                tempFile.open("tempFile.txt", ios::binary | ios::out);
                file.seekg(0);
                for (int i = 0; i < recordNumber - 1; i++)
                {
                    file.read(reinterpret_cast<char *>(&c), sizeof(c));
                    tempFile.write(reinterpret_cast<char *>(&c), sizeof(c));
                }
                c.getData();
                tempFile.write(reinterpret_cast<char *>(&c), sizeof(c)); // write the updated data into new file
                file.seekg(sizeof(c), ios::cur);                         // skip the old data while writing data into new filr
                for (int i = recordNumber; i < numberOfRecords; i++)
                {
                    file.read(reinterpret_cast<char *>(&c), sizeof(c));
                    tempFile.write(reinterpret_cast<char *>(&c), sizeof(c));
                }
                tempFile.close();
                file.close();

                // copying from tempfile to file
                file.open("customer.txt", ios::out | ios::binary);
                tempFile.open("tempFile.txt", ios::in | ios::binary);
                for (int i = 0; i < numberOfRecords; i++)
                {
                    tempFile.read(reinterpret_cast<char *>(&c), sizeof(c));
                    file.write(reinterpret_cast<char *>(&c), sizeof(c));
                }
                file.close();
                tempFile.close();
                break;
            }
            case 3:
            {
                Customer c;
                int numberOfRecords, recordNumber;
                file.open("customer.txt", ios::binary | ios::in);
                file.seekg(0, ios::end);
                numberOfRecords = file.tellp() / sizeof(Customer);
                cout << "There are total " << numberOfRecords << " records." << endl
                    << "Enter the record number to be deleted: ";
                cin >> recordNumber;

                fstream tempFile;
                tempFile.open("tempFile.txt", ios::binary | ios::out);
                file.seekg(0);
                for (int i = 0; i < recordNumber - 1; i++)
                {
                    file.read(reinterpret_cast<char *>(&c), sizeof(c));
                    tempFile.write(reinterpret_cast<char *>(&c), sizeof(c));
                }
                file.seekg(sizeof(c), ios::cur); // skipping the data to be deleted
                for (int i = recordNumber; i < numberOfRecords; i++)
                {
                    file.read(reinterpret_cast<char *>(&c), sizeof(c));
                    tempFile.write(reinterpret_cast<char *>(&c), sizeof(c));
                }
                tempFile.close();
                file.close();

                // copying from tempfile to file
                file.open("customer.txt", ios::out | ios::binary);
                tempFile.open("tempFile.txt", ios::in | ios::binary);
                for (int i = 0; i < numberOfRecords - 1; i++) //-1 because we just deleted a record
                {
                    tempFile.read(reinterpret_cast<char *>(&c), sizeof(c));
                    file.write(reinterpret_cast<char *>(&c), sizeof(c));
                }
                file.close();
                tempFile.close();
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
                for (int i = 0; i < numberOfRecords; i++)
                {
                    file.read(reinterpret_cast<char *>(&c[i]), sizeof(c[i]));
                }
                cout << setw(MAX) << left << "First name" << setw(MAX) << left << "Last name" << setw(MAX) << left << "Account number" << setw(MAX) << left << "Total balance" << endl;
                for (int i = 0; i < numberOfRecords; i++)
                {
                    c[i].showData();
                }
                file.close();
                delete[] c;
                break;
            }
            default:
                cout << "Invalid input..." << endl;
        }
        cout << "Do you wish to continue? ['y' or 'n']: ";
        cin >> choiceChar;
    }
    return 0;
}