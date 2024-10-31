#include<stdio.h>

int main()
{
    int n = 10;
    int m[n];
    float a = 1;
    m[(int)a] = 2;
    printf("%d", m[(int)a]);

    return 0;
}