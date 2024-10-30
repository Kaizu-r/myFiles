#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 100

typedef struct logbook{
    char plateNum[MAX];
    char profileID[MAX];
    //unsure!!
    //char type;

    //0 for logged out, 1-X for parking designation
    int status;
    
    struct tm timeIn;
    struct tm timeOut;
    struct logbook * next;
}log;

//RETURNS PARKING DESIGNATION. MOTOR CYCLE LOT IS CAR LOT SIZE++
int useLog(log **head, int option);


//FUNCTION REQUIREMENTS
//-------------------------------------------------------------
//please define with return int (0 for no prob,1 for no Plate Num)
void traverseProfile(void);
//please define with void return and void parameters
void registerProfile(void);
//please define with return int and parameter of profile ID. RETURN 0 IF NO ERROR, 1 IF NO ID
void dscrpncyCheck(void);
///----------------------------------------------------------==
//prints logbook to logbook.txt. Happens at the end of program execution
void printLog(log * head, int option);

void currLog(log * head);

int main()
{
    //ARRAYS TO BE USED FOR CHECKING MAX CAP AND FOR PRINTING
    int car[20] = {0}; //CHANGE SIZE IF NEEDED
    int motor[30] = {0}; //CHANGE SIZE IF NEEDED
    time_t t;

    //declare logbook + first log in 
    log * head = NULL;

    //testing
    int x = 1;
    int a;
    printf("No Logged in Users\n");
    printf("log in or log out: ");
    while(scanf("%d", &a) != EOF)
    {
        x = useLog(&head, a);
        t = time(NULL);
        while((time(NULL) - t) != 3);
        printf("\e[1;1H\e[2J");
        currLog(head);
        printf("%d\n", x);
        printf("log in or log out: ");
    }
    printLog(head, 0);


    return 0;
}

//option if log in (1) or log out (2)
int useLog(log **head, int option)
{
    log * p, *q, *new;
    char tempNo[MAX];
    char tempID[MAX];
    int choice, temphr, tempmin, outNotFound = 0;

    p = *head;
    time_t t;
    if(option == 1)
    {
        printf("Log IN\nPlate No: ");
        scanf("%s", tempNo);
        printf("Driver ID: ");
        scanf("%s", tempID);
        //ends once profile is registered or transaction is ended
        /*while(traverseProfile(parameters here) == 1)
        {
            printf("Plate Number is not in our data base.\n\t1. End Transaction\n\t2. Register Profile\n");
            scanf("%d", &choice);
            if(option == 1)
                return 0;
            else if(option == 2)
                registerProfile(parameters here);*/
        /*
        while(dscrpncyCheck(/* PROFILE ID HERE. OTHER PARAMETERS UNKOWN) == 1)
        {
            printf("Profile ID not found in the data base");
            printf("1. End Transaction. \n2. Archive\n");
            scanf("%d", &choice);
            if(choice == 1)
            return 0;


            /*Archive feature not added yet
            
            if(choice == 2)
            {
                archive();
                break;??
            }    
            
        }*/
        //making new pointer
        new = (log *) malloc(sizeof(log));
        strcpy(new->plateNum, tempNo);
        strcpy(new->profileID, tempID);
        t = time(NULL);
        new->timeIn = *localtime(&t);
        /*PLEASE ADD LIST TRAVERSAL FOR PROFILE UNTIL PLATE NUMBER IS FOUND
                WHEN PLATE NUMBER FOUND, PLEASE CHECK VEHICLE TYPE
                
                if(pointer->type == A)
                {
                    for(int i = 0; i<size of car spaces; i++)
                    {
                        searches for empty car spaces
                        if(car[i] == 0)
                        {
                            car[i] = 1;
                            new->status = i;
                            break;
                        }
                    }
                }
                else if(pointer->type == B)
                {
                    for(int i = 0; i < size of motor spaces; i++)
                    {
                        if(motor[i] == 0)
                        {
                            motor[i] = 1;
                            new->status = i + size of car spaces;
                            break;
                        }
                    }
                }
                
                add extra selections if necessary*/
        new->status = 10;
        new->next = NULL;
        
        //adding log details
        if(*head == NULL)
        {
            *head = new;
            return (*head)->status + 1;
        }
        while(p->next!= NULL)
            p = p->next;
        if(p->next == NULL)
        {
            p->next = new;
            //RETURNS PARKING SPOT. 1 IS LOWEST. RETURN 0 IS LOG OUT 
            return p->status + 1;
        }


    }
    else if(option == 2)
    {
        do
        {
            printf("Log OUT\nPlate No: ");
            scanf("%s", tempNo);
            printf("Driver ID: ");
            scanf("%s", tempID);

 


            //CHECKS IF ALREADY LOGGED OUT. FIND MOST RECENT LOG OUT
            
            if((strcmp(p->plateNum, tempNo) == 0) && p->status == 0)
            {
                q = p->next;
                while(q != NULL)
                {
                    if((strcmp(q->plateNum, tempNo) == 0) && q->status != 0)
                    {
                        p = q;
                        printf("x");
                    }
                    q = q->next;
                }
                if((p->status == 0 && q == NULL))
                {
                    printf("User already logged out. Exiting Log Out.\n");
                    return 0;
                }
            }
            else if(p->next == NULL)
            {
                 if((p->status == 0 && q == NULL))
                {
                    printf("User already logged out. Exiting Log Out.\n");
                    return 0;
                }
            }
            while((strcmp(p->plateNum, tempNo) != 0) && p->next != NULL)
            {
                q = p->next;
                while(q != NULL)
                {
                    if((strcmp(q->plateNum, tempNo) == 0) && q->status != 0)
                    {
                        p = q;
                    }
                    q = q->next;
                }
                if((p->status == 0 && q == NULL))
                {
                    printf("User already logged out. Exiting Log Out.\n");
                    return 0;
                }
            }

            /*
            //CHECK FOR DISCREPANCY
            while(dscrpncyCheck(/* PROFILE ID HERE. OTHER PARAMETERS UNKOWN) == 1)
            {
                printf("Profile ID not found in the data base");
                printf("1. End Transaction. \n2. Archive\n");
                scanf("%d", &choice);
                if(choice == 1)
                    return 0;
                /*Archive feature not added yet
            
                if(choice == 2)
                {
                    archive();??
                    break;
                }
                */
            //find platenumber to log out
            if((strcmp(p->plateNum, tempNo) == 0) && (strcmp(p->profileID, tempID) == 0) && p->status != 0)
            {             
                t = time(NULL);
                p->timeOut = *localtime(&t);

                p->status = 0;

                //calculating balance
                printf("Total balance is: Php %.2f", (((p->timeOut.tm_hour*60 + p->timeOut.tm_min)/60) - (p->timeIn.tm_hour*60 + p->timeIn.tm_min)/60) * 0.5 /*rate*/);

                return p->status;
                    
            }
            printf("Driver not logged in. \n1. End Transaction\n2. Log Out another driver\n");
            scanf("%d", &choice);
            if(choice == 1)
                return 0;
            else if(choice == 2)
                ;//DO NOTHING
                

        //Checks if car was even logged in (prevent security breaches)
        } while (outNotFound == 0); 
    }


}

void printLog(log * head, int option)
{
    log * p = head;
    FILE * ptr = fopen("logboook.txt", "a");

    char timeIN[100];
    char timeOUT[100];

    //p!= NULL because it needs to print until the last log
    while(p != NULL)
    {
        //gets date of timeIn
        strftime(timeIN, sizeof(timeIN), "%x", &p->timeIn);
        //runs if option is 1
        if(option)
        {
            fprintf(ptr, "| %s | ", timeIN);
            fprintf(ptr, "%s | %s ", p->plateNum, p->profileID);
            //gets hour of time in
            //DI KO ALAM BAKIT PULA YUNG FORMAT SPECIFIER PERO NAGA WORK YAN I TESTED IT
            strftime(timeIN, sizeof(timeIN), "%I:%M%p", &p->timeIn);
            strftime(timeOUT, sizeof(timeOUT), "%I:%M%p", &p->timeOut);
            fprintf(ptr, "| %s | %7s |\n", timeIN, timeOUT);
        }
        else
        {
            printf("| %s | ", timeIN);
            printf("%s | %s ", p->plateNum, p->profileID);
            //gets hour of time in
            //DI KO ALAM BAKIT PULA YUNG FORMAT SPECIFIER PERO NAGA WORK YAN I TESTED IT
            strftime(timeIN, sizeof(timeIN), "%I:%M%p", &p->timeIn);
            strftime(timeOUT, sizeof(timeOUT), "%I:%M%p", &p->timeOut);
            printf("| %s | %7s |\n", timeIN, timeOUT);
        }

        p = p->next;
    }
    fclose(ptr);
    return;
}

void currLog(log * head)
{
    log * p = head;
    char timeIN[100];
    char timeOUT[100];
    printf("CURRENT LOGGED IN USERS\n");
    //for first
    if(p->next == NULL)
    {
        if(p->status != 0)
        {
            //gets date of timeIn
            strftime(timeIN, sizeof(timeIN), "%x", &p->timeIn);
            printf("| %s | ", timeIN);
            printf("%s | %s |\n", p->plateNum, p->profileID);
            return;
        }
    }
    while(p != NULL)
    {
        if(p->status != 0)
        {
            //gets date of timeIn
            strftime(timeIN, sizeof(timeIN), "%x", &p->timeIn);
            printf("| %s | ", timeIN);
            printf("%s | %s |\n", p->plateNum, p->profileID);
        }

        p = p->next;
    }
    return;
}