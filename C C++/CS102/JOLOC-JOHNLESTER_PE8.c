//PROGRAMMING EXERCISES 8
//JOHN LESTER L. JOLOC
//BSCS 1 - B
//PRIME AND PERFECT CHECKER 

#include<stdio.h>

int isPrime(int num);
int isPerfect(int num);

int main()
{
    int num;

    printf("Enter a positive integer (Ctrl-Z to end): ");
    while((scanf("%d", &num) != EOF))
    {
        if(isPrime(num) == 1)
            printf(" prime: YES\n");
        else
            printf(" prime: NO\n");
        
        if(isPerfect(num) == 1)
            printf(" perfect: YES\n");
        else
            printf(" perfect: NO\n");

        printf("Enter a positive integer (Ctrl-Z to end): ");

    }
    printf(" End of program. Thanks!");
    return 0;
}

int isPrime(int num)
{
    int i = 2;
    do
    {
        if(num%i == 0)
            return 0;
        i++;
    } while (i < num);
    
    return 1;
}
int isPerfect(int num)
{
    int sum = 0;
    //checks if num is divisible by i, adds it if it is
    for(int i = 1; i < num; i++)
    {
        if((num%i) == 0)
            sum += i;
    }
    if(sum == num)
        return 1;
    else
        return 0;
}
