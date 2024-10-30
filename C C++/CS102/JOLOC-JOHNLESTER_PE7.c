//PROGRAMMING EXERCISES 7
//JOHN LESTER L. JOLOC
//BSCS 1 - B
//CENTAVOS SALARY LOOP

#include<stdio.h>

int main()
{
    int cent, hr;
    float pay, total;
    total = 0;
    FILE *opf;
    opf = fopen("payment.txt", "w");

    fprintf(opf, "Computation of your payment for this week\n");
    fprintf(opf, "------------------------------------\n");
    fprintf(opf, "|Rate(cts/hr)| # Hours | Pay(Pesos) |\n");
    fprintf(opf, "------------------------------------\n");

    while(1)
    {
        printf("Please input a pair of integers(ctrl-D to end): ");
        if(scanf("%d %d", &cent, &hr) == EOF)
            break;
        if(hr <= 40)
            pay = (cent * hr)/100;
        else if(hr <= 60)
            pay = ((cent * 40) + (cent * 1.5 * (hr - 40)))/100.0;
        else
            pay = ((cent *40) + (cent * 1.5 * 20) + (cent * 2 * (hr - 60)))/100.0;
        printf("Pay at %d centavos/hr for %d hours is %.2f pesos\n\n", cent, hr, pay);
        fprintf(opf, "|%11d |%8d |%11.2f |\n", cent, hr, pay);
        
        total += pay;

    }

    printf("TOTAL PAY: %.2f pesos", total);
    fprintf(opf, "\nTotal Pay: PhP %.2f\n", total);

    fclose(opf);


    return 0;
}