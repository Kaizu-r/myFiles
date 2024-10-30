#include<stdio.h>
#include<math.h>

int main()
{
    // Initialize all variables
    
    int a, b, c;
    float s, P, A;
    
    // Getting values for the sides
    
    printf("Enter the length of sides: \n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    
    // Checking of validity of inputs
    
    if (a <= 0 || b <= 0 || c <= 0 )
    {
        printf("Invalid values for sides");
    }
    
    // Checking if sides satisfies Triangle Inequality Theorem
   
    else if (a <= b + c && b <= a + c && c <= a + b)
    {
        
        // Calculation of outputs if input is valid
       
        P = a + b + c;
        
        // Compute s first before A
        
        s = (a + b + c) / 2.0;
        A = sqrt(s * (s - a) * (s - b) * (s - c));
        printf("The perimeter is %f and the area is %f", P, A);
    }
    
    // If triangle inequality theorem is not satisfied
    
    else
    {
        printf("Triangle does not exist");
    }
    
    return 0;
}