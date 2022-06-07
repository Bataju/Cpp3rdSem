//Lab - 1 Qn - 1

/*A program to find the average expenditure of a company for each month of each year, 
each year and average over the range of years specified. Use arrays to construct a table, 
display the table of expenditure and find the sum and average.*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
    char headings[][8] = {"Years", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec", "Sum", "Average"};
    float **expenditure;
    float *sum, *average;
    int startYear, numberOfYears;

    printf("Enter the start year(eg: 2012): ");
    scanf("%d", &startYear);
    printf("Enter the number of years: ");
    scanf("%d", &numberOfYears);

    expenditure = (float**)malloc(numberOfYears * sizeof(float*));
    for(int i=0;i<numberOfYears;i++)
    {
        expenditure[i] = (float*)malloc(12 * sizeof(float));
    }
    sum = (float*)malloc(numberOfYears * sizeof(float));
    average = (float*)malloc(numberOfYears * sizeof(float));

    // taking data from the user
    for (int i = 0; i < numberOfYears; i++)
    {
        printf("Enter the data for the year %d\n", startYear + i);
        sum[i] = 0;
        for (int j = 0; j < 12; j++)
        {
            printf("Expenditure for the month %s:", headings[j + 1]);
            scanf("%f", &expenditure[i][j]);
            sum[i] += expenditure[i][j];
        }
        average[i] = sum[i] / 12;
    }

    // displaying data
    printf("Expenditure table\n");
    for (int i = 0; i < 15; i++)
    {
        printf("%-10s", headings[i]);
    }
    for (int i = 0; i < numberOfYears; i++)
    {
        printf("\n%-10d", startYear + i);
        for (int j = 0; j < 12; j++)
        {
            printf("%-10.2f", expenditure[i][j]);
        }
        printf("%-10.2f%-10.2f", sum[i], average[i]);
    }

    free(expenditure);
    free(sum);
    free(average);
    return 0;
}