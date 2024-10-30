#include<stdio.h>

int main()
{
    // Initialize all variables
    
    int r;
    float P, A, pi;
    
    // Set value of pi
    
    pi = 3.14159;
    
    // Get value for radiues
   
    printf("Enter radius: \n");
    scanf("%d", &r);
    
    // Check for validity of radius value
    
    if (r <= 0)
    {
        printf("Invalid value for radius");
    }
    else
    {
       
        // Calculations if input is correct
        
        P = 2 * pi * r;
        A = pi * r * r;
        printf("The perimeter is %f and the area is %f", P, A);
    }

    return 0;
}