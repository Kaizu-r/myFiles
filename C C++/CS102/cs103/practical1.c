#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

int linear(int array[], int size, int key);
int binary(int array[], int size, int key);

void selection(int array[], int size);
void insertion(int array[], int size);
void bubble(int array[], int size);
void mergesort(int array[], int i, int j);
void merge(int array[], int i, int j, int i1, int j1);

void add(int A[][MAX], int B[][MAX], int C[MAX][MAX], int r, int c);
void multiply(int A[][MAX], int r, int x, int B[][MAX], int c, int C[MAX][MAX]);

void toPlural(char string[], int x);

int main()
{

    int array[MAX];
    int A[MAX][MAX];
    int B[MAX][MAX];
    int C[MAX][MAX];

    char string[MAX];

    int n, key, k, pos, r, c, x;
    char mode, mode1;

    printf("Welcome! Pick a mode!(Ctrl-Z to end)\n\tA. Search\n\tB. Sort\n\tC. Matrix\n\tD. String\n");
    while(scanf("%c", &mode) != EOF)
    {
        switch(mode)
        {
            case 'A': 
                printf("Enter the array size: \n");
                scanf(" %d", &n);
                printf("Enter array: \n");
                for(int i = 0; i < n; i++)
                    scanf("%d", &array[i]);
                printf("Enter the key: ");
                scanf(" %d", &key);
                printf("Enter search type: \n\ta. Linear\n\tb. Binary\n");
                scanf(" %c", &mode1);
                switch(mode1)
                {
                    case 'a':
                        pos = linear(array, n, key);
                        if(pos > -1)
                            printf("The key %d is at position %d.\n", key, pos + 1);
                        else
                            printf("Key was not found :( \n");
                        break;
                    case 'b':
                        printf("Binary search requires to a sorted array. Let us sort it. \n");
                        mergesort(array, 0, n-1);
                        pos = binary(array, n-1, key);
                        if(pos > -1)
                            printf("The key %d is at position %d.\n", key, pos + 1);
                        else
                            printf("Key was not found :( \n");
                        break;
                }
                break;
            case 'B':
                printf("Enter the array size: \n");
                scanf(" %d", &n);
                printf("Enter array: \n");
                for(int i = 0; i < n; i++)
                    scanf("%d", &array[i]);
                printf("Enter sort type: \n\ta. Selection\n\tb. Insertion\n\tc. Bubble\n\td. Merge\n");
                scanf(" %c", &mode1);
                switch(mode1)
                {
                    case 'a': 
                        selection(array, n);
                        break;
                    case 'b':
                        insertion(array, n);
                        break;
                    case 'c':
                        bubble(array, n);
                        break;
                    case 'd':
                        mergesort(array, 0, n-1);
                        break;
                }
                break;
            case 'C':
                printf("Enter operation: \n\ta. Addition\n\tb. Multiplication");
                scanf(" %c", &mode1);
                switch(mode1)
                {
                    case 'a':
                        printf("Enter array dimensions: ");
                        scanf("%d %d", &r, &c);
                        printf("Enter array A elements\n");
                        for(int i = 0; i < r; i++)
                        {
                            for(int j = 0; j < c; j++)
                                scanf(" %d", &A[i][j]);
                        }
                        printf("Enter array B elements\n");
                        for(int i = 0; i < r; i++)
                        {
                            for(int j = 0; j < c; j++)
                                scanf(" %d", &B[i][j]);
                        }
                        add(A, B, C, r, c);
                        printf("The sum of the two array is: \n");
                        for(int i = 0; i < r; i++)
                        {
                            for(int j = 0; j < c; j++)
                                printf("%d ", C[i][j]);
                            printf("\n");
                        }
                        break;
                    case 'b': 
                        printf("REMEMBER!!! Column of array A must be the same as row of array B!\n");
                        printf("Enter array A dimensions: ");
                        scanf("%d %d", &r, &x);
                        printf("Enter array B dimensions: ");
                        scanf("%d %d", &x, &c);
                        printf("Enter array A elements\n");
                        for(int i = 0; i < r; i++)
                        {
                            for(int j = 0; j < x; j++)
                                scanf(" %d", &A[i][j]);
                        }
                        printf("Enter array B elements\n");
                        for(int i = 0; i < x; i++)
                        {
                            for(int j = 0; j < c; j++)
                                scanf(" %d", &B[i][j]);
                        }
                        multiply(A, r, x, B, c, C);
                        printf("The product of the two array is: \n");
                        for(int i = 0; i < r; i++)
                        {
                            for(int j = 0; j < c; j++)
                                printf("%d ", B[i][j]);
                            printf("\n");
                        }
                        break;
                }
                break;
            case 'D': 
                printf("Enter the singular word: ");
                scanf(" %s", string);
                for(int i = 0; i < strlen(string); i++)
                    string[i] = tolower(string[i]);
                toPlural(string, strlen(string));
                printf("The plural of the word is %s.\n", string);
                break;
        }
    }

    return 0;
}

int linear(int array[], int size, int key)
{
    for(int i = 0; i < size; i++)
    {
        if(key == array[i])
            return i;
    }
    return -1;
}
int binary(int array[], int size, int key)
{
    int start = 0;
    int mid;
    int end = size-1;

    while(start<=end)
    {
        mid = (start+end)/2;
        if(key < array[mid])
        {
            end = mid-1;
        }
        else if(key > array[mid])
        {
            start = mid+1;
        }
        else
            return mid;
    }
    return -1;
}

void selection(int array[], int size)
{
    int temp;
    int pos = 0;
    printf("Array recieved: \n");
    for(int k = 0; k<size; k++)
    {
        printf("%d ", array[k]);
    }
    printf("\n");
    for(int i = 0; i < size-1; i++)
    {
        pos = i;
        for(int j = i + 1; j < size; j++)
        {
            if(array[j] < array[pos])
                pos = j;
        }
        temp = array[i];
        array[i] = array[pos];
        array[pos] = temp;
        printf("Sorting\n");
        for(int k = 0; k<size; k++)
        {
            printf("%d ", array[k]);
        }
        printf("\n");
    }
}
void insertion(int array[], int size)
{
    int temp = 0;
    printf("Array recieved: \n");
    for(int k = 0; k<size; k++)
    {
        printf("%d ", array[k]);
    }
    printf("\n");
    for(int i = 1; i < size; i++)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            if(array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        printf("Sorting\n");
        for(int k = 0; k<size; k++)
        {
            printf("%d ", array[k]);
        }
        printf("\n");
    }
}
void bubble(int array[], int size)
{
    int temp = 0;
     printf("Array recieved: \n");
    for(int k = 0; k<size; k++)
    {
        printf("%d ", array[k]);
    }
    printf("\n");
    for(int i = 0; i < size-1; i++)
    {
        for(int j = 0; j < size-1; j++)
        {
            if(array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        printf("Sorting\n");
        for(int k = 0; k<size; k++)
        {
            printf("%d ", array[k]);
        }
        printf("\n");
    }
}
void mergesort(int array[], int i, int j)
{
    if(i<j)
    {
        int mid = (i+j)/2;
        printf("Dividing\n");
        for(int k = 0; k<=j; k++)
        {
            printf("%d ", array[k]);
        }
        printf("\n");
        mergesort(array, i, mid);
        mergesort(array, mid+1, j);
        merge(array, i, mid, mid+1, j);
        printf("Merge elements %d to %d, and %d to %d\n", i, mid, mid+1, j);
        for(int k = 0; k<=j; k++)
        {
            printf("%d ", array[k]);
        }
        printf("\n");
    }
}
void merge(int array[], int i, int j, int i1, int j1)
{
    int temp[j1 + 1];
    int k = 0;
    int start1 = i;
    int start2 = i1;
    int end1 = j;
    int end2 = j1;
    while(start1 <= j && start2 <= j1)
    {
        if(array[start1] < array[start2])
        {
            temp[k++] = array[start1++];
        }
        else
        {
            temp[k++] = array[start2++];
        }
    }

    while(start1<=j)
        temp[k++] = array[start1++];
    while(start2<=j1)
        temp[k++] = array[start2++];

    for(int j = i, k = 0; j <= j1; j++, k++)
    {
        array[j] = temp[k];
    }
}

void add(int A[][MAX], int B[][MAX], int C[MAX][MAX], int r, int c)
{
    for(int i = 0; i<r; i++)
    {
        for(int j = 0;j < c; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void multiply(int A[][MAX], int r, int x, int B[][MAX], int c, int C[MAX][MAX])
{
    int sum = 0;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            for(int k = 0; k<x; k++)
            {
                sum += A[i][k]*B[k][j];
            }
            C[i][j] = sum;
            sum = 0;
        }
    }
}

void toPlural(char string[], int x)
{
    if(string[x-1] == 'y')
    {
        if(string[x-2] == 'a' || string[x-2] == 'e' || string[x-2] == 'i' || string[x-2] == 'o' || string[x-2] == 'u')
        {
            strcat(string, "s");
        }
        else
        {
            string[x-1] = 'i';
            strcat(string, "es");
        }
    }
    else if(string[x-1] == 's' || (string[x-1] == 'h' && ((string[x-2] == 's' || string[x-2] == 'c'))) || string[x-1] == 'x' || string[x-1] == 'z' )
        strcat(string, "es");
    else if(string[x-1] == 'o' && !(string[x-2] == 'a' || string[x-2] == 'e' || string[x-2] == 'i' || string[x-2] == 'o' || string[x-2] == 'u'))
        strcat(string, "es");
    else if(string[x-1] == 's' && string[x-2] == 'u')
    {
        string[x-1] = '\0';
        string[x-2] = 'i';
    }
    else
        strcat(string, "s");
    
}