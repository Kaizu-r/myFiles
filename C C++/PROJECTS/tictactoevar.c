//John Lester L. Joloc
//BSCS 1 - B
//VS CODE

//Tictactoe with PvP and PvE


#include<stdio.h>

char A,B,C,D,E,F,G,H,I;
char PLAYERA, PLAYERB;
void resetBoard();
void printBoard();
char PLAYERMOVE(char player);
char checkWinner();
void printWinner(char winner);
void computer(char tile);
int checkFreeSpaces();
void playerVsPlayer();
void ComputerVsPlayer();


int main()
{
	char response, type;
	do
	{
		printf("Would you like to play?(Y/N)\n");
		scanf(" %c", &response);
		if(response == 'N')
		{
			break;
		}
		else if(response == 'Y')
		{
			printf("Pick a mode: \nA. Player vs Player \nB. Player vs Computer\n Your choice: \n");
			scanf(" %c", &type);
			if(type == 'A')
			{
				playerVsPlayer();
			}
			else if(type == 'B')
			{
				ComputerVsPlayer();
			}
		}
		else
		{
			printf("Invalid response!\n");
		}
	}while (response == 'Y' || response != 'N');
	return 0;
}


void playerVsPlayer()
{
	char winner = ' ';
	resetBoard();
	PLAYERA = 'X';
	PLAYERB = 'O';
	printBoard();
	while(checkFreeSpaces() != 0 && winner == ' ')
	{
		PLAYERMOVE(PLAYERA);
		winner = checkWinner();
		if(winner != ' ' || checkFreeSpaces() == 0)
		{
			break;
		}
		PLAYERMOVE(PLAYERB);
		winner = checkWinner();
		if(winner != ' ' || checkFreeSpaces() == 0)
		{
			break;
		}	
	}
	winner = checkWinner();
	printBoard();
	printWinner(winner);
	return;
}

void resetBoard()
{
	A = ' ';
	B = ' ';
	C = ' ';
	D = ' ';
	E = ' ';
	F = ' ';
	G = ' ';
	H = ' ';
	I = ' ';
}

void printBoard()
{
	printf("\n");
	printf(" %c | %c | %c ",A, B, C);
	printf("\n-----------\n");
	printf(" %c | %c | %c ",D, E, F);
	printf("\n-----------\n");
	printf(" %c | %c | %c\n ",G, H, I);
	printf("\n");
}

int checkFreeSpaces()
{
	int freeSpaces = 9;
	if(A != ' ')
	{
		freeSpaces--;
	}
	if(B != ' ')
	{
		freeSpaces--;
	}
	if(C != ' ')
	{
		freeSpaces--;
	}
	if(D != ' ')
	{
		freeSpaces--;
	}
	if(E != ' ')
	{
		freeSpaces--;
	}
	if(F != ' ')
	{
		freeSpaces--;
	}
	if(G != ' ')
	{
		freeSpaces--;
	}
	if(H != ' ')
	{
		freeSpaces--;
	}
	if(I != ' ')
	{
		freeSpaces--;
	}
	return freeSpaces;
}

char PLAYERMOVE(char player)
{
	char x;
	int validity = 0;

	do
	{
		printf("Player %c! Enter Tile(A-I): ",player);
		scanf(" %c", &x);
		if(x < 65 || x > 90)
		{
			printf("Invalid move\n");
		}
		else if(x == 'A')
		{
			if(A != ' ')
			{
				printf("Invalid move\n");
			}
			else
			{
				A = player;
				break;
			}
		}
		else if(x == 'B')
		{
			if(B != ' ')
			{
				printf("Invalid move\n");
			}
			else
			{
				B = player;
				break;
			}
		}
		else if(x == 'C')
		{
			if(C != ' ')
			{
				printf("Invalid move\n");
			}
			else
			{
				C = player;
				break;
			}
		}
		else if(x == 'D')
		{
			if(D != ' ')
			{
				printf("Invalid move\n");
			}
			else
			{
				D = player;
				break;
			}
		}
		else if(x == 'E')
		{
			if(E != ' ')
			{
				printf("Invalid move\n");
			}
			else
			{
				E = player;
				break;
			}
		}
		else if(x == 'F')
		{
			if(F != ' ')
			{
				printf("Invalid move\n");
			}
			else
			{
				F = player;
				break;
			}
		}
		else if(x == 'G')
		{
			if(G != ' ')
			{
				printf("Invalid move\n");
			}
			else
			{
				G = player;
				break;
			}
		}
		else if(x == 'H')
		{
			if(H != ' ')
			{
				printf("Invalid move\n");
			}
			else
			{
				H = player;
				break;
			}
		}
		else if(x == 'I')
		{
			if(I != ' ')
			{
				printf("Invalid move\n");
			}
			else
			{
				I = player;
				break;
			}
		}
	}while(1);
	printBoard();
	return x;
}
char checkWinner()
{
	//rows
	if(A == B && A == C && A != 0)
	{
		return A;
	}
	else if (D == E && D == F)
	{
		return D;
	}
	else if(G == H && G == I)
	{
		return G;
	}
	//columns
	if(A == D && A == G)
	{
		return A;
	}
	else if(B == E && B == H)
	{
		return B;
	}
	else if(C == F && C == I)
	{
		return C;
	}
	//diagonals
	if(A == E && A == I)
	{
		return A;
	}
	if(C == E && C == G)
	{
		return C;
	}
	return ' '; 
}

void printWinner(char winner)
{
	if(winner != ' ')
	{
		printf("%c IS THE WINNER!\n", winner);
	}
	else
	{
		printf("IT'S A TIE!\n");
	}
}

void computer(char tile)
{
	int mA, mB, mC, mD, mE, mF, mG, mH, mI;
	mA = mB = mC = mD = mE = mF = mG = mH = mI = 0;
	//first move
	if(checkFreeSpaces() == 8)
	{
		if(tile == 'A' || tile == 'C' || tile == 'G' || tile == 'I')
		{
			E = 'O';
		}
		else if(tile == 'B' || tile == 'D' || tile == 'F' || tile == 'H')
		{
			E = 'O';
		}
		else if(tile == 'E')
		{
			A = 'O';
		}
		return; 
	}
	else
	{
		//availability
		//if center is occupied by X, put priority to corner
		if(E == 'X')
		{
			mA = mC = mG = mI = 1;
		}
		//wins first before blocks
		if(A == ' ')
		{
			if((B == 'O' && C == 'O') || (D == 'O' && G == 'O') || (E == 'O' && I == 'O'))
			{
				A = 'O';
				return; 
			}
		}
		if(B == ' ')
		{
			if((A == 'O' && C == 'O') || (E == 'O' && H == 'O'))
			{
				B = 'O';
				return; 
			}
		}
		if(C == ' ')
		{
			if((B == 'O' && A == 'O') || (F == 'O' && I == 'O') || (E == 'O' && G == 'O'))
			{
				C = 'O';
				return; 
			}
		}
		if(D == ' ')
		{
			if((A == 'O' && G == 'O') || (E == 'O' && F == 'O'))
			{
				D = 'O';
				return; 
			}
		}
		if(E == ' ')
		{
			if((A == 'O' && I == 'O') || (C == 'O' && G == 'O') || (B == 'O' && H == 'O') || (D == 'O' && F == 'O'))
			{
				E = 'O';
				return; 
			}
		}
		if(F == ' ')
		{
			if((C == 'O' && I == 'O') || (E == 'O' && D == 'O'))
			{
				F = 'O';
				return; 
			}
		}
		if(G == ' ')
		{
			if((D == 'O' && A == 'O') || (H == 'O' && I == 'O') || (E == 'O' && C == 'O'))
			{
				G = 'O';
				return; 
			}
		}
		if(H == ' ')
		{
			if((G == 'O' && I == 'O') || (E == 'O' && B == 'O'))
			{
				H = 'O';
				return; 
			}
		}
		if(I == ' ')
		{
			if((B == 'O' && F == 'O') || (H == 'O' && G == 'O') || (E == 'O' && A == 'O'))
			{
				I = 'O';
				return; 
			}
		}
		//checks blocks, if none then proceed to standard move
		if(A == ' ')
		{
			//blocks
			if((B == 'X' && C == 'X') || (D == 'X' && G == 'X') || (E == 'X' && I == 'X'))
			{
				A = 'O';
				return; 
			}
			//standard move
			if(B == 'X')
			{
				mA++;
			}
			if(E == 'X')
			{
				mA++;
			}
			if(D == 'X')
			{
				mA++;
			}
			if(B == 'O')
			{
				mA++;
			}
			if(E == 'O')
			{
				mA++;
			}
			if(D == 'O')
			{
				mA++;
			}
			if(B == 'O' && C == 'X')
			{
				mA--;
			}
			if(E == 'O' && I == 'X')
			{
				mA--;
			}
			if(D == 'O' && G == 'X')
			{
				mA--;
			}
		}
		if(B == ' ')
		{
			//blocks
			if((A == 'X' && C == 'X') || (E == 'X' && H == 'X'))
			{
				B = 'O';
				return; 
			}
			//standard move
			if(A == 'X')
			{
				mB++;
			}
			if(C == 'X')
			{
				mB++;
			}
			if(E == 'X')
			{
				mB++;
			}
			if(A == 'O')
			{
				mB++;
			}
			if(C == 'O')
			{
				mB++;
			}
			if(E == 'O')
			{
				mB++;
			}
			if((A == 'O' && C == 'X') || (C == 'O' && A == 'X'))
			{
				mB--;
			}
			if(E == 'O' && H == 'X')
			{
				mB--;
			}
		}
		if(C == ' ')
		{
			//blocks
			if((B == 'X' && A == 'X') || (F == 'X' && I == 'X') || (E == 'X' && G == 'X'))
			{
				C = 'O';
				return; 
			}
			//standard move
			if(B == 'X')
			{
				mC++;
			}
			if(E == 'X')
			{
				mC++;
			}
			if(F == 'X')
			{
				mC++;
			}
			if(B == 'O')
			{
				mC++;
			}
			if(E == 'O')
			{
				mC++;
			}
			if(F == 'O')
			{
				mC++;
			}
			if(B == 'O' && A =='X')
			{
				mC--;
			}
			if(E == 'O' && G == 'X')
			{
				mC--;
			}
			if(F == 'O' && I == 'X')
			{
				mC--;
			}
		}
		if(G == ' ')
		{
			//blocks
			if((D == 'X' && A == 'X') || (H == 'X' && I == 'X') || (E == 'X' && C == 'X'))
			{
				G = 'O';
				return; 
			}
			//standard move
			if(D == 'X')
			{
				mG++;
			}
			if(E == 'X')
			{
				mG++;
			}
			if(H == 'X')
			{
				mG++;
			}
			if(D == 'O')
			{
				mG++;
			}
			if(E == 'O')
			{
				mG++;
			}
			if(H == 'O')
			{
				mG++;
			}
			if(D == 'O' && A == 'X')
			{
				mG--;
			}
			if(E == 'O' && C == 'X')
			{
				mG--;
			}
			if(H == 'O' && I == 'X')
			{
				mG--;
			}
		}
		if(I == ' ')
		{
			//blocks
			if((B == 'X' && F == 'X') || (H == 'X' && G == 'X') || (E == 'X' && A == 'X'))
			{
				I = 'O';
				return; 
			}
			//standard move
			if(F == 'X')
			{
				mI++;
			}
			if(E == 'X')
			{
				mI++;
			}
			if(H == 'X')
			{
				mI++;
			}
			if(F == 'O')
			{
				mI++;
			}
			if(E == 'O')
			{
				mI++;
			}
			if(H == 'O')
			{
				mI++;
			}
			if(F == 'O' && C == 'X')
			{
				mI--;
			}
			if(E == 'O' && A == 'X')
			{
				mI--;
			}
			if(H == 'O' && G == 'X')
			{
				mI--;
			}
		}
		if(D == ' ')
		{
			//blocks
			if((A == 'X' && G == 'X') || (E == 'X' && F == 'X'))
			{
				D = 'O';
				return; 
			}
			//standard move
			if(A == 'X')
			{
				mD++;
			}
			if(G == 'X')
			{
				mD++;
			}
			if(E == 'X')
			{
				mD++;
			}
			if(A == 'O')
			{
				mD++;
			}
			if(G == 'O')
			{
				mD++;
			}
			if(E == 'O')
			{
				mD++;
			}
			if((A == 'O' && G == 'X') || (G == 'O' && A == 'X'))
			{
				mD--;
			}
			if(E == 'O' && F == 'X')
			{
				mD--;
			}
		}
		if(F == ' ')
		{
			//blocks
			if((C == 'X' && I == 'X') || (E == 'X' && D == 'X'))
			{
				F = 'O';
				return; 
			}
			//standard move
			if(C == 'X')
			{
				mF++;
			}
			if(I == 'X')
			{
				mF++;
			}
			if(E == 'X')
			{
				mF++;
			}
			if(C == 'O')
			{
				mF++;
			}
			if(I == 'O')
			{
				mF++;
			}
			if(E == 'O')
			{
				mF++;
			}
			if((C == 'O' && I == 'X') || (I == 'O' && C == 'X'))
			{
				mF--;
			}
			if(E == 'O' && D == 'X')
			{
				mF--;
			}
		}
		if(H == ' ')
		{
			//blocks
			if((I == 'X' && G == 'X') || (E == 'X' && B == 'X'))
			{
				H = 'O';
				return; 
			}
			//standard move
			if(I == 'X')
			{
				mH++;
			}
			if(G == 'X')
			{
				mH++;
			}
			if(E == 'X')
			{
				mH++;
			}
			if(I == 'O')
			{
				mH++;
			}
			if(G == 'O')
			{
				mH++;
			}
			if(E == 'O')
			{
				mH++;
			}
			if((I == 'O' && G == 'X') || (G == 'O' && I == 'X'))
			{
				mH--;
			}
			if(E == 'O' && B == 'X')
			{
				mH--;
			}
		}
		if(E == ' ')
		{
			//blocks
			if((A == 'X' && I == 'X') || (C == 'X' && G == 'X') || (B == 'X' && H == 'X') || (D == 'X' && F == 'X'))
			{
				E = 'O';
				return; 
			}
			//standard move
			if(A == 'X')
			{
				mE++;
			}
			if(B == 'X')
			{
				mE++;
			}
			if(C == 'X')
			{
				mE++;
			}
			if(D == 'X')
			{
				mE++;
			}
			if(I == 'X')
			{
				mE++;
			}
			if(F == 'X')
			{
				mE++;
			}
			if(G == 'X')
			{
				mE++;
			}
			if(H== 'X')
			{
				mE++;
			}
			if(A == 'O')
			{
				mE++;
			}
			if(B == 'O')
			{
				mE++;
			}
			if(C == 'O')
			{
				mE++;
			}
			if(D == 'O')
			{
				mE++;
			}
			if(I == 'O')
			{
				mE++;
			}
			if(F == 'O')
			{
				mE++;
			}
			if(G == 'O')
			{
				mE++;
			}
			if(H == 'O')
			{
				mE++;
			}
			if((A == 'O' && I == 'X') || (I == 'O' && A == 'X'))
			{
				mE--;
			}
			if((B == 'O' && H == 'X') || (H == 'O' && B =='X'))
			{
				mE--;
			}
			if((C == 'O' && G == 'X') || (G == 'O' && C == 'X'))
			{
				mE--;
			}
			if((D == 'O' && F == 'X') || (F == 'O' && D == 'X'))
			{
				mE--;
			}
		}
		//check for best standard moves. Center and corner at highest priority.
		if(mE >= mA && mE >= mB && mE >= mC && mE >= mD && mE >= mF && mE >= mG && mE >= mH && mE >= mI)
		{
			E = 'O';
			return; 
		}
		if(mA >= mB && mA >= mC && mA >= mD && mA >= mE && mA >= mF && mA >= mG && mA >= mH && mA >= mI)
		{
			A = 'O';
			return; 
		}
		if(mC >= mA && mC >= mB && mC >= mD && mC >= mE && mC >= mF && mC >= mG && mC >= mH && mC >= mI)
		{
			C = 'O';
			return; 
		}
		if(mG >= mA && mG >= mB && mG >= mC && mG >= mE && mG >= mF && mG >= mD && mG >= mH && mG >= mI)
		{
			G = 'O';
			return; 
		}
		if(mI >= mA && mI >= mB && mI >= mC && mI >= mE && mI >= mF && mI >= mG && mI >= mH && mI >= mD)
		{
			I = 'O';
			return; 
		}
		if(mB >= mA && mB >= mC && mB >= mD && mB >= mE && mB >= mF && mB >= mG && mB >= mH && mB >= mI)
		{
			B = 'O';
			return; 
		}
		if(mD >= mA && mD >= mB && mD >= mC && mD >= mE && mD >= mF && mD >= mG && mD >= mH && mD >= mI)
		{
			D = 'O';
			return; 
		}
		if(mF >= mA && mF >= mB && mF >= mC && mF >= mE && mF >= mD && mF >= mG && mF >= mH && mF >= mI)
		{
			F = 'O';
			return; 
		}
		if(mH >= mA && mH >= mB && mH >= mC && mH >= mE && mH >= mF && mG >= mG && mH >= mD && mH >= mI)
		{
			H = 'O';
			return; 
		}
	}
	return; 
}
void ComputerVsPlayer()
{
	char winner = ' ';
	resetBoard();
	PLAYERA = 'X';
	while(checkFreeSpaces() != 0 && winner == ' ')
	{
		printBoard();
		char tile = PLAYERMOVE(PLAYERA);
		winner = checkWinner();
		if(winner != ' ' || checkFreeSpaces() == 0)
		{
			break;
		}
		computer(tile);
		printf("Computer Move!!!\n");
		winner = checkWinner();
		if(winner != ' ' || checkFreeSpaces() == 0)
		{
			break;
		}
	}
	winner = checkWinner();
	printBoard();
	printWinner(winner);
}