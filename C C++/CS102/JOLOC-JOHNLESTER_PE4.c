//PROGRAMMING EXERCISES 4
//JOHN LESTER L. JOLOC
//BSCS 1 - B
//INPUT AND OUTPUT FORMATTING USING FILE I/O

#include<stdio.h>

int main()
{
	//Variable and pointer declararion
	char name[100];
	int s1, s2, s3, s4, s5, t1,t2,t3,t4,t5;
	float r1,r2,r3,r4,r5,avg;
	FILE *ipr;
	FILE *opr;

	//opens and creates file
	/*note that in some IDEs, the file isnt made
	automatically, so make the file first if code 
	is not running properly*/
	ipr = fopen("grade.txt","rt");
	opr = fopen("output.txt","wt");

	//Getting necessary inputs
	fscanf(ipr, "%s", name);
	fscanf(ipr, "%d %d", &t1, &s1);
	fscanf(ipr, "%d %d", &t2, &s2);
	fscanf(ipr,"%d %d", &t3, &s3);
	fscanf(ipr, "%d %d", &t4, &s4);
	fscanf(ipr, "%d %d", &t5, &s5);
	
	//Calculates rate and average
	r1 = (s1 * 100.0)/t1;
	r2 = (s2 * 100.0)/t2;
	r3 = (s3 * 100.0)/t3;
	r4 = (s4 * 100.0)/t4;
	r5 = (s5 * 100.0)/t5;
	avg = (r1 + r2 + r3 + r4 + r5)/5;
	
	//header format
	fprintf(opr, "The following is the %s\'s grades: \n", name);
	fprintf(opr, "---------------------------------\n");
	fprintf(opr, " QUIZ#| SCORE | TOTAL |  RATE   |\n");
	fprintf(opr, "---------------------------------\n");
	//line 1
	fprintf(opr, "|1    |%6d |%6d | %6.2f%% |\n", s1, t1, r1);
	//line 2
	fprintf(opr, "|2    |%6d |%6d | %6.2f%% |\n", s2, t2, r2);
	//line 3
	fprintf(opr, "|3    |%6d |%6d | %6.2f%% |\n", s3, t3, r3);
	//line4
	fprintf(opr, "|4    |%6d |%6d | %6.2f%% |\n", s4, t4, r4);
	//line5
	fprintf(opr, "|5    |%6d |%6d | %6.2f%% |\n", s5, t5, r5);
	//average
	fprintf(opr, "\nQuiz Average: %.2f%%",avg);
	//close the  files
	fclose(ipr);
	fclose(opr);

	return 0;
}