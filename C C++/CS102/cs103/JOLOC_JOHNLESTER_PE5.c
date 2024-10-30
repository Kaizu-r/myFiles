//PROGRAMMING EXERCISES 5
//JOHN LESTER L. JOLOC
//BSCS 1 - B

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void sort(char *array[], int n);
void lower(char *array);
int main(int argc, char *argv[])
{
    FILE *inp = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");

    char nstring[10][1000];
    int n;
    fscanf(inp, "%d", &n);
    char *string[1000] = {NULL};
    for(int i = 0; i < n; i++)
    {
        *(string + i) = &(nstring[i]);
        fscanf(inp, "%s", (nstring + i));
        lower(*(string + i));
    }
    sort(string, n);
    printf("STRING\t\tMEMORY ADDRESS\t\tLENGTH\n");
    printf("---------------------------------------------------------\n");
    fprintf(out, "STRING\t\tMEMORY ADDRESS\t\tLENGTH\n");
    fprintf(out, "---------------------------------------------------------\n");
    for(int i = 0; i < n; i++)
    {
        printf("%-10s\t%p\t%d\n", *(string + i), *(string + i), strlen(*(string + i)));
        fprintf(out, "%-10s\t%p\t%d\n", *(string + i), *(string + i), strlen(*(string + i)));
    }

    fclose(inp);
    fclose(out);

    return 0;
}

void sort(char *array[100], int n)
{
    char *temp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            if(strlen(*(array + (j + 1))) < strlen(*(array + j)))
            {
                temp = *(array + (j + 1));
                *(array + (j + 1)) = *(array + j);
                *(array + j) = temp;
            }
            else if(strlen(*(array + (j + 1))) == strlen(*(array + j)))
            {
                if(strcmp(array + (j + 1), array + j) < 0)
                {
                    temp = *(array + (j + 1));
                    *(array + (j + 1)) = *(array + j);
                    *(array + j) = temp;
                }
            }
        }
    }
}



void lower(char *array)
{
    for(int i = 0; i < strlen(array); i++)
    {
        *(array + i) = tolower(*(array + i));
    }
}