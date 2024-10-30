#include <stdio.h>

int main()
{
    int x, great, least, count, items;
    printf("Enter number of items: \n");
    scanf(" %d", &items);
    printf("Enter a number: \n");
    scanf(" %d", &x);
    great = least = x;
    count = 0;
    while(count < items - 1)
    {
        printf("Enter a number: \n");
        scanf(" %d", &x);
        if(x > great)
        {
            great = x;
        }
        else if(x < least)
        {
            least = x;
        }
        count++;
    }
    printf("Greatest: %d, Least: %d", great, least);
}