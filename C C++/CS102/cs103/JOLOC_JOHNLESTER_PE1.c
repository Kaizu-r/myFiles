//PROGRAMMING EXERCISE 1
//JOHN LESTER L. JOLOC
//BSCS 1-B
//MEAN AND STANDARD DEVIATION

#include<stdio.h>
#include<math.h>

int main()
{
    FILE *ipr;
    FILE *opr;

    ipr = fopen("input.dat", "r");
    opr = fopen("output.dat", "w");

    int n;
    float arr[100];
    float mean, sd = 0, sum = 0;

    fscanf(ipr, " %d", &n);

    //storing floats into arr and adding it to sum
    for(int i = 0; i < n; i++)
    {
        fscanf(ipr, " %f", &arr[i]);
        sum += arr[i];
    }

    //looking for mean
    mean = sum/n;

    //looking for sd
    for(int i = 0; i < n; i++)
    {
        sd += pow((mean - arr[i]), 2);
    }
    sd = sqrt(sd/(n-1));

    //printing
    fprintf(opr, "The mean is %.4f.\n", mean);
    fprintf(opr, "The standard deviation is %.4f.\n", sd);
    fprintf(opr, "Table of differences between the data values and mean deviation\n");
    fprintf(opr, " Index    Data           Data-Mean\n");
    for(int i = 0; i < n; i++)
    {
        fprintf(opr, "%3d     %6.2f          %6.2f\n", i, arr[i], arr[i] - mean);
    }

    printf("The mean is %.4f.\n", mean);
    printf("The standard deviation is %.4f.\n", sd);
    printf("Table of differences between the data values and mean deviation\n");
    printf(" Index    Data           Data-Mean\n");
    for(int i = 0; i < n; i++)
    {
        printf("%3d     %6.2f          %6.2f\n", i, arr[i], arr[i] - mean);
    }


    fclose(ipr);
    fclose(opr);

    return 0;
}