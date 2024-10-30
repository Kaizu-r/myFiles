#include<stdio.h>

float add(int number[]);
float subtract(int number[]);
float multiply(int number[]);
float divide(int number[]);
void absolute(int number[]);
void square(int number[]);
float average(int number[]);
int main()
{
    char operation;
    int num;
    int x;
    int number[100];
    printf("Enter operation(+, -, *, /, A, ^, |): \n");
    scanf(" %c", &operation);
    printf("Enter number of numbers: \n");
    scanf(" %d", &num);
    for(int i = 0; i < num; i++)
    {
        printf("Enter the number: \n");
        scanf(" %d", &x);
        number[i] = x;
    }
    switch(operation)
    {
        case '+':
            float sum = add(number);
            printf("%f", sum);
            break;
        case '-':
            float diff = subtract(number);
            printf("%f", diff);
            break;
        case '*':
            float prod = multiply(number);
            printf("%f", prod);
            break;
        case '/':
            float quo = divide(number);
            printf("%f", quo);
            break;
        case 'A':
            float avg = average(number);
            printf("%f", avg);
            break;
        case '^':
            square(number);
            printf("%f", square);
            break;
        case '|':
            absolute(number);
            break;
    }

    return 0;
}

float add(int number[])
{
    int size;
    float sum = number[0];
    size = sizeof(number)/sizeof(number[0]);
    for(int i = 1; i < size + 1; i++)
    {
        sum = sum + number[i];
    }
    return sum;
}
float subtract(int number[])
{
    int size;
    float diff = number[0];
    size = sizeof(number)/sizeof(number[0]);
    for(int i = 1; i < size + 1; i++)
    {
        diff = diff - number[i];
    }
    return diff;
}
float multiply(int number[])
{
    int size;
    float prod;
    prod = number[0];
    size = sizeof(number)/sizeof(number[0]);
    for(int i = 1; i < size + 1; i++)
    {
        prod = prod * number[i];
    }
    return prod;
}
float divide(int number[])
{
    int size;
    float quo = number[0];
    size = sizeof(number)/sizeof(number[0]);
    for(int i = 1; i < size + 1; i++)
    {
        quo = quo/number[i];
    }
    return quo;
}
void absolute(int number[])
{
    float size;
    size = sizeof(number)/sizeof(number[0]);
    for(int i = 0; i < size - 1; i++)
    {
        if(number[i] < 0)
        {
            number[i] = number[i] * -1;
        }
        printf("%f", number[i]);
    }
}
void square(int number[])
{
    float size, power;
    printf("Enter power: \n");
    scanf(" %d", &power);
    size = sizeof(number)/sizeof(number[0]);
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 1; j < power; j++)
        {
            number[i] = number[i] * number[i];
        }
        printf("%f", number[i]);
    }
}
float average(int number[])
{
    int size;
    size = sizeof(number)/sizeof(number[0]);
    float sum = add(number);
    float avg = sum/(size + 1.0);
    return avg;
}