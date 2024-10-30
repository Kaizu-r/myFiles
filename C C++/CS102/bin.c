#include<stdio.h>
#include<string.h>

int main()
{
    int i = 0;
    char *string[] = {NULL};
    while(scanf("%s", (string + i)) != EOF)
        i++;
    for(int j = 0; j < i; j++)
    {
        printf("%s %p %d", string[j], string[j], strlen(string[j]));
    }

    return 0;
}