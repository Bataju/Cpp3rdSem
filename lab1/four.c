//Lab - 1   Qn - 4

/*A program to read name, rollno, address, and phone number of each student in your class using structure. 
Store the information in file so that you can recover the information later. 
While recovering the information from the file sort the information alphabetically according to the name.*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct Student
{
    char name[20];
    char roll[10];
    char address[20];
    char phoneNumber[20];
};

int main()
{
    int numberOfStudents;
    struct Student *studentPtr;
    FILE *filePtr;
    printf("Enter the number of students: ");
    scanf("%d", &numberOfStudents);
    studentPtr = (struct Student *)malloc(numberOfStudents * sizeof(struct Student));

    // taking input from the user
    printf("Enter student data\n");
    filePtr = fopen("studentdata.txt", "wb");
    for (int i = 0; i < numberOfStudents; i++)
    {
        printf("Student %d\n", i + 1);
        printf("Name: ");
        scanf("%s", (studentPtr + i)->name);
        printf("Roll number: ");
        scanf("%s", (studentPtr + i)->roll);
        printf("Address: ");
        scanf("%s", (studentPtr + i)->address);
        printf("Phone number: ");
        scanf("%s", (studentPtr + i)->phoneNumber);
    }

    for (int i = 0; i < numberOfStudents; i++)
    {
        fwrite(studentPtr + i, sizeof(struct Student), 1, filePtr);
    }
    fclose(filePtr);
    free(studentPtr);

    // dislaying the data to the console
    filePtr = fopen("studentdata.txt", "rb");
    studentPtr = (struct Student *)malloc(numberOfStudents * sizeof(struct Student));
    printf("STUDENT DATA\n");
    printf("%-15s%-15s%-15s%-15s\n", "Name", "Roll number", "Address", "Phone number");

    for (int i = 0; i < numberOfStudents; i++)
    {
        fread(studentPtr + i, sizeof(struct Student), 1, filePtr);
    }

    for (int i = 0; i < numberOfStudents; i++)
    {
        for (int j = i; j < numberOfStudents; j++)
        {
            if (strcmp((studentPtr + i)->name, (studentPtr + j)->name) > 0)
            {
                struct Student temp;
                temp = *(studentPtr + i);
                *(studentPtr + i) = *(studentPtr + j);
                *(studentPtr + j) = temp;
            }
        }
    }
    
    for (int i = 0; i < numberOfStudents; i++)
    {
        printf("%-15s%-15s%-15s%-15s\n", (studentPtr + i)->name, (studentPtr + i)->roll, (studentPtr + i)->address, (studentPtr + i)->phoneNumber);
    }
    return 0;
}