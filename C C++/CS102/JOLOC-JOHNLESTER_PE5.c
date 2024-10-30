//PROGRAMMING EXERCISES 5
//JOHN LESTER L. JOLOC
//BSCS 1 - B
//GRADE CALCULATOR AND TRANSMUTATOR 

#include<stdio.h>

int main()
{
    float quiz, midterm, final, proj, recit;
    int transGrade;
    float actual, gradePoint;
    FILE *opf;
    opf = fopen("grade.txt", "w");

    printf("Enter grade for Quizzes: ");
    scanf(" %f", &quiz);
    printf("Enter grade for Midterm exam: ");
    scanf(" %f", &midterm);
    printf("Enter grade for Final exam: ");
    scanf(" %f", &final);
    printf("Enter grade for Project: ");
    scanf(" %f", &proj);
    printf("Enter grade for Recitation: ");
    scanf(" %f", &recit);

    actual = (quiz * .25) + (midterm * 0.2) + (final * 0.25) + (proj * 0.2) + (recit * 0.1);
    //Transumate and floor by using int for transmuted grade instead of float
    if(actual < 60)
        transGrade = 60 + (actual/4);
    else
        transGrade = 75 + ((actual - 60)/1.6);
    
    //Convert to grade point
    if(transGrade <= 74)
        gradePoint = 5;
    else if(transGrade <= 76)
        gradePoint = 3;
    else if(transGrade <= 78)
        gradePoint = 2.75;
    else if(transGrade <= 81)
        gradePoint = 2.5;   
    else if(transGrade <= 83)
        gradePoint = 2.25;
    else if(transGrade <= 85)
        gradePoint = 2;
    else if(transGrade <= 87)
        gradePoint = 1.75;
    else if(transGrade <= 90)
        gradePoint = 1.5;
    else if(transGrade <= 94)
      gradePoint = 1.25;
    else
        gradePoint = 1;
    
    //printing on stdout
    printf("\n----------------------------------------\n");
    printf("REQUIREMENT           GRADE       WEIGHT\n");
    printf("----------------------------------------\n");
    printf("Quizzes               %6.2f       25%%   \n", quiz);
    printf("Midterm Exam          %6.2f       20%%   \n", midterm);
    printf("Final Exam            %6.2f       25%%   \n", final);
    printf("Project               %6.2f       20%%   \n", proj);
    printf("Recitation            %6.2f       25%%   \n", recit);
    printf("\n");

    printf("Actual Grade          %.2f\n", actual);
    printf("Transmuted Grade      %.2d\n", transGrade);
    printf("Grade point           %.2f\n", gradePoint);
    printf("Description           ");
    
    if(gradePoint == 5)
        printf("Failure\n");
    else if(gradePoint >= 2.5)
        printf("Fair\n");
    else if(gradePoint >= 2)
        printf("Satisfactory\n");
    else if(gradePoint >= 1.5)
        printf("Very Satisfactory\n");
    else if(gradePoint == 1.25)
        printf("Superior\n");
    else
        printf("Outstanding\n");

    //printing on grades.txt
    fprintf(opf, "\n----------------------------------------\n");
    fprintf(opf, "REQUIREMENT           GRADE       WEIGHT\n");
    fprintf(opf, "----------------------------------------\n");
    fprintf(opf, "Quizzes               %6.2f       25%%   \n", quiz);
    fprintf(opf, "Midterm Exam          %6.2f       20%%   \n", midterm);
    fprintf(opf, "Final Exam            %6.2f       25%%   \n", final);
    fprintf(opf, "Project               %6.2f       20%%   \n", proj);
    fprintf(opf, "Recitation            %6.2f       25%%   \n", recit);
    fprintf(opf, "\n");

    fprintf(opf, "Actual Grade          %.2f\n", actual);
    fprintf(opf, "Transmuted Grade      %.2d\n", transGrade);
    fprintf(opf, "Grade point           %.2f\n", gradePoint);
    fprintf(opf, "Description           ");
    if(gradePoint == 5)
        fprintf(opf, "Failure\n");
    else if(gradePoint >= 2.5)
        fprintf(opf, "Fair\n");
    else if(gradePoint >= 2)
        fprintf(opf, "Satisfactory\n");
    else if(gradePoint >= 1.5)
        fprintf(opf, "Very Satisfactory\n");
    else if(gradePoint == 1.25)
        fprintf(opf, "Superior\n");
    else
        fprintf(opf, "Outstanding\n");


    fclose(opf);
    return 0;
}
