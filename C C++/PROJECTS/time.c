#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    struct tm *ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    printf("%s", asctime(ptr));


    return 0;
}