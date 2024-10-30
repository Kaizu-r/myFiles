#include "cs50.h"
#include <stdio.h>

int main(void){
// Ask user for first number
    
     float n1 = get_float("First Number?\n");
    
// Ask user for second number
    
    float n2 = get_float("Second Number?\n");

    
// Ask user for operator
    
    char operator = get_char("What operation?\n");
    
// Bool for operation
 
    if(operator == '+')
    {
        float r = n1 + n2;
        printf("%.2f", r);
      
    }

    else if(operator == '-')
    {
        float r = n1 - n2;
        printf("%.2f",r);
        
    }
    else if(operator == '*')
    {
        float r = n1 * n2;
        printf("%.2f",r);
    }
    else if(operator == '/')
    {
        float r = n1 / n2;
        printf("%.2f",r);

    }
    else
    {
        printf("Invalid Input");
    }
    return 0;
}