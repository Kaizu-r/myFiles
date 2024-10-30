#include<stdio.h>
#include<math.h>

float factorial(int num);
int binary(int num);
int scientific(float num);

int main()
{
    float num1,num2, result;
    int num3;
    int dec, power;
    char operation;
    char mode;

    printf("Welcome to Calculator!\nPick a mode:\n A. Standard \t B. Scientific \n C. Factorial \t D. Binary\n");
    scanf(" %c", &mode);

    switch(mode)
    {
        case 'A':
        case 'B':
            printf("Enter two numbers: ");
            scanf(" %f %f", &num1, &num2);
            do
            {   printf("Select operation(+,-,*,/): ");
                scanf(" %c", &operation);
                switch(operation)
                {
                    case '+':
                        result = num1 + num2;
                        break;
                    case '-':
                        result = num1 - num2;
                        break;
                    case '*':
                        result = num1 * num2;
                        break;
                    case '/':
                        result = num1 / num2;
                        break;
                    default:
                        printf("Operation not recognized");
                        operation = 0;
                      
                }
            }while(operation == 0);
            if(mode == 'A')
                printf("%.8f\n", result);
            else
                {
                    power = scientific(result);
                    for(int i = 0; i < power; i++)
                    {
                        result = result/10;
                    }
                    printf("%fe%d\n", result, power);
                }
            break;
        case 'C':
            do
            {
                printf("Enter a positive number: ");
                scanf(" %d", &num3);
                if(num3 < 0)
                    printf("Not a positive number.\n");
                else
                    printf(" %d/n", factorial(num3));
            }while(num3 < 0);
            break;
        case 'D': 
            do
            {
                printf("Enter a decimal integer\n");
                scanf(" %d", &dec);
                if(dec < 0)
                    printf("Enter a positive integer!\n");
                else
                    printf("%d/n", binary(dec));
            }while(dec < 0);
    }

    return 0;
}

float factorial(int num)
{
    if(num < 2)
        return 1;
    else
        return num * factorial(num - 1);
}
int binary(int num)
{
    int bin = 0;
    int counter, temp;
    while(num != 0)
    {
        temp = num%2;
        for(int i = 0; i < counter; i++)
            temp = temp * 10;
        bin += temp;
        num = num/2;
        counter++;
    }

    return bin;
}
int scientific(float num)
{
    if(num/10 < 1)
        return 0;
    else
        return 1 + scientific(num/10);
}