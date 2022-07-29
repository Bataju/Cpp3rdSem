/*Write a program that stores the information about students (name, student id, department, and address)
in a structure and then transfers the information to a file in your directory.
Finally, retrieve the information from your file and print it in the proper format on your output screen.*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const int MAX = 25;

typedef struct Student
{
    char studentName[MAX];
    char studentId[MAX];
    char studentDepartment[MAX];
    char studentAddress[MAX];
} Student;

int main()
{
    int numberOfStudents;
    cout << "Enter the number of students: ";
    cin >> numberOfStudents;
    cin.ignore();
    Student *student = new Student[numberOfStudents];

    for (int i = 0; i < numberOfStudents; i++)
    {
        cout << "Student " << i + 1 << endl;
        cout << "Enter Student's Name: ";
        cin.getline(student[i].studentName, MAX);
        cout << "Enter Student's Id: ";
        cin.getline(student[i].studentId, MAX);
        cout << "Enter Student's Department: ";
        cin.getline(student[i].studentDepartment, MAX);
        cout << "Enter Student's Address: ";
        cin.getline(student[i].studentAddress, MAX);
    }

    fstream file;
    file.open("student.txt", ios::binary | ios::out);
    cout << endl
         << "Writing data to the file...." << endl;
    for (int i = 0; i < numberOfStudents; i++)
    {
        file.write(reinterpret_cast<char *>(&student[i]), sizeof(student[i]));
    }
    file.close();
    delete[] student;

    Student *studentOutput = new Student[numberOfStudents];
    file.open("student.txt", ios::binary | ios::in);
    for (int i = 0; i < numberOfStudents; i++)
    {
        file.read(reinterpret_cast<char *>(&studentOutput[i]), sizeof(studentOutput[i]));
    }
    cout << endl
         << "Displaying the data read from file...." << endl;
    for (int i = 0; i < numberOfStudents; i++)
    {
        cout << "Student " << i + 1 << endl;
        cout << setw(14) << left << "Name : " << studentOutput[i].studentName << endl
             << setw(14) << left << "Id : " << studentOutput[i].studentId << endl
             << setw(14) << left << "Department : " << studentOutput[i].studentDepartment << endl
             << setw(14) << left << "Address : " << studentOutput[i].studentAddress << endl;
    }
    file.close();
    delete[] studentOutput;
    return 0;
}