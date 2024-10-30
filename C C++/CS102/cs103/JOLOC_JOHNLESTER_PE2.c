//PROGRAMMING EXERCISES 2
//JOHN LESTER L. JOLOC
//BSCS 1 - B
//SORTING ALGORITHMS

#include<stdio.h>


void selection(FILE *ofp, int array[], int size);
void insertion(FILE *ofp, int array[], int size);
void bubble(FILE *ofp, int array[], int size);

void mergesort(FILE *ofp, int array[], int start, int end);
void merge(int array[], int start1, int end1, int start2, int end2);

int main()
{
    int array[100];
    int size, choice, flag;
    FILE *ofp;
    ofp = fopen("output.dat", "w");

    do
    {
        printf("Enter the size of array: ");
        fprintf(ofp, "Enter the size of array: ");
        scanf(" %d", &size);
        fprintf(ofp, "%d\n", size);
        //error catch
        if(size > 100)
        {
            printf("Invalid (Size < 100)\n");
            fprintf(ofp, "Invalid (Size < 100)\n");
        }
    } while (size > 100);
    printf("Enter the array elements: ");
    fprintf(ofp, "Enter the array elements: ");
    for(int i = 0; i < size; i++)
    {
       scanf(" %d", &array[i]);
       fprintf(ofp, " %d", array[i]);
    }
    fprintf(ofp, "\n");
   
    printf("Which sorting algorithm do you want to use?\n");
    printf("\t1. SELECTION SORT\n\t2. INSERTION SORT\n\t3. BUBBLE SORT\n\t4. MERGE SORT\n");
    printf("\tType number of choice: ");
    scanf(" %d", &choice);
    fprintf(ofp, "Which sorting algorithm do you want to use?\n");
    fprintf(ofp, "\t1. SELECTION SORT\n\t2. INSERTION SORT\n\t3. BUBBLE SORT\n\t4. MERGE SORT\n");
    fprintf(ofp, "\tType number of choice: %d\n", choice);

    switch(choice)
    {
        case 1:
            selection(ofp, array, size);
            break;
        case 2:
            insertion(ofp, array, size);
            break;
        case 3:
            bubble(ofp, array, size);
            break;
        case 4:
            mergesort(ofp, array, 0, size-1);
            printf("Sorted Array: ");
            fprintf(ofp, "Sorted Array: ");
            for(int i = 0; i < size; i++)
            {
                printf("%d ", array[i]);
                fprintf(ofp, "%d ", array[i]);
            }
            break;
        default:
            printf("Invalid Input\n");
            break;
    }

    fclose(ofp);

    return 0;
}

void selection(FILE *ofp, int array[], int size)
{
    int temp;
    for(int i = 0; i < size - 1; i++)
    {
        int min = i;    
        //printing per i
        printf("Iteration %d: ", i);
        fprintf(ofp, "Iteration %d: ", i);
        for(int k = 0; k < size; k++)
        {
            printf("%d ", array[k]);
            fprintf(ofp, "%d ", array[k]);
        }
        printf("\n");
        fprintf(ofp, "\n");
        //selection
        for(int j = i + 1; j < size; j++)
        {
            if(array[min] > array[j])
            {
                min = j;
            }
        }
        if(min != i)
        {
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
        
    }

    //final printing
    printf("Sorted Array: ");
    fprintf(ofp, "Sorted Aray: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
        fprintf(ofp, "%d ", array[i]);
    }
    printf("\n");
    fprintf(ofp, "\n");

}
void insertion(FILE *ofp, int array[], int size)
{
    int temp;

    //iteration 0 printing(i = 0 is alr sorted)
    printf("Iteration 0: ");
    fprintf(ofp, "Iteration 0: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
        fprintf(ofp, "%d ", array[i]);
    }
    printf("\n");
    fprintf(ofp, "\n");

    //sorting + insertion
    for(int i = 1; i < size; i++)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            if(array[j + 1] < array[j])
            {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
        //printing per iteration
        printf("Iteration %d: ", i);
        fprintf(ofp, "Iteration %d: ", i);
        for(int k = 0; k < size; k++)
        {
            printf("%d ", array[k]);
            fprintf(ofp, "%d ", array[k]);
        }
        printf("\n");
        fprintf(ofp, "\n");
    }
    //final printing
    printf("Sorted Array: ");
    fprintf(ofp, "Sorted Array: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
        fprintf(ofp, "%d ", array[i]);
    }
    printf("\n");
    fprintf(ofp, "\n");
}
void bubble(FILE *ofp, int array[], int size)
{
    int temp;

    for(int i = 0; i < size; i++)
    {
        //printing per i
        printf("Iteration %d: ", i);
        fprintf(ofp, "Iteration %d: ", i);
        for(int k = 0; k < size; k++)
        {
            printf("%d ", array[k]);
            fprintf(ofp, "%d ", array[k]);
        }
        printf("\n");
        fprintf(ofp, "\n");
        
        //bubble sorting
        for(int j = 0; j < size - 1; j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j+1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
    //final printing
    printf("Sorted Array: ");
    fprintf(ofp, "Sorted Array: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
        fprintf(ofp, "%d ", array[i]);
    }
    printf("\n");
    fprintf(ofp, "\n");

}

void mergesort(FILE *ofp, int array[], int start, int end)
{

    if(start<end)
    {
        int mid = (start + end)/2;
        //printing during the division
        for(int i = 0; i <= end; i++)
        {
            printf("%d ", array[i]);
            fprintf(ofp, "%d ", array[i]);
        }
        printf("\n");
        fprintf(ofp, "\n");
        mergesort(ofp, array, start, mid);
        mergesort(ofp, array, mid+1, end);
        merge(array, start, mid, mid + 1, end);
        //printing during the merging 
        for(int i = 0; i <= end; i++)
        {
            printf("%d ", array[i]);
            fprintf(ofp, "%d ", array[i]);
        }
        printf("\n");
        fprintf(ofp, "\n");
    }
}
void merge(int array[], int start1, int end1, int start2, int end2)
{
    int temp[100];
    int i = start1;
    int j = start2;
    int k = 0;

    //compare each element per half and copy to temp
    while(i <= end1 && j <= end2)
    {
        if(array[i] < array[j])
        {
            temp[k++] = array[i++];
        }
        else
        {
            temp[k++] = array[j++];
        }
    }

    //copy remaining list to temp from first half to last half
    while(i <= end1)
        temp[k++] = array[i++];
    while(j <= end2)
        temp[k++] = array[j++];
    //copy temp to og array
    for(int i = start1, j = 0; i <= end2; i++, j++)
        array[i] = temp[j];
}
