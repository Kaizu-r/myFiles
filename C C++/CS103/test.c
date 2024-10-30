#include<stdio.h>


void merge(int array[], int i, int j);
void mergesort(int array[], int i1, int j1, int i2, int j2);
void bubble(int array[], int j);
void insertion(int array[], int j);


int main()
{
    int size;
    int array[100]; 
    printf("enter number of elements: ");
    scanf(" %d", &size);
    printf("Enter elements: ");
    for(int i = 0; i < size; i++)
    {
        scanf(" %d", &array[i]);
    }
    insertion(array, size - 1);
    //bubble(array, size-1);
    //merge(array, 0, size - 1);

    return 0;
}

void merge(int array[], int i, int j)
{
    if(i<j)
    {
        int mid = (i+j)/2;
        for(int a = 0; a <= j; a++)
        {
            printf("%d", array[a]);
        }
        printf("\n");
        merge(array, i, mid);
        merge(array, mid+1, j);
        mergesort(array, i,mid, mid+1, j);
        for(int a = 0; a <= j; a++)
        {
            printf("%d", array[a]);
        }
        printf("\n");
    }

}
void mergesort(int array[], int i1, int j1, int i2, int j2)
{

    int temp[100];
    int start1 = i1;
    int start2 = i2;
    int k = 0;


    while(start1 <= j1 && start2 <= j2)
    {
        if(array[start1] < array[start2])
            temp[k++] = array[start1++];
        else
            temp[k++] = array[start2++];
    }

    while(start1 <= j1)
    {
        temp[k++] = array[start1++];
    }
    while(start2 <= j2)
    {
        temp[k++] = array[start2++];
    }
    for(int i = i1, j = 0; i <= j2; i++, j++)
        array[i] = temp[j];
}

void bubble(int array[], int j)
{
    int temp;
    for(int i = 0; i<=j; i++)
    {
        for(int k = 0; k<=j - 1; k++)
        {
            if(array[k] > array[k+1])
            {
                temp = array[k];
                array[k] = array[k+1];
                array[k+1] = temp;
            }
        }
        for(int a = 0; a <= j; a++)
        {
            printf("%d", array[a]);
        }
        printf("\n");
    }
}

void insertion(int array[], int j)
{
    int temp;

    for(int i = 1; i<=j; i++)
    {
        for(int k = i - 1; k >= 0; k--)
        {
            if(array[k] > array[k+1])
            {
                temp = array[k];
                array[k] = array[k+1];
                array[k+1] = temp;
            }
        }
        for(int a = 0; a <= j; a++)
        {
            printf("%d", array[a]);
        }
        printf("\n");
    }
}