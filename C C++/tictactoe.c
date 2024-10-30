#include<stdio.h>

int checkSpaces();
void playerMove(char player);
void computerMove();
char checkWinner();
void printWinner(char winner);
void resetBoard();
void printBoard();

char board[3][3]; 

int main()
{
    resetBoard();
    printBoard();

    while(checkWinner() == ' ' && checkSpaces() != 0)
    {

    }


    return 0;
}

int checkSpaces()
{
    int space = 9;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != ' ')
                space--;
        }
    }

    return space;
}
void playerMove(char player)
{
    int x, y;
    do
    {
        printf("Select a row number(1-3): ");
        scanf(" %d", &x);
        printf('Select a column number(1-3): ');
        scanf(" %d", &y);
        if(board[x - 1][y - 1] == ' ')
            board[x - 1][y - 1] = board[x - 1][y - 1];
    }while(board[x - 1][y - 1] != ' ');
}
void computerMove();
char checkWinner()
{
    //rows
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][3])
            return board[i][0];
    }
    //columns
    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[i][1] && board[i][0] == board[i][3])
            return board[i][0];
    }
}
void printWinner(char winner);
void resetBoard()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            board[i][j] = ' ';
    }
}
void printBoard()
{
    for(int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        printf("-----------\n");
    }
}