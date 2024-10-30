//PROGRAMMING EXERCISE 6
//JOHN LESTER L. JOLOC
//BSCS 1 - B

#include<stdio.h>
#include<string.h>

typedef struct
{
    char name[100];
    int id, age;
    char gender;
}record;

void sort(record student[20], int n);
int main(int argc, char *argv[])
{
    FILE *inp = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");

    record student[100];
    int n;

    fscanf(inp, "%d", &n);
    for(int i = 0; i < n; i++)
    {
        fscanf(inp, "%s %d %d %c", student[i].name, &student[i].id, &student[i].age, &student[i].gender);
    }

    sort(student, n);
    printf("%-8s\tID#\tAGE\n", "NAME");
    fprintf(out, "%-8s\tID#\tAGE\n", "NAME");
    printf("-----------------------------------------\n");
    fprintf(out, "-----------------------------------------\n");
    printf("MALE:\n");
    fprintf(out, "MALE:\n");
    for(int i = 0; i < n; i++)
    {
        if(student[i].gender == 'M')
        {
            printf("%-8s\t%02d\t%d\n", student[i].name, student[i].id, student[i].age);
            fprintf(out, "%-8s\t%02d\t%d\n", student[i].name, student[i].id, student[i].age);
        }
    }
    printf("\nFEMALE:\n");
    for(int i = 0; i < n; i++)
    {
        if(student[i].gender == 'F')
        {
            printf("%-8s\t%02d\t%d\n", student[i].name, student[i].id, student[i].age);
            fprintf(out, "%-8s\t%02d\t%d\n", student[i].name, student[i].id, student[i].age);
        }
    }

    fclose(inp);
    fclose(out);
    return 0;
}

void sort(record student[20], int n)
{
    record temp;
    int pos = 0;
    for(int i = 0; i < n - 1; i++)
    {
        pos = i;
        for(int j = i + 1; j < n; j++)
        {
            if(strcmp(student[j].name, student[pos].name) < 0)
                pos = j;
        }
        if(pos != i)
        {
            temp = student[pos];
            student[pos] = student[i];
            student[i] = temp;
        }
    }
}