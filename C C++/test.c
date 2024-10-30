#include<stdio.h>

int main()
{
    int number[100];
    int size = sizeof(number)/sizeof(number[0]);
    for(int i = 0; i < size - 1; i++)
    {
        printf("Enter Number: \n");
        scanf(" %d", number[i]);
    }
    for(int i = 0; i < size - 1; i++)
    {
        printf("%d\n", number[i]);

    }

    return 0;
}