//PROGRAMMING EXERCISES 9
//JOHN LESTER L. JOLOC
//BSCS 1 - B
//NUMBER FREQUENCY

#include<stdio.h>
#include<math.h>

int frequency(int num, int digit);

int main()
{
    FILE *ifp;
    ifp = fopen("integers.txt", "rt");
    int num;
    int hz;

    printf("INTEGER   0s   1s   2s   3s   4s   5s   6s   7s   8s   9s\n");
    printf("---------------------------------------------------------\n");
    fscanf(ifp, "%d", &num);
    while(num != 0)
    {
        printf("%-10d", num);
        for(int i = 0; i <= 9; i++)
        {
            printf("%-5d", frequency(num, i));
        }
        printf("\n");

        fscanf(ifp, "%d", &num);
    }

    fclose(ifp);

    return 0;
}

int frequency(int num, int digit)
{
    int n = 0;
    if(num == 0)
        return n;
    else if(abs(num%10) == digit)
        n++;
    return n + frequency(num/10, digit);
}