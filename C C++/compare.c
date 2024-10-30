#include<stdio.h>

int main()
{
    int n, i, x, y, greatest_number, least_number;
    i =0;
    printf("Enter Number of Elements: ");
    scanf("%d", &n);
    if(n > 0)
    {
        printf("Enter Number: ");
        scanf("%d", &y);
        greatest_number = y;
        least_number = y;
        while(i < n - 1)
        {
            printf("Enter Number: ");
            scanf("%d", &x);
            if(x > greatest_number)
            {
                greatest_number = x;
            }
            else if(x < least_number)
            {
                least_number = x;
            }
            i++;
        }
        printf("The greatest number is %d, and the least number is %d", greatest_number, least_number);
    }
    else
    {
        printf("Invalid Input");
    }

}