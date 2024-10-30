//PROGRAMMING EXERCISE 3
//JOHN LESTER L. JOLOC
//BSCS 1-B
//MATRIX OPERATION

#include<stdio.h>

int sumdiag(int array[][10], int row);
int sumcol(int array[][10],int row, int column);
int sumrow(int array[][10], int row, int column);
int sumtotal(int array[][10], int row, int column);
void transpose(int array[][10], int row, int column);
int upper(int array[][10], int row);
int lower(int array[][10], int row);

int main()
{
    FILE* matrix;
    matrix = fopen("matrix.in", "r");

    int row, column, type, temp;
    int A[10][10];

    fscanf(matrix, "%d %d", &row, &column);

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            fscanf(matrix, "%d", &A[i][j]);
        }
    }

    //identifying(1 for square, 0 for rectangle)
    if(row == column)
        type = 1;
    else
        type = 0;

    //printing
    printf("Original Matrix: ");
    //if type = 1, bool is true for square matrix print
    if(type)
        printf("Square Matrix\n");
    else
        printf("Rectangular Matrix\n");

    printf("\t\t");
    //creating space for Sum-of-Row
    for(int i = 0; i < (column * 4) + 1; i++)
        printf(" ");
    printf("Sum-of-Row\n\t\t");
    //printing array 
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            printf("%3d ", A[i][j]);
        }
        printf("| %3d\n\t\t", sumrow(A, i, column));
    }
    printf("-------------------------\n");
    printf("Sum-of-Columns: ");
    for(int i = 0; i < column; i++)
    {
        printf("%3d ", sumcol(A, row, i));
    }
    printf("| %3d\n", sumtotal(A, row, column));

    //type = 1 is square, therefore it will execute for square
    if(type)
    {
        printf("Sum of the Main Diagonal: %3d\n", sumdiag(A, row));
        printf("Sum of the Upper Triangular Matrix: %3d\n", upper(A, row));
        printf("Sum of Lower Triangular Matrix: %3d\n", lower(A, row));
    }
    printf("\n*******************************************\n");
    
    printf("Transpose of Matrix\n");
    
    //space for Sum-of-Row, but using var row because of transpose
    for(int i = 0; i < (row * 4) + 1; i++)
        printf(" ");
    printf("Sum-of-Row\n\t\t");

    transpose(A, row, column);
    //switching row and column for easy printing(forbidden copy+paste of code for original matrix)
    temp = row;
    row = column;
    column = temp;

    //printing transpose array
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            printf("%3d ", A[i][j]);
        }
        printf("| %3d\n\t\t", sumrow(A, i, column));
    }
    printf("-------------------------\n");
    printf("Sum-of-Columns: ");
    for(int i = 0; i < column; i++)
    {
        printf("%3d ", sumcol(A, row, i));
    }
    printf("| %3d\n", sumtotal(A, row, column));

    //type = 1 is square, therefore it will execute for square
    if(type)
    {
        printf("Sum of the Main Diagonal: %3d\n", sumdiag(A, row));
        printf("Sum of the Upper Triangular Matrix: %3d\n", upper(A, row));
        printf("Sum of Lower Triangular Matrix: %3d\n", lower(A, row));
    }

    fclose(matrix);

    return 0;
}
int sumdiag(int array[][10], int row)
{
    int sum = 0;
    //since i = j, no need for second loop
    for(int i = 0; i < row; i++)
        sum += array[i][i];
    return sum;
}
int sumcol(int array[][10],int row, int column)
{
    int sum = 0;
    for(int i = 0; i < row; i++)
    {
        sum+= array[i][column];
    }

    return sum;
}
int sumrow(int array[][10], int row, int column)
{
    int sum = 0;
    for(int i = 0; i < column; i++)
    {
        sum+= array[row][i];
    }

    return sum;
}
int sumtotal(int array[][10], int row, int column)
{
    int sum = 0;
    for(int i = 0; i < row; i++)
        sum += sumrow(array, i, column);
    return sum;
}
void transpose(int array[][10], int row, int column)
{
    int temp[10][10];
    //transposing
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            temp[j][i] = array[i][j];
        }
    }
    //copying elements back to array
    for(int i = 0; i < column; i++)
    {
        for(int j = 0; j < row; j++)
        {
            array[i][j] = temp[i][j];
        }
    }
}
int lower(int array[][10], int row)
{
    int sum = 0;
    //skip row 0 since it is in diagonal
    for(int i = 1; i < row; i++)
    {
        for(int j = 0; j < i; j++)
        {
            sum += array[i][j];
        }
    }
    return sum;
}
int upper(int array[][10], int row)
{
    int sum = 0;
    for(int i = 0; i < row - 1; i++)
    {
        //skip column = i since it is part of diagonal
        for(int j = i + 1; j < row; j++)
        {
            sum+= array[i][j];
        }
    }
    return sum;
}
