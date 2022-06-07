//Lab - 1 Qn - 2

/*A program to find the position of the character 'C' in the sentence "idea without execution is worthless" 
using pointer and string.*/

#include<stdio.h>
#include<conio.h>

int main()
{
    char *string = "idea without execution is worthless";
    int i=0;
    printf("%s\n", string);
    while(*(string+i)!='\0')
    {
        if(*(string+i) == 'c')
        {
            printf("I found the character 'c' at index %d", i);
        }
        i++;
    }
    return 0;
}