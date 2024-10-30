#include<stdio.h>

//variables for players and board
char board[9][9];
char large[9];
const char PLAYERX = 'X';
const char PLAYERO = 'O';


void resetBoard();
void printBoard(int tile);
int checkCellSpace(int tile);
int checkTileSpace();
void dotSpaces(int tile);
void revertSpaces(int tile);
char tileWinner(int tile);
char trueWinner();
void printTileWinner(int tile, char player);
void printWinner(char winner);
int playerMove(int tile, char player);
int specialMove(char player);

int main()
{
    int tile;
    resetBoard(); 
    printBoard(10);
    tile = specialMove(PLAYERX);
    while(trueWinner() != ' ' || checkTileSpace() == 0)
    {
        if(checkCellSpace(tile) == 0 || tileWinner(tile) != ' ')
        {
            printBoard(10);
            tile = specialMove(PLAYERO);
            if(trueWinner() != ' ')
            {
                break;
            }

        }
        else
        {
            printBoard(tile);
            tile = playerMove(tile, PLAYERO); 
        }
        if(checkCellSpace(tile) == 0 || tileWinner(tile) != ' ')
        {
            printBoard(10);
            tile = specialMove(PLAYERX);
            if(trueWinner() != ' ')
            {
                break;
            }
        }
        else
        {
            printBoard(tile);
            tile = playerMove(tile, PLAYERX); 
        }
    }
    
    printBoard(10);
    printWinner(trueWinner());
    return 0;
}

void resetBoard()
{
    int i,j;
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            board[i][j] = ' ';
            large[j] = ' ';
        }
    }
}
void printBoard(int tile)
{
    if(tile == 10)
    {
        printf("\n %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board[0][0], board[0][1], board[0][2], board[1][0], board[1][1], board[1][2], board[2][0], board[2][1], board[2][2]); 
        printf("-----------||-----------||-----------");
        printf("\n %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board[0][3], board[0][4], board[0][5], board[1][3], board[1][4], board[1][5], board[2][3], board[2][4], board[2][5]); 
        printf("-----------||-----------||-----------");
        printf("\n %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board[0][6], board[0][7], board[0][8], board[1][6], board[1][7], board[1][8], board[2][6], board[2][7], board[2][8]); 
        printf("===========||===========||============");
        printf("\n %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board[3][0], board[3][1], board[3][2], board[4][0], board[4][1], board[4][2], board[5][0], board[5][1], board[5][2]); 
        printf("-----------||-----------||-----------");
        printf("\n %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board[3][3], board[3][4], board[3][5], board[4][3], board[4][4], board[4][5], board[5][3], board[5][4], board[5][5]); 
        printf("-----------||-----------||-----------");
        printf("\n %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board[3][6], board[3][7], board[3][8], board[4][6], board[4][7], board[4][8], board[5][6], board[5][7], board[5][8]); 
        printf("===========||===========||============");
        printf("\n %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board[6][0], board[6][1], board[6][2], board[7][0], board[7][1], board[7][2], board[8][0], board[8][1], board[8][2]); 
        printf("-----------||-----------||-----------");
        printf("\n %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board[6][3], board[6][4], board[6][5], board[7][3], board[7][4], board[7][5], board[8][3], board[8][4], board[8][5]); 
        printf("-----------||-----------||-----------");
        printf("\n %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board[6][6], board[6][7], board[6][8], board[7][6], board[7][7], board[7][8], board[8][6], board[8][7], board[8][8]); 
        printf("\n");
    }
    else
    {
        dotSpaces(tile);
        printf("\n %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board[0][0], board[0][1], board[0][2], board[1][0], board[1][1], board[1][2], board[2][0], board[2][1], board[2][2]); 
        printf("-----------||-----------||-----------");
        printf("\n %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board[0][3], board[0][4], board[0][5], board[1][3], board[1][4], board[1][5], board[2][3], board[2][4], board[2][5]); 
        printf("-----------||-----------||-----------");
        printf("\n %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board[0][6], board[0][7], board[0][8], board[1][6], board[1][7], board[1][8], board[2][6], board[2][7], board[2][8]); 
        printf("===========||===========||============");
        printf("\n %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board[3][0], board[3][1], board[3][2], board[4][0], board[4][1], board[4][2], board[5][0], board[5][1], board[5][2]); 
        printf("-----------||-----------||-----------");
        printf("\n %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board[3][3], board[3][4], board[3][5], board[4][3], board[4][4], board[4][5], board[5][3], board[5][4], board[5][5]); 
        printf("-----------||-----------||-----------");
        printf("\n %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board[3][6], board[3][7], board[3][8], board[4][6], board[4][7], board[4][8], board[5][6], board[5][7], board[5][8]); 
        printf("===========||===========||============");
        printf("\n %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board[6][0], board[6][1], board[6][2], board[7][0], board[7][1], board[7][2], board[8][0], board[8][1], board[8][2]); 
        printf("-----------||-----------||-----------");
        printf("\n %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board[6][3], board[6][4], board[6][5], board[7][3], board[7][4], board[7][5], board[8][3], board[8][4], board[8][5]); 
        printf("-----------||-----------||-----------");
        printf("\n %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board[6][6], board[6][7], board[6][8], board[7][6], board[7][7], board[7][8], board[8][6], board[8][7], board[8][8]); 
        printf("\n");
        revertSpaces(tile);
    }
}
int checkCellSpace(int tile)
{
    int space = 9;
    for(int i = 0; i < 9; i++)
    {
        if(board[tile][i] != ' ')
        {
            space--;
        }
    }
    return space;
}
int checkTileSpace()
{
    int space;
    for(int i = 0; i < 9; i++)
    {
        if(large[i] != ' ')
        {
            space--;
        }
    }
    return space;
}
void dotSpaces(int tile)
{
    int i;
    for(i = 0; i < 9; i++)
    {
        if(board[tile][i] == ' ')
        {
            board[tile][i] = '-';
        }
    }
}
void revertSpaces(int tile)
{
    int i;
    for(i = 0; i < 9; i++)
    {
        if(board[tile][i] == '-')
        {
            board[tile][i] = ' ';
        }
    }
}
char tileWinner(int tile)
{
    //rows
    if(board[tile][0] == board[tile][1] && board[tile][0] == board[tile][2] && board[tile][0] != ' ')
    {
        large[tile] = board[tile][0];
        return large[tile];
    }
    if(board[tile][3] == board[tile][4] && board[tile][3] == board[tile][5] && board[tile][3] != ' ')
    {
        large[tile] = board[tile][3];
        return large[tile];
    }
    if(board[tile][6] == board[tile][7] && board[tile][6] == board[tile][8] && board[tile][6] != ' ')
    {
        large[tile] = board[tile][6];
        return large[tile];
    }
    //columns
    if(board[tile][0] == board[tile][3] && board[tile][0] == board[tile][6] && board[tile][0] != ' ')
    {
        large[tile] = board[tile][0];
        return large[tile];
    }
    if(board[tile][1] == board[tile][4] && board[tile][1] == board[tile][7] && board[tile][1] != ' ')
    {
        large[tile] = board[tile][1];
        return large[tile];
    }
    if(board[tile][2] == board[tile][5] && board[tile][2] == board[tile][8] && board[tile][2] != ' ')
    {
        large[tile] = board[tile][2];
        return large[tile];
    }
    //diagonals
    if(board[tile][0] == board[tile][4] && board[tile][0] == board[tile][8] && board[tile][0] != ' ')
    {
        large[tile] = board[tile][0];
        return large[tile];
    }
    if(board[tile][2] == board[tile][4] && board[tile][2] == board[tile][6] && board[tile][2] != ' ')
    {
        large[tile] = board[tile][2];
        return large[tile];
    }
    if(checkCellSpace(tile) == 0)
    {
        return '-';
    }
    return ' ';
}
char trueWinner()
{
    //rows
    for(int i = 0; i < 8; i += 3)
    {
        if(large[i] == large[i + 1] && large[i] == large[i + 2] && large[i] != ' ')
        {
            return large[i];
        }
    }
    //columns
    for(int i = 0; i < 3; i++)
    {
        if(large[i] == large[i + 3] && large[i] == large[i + 6] && large[i] != ' ')
        {
            return large[i];
        }
    }
    //diagonals
    if(large[0] == large[4] && large[0] == large[8] && large[0] != ' ')
    {
        return large[0];
    }
    if(large[2] == large[4] && large[2] == large[6] && large[2] != ' ')
    {
        return large[2];
    }
    else if(checkTileSpace() == 0)
    {
        return '-';
    }
    return ' ';
}

void printTileWinner(int tile, char player)
{
    switch(player)
    {
        case 'X':
            board[tile][0] = board[tile][2] = board[tile][4] = board[tile][6] = board[tile][8] = 'X';
            board[tile][1] = board[tile][3] = board[tile][5] = board[tile][7] = ' ';
            break;
        case 'O':
            for(int i = 0; i < 4; i++)
            {
                board[tile][i] = 'O';
            }
            board[tile][4] = ' ';
            for(int i = 5; i < 9; i++)
            {
                board[tile][i] = 'O';
            }
            break;
        case '-':
            for(int i = 0; i < 4; i++)
            {
                board[tile][i] = ' ';
            }
            board[tile][4] = '-';
            for(int i = 5; i < 9; i++)
            {
                board[tile][i] = ' ';
            }
            break;
    }
}
void printWinner(char winner)
{
    if(winner == 'X')
    {
        printf("The winner is X!\n");
    }
    else if(winner == 'O')
    {
        printf("The winner is O!\n");
    }
    else if(winner == '-')
    {
        printf("Its a tie!\n");
    }
}
int playerMove(int tile, char player)
{
    int y;
    do
    {
        printf("PLAYER %c!!! Pick a cell (1-9) in tile %d: \n", player, tile);
        scanf(" %d", &y);
        y--;
        if(board[tile][y] != ' ')
        {
            printf("Invalid Move\n");
        }
        else
        {
            board[tile][y] = player;
            break; 
        }
    } while(board[tile][y] != ' ');
    return y;
}
int specialMove(char player)
{
    int x,y;
    do
    {
        printf("PLAYER %c!!! Pick a tile from 1-9: \n", player);
        scanf(" %d", &x);
        x--;
        if((x < 0 || x > 8) || large[x] != ' ')
        {
            printf("Invalid Input\n");
        }
        else
        {
            printf("PLAYER %c!!! Pick a cell (1-9) in tile %d: \n", player, x);
            scanf(" %d", &y);
            y--;
            if((y < 0 || y > 8) || board[x][y] != ' ')
            {
                printf("Invalid Input\n");
            }
            else
            {
                board[x][y] = player;
                break;
            }
        }
    } while (board[x][y] != ' ');
    printTileWinner(x, tileWinner(x));
    return y;
    
}