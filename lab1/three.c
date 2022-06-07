//Lab - 1 Qn - 3

/*A program to store and retrieve the name of the students and obtained marks in c programming 
in 1st semester using structure.*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct Student
{
    char name[20];
    float marksInC;
}Student;

int main()
{
    Student *studentArray;
    int noOfStudents;
    printf("Enter the number of students: ");
    scanf("%d", &noOfStudents);
    studentArray = (Student *)malloc(noOfStudents * sizeof(Student));
    printf("\nEnter the students' details\n");
    for(int i=0; i<noOfStudents ; i++)
    {
        printf("%d. Enter the student's name: ", i+1);
        scanf("%s", studentArray[i].name);
        printf("   Enter the student's marks in C programming: ");
        scanf("%f", &studentArray[i].marksInC);
    }
    printf("STUDENT DATA\n");
    printf("%-15s%-15s\n", "Name","Marks");

    for(int i=0; i<noOfStudents; i++)
    {
        printf("%-15s%-15f\n", studentArray[i].name, studentArray[i].marksInC);
    }
    return 0;
}