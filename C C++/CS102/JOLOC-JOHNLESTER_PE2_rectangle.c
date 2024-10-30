#include<stdio.h>

int main()
{
    // Initialize all the variables
    
    int L, W;
    float P,A;
    
    // Getting the values for length and width
   
    printf("Enter the Length: \n");
    scanf("%d", &L);
    printf("Enter the width: \n");
    scanf("%d", &W);
    
    // Check for validity of input data
    
    if (L <= 0 || W <= 0)
    {
        printf("Invalid values of sides");
    }
    else
    {
       
        // Calculation of outputs if input is valid
       
        P = (2*L) + (2*W);
        A = L * W;
        
        // Printing of outputs
        
        printf("The perimeter is %f and the area is %f", P, A);

    }

    return 0;
}