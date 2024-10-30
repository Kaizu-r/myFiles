//PROGRAMMING EXERCISES 3
//JOHN LESTER L. JOLOC
//BSCS 1 - B
//INPUT AND OUTPUT FORMATTING

#include<stdio.h>

int main()
{
	//Variable declararion
	char name[100];
	int s1, s2, s3, s4, s5, t1,t2,t3,t4,t5;
	float r1,r2,r3,r4,r5,avg;
	//Getting necedsary inputs
	printf("Input name of student: ");
	scanf("%s", name);
	printf("\nPlease input five pairs of integer values representing the total number of points and score of %s\'s quizzes.\n", name);
	printf("Input Quiz 1 : ");
	scanf("%d %d", &t1, &s1);
	printf("Input Quiz 2 : ");
	scanf("%d %d", &t2, &s2);
	printf("Input Quiz 3 : ");
	scanf("%d %d", &t3, &s3);
	printf("Input Quiz 4 : ");
	scanf("%d %d", &t4, &s4);
	printf("Input Quiz 5 : ");
	scanf("%d %d", &t5, &s5);
	//checking the validity of input
	if(s1 >= 0 && s2 >= 0 && s3 >= 0 && s4 >= 0 && s5 >= 0 && t1 > 0 && t2 > 0 && t3 > 0 && t4 > 0 && t5 > 0)
	{
		r1 = (s1 * 100.0)/t1;
		r2 = (s2 * 100.0)/t2;
		r3 = (s3 * 100.0)/t3;
		r4 = (s4 * 100.0)/t4;
		r5 = (s5 * 100.0)/t5;
		avg = (r1 + r2 + r3 + r4 + r5)/5;
		//table header format
		printf("---------------------------------\n");
		printf("%7s", "QUIZ#|");
		printf("%6s", "SCORE");
		printf("%2s", "|");
		printf("%6s", "TOTAL");
		printf("%2s","|");
		printf("%6s", "RATE");
		printf("%4s\n","|");
		printf("---------------------------------\n");
		//line 1
		printf("|1    |");
		printf("%6d", s1);
		printf("%2s","|");
		printf("%6d", t1);
		printf("%2s","|");
		printf("%7.2f%%",r1);
		printf("%2s\n", "|");
		//line 2
		printf("|2    |");
		printf("%6d", s2);
		printf("%2s","|");
		printf("%6d", t2);
		printf("%2s","|");
		printf("%7.2f%%",r2);
		printf("%2s\n", "|");
		//line 3
		printf("|3    |");
		printf("%6d", s3);
		printf("%2s","|");
		printf("%6d", t3);
		printf("%2s","|");
		printf("%7.2f%%",r3);
		printf("%2s\n", "|");
		//line4
		printf("|4    |");
		printf("%6d", s4);
		printf("%2s","|");
		printf("%6d", t4);
		printf("%2s","|");
		printf("%7.2f%%",r4);
		printf("%2s\n", "|");
		//line5
		printf("|5    |");
		printf("%6d", s5);
		printf("%2s","|");
		printf("%6d", t5);
		printf("%2s","|");
		printf("%7.2f%%",r5);
		printf("%2s\n", "|");
		//average
		printf("\nQuiz Average: %.2f%%",avg);
	}
	else
	{
		printf("Invalid input");
	}
	
	return 0;
}