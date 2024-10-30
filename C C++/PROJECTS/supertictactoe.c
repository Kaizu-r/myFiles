#include<stdio.h>

//initializes tiles(single letter) and cells(two letters)
char A, AA, AB, AC, AD, AE, AF, AG, AH, AI;
char B, BA, BB, BC, BD, BE, BF, BG, BH, BI;
char C, CA, CB, CC, CD, CE, CF, CG, CH, CI;
char D, DA, DB, DC, DD, DE, DF, DG, DH, DI;
char E, EA, EB, EC, ED, EE, EF, EG, EH, EI;
char F, FA, FB, FC, FD, FE, FF, FG, FH, FI;
char G, GA, GB, GC, GD, GE, GF, GG, GH, GI;
char H, HA, HB, HC, HD, HE, HF, HG, HH, HI;
char I, IA, IB, IC, ID, IE, IF, IG, IH, II;
char PLAYER1 = 'X';
char PLAYER2 = 'O';

//checks free spaces per tile and returns number of freespaces
int checkSpace(char tile);
//declares who won in the tile and returns what character they use
char tileWinner(char tile);
//checks who won the whole game and returns the character of the winner
char trueWinner();
//primts the board
void printBoard(char tile);
//replaces empty spaces with dots on the next major tile
void dotSpaces(char tile);
//reverts dotted spaces back to space
void revertSpaces(char tile);
//prints tile into symbol of tile winner
void printTileWinner(char tile, char winner);
//occurs on first move or when player is forced to play on tile with a winner
char specialMove(char player);
//Move for players
char playerMove(char tile, char player);
//resets the whole board
void resetBoard();
//Print's the overall winner
void printTrueWinner(char trueWinner);
//Checks spaces for the big tiles
int checkBigSpaces();



int main()
{
    char tile;
    char tileWin;
    resetBoard();
    //print blank board
    printBoard('s');
    //set the cell picked by player to a tile for the next player
    tile = specialMove(PLAYER1);
    while(trueWinner() == ' ') //checks if theres a winner
    {
        tileWin = tileWinner(tile);
        
        if(checkSpace(tile) == 0 || tileWin != ' ') 
        //instructions will only occur if theres no space to play or if a player has won in that tile
        {
            //print board as it is 
            printBoard('S');
            //player2 gets to pick what tile to play in. The cell they play in will now correspond to the tile for player1
            tile = specialMove(PLAYER2);
            tileWin = tileWinner(tile);
            if(trueWinner() != ' ')
            {
                //if trueWinner returns a character thats not an empty space, break from the while loop
                break;
            }
        }
        else
        {
            //print board and show which tile to play in if player2 has to play on a tile with no victor
            printBoard(tile);
            tileWin = tileWinner(tile);
            //force player2 to play on tile corresponding to player1's cell
            printTileWinner(tile, tileWin); 
            tile = playerMove(tile, PLAYER2);
        }
        //print tile winner if there is even a winner for that tile
        tileWin = tileWinner(tile);
        printTileWinner(tile, tileWin); 
        if(checkSpace(tile) == 0 || tileWin != ' ')
        {
            printBoard('s');
            tile = specialMove(PLAYER1);
            tileWin = tileWinner(tile);
            if(trueWinner() != ' ')
            {
                break;
            }
            
        }
        else
        {   printBoard(tile);
            tileWin = tileWinner(tile);
            printTileWinner(tile, tileWin); 
            tile = playerMove(tile, PLAYER1);
        }
    }
    printBoard('S');
    printTrueWinner(trueWinner());
    return 0;
}




//checks free spaces per major tile and returns number of freespaces
int checkSpace(char tile)
{
    int space = 9;
    switch(tile)
    {
       case 'A':
            if(AA != ' ')
            {
                space--;
            }
            if(AB != ' ')
            {
                space--;
            }
            if(AC != ' ')
            {
                space--;
            }
            if(AD != ' ')
            {
                space--;
            }
            if(AE != ' ')
            {
                space--;
            }
            if(AF != ' ')
            {
                space--;
            }
            if(AG != ' ')
            {
                space--;
            }
            if(AH != ' ')
            {
                space--;
            }
            if(AI != ' ')
            {
                space--;
            }
            break;
        case 'B':
            if(BA != ' ')
            {
                space--;
            }
            if(BB != ' ')
            {
                space--;
            }
            if(BC != ' ')
            {
                space--;
            }
            if(BD != ' ')
            {
                space--;
            }
            if(BE != ' ')
            {
                space--;
            }
            if(BF != ' ')
            {
                space--;
            }
            if(BG != ' ')
            {
                space--;
            }
            if(BH != ' ')
            {
                space--;
            }
            if(BI != ' ')
            {
                space--;
            }
            break;
        case 'c':
            if(CA != ' ')
            {
                space--;
            }
            if(CB != ' ')
            {
                space--;
            }
            if(CC != ' ')
            {
                space--;
            }
            if(CD != ' ')
            {
                space--;
            }
            if(CE != ' ')
            {
                space--;
            }
            if(CF != ' ')
            {
                space--;
            }
            if(CG != ' ')
            {
                space--;
            }
            if(CH != ' ')
            {
                space--;
            }
            if(CI != ' ')
            {
                space--;
            }
            break;
        case 'D': 
            if(DA != ' ')
            {
                space--;
            }
            if(DB != ' ')
            {
                space--;
            }
            if(DC != ' ')
            {
                space--;
            }
            if(DD != ' ')
            {
                space--;
            }
            if(DE != ' ')
            {
                space--;
            }
            if(DF != ' ')
            {
                space--;
            }
            if(DG != ' ')
            {
                space--;
            }
            if(DH != ' ')
            {
                space--;
            }
            if(DI != ' ')
            {
                space--;
            }
            break;
        case 'E': 
            if(EA != ' ')
            {
                space--;
            }
            if(EB != ' ')
            {
                space--;
            }
            if(EC != ' ')
            {
                space--;
            }
            if(ED != ' ')
            {
                space--;
            }
            if(EE != ' ')
            {
                space--;
            }
            if(EF != ' ')
            {
                space--;
            }
            if(EG != ' ')
            {
                space--;
            }
            if(EH != ' ')
            {
                space--;
            }
            if(EI != ' ')
            {
                space--;
            }
            break;
        case 'F':
            if(FA != ' ')
            {
                space--;
            }
            if(FB != ' ')
            {
                space--;
            }
            if(FC != ' ')
            {
                space--;
            }
            if(FD != ' ')
            {
                space--;
            }
            if(FE != ' ')
            {
                space--;
            }
            if(FF != ' ')
            {
                space--;
            }
            if(FG != ' ')
            {
                space--;
            }
            if(FH != ' ')
            {
                space--;
            }
            if(FI != ' ')
            {
                space--;
            }
            break;
        case 'G':
            if(GA != ' ')
            {
                space--;
            }
            if(GB != ' ')
            {
                space--;
            }
            if(GC != ' ')
            {
                space--;
            }
            if(GD != ' ')
            {
                space--;
            }
            if(GE != ' ')
            {
                space--;
            }
            if(GF != ' ')
            {
                space--;
            }
            if(GG != ' ')
            {
                space--;
            }
            if(GH != ' ')
            {
                space--;
            }
            if(GI != ' ')
            {
                space--;
            }
            break;
        case 'H':
            if(HA != ' ')
            {
                space--;
            }
            if(HB != ' ')
            {
                space--;
            }
            if(HC != ' ')
            {
                space--;
            }
            if(HD != ' ')
            {
                space--;
            }
            if(HE != ' ')
            {
                space--;
            }
            if(HF != ' ')
            {
                space--;
            }
            if(HG != ' ')
            {
                space--;
            }
            if(HH != ' ')
            {
                space--;
            }
            if(HI != ' ')
            {
                space--;
            }
            break; 
        case 'I':
            if(IA != ' ')
            {
                space--;
            }
            if(IB != ' ')
            {
                space--;
            }
            if(IC != ' ')
            {
                space--;
            }
            if(ID != ' ')
            {
                space--;
            }
            if(IE != ' ')
            {
                space--;
            }
            if(IF != ' ')
            {
                space--;
            }
            if(IG != ' ')
            {
                space--;
            }
            if(IH != ' ')
            {
                space--;
            }
            if(II != ' ')
            {
                space--;
            }
            break;
    }
    return space;
}

//declares who won in the major tile and returns what character they use
char tileWinner(char tile)
{
    switch(tile)
    {
        case 'A':
            //rows
            if(AA == AB && AA == AC && AA != ' ')
            {
                A = AA;
                return A;
            }
            if(AD == AE && AD == AF && AD != ' ')
            {
                A = AD;
                return A;
            }
            if(AG == AH && AG == AI && AG != ' ')
            {
                A = AG;
                return A;
            }
            //columns
            if(AA == AD && AA == AG && AA != ' ')
            {
                A = AA;
                return A;
            }
            if(AB == AE && AB == AH)
            {
                A = AB;
                return A;
            }
            if(AC == AF && AC == AI && AC != ' ')
            {
                A = AC;
                return A;
            }
            //diagonals
            if(AA == AE && AA == AI && AA != ' ')
            {
                A = AA;
                return A;
            }
            if(AC == AE && AC == AG && AC != ' ')
            {
                A = AC;
                return A;
            }
            break;

        case 'B':
            //rows
            if(BA == BB && BA == BC && BA != ' ')
            {
                B = BA;
                return B;
            }
            if(BD == BE && BD == BF && BD != ' ')
            {
                B = BD;
                return B;
            }
            if(BG == BH && BG == BI && BG != ' ')
            {
                B = BG;
                return B;
            }
            //columns
            if(BA == BD && BA == BG && BA != ' ')
            {
                B = BA;
                return B;
            }
            if(BB == AE && BB == BH && BB != ' ')
            {
                B = BB;
                return B;
            }
            if(BC == BF && BC == BI && BC != ' ')
            {
                B = BC;
                return B;
            }
            //diagonals
            if(BA == BE && BA == BI && BA != ' ')
            {
                B = BA;
                return B;
            }
            if(BC == BE && BC == BG && BC != ' ')
            {
                B = BC;
                return B;
            }
            break;
        case 'C':
            //rows
            if(CA == CB && CA == CC && CA != ' ')
            {
                C = CA;
                return C;
            }
            if(CD == CE && CD == CF && CD != ' ')
            {
                C = CD;
                return C;
            }
            if(CG == CH && CG == CI && CG != ' ')
            {
                C = CC;
                return A;
            }
            //columns
            if(CA == CD && CA == CG && CA != ' ')
            {
                C = CA;
                return C;
            }
            if(CB == CE && CB == CH && CB!= ' ')
            {
                C = CB;
                return C;
            }
            if(CC == CF && CC == CI && CC != ' ')
            {
                C = CC;
                return C;
            }
            //diagonals
            if(CA == CE && CA == CI && CA != ' ')
            {
                C = CA;
                return C;
            }
            if(CC == CE && CC == CG && CC != ' ')
            {
                C = CC;
                return C;
            }
            break;
        case 'D':
            //rows
            if(DA == DB && DA == DC && DA != ' ')
            {
                D = DA;
                return D;
            }
            if(DD == DE && DD == DF && DD != ' ')
            {
                D = DD;
                return D;
            }
            if(DG == DH && DG == DI && DI != ' ')
            {
                D = DG;
                return A;
            }
            //columns
            if(DA == DD && DA == DG && DA != ' ')
            {
                D = DA;
                return D;
            }
            if(DB == DE && DB == DH && DB != ' ')
            {
                D = DB;
                return D;
            }
            if(DC == DF && DC == DI && DC != ' ')
            {
                D = DC;
                return D;
            }
            //diagonals
            if(DA == DE && DA == DI && DA != ' ')
            {
                D = DA;
                return D;
            }
            if(DC == DE && DC == DG && DC != ' ')
            {
                D = DC;
                return D;
            }
            break;
        case 'E':
            //rows
            if(EA == EB && EA == EC && EA != ' ')
            {
                E = EA;
                return E;
            }
            if(ED == EE && ED == EF && ED != ' ')
            {
                E = ED;
                return E;
            }
            if(EG == EH && EG == EI && EG != ' ')
            {
                E = EG;
                return E;
            }
            //columns
            if(EA == ED && EA == EG && EA != ' ')
            {
                E = EA;
                return E;
            }
            if(EB == EE && EB == EH && EB != ' ')
            {
                E = EB;
                return E;
            }
            if(EC == EF && EC == EI && EC != ' ')
            {
                E = EC;
                return E;
            }
            //diagonals
            if(EA == EE && EA == EI && EA != ' ')
            {
                E = EA;
                return E;
            }
            if(EC == EE && EC == EG && EC != ' ')
            {
                E = EC;
                return E;
            }
            break;
        case 'F':
        //rows
            if(FA == FB && FA == FC && FA != ' ')
            {
                F = FA;
                return F;
            }
            if(FD == FE && FD == FF && FD != ' ')
            {
                F = FD;
                return F;
            }
            if(FG == FH && FG == FI && FI != ' ')
            {
                F = FG;
                return F;
            }
            //columns
            if(FA == FD && FA == FG && FA != ' ')
            {
                A = AA;
                return A;
            }
            if(FB == FE && FB == FH && FB != ' ')
            {
                F = FB;
                return F;
            }
            if(FC == FF && FC == FI && FC != ' ')
            {
                F = FC;
                return F;
            }
            //diagonals
            if(FA == FE && FA == FI && FA != ' ')
            {
                F = FA;
                return F;
            }
            if(FC == FE && FC == FG && FC != ' ')
            {
                F = FC;
                return A;
            }
            break;
        case 'G':
        //rows
            if(GA == GB && GA == GC && GA != ' ')
            {
                G = GA;
                return G;
            }
            if(GD == GE && GD == GF && GD != ' ')
            {
                G = GD;
                return G;
            }
            if(GG == GH && GG == GI && GI != ' ')
            {
                G = GG;
                return G;
            }
            //columns
            if(GA == GD && GA == GG && GA != ' ')
            {
                G = GA;
                return G;
            }
            if(GB == GE && GB == GH && GB != ' ')
            {
                G = GB;
                return A;
            }
            if(GC == GF && GC == GI && GC != ' ')
            {
                G = GC;
                return G;
            }
            //diagonals
            if(GA == GE && GA == GI && GA != ' ')
            {
                G = GA;
                return G;
            }
            if(GC == GE && GC == GG && GC != ' ')
            {
                G = GC;
                return G;
            }
            break;
        case 'H':
            //rows
            if(HA == HB && HA == HC && HA != ' ')
            {
                H = HA;
                return H;
            }
            if(HD == HE && HD == HF && HD != ' ')
            {
                H = HD;
                return H;
            }
            if(HG == HH && HG == HI && HI != ' ')
            {
                H = HG;
                return H;
            }
            //columns
            if(HA == HD && HA == HG && HA != ' ')
            {
                H = HA;
                return H;
            }
            if(HB == HE && HB == HH && HB != ' ')
            {
                H = HB;
                return H;
            }
            if(HC == HF && HC == HI && HC != ' ')
            {
                H = HC;
                return H;
            }
            //diagonals
            if(HA == HE && HA == HI && HA != ' ')
            {
                H = HA;
                return H;
            }
            if(HC == HE && HC == HG && HC != ' ')
            {
                H = HC;
                return H;
            }
            break;
        case 'I':
            //rows
            if(IA == IB && IA == IC && IA != ' ')
            {
                I = IA;
                return I;
            }
            if(ID == IE && ID == IF && ID != ' ')
            {
                I = ID;
                return I;
            }
            if(IG == IH && IG == II && II != ' ')
            {
                I = IG;
                return I;
            }
            //columns
            if(IA == ID && IA == IG && IA != ' ')
            {
                I = IA;
                return I;
            }
            if(IB == IE && IB == IH && IB != ' ')
            {
                I = IB;
                return I;
            }
            if(IC == IF && IC == II && IC != ' ')
            {
                I = IC;
                return I;
            }
            //diagonals
            if(IA == IE && IA == II && IA != ' ')
            {
                I = IA;
                return I;
            }
            if(IC == IE && IC == IG && IC != ' ')
            {
                I = IC;
                return I;
            }
            break;
    }
    if(checkSpace(tile) == 0)
    {
        switch(tile)
        {
            case 'A':
                A = '-';
                return A;
                break;
            case 'B':
                B = '-';
                return B;
                break;
            case 'C':
                C = '-';
                return C;
                break;
            case 'D':
                D = '-';
                return D;
                break;
            case 'E':
                E = '-';
                return E;
                break;
            case 'F':
                F = '-';
                return F;
                break;
            case 'G':
                G = '-';
                return G;
                break;
            case 'H':
                H = '-';
                return H;
                break;
            case 'I':
                I = '-';
                return I;
                break;
        }
    }
    else
    {
        return ' ';
    }
    return ' ';
}

//checks who won the whole game and returns the character of the winner
char trueWinner()
{
    //rows
    if(A == B && A == C && A != ' ')
    {
        return A;
    }
    else if(D == E && D == F && D != ' ')
    {
        return D;
    }
    else if(G == H && G == I && G != ' ')
    {
        return G;
    }

    //columns

    if(A == D && A == G && A != ' ')
    {
        return A;
    }
    else if(B == E && B == H && B != ' ')
    {
        return B;
    }
    else if(C == F && C == I && C != ' ')
    {
        return C;
    }

    //diagonals

    if(A == E && A == I && A != ' ')
    {
        return A;
    }
    else if(C == E && C == G)
    {
        return C;
    }
    if(checkBigSpaces() == 0)
    {
        return '-';
    }
    return ' ';
}

//primts the board
void printBoard(char tile)
{
    switch(tile)
    {
        case 'S':
    
            printf("\n %c | %c | %c [] %c | %c | %c [] %c | %c | %c \n", AA, AB, AC, BA, BB, BC, CA, CB, CC);
            printf("-------------------------------------");
            printf("\n %c | %c | %c [] %c | %c | %c [] %c | %c | %c \n", AD, AE, AF, BD, BE, BF, CD, CE, CF);
            printf("-------------------------------------");
            printf("\n %c | %c | %c [] %c | %c | %c [] %c | %c | %c \n", AG, AH, AI, BG, BH, BI, CG, CH, CI);
            printf("===========  ===========  ===========");
            printf("\n %c | %c | %c [] %c | %c | %c [] %c | %c | %c \n", DA, DB, DC, EA, EB, EC, FA, FB, FC);
            printf("-------------------------------------");
            printf("\n %c | %c | %c [] %c | %c | %c [] %c | %c | %c \n", DD, DE, DF, ED, EE, EF, FD, FE, FF);
            printf("-------------------------------------");
            printf("\n %c | %c | %c [] %c | %c | %c [] %c | %c | %c \n", DG, DH, DI, EG, EH, EI, FG, FH, FI);
            printf("===========  ===========  ===========");
            printf("\n %c | %c | %c [] %c | %c | %c [] %c | %c | %c \n", GA, GB, GC, HA, HB, HC, IA, IB, IC);
            printf("-------------------------------------");
            printf("\n %c | %c | %c [] %c | %c | %c [] %c | %c | %c \n", GD, GE, GF, HD, HE, HF, ID, IE, IF);
            printf("-------------------------------------");
            printf("\n %c | %c | %c [] %c | %c | %c [] %c | %c | %c \n", GG, GH, GI, HG, HH, HI, IG, IH, II);
            printf("\n");
        default: 
            dotSpaces(tile);
            printf("\n %c | %c | %c [] %c | %c | %c [] %c | %c | %c \n", AA, AB, AC, BA, BB, BC, CA, CB, CC);
            printf("-------------------------------------");
            printf("\n %c | %c | %c [] %c | %c | %c [] %c | %c | %c \n", AD, AE, AF, BD, BE, BF, CD, CE, CF);
            printf("-------------------------------------");
            printf("\n %c | %c | %c [] %c | %c | %c [] %c | %c | %c \n", AG, AH, AI, BG, BH, BI, CG, CH, CI);
            printf("===========  ===========  ===========");
            printf("\n %c | %c | %c [] %c | %c | %c [] %c | %c | %c \n", DA, DB, DC, EA, EB, EC, FA, FB, FC);
            printf("-------------------------------------");
            printf("\n %c | %c | %c [] %c | %c | %c [] %c | %c | %c \n", DD, DE, DF, ED, EE, EF, FD, FE, FF);
            printf("-------------------------------------");
            printf("\n %c | %c | %c [] %c | %c | %c [] %c | %c | %c \n", DG, DH, DI, EG, EH, EI, FG, FH, FI);
            printf("===========  ===========  ===========");
            printf("\n %c | %c | %c [] %c | %c | %c [] %c | %c | %c \n", GA, GB, GC, HA, HB, HC, IA, IB, IC);
            printf("-------------------------------------");
            printf("\n %c | %c | %c [] %c | %c | %c [] %c | %c | %c \n", GD, GE, GF, HD, HE, HF, ID, IE, IF);
            printf("-------------------------------------");
            printf("\n %c | %c | %c [] %c | %c | %c [] %c | %c | %c \n", GG, GH, GI, HG, HH, HI, IG, IH, II);
            printf("\n");
            revertSpaces(tile); 
    }

}

//replaces empty spaces with dots on the next major tile
void dotSpaces(char tile)
{
    switch(tile)
    {
        case 'A':
            if(AA == ' ')
            {
                AA = '-';
            }
            if(AB == ' ')
            {
                AB = '-';
            }
            if(AC == ' ')
            {
                AC = '-';
            }
            if(AD == ' ')
            {
                AD = '-';
            }
            if(AE == ' ')
            {
                AE = '-';
            }
            if(AF == ' ')
            {
                AF = '-';
            }
            if(AG == ' ')
            {
                AG = '-';
            }
            if(AH == ' ')
            {
                AH = '-';
            }
            if(AI == ' ')
            {
                AI = '-';
            }
            break;
        case 'B':
            if(BA == ' ')
            {
                BA = '-';
            }
            if(BB == ' ')
            {
                BB = '-';
            }
            if(BC == ' ')
            {
                BC = '-';
            }
            if(BD == ' ')
            {
                BD = '-';
            }
            if(BE == ' ')
            {
                BE = '-';
            }
            if(BF == ' ')
            {
                BF = '-';
            }
            if(BG == ' ')
            {
                BG = '-';
            }
            if(BH == ' ')
            {
                BH = '-';
            }
            if(BI == ' ')
            {
                BI = '-';
            }
            break;
        case 'C':
            if(CA == ' ')
            {
                CA = '-';
            }
            if(CB == ' ')
            {
                CB = '-';
            }
            if(CC == ' ')
            {
                CC = '-';
            }
            if(CD == ' ')
            {
                CD = '-';
            }
            if(CE == ' ')
            {
                CE = '-';
            }
            if(CF == ' ')
            {
                CF = '-';
            }
            if(CG == ' ')
            {
                CG = '-';
            }
            if(CH == ' ')
            {
                CH = '-';
            }
            if(CI == ' ')
            {
                CI = '-';
            }
            break;
        case 'D': 
            if(DA == ' ')
            {
                DA = '-';
            }
            if(DB == ' ')
            {
                DB = '-';
            }
            if(DC == ' ')
            {
                DC = '-';
            }
            if(DD == ' ')
            {
                DD = '-';
            }
            if(DE == ' ')
            {
                DE = '-';
            }
            if(DF == ' ')
            {
                DF = '-';
            }
            if(DG == ' ')
            {
                DG = '-';
            }
            if(DH == ' ')
            {
                DH = '-';
            }
            if(DI == ' ')
            {
                DI = '-';
            }
            break;
        case 'E': 
            if(EA == ' ')
            {
                EA = '-';
            }
            if(EB == ' ')
            {
                EB = '-';
            }
            if(EC == ' ')
            {
                EC = '-';
            }
            if(ED == ' ')
            {
                ED = '-';
            }
            if(EE == ' ')
            {
                EE = '-';
            }
            if(EF == ' ')
            {
                EF = '-';
            }
            if(EG == ' ')
            {
                EG = '-';
            }
            if(EH == ' ')
            {
                EH = '-';
            }
            if(EI == ' ')
            {
                EI = '-';
            }
            break;
        case 'F':
            if(FA == ' ')
            {
                FA = '-';
            }
            if(FB == ' ')
            {
                FB = '-';
            }
            if(FC == ' ')
            {
                FC = '-';
            }
            if(FD == ' ')
            {
                FD = '-';
            }
            if(FE == ' ')
            {
                FE = '-';
            }
            if(FF == ' ')
            {
                FF = '-';
            }
            if(FG == ' ')
            {
                FG = '-';
            }
            if(FH == ' ')
            {
                FH = '-';
            }
            if(FI == ' ')
            {
                FI = '-';
            }
            break;
        case 'G':
            if(GA == ' ')
            {
                GA = '-';
            }
            if(GB == ' ')
            {
                GB = '-';
            }
            if(GC == ' ')
            {
                GC = '-';
            }
            if(GD == ' ')
            {
                GD = '-';
            }
            if(GE == ' ')
            {
                GE = '-';
            }
            if(GF == ' ')
            {
                GF = '-';
            }
            if(GG == ' ')
            {
                GG = '-';
            }
            if(GH == ' ')
            {
                GH = '-';
            }
            if(GI == ' ')
            {
                GI = '-';
            }
            break;
        case 'H':
            if(HA == ' ')
            {
                HA = '-';
            }
            if(HB == ' ')
            {
                HB = '-';
            }
            if(HC == ' ')
            {
                HC = '-';
            }
            if(HD == ' ')
            {
                HD = '-';
            }
            if(HE == ' ')
            {
                HE = '-';
            }
            if(HF == ' ')
            {
                HF = '-';
            }
            if(HG == ' ')
            {
                HG = '-';
            }
            if(HH == ' ')
            {
                HH = '-';
            }
            if(HI == ' ')
            {
                HI = '-';
            }
            break; 
        case 'I':
            if(IA == ' ')
            {
                IA = '-';
            }
            if(IB == ' ')
            {
                IB = '-';
            }
            if(IC == ' ')
            {
                IC ='-';
            }
            if(ID == ' ')
            {
                ID = '-';
            }
            if(IE == ' ')
            {
                IE = '-';
            }
            if(IF == ' ')
            {
                IF = '-';
            }
            if(IG == ' ')
            {
                IG = '-';
            }
            if(IH == ' ')
            {
                IH = '-';
            }
            if(II == ' ')
            {
                II = '-';
            }
            break;

    }

}

//reverts dotted spaces back to spac
void revertSpaces(char tile)
{
    switch(tile)
    {
        case 'A':
            if(AA == '-')
            {
                AA = ' ';
            }
            if(AB == '-')
            {
                AB = ' ';
            }
            if(AC == '-')
            {
                AC = ' ';
            }
            if(AD == '-')
            {
                AD = ' ';
            }
            if(AE == '-')
            {
                AE = ' ';
            }
            if(AF == '-')
            {
                AF = ' ';
            }
            if(AG == '-')
            {
                AG = ' ';
            }
            if(AH == '-')
            {
                AH = ' ';
            }
            if(AI == '-')
            {
                AI = ' ';
            }
            break;
        case 'B':
            if(BA == '-')
            {
                BA = ' ';
            }
            if(BB == '-')
            {
                BB = ' ';
            }
            if(BC == '-')
            {
                BC = ' ';
            }
            if(BD == '-')
            {
                BD = ' ';
            }
            if(BE == '-')
            {
                BE = ' ';
            }
            if(BF == '-')
            {
                BF = ' ';
            }
            if(BG == '-')
            {
                BG = ' ';
            }
            if(BH == '-')
            {
                BH = ' ';
            }
            if(BI == '-')
            {
                BI = ' ';
            }
            break;
        case 'C':
            if(CA == '-')
            {
                CA = ' ';
            }
            if(CB == '-')
            {
                CB = ' ';
            }
            if(CC == '-')
            {
                CC = ' ';
            }
            if(CD == '-')
            {
                CD = ' ';
            }
            if(CE == '-')
            {
                CE = ' ';
            }
            if(CF == '-')
            {
                CF = ' ';
            }
            if(CG == '-')
            {
                CG = ' ';
            }
            if(CH == '-')
            {
                CH = ' ';
            }
            if(CI == '-')
            {
                CI = ' ';
            }
            break;
        case 'D': 
            if(DA == '-')
            {
                DA = ' ';
            }
            if(DB == '-')
            {
                DB = ' ';
            }
            if(DC =='-')
            {
                DC = ' ';
            }
            if(DD == '-')
            {
                DD = ' ';
            }
            if(DE == '-')
            {
                DE = ' ';
            }
            if(DF == '-')
            {
                DF = ' ';
            }
            if(DG == '-')
            {
                DG = ' ';
            }
            if(DH == '-')
            {
                DH = ' ';
            }
            if(DI == '-')
            {
                DI = ' ';
            }
            break;
        case 'E': 
            if(EA == '-')
            {
                EA = ' ';
            }
            if(EB == '-')
            {
                EB = ' ';
            }
            if(EC == '-')
            {
                EC = ' ';
            }
            if(ED == '-')
            {
                ED = ' ';
            }
            if(EE == '-')
            {
                EE = ' ';
            }
            if(EF == '-')
            {
                EF = ' ';
            }
            if(EG == '-')
            {
                EG = ' ';
            }
            if(EH == '-')
            {
                EH = ' ';
            }
            if(EI == '-')
            {
                EI = ' ';
            }
            break;
        case 'F':
            if(FA == '-')
            {
                FA = ' ';
            }
            if(FB == '-')
            {
                FB = ' ';
            }
            if(FC == '-')
            {
                FC = ' ';
            }
            if(FD == '-')
            {
                FD = ' ';
            }
            if(FE == '-')
            {
                FE = ' ';
            }
            if(FF == '-')
            {
                FF = ' ';
            }
            if(FG == '-')
            {
                FG = ' ';
            }
            if(FH == '-')
            {
                FH = ' ';
            }
            if(FI == '-')
            {
                FI = ' ';
            }
            break;
        case 'G':
            if(GA == '-')
            {
                GA = ' ';
            }
            if(GB == '-')
            {
                GB = ' ';
            }
            if(GC == '-')
            {
                GC = ' ';
            }
            if(GD == '-')
            {
                GD = ' ';
            }
            if(GE == '-')
            {
                GE = ' ';
            }
            if(GF == '-')
            {
                GF = ' ';
            }
            if(GG == '-')
            {
                GG = ' ';
            }
            if(GH == '-')
            {
                GH = ' ';
            }
            if(GI == '-')
            {
                GI = ' ';
            }
            break;
        case 'H':
            if(HA == '-')
            {
                HA = ' ';
            }
            if(HB == '-')
            {
                HB = ' ';
            }
            if(HC == '-')
            {
                HC = ' ';
            }
            if(HD == '-')
            {
                HD = ' ';
            }
            if(HE == '-')
            {
                HE = ' ';
            }
            if(HF == '-')
            {
                HF = ' ';
            }
            if(HG == '-')
            {
                HG = ' ';
            }
            if(HH == '-')
            {
                HH = ' ';
            }
            if(HI == '-')
            {
                HI = ' ';
            }
            break; 
        case 'I':
            if(IA == '-')
            {
                IA = ' ';
            }
            if(IB == '-')
            {
                IB = ' ';
            }
            if(IC == '-')
            {
                IC = ' ';
            }
            if(ID == '-')
            {
                ID = ' ';
            }
            if(IE == '-')
            {
                IE = ' ';
            }
            if(IF == '-')
            {
                IF = ' ';
            }
            if(IG == '-')
            {
                IG = ' ';
            }
            if(IH == '-')
            {
                IH = ' ';
            }
            if(II == '-')
            {
                II = ' ';
            }
            break;

    }
}

//prints tile into symbol of tile winner
void printTileWinner(char tile, char winner)
{
    switch(tile)
    {
        case 'A':
            switch(winner)
            {
                case 'X':
                    AA = AC = AE = AG= AI = 'X';
                    AB = AD=AF=AH =' ';
                    break;
                case 'O':
                    AA = AB = AC  =AD= AF = AG = AH = AI = 'O';
                    AE = ' '; 
                    break;
                case '-':
                    AA = AB = AC = AD = AF = AG = AH = I = ' ';
                    AE = '-'; 
                    break;
            }
            break;
        case 'B':
            switch(winner)
            {
                case 'X':
                    BA = BC = BE = BG = BI = 'X';
                    BB = BD = BF = BH =' ';
                    break;
                case 'O':
                    BA = BB = BC = BD = BF = BG = BH = BI = 'O';
                    BE = ' '; 
                    break;
                case '-':
                    BA = BB = BC = BD = BF = BG = BH = BI = ' ';
                    BE = 'X'; 
                    break;
            }
            break;
        case 'C':
            switch(winner)
            {
                case 'X':
                    CA =CC = CE = CG = CI = 'X';
                    CB = CD = CF = CH =' ';
                    break;
                case 'O':
                    CA = CB = CC = CD = CF = CG = CH = CI = 'O';
                    CE = ' '; 
                    break;
                case '-':
                    CA = CB = CC = CD = CF = CG = CH = CI = ' ';
                    CE = '-'; 
                    break;
            }
            break;
        case 'D':
            switch(winner)
            {
                case 'X':
                    DA =DC = DE = DG = DI = 'X';
                    DB = DD = DF = DH =' ';
                    break;
                case 'O':
                    DA = DB = DC = DD = DF = DG = DH = DI = 'O';
                    DE = ' '; 
                    break;
                case '-':
                    DA = DB = DC = DD = DF = DG = DH = DI = ' ';
                    DE = '-'; 
                    break;
            }
            break;
        case 'E':
            switch(winner)
            {
                case 'X':
                    EA = EC = EE = EG = EI = 'X';
                    EB = ED = EF = EH =' ';
                    break;
                case 'O':
                    EA = EB = EC = ED = EF = EG = EH = EI = 'O';
                    EE = ' '; 
                    break;
                case '-':
                    EA = EB = EC = ED = EF = EG = EH = EI = ' ';
                    EE = '-'; 
                    break;
            }
            break;
        case 'F':
            switch(winner)
            {
                case 'X':
                    FA = FC = FE = FG = FI = 'X';
                    FB = FD = FF = FH =' ';
                    break;
                case 'O':
                    FA = FB = FC = FD = FF = FG = FH = FI = 'O';
                    FE = ' '; 
                    break;
                case '-':
                    FA = FB = FC = FD = FF = FG = FH = FI = ' ';
                    FE = '-'; 
                    break;
            }
            break;
        case 'G':
            switch(winner)
            {
                case 'X':
                    GA = GC =  GE = GG = GI = 'X';
                    GB = GD = GF = GH =' ';
                    break;
                case 'O':
                    GA = GB = GC = GD = GF = GG = GH = GI = 'O';
                    GE = ' '; 
                    break;
                case '-':
                    GA = GB = GC = GD = GF = GG = GH = GI = ' ';
                    GE = '-'; 
                    break;
            }
            break;
        case 'H':
            switch(winner)
            {
                case 'X':
                    HA = HC = HE = HG = HI = 'X';
                    HB = HD = HF = HH =' ';
                    break;
                case 'O':
                    HA = HB = HC = HD = HF = HG = HH = HI = 'O';
                    HE = ' '; 
                    break;
                case '-':
                    HA = HB = HC = HD = HF = HG = HH = HI = ' ';
                    HE = '-'; 
                    break;
            }
            break;
        case 'I':
            switch(winner)
            {
                case 'X':
                    IA = IC = IE = IG = II = 'X';
                    IB = ID = IF = IH =' ';
                    break;
                case 'O':
                    IA = IB = IC = ID = IF = IG = IH = II = 'O';
                    IE = ' '; 
                    break;
                case '-':
                    IA = IB = IC = ID = IF = IG = IH = II = ' ';
                    IE = '-'; 
                    break;
            }
            break;
    }
}

//occurs on first move or when player is forced on tile with a winner
char specialMove(char player)
{
    char x, Y;
    int valid = 0;
    do
    {
        printf("PLAYER %c!!! Pick a large tile (double lines): ", player);
        scanf(" %c", &x);
        if((x == 'A' && A != ' ') || (x == 'B' && B != ' ') || (x == 'C' && C != ' ') || (x == 'D' && D != ' ') || (x == 'E' && E != ' ') || (x == 'F' && F != ' ') || (x == 'G' && G != ' ') || (x == 'H' && H != ' ') || (x == 'I' && I != ' '))
        {
            printf("Invalid move!\n");
        }
        else if(x < 65 || x > 73)
        {
            printf("Invalid Move! Pick from A-I!\n");
        }
        else
        {
            printf("\nPick a cell inside tile %c: ",x);
            scanf(" %c", &Y);
            if(Y < 65 || Y >73)
            {
                printf("Invalid Move! Pick from A-I!\n");
            }
            else
            {
                switch (x)
                {
                    case 'A':
                        if((Y == 'A' && AA != ' ') || (Y == 'B' && AB != ' ') || (Y == 'C' && AC != ' ') || (Y == 'D' && AD != ' ') || (Y == 'E' && AE != ' ') || (Y == 'F' && AF != ' ') || (Y == 'G' && AG != ' ') || (Y == 'H' && AH != ' ') || (Y == 'I' && AI != ' '))
                        {
                            printf("Invalid Move\n");
                        }
                        else
                        {
                            switch(Y)
                            {
                                case 'A':
                                    AA = player;
                                    break;
                                case 'B':
                                    AB = player;
                                    break;
                                case 'C':
                                    AC = player;
                                    break;
                                case 'D':
                                    AD = player;
                                    break;
                                case 'E':
                                    AE = player;
                                    break;
                                case 'F':
                                    AF = player;
                                    break;
                                case 'G':
                                    AG = player;
                                    break;
                                case 'H':
                                    AH = player;
                                    break;
                                case 'I':               
                                    AI = player;
                                    break;
                                default:
                                    printf("Invalid Move!\n");
                                   
                            }
                            valid++;
                        }
                        break;
                    case 'B':
                        if((Y == 'A' && BA != ' ') || (Y == 'B' && BB != ' ') || (Y == 'C' && BC != ' ') || (Y == 'D' && BD != ' ') || (Y == 'E' && BE != ' ') || (Y == 'F' && BF != ' ') || (Y == 'G' && BG != ' ') || (Y == 'H' && BH != ' ') || (Y == 'I' && BI != ' '))
                        {
                            printf("Invalid Move\n");
                        }
                        else
                        {
                            switch(Y)
                            {
                                case 'A':
                                    BA = player;
                                    break;
                                case 'B':
                                    BB = player;
                                    break;
                                case 'C':
                                    BC = player;
                                    break;
                                case 'D':
                                    BD = player;
                                    break;
                                case 'E':
                                    BE = player;
                                    break;                            
                                case 'F':
                                    BF = player;
                                    break;
                                case 'G':
                                    BG = player;
                                    break;
                                case 'H':
                                    BH = player;
                                    break;
                                case 'I':               
                                    BI = player;
                                    break;
                                default:
                                    printf("Invalid Move!\n");
                                    
                            }
                            valid++;
                        }
                        break;
                    case 'C':
                        if((Y == 'A' && CA != ' ') || (Y == 'B' && CB != ' ') || (Y == 'C' && CC != ' ') || (Y == 'D' && CD != ' ') || (Y == 'E' && CE != ' ') || (Y == 'F' && CF != ' ') || (Y == 'G' && CG != ' ') || (Y == 'H' && CH != ' ') || (Y == 'I' && CI != ' '))
                        {
                            printf("Invalid Move\n");
                        }
                        else
                        {
                            switch(Y)
                            {
                                case 'A':
                                    CA = player;
                                    break;
                                case 'B':
                                    CB = player;                                
                                    break;
                                case 'C':
                                    CC = player;
                                    break;
                                case 'D':
                                    CD = player;
                                    break;
                                case 'E':
                                    CE = player;
                                    break;
                                case 'F':
                                    CF = player;
                                    break;
                            case 'G':
                                    CG = player;
                                    break;
                                case 'H':
                                    CH = player;
                                    break;
                                case 'I':               
                                    CI = player;
                                    break;
                                default:
                                    printf("Invalid Move!\n");
                                    
                            }
                            valid++;
                        }
                        break;
                    case 'D':
                        if((Y == 'A' && DA != ' ') || (Y == 'B' && DB != ' ') || (Y == 'C' && DC != ' ') || (Y == 'D' && DD != ' ') || (Y == 'E' && DE != ' ') || (Y == 'F' && DF != ' ') || (Y == 'G' && DG != ' ') || (Y == 'H' && DH != ' ') || (Y == 'I' && DI != ' '))
                        {
                            printf("Invalid Move\n");
                        }
                        else
                        {
                            switch(Y)
                            {
                                case 'A':
                                    DA = player;
                                    break;
                                case 'B':
                                    DB = player;
                                    break;
                                case 'C':
                                    DC = player;
                                    break;
                                case 'D':
                                    DD = player;
                                    break;
                                case 'E':
                                    DE = player;
                                    break;
                                case 'F':
                                    DF = player;
                                    break;
                                case 'G':
                                    DG = player;
                                    break;
                                case 'H':
                                    DH = player;
                                    break;
                                case 'I':               
                                    DI = player;
                                    break;
                                default:
                                    printf("Invalid Move!\n");
                                    
                            }
                            valid++;
                        }
                        break;
                        
                    case 'E':
                        if((Y == 'A' && EA != ' ') || (Y == 'B' && EB != ' ') || (Y == 'C' && EC != ' ') || (Y == 'D' && ED != ' ') || (Y == 'E' && EE != ' ') || (Y == 'F' && EF != ' ') || (Y == 'G' && EG != ' ') || (Y == 'H' && EH != ' ') || (Y == 'I' && EI != ' '))
                        {
                            printf("Invalid Move\n");
                        }
                        else
                        {
                            switch(Y)
                            {
                                case 'A':
                                    EA = player;
                                    break;
                                case 'B':
                                    EB = player;
                                    break;
                                case 'C':
                                    EC = player;
                                    break;
                                case 'D':
                                    ED = player;
                                    break;
                                case 'E':
                                    EE = player;
                                    break;
                                case 'F':
                                    EF = player;
                                break;
                                case 'G':
                                    EG = player;
                                    break;
                                case 'H':
                                    EH = player;
                                    break;
                                case 'I':               
                                    EI = player;
                                    break;
                                default:
                                    printf("Invalid Move!\n");
                                    
                            }
                            valid++;
                        }
                        break;
                    case 'F':
                        if((Y == 'A' && FA != ' ') || (Y == 'B' && FB != ' ') || (Y == 'C' && FC != ' ') || (Y == 'D' && FD != ' ') || (Y == 'E' && FE != ' ') || (Y == 'F' && FF != ' ') || (Y == 'G' && FG != ' ') || (Y == 'H' && FH != ' ') || (Y == 'I' && FI != ' '))
                        {
                            printf("Invalid Move\n");
                        }
                        else
                        {
                            switch(Y)
                            {
                                case 'A':
                                    FA = player;
                                    break;
                                case 'B':
                                    FB = player;
                                    break;
                                case 'C':
                                    FC = player;
                                    break;
                                case 'D':
                                    FD = player;
                                    break;
                                case 'E':
                                    FE = player;
                                    break;
                                case 'F':
                                    FF = player;
                                    break;
                                case 'G':
                                    FG = player;
                                    break;
                                case 'H':
                                    FH = player;
                                    break;
                                case 'I':               
                                    FI = player;
                                    break;
                                default:
                                    printf("Invalid Move!\n");
                                    
                            }
                            valid++;
                        }
                        break;
                    case 'G':
                        if((Y == 'A' && GA != ' ') || (Y == 'B' && GB != ' ') || (Y == 'C' && GC != ' ') || (Y == 'D' && GD != ' ') || (Y == 'E' && GE != ' ') || (Y == 'F' && GF != ' ') || (Y == 'G' && GG != ' ') || (Y == 'H' && GH != ' ') || (Y == 'I' && GI != ' '))
                        {
                            printf("Invalid Move\n");
                        }
                        else
                        {
                            switch(Y)
                            {
                                case 'A':
                                    GA = player;
                                    break;
                                case 'B':
                                    GB = player;
                                    break;
                                case 'C':
                                    GC = player;
                                    break;
                                case 'D':
                                    GD = player;
                                    break;
                                case 'E':
                                    GE = player;
                                    break;
                                case 'F':
                                    GF = player;
                                    break;
                                case 'G':
                                    GG = player;
                                    break;
                                case 'H':
                                    GH = player;
                                    break;
                                case 'I':               
                                    GI = player;
                                    break;
                                default:
                                    printf("Invalid Move!\n");
                                    
                            }
                            valid++;
                        }
                        break;
                    case 'H':
                        if((Y == 'A' && HA != ' ') || (Y == 'B' && HB != ' ') || (Y == 'C' && HC != ' ') || (Y == 'D' && HD != ' ') || (Y == 'E' && HE != ' ') || (Y == 'F' && HF != ' ') || (Y == 'G' && HG != ' ') || (Y == 'H' && HH != ' ') || (Y == 'I' && HI != ' '))
                        {
                            printf("Invalid Move\n");
                        }
                        else
                        {
                            switch(Y)
                            {
                                case 'A':
                                    HA = player;
                                    break;
                                case 'B':
                                    HB = player;
                                    break;
                                case 'C':
                                    HC = player;
                                    break;
                                case 'D':
                                    HD = player;
                                    break;
                                case 'E':
                                    HE = player;
                                    break;
                                case 'F':
                                    HF = player;
                                    break;
                                case 'G':
                                    HG = player;
                                    break;
                                case 'H':
                                    HH = player;
                                    break;
                                case 'I':               
                                    HI = player;
                                    break;
                                default:
                                    printf("Invalid Move!\n");
                                    
                            }
                            valid++;
                            
                        }
                        break;
                    case 'I':
                        if((Y == 'A' && IA != ' ') || (Y == 'B' && IB != ' ') || (Y == 'C' && IC != ' ') || (Y == 'D' && ID != ' ') || (Y == 'E' && IE != ' ') || (Y == 'F' && IF != ' ') || (Y == 'G' && IG != ' ') || (Y == 'H' && IH != ' ') || (Y == 'I' && II != ' '))
                        {
                            printf("Invalid Move\n");
                        }
                        else
                        {
                            switch(Y)
                            {
                                case 'A':
                                    IA = player;
                                    break;
                                case 'B':
                                    IB = player;
                                    break;
                                case 'C':
                                    IC = player;
                                    break;
                                case 'D':
                                    ID = player;
                                    break;
                                case 'E':
                                    IE = player;
                                    break;
                                case 'F':
                                    IF = player;
                                    break;
                                case 'G':
                                    IG = player;
                                    break;
                                case 'H':
                                    IH = player;
                                    break;
                                case 'I':               
                                    II = player;
                                    break;
                                default:
                                    printf("Invalid Move!\n");
                                    
                            }
                            valid++;
                            
                        }
                        break;

                }
                if(valid > 0)
                {
                    break;
                }
            }
        }
    }while(1);

    printTileWinner(x, tileWinner(x));
    return Y;
}

//Move of player 
char playerMove(char tile, char player)
{
    //initialize values
    char Y;
    int valid = 0;
    //post-check of a while loop
    do
    {
        printf("PLAYER %c!!! Pick a cell inside tile %c: ", player, tile);
        scanf(" %c", &Y);
        if(Y < 65 || Y > 73)
        {
            printf("Invalid Move! Pick from A-I!\n");
        }
        else
        {
            switch (tile)
            {
                case 'A':
                    if((Y == 'A' && AA != ' ') || (Y == 'B' && AB != ' ') || (Y == 'C' && AC != ' ') || (Y == 'D' && AD != ' ') || (Y == 'E' && AE != ' ') || (Y == 'F' && AF != ' ') || (Y == 'G' && AG != ' ') || (Y == 'H' && AH != ' ') || (Y == 'I' && AI != ' '))
                    {
                        printf("Invalid Move\n");
                    }
                    else
                    {
                        switch(Y)
                        {
                            case 'A':
                                AA = player;
                                break;
                            case 'B':
                                AB = player;
                                break;
                            case 'C':
                                AC = player;
                                break;
                            case 'D':
                                AD = player;
                                break;
                            case 'E':
                                AE = player;
                                break;
                            case 'F':
                                AF = player;
                                break;
                            case 'G':
                                AG = player;
                                break;
                            case 'H':
                                AH = player;
                                break;
                            case 'I':               
                                AI = player;
                                break;
                            }
                            valid++;
                            
                        }
                        break;
                case 'B':
                    if((Y == 'A' && BA != ' ') || (Y == 'B' && BB != ' ') || (Y == 'C' && BC != ' ') || (Y == 'D' && BD != ' ') || (Y == 'E' && BE != ' ') || (Y == 'F' && BF != ' ') || (Y == 'G' && BG != ' ') || (Y == 'H' && BH != ' ') || (Y == 'I' && BI != ' '))
                    {
                        printf("Invalid Move\n");
                    }
                    else
                    {
                        switch(Y)
                        {
                            case 'A':
                                BA = player;
                                break;
                            case 'B':
                                BB = player;
                                break;
                            case 'C':
                                BC = player;
                                break;
                            case 'D':
                                BD = player;
                                break;
                            case 'E':
                                BE = player;
                                break;                            
                            case 'F':
                                B = player;
                                break;
                            case 'G':
                                BG = player;
                                break;
                            case 'H':
                                BH = player;
                                break;
                            case 'I':               
                                BI = player;
                                break;
                        }
                        
                        valid++;
                    }
                    break;
                case 'C':
                    if((Y == 'A' && CA != ' ') || (Y == 'B' && CB != ' ') || (Y == 'C' && CC != ' ') || (Y == 'D' && CD != ' ') || (Y == 'E' && CE != ' ') || (Y == 'F' && CF != ' ') || (Y == 'G' && CG != ' ') || (Y == 'H' && CH != ' ') || (Y == 'I' && CI != ' '))
                    {
                        printf("Invalid Move\n");
                    }
                    else
                    {
                        switch(Y)
                        {
                            case 'A':
                                CA = player;
                                break;
                            case 'B':
                                CB = player;                                
                                break;
                            case 'C':
                                CC = player;
                                break;
                            case 'D':
                                CD = player;
                                break;
                            case 'E':
                                CE = player;
                                break;
                            case 'F':
                                CF = player;
                                break;
                            case 'G':
                                CG = player;
                                break;
                            case 'H':
                                CH = player;
                                    break;
                            case 'I':               
                                CI = player;
                                break;
                        }
                        valid++;
                        
                    }
                    break;
                case 'D':
                    if((Y == 'A' && BA != ' ') || (Y == 'B' && BB != ' ') || (Y == 'C' && BC != ' ') || (Y == 'D' && BD != ' ') || (Y == 'E' && BE != ' ') || (Y == 'F' && BF != ' ') || (Y == 'G' && BG != ' ') || (Y == 'H' && BH != ' ') || (Y == 'I' && BI != ' '))
                    {
                        printf("Invalid Move\n");
                    }
                    else
                    {
                        switch(Y)
                        {
                            case 'A':
                                DA = player;
                                break;
                            case 'B':
                                DB = player;
                                break;
                            case 'C':
                                DC = player;
                                break;
                            case 'D':
                                DD = player;
                                break;
                            case 'E':
                                DE = player;
                                break;
                            case 'F':
                                DF = player;
                                break;
                            case 'G':
                                DG = player;
                                break;
                            case 'H':
                                DH = player;
                                break;
                            case 'I':               
                                DI = player;
                                break;
                        }
                        valid++;
                        
                    }
                    break;
                case 'E':
                    if((Y == 'A' && EA != ' ') || (Y == 'B' && EB != ' ') || (Y == 'C' && EC != ' ') || (Y == 'D' && ED != ' ') || (Y == 'E' && EE != ' ') || (Y == 'F' && EF != ' ') || (Y == 'G' && EG != ' ') || (Y == 'H' && EH != ' ') || (Y == 'I' && EI != ' '))
                    {
                        printf("Invalid Move\n");
                    }
                    else
                    {
                        switch(Y)
                        {
                            case 'A':
                                EA = player;
                                break;
                            case 'B':
                                EB = player;
                                break;
                            case 'C':
                                EC = player;
                                break;
                            case 'D':
                                ED = player;
                                break;
                            case 'E':
                                EE = player;
                                break;
                            case 'F':
                                EF = player;
                                break;
                            case 'G':
                                EG = player;
                                break;
                            case 'H':
                                EH = player;
                                break;
                                case 'I':               
                                EI = player;
                                break;
                        }
                        valid++;
                        
                    }
                    break;
                case 'F':
                    if((Y == 'A' && FA != ' ') || (Y == 'B' && FB != ' ') || (Y == 'C' && FC != ' ') || (Y == 'D' && FD != ' ') || (Y == 'E' && FE != ' ') || (Y == 'F' && FF != ' ') || (Y == 'G' && FG != ' ') || (Y == 'H' && FH != ' ') || (Y == 'I' && FI != ' '))
                    {
                        printf("Invalid Move\n");
                    }
                    else
                    {
                        switch(Y)
                        {
                            case 'A':
                                FA = player;
                                break;
                            case 'B':
                                FB = player;
                                break;
                            case 'C':
                                FC = player;
                                break;
                            case 'D':
                                FD = player;
                                break;
                            case 'E':
                                    FE = player;
                                break;
                            case 'F':
                                FF = player;
                                break;
                            case 'G':
                                FG = player;
                                break;
                            case 'H':
                                FH = player;
                                break;
                            case 'I':               
                                FI = player;
                                break;
                        }
                        valid++;
                        
                    }
                    break;
                case 'G':
                    if((Y == 'A' && GA != ' ') || (Y == 'B' && GB != ' ') || (Y == 'C' && GC != ' ') || (Y == 'D' && GD != ' ') || (Y == 'E' && GE != ' ') || (Y == 'F' && GF != ' ') || (Y == 'G' && GG != ' ') || (Y == 'H' && GH != ' ') || (Y == 'I' && GI != ' '))
                    {
                        printf("Invalid Move\n");
                    }
                    else
                    {
                        switch(Y)
                        {
                            case 'A':
                                GA = player;
                                break;
                            case 'B':
                                GB = player;
                                break;
                            case 'C':
                                GC = player;
                                break;
                            case 'D':
                                GD = player;
                                break;
                            case 'E':
                                GE = player;
                                break;
                            case 'F':
                                GF = player;
                                break;
                            case 'G':
                                GG = player;
                                break;
                            case 'H':
                                GH = player;
                                break;
                            case 'I':               
                                GI = player;
                                break;
                        }
                        valid++;
                        
                    }
                    break;
                case 'H':
                    if((Y == 'A' && HA != ' ') || (Y == 'B' && HB != ' ') || (Y == 'C' && HC != ' ') || (Y == 'D' && HD != ' ') || (Y == 'E' && HE != ' ') || (Y == 'F' && HF != ' ') || (Y == 'G' && HG != ' ') || (Y == 'H' && HH != ' ') || (Y == 'I' && HI != ' '))
                    {
                        printf("Invalid Move\n");
                    }
                    else
                    {
                        switch(Y)
                            {
                            case 'A':
                                HA = player;
                                break;
                            case 'B':
                                HB = player;
                                break;
                            case 'C':
                                HC = player;
                                break;
                            case 'D':
                                HD = player;
                                break;
                            case 'E':
                                HE = player;
                                break;
                            case 'F':
                                HF = player;
                                break;
                            case 'G':
                                HG = player;
                                break;
                            case 'H':
                                HH = player;
                                break;
                            case 'I':               
                                HI = player;
                                break;
                        }
                        valid++;
                        
                    }
                    break;
                case 'I':
                    if((Y == 'A' && IA != ' ') || (Y == 'B' && IB != ' ') || (Y == 'C' && IC != ' ') || (Y == 'D' && ID != ' ') || (Y == 'E' && IE != ' ') || (Y == 'F' && IF != ' ') || (Y == 'G' && IG != ' ') || (Y == 'H' && IH != ' ') || (Y == 'I' && II != ' '))
                    {
                        printf("Invalid Move\n");
                    }
                    else
                    {
                        switch(Y)
                        {
                            case 'A':
                                IA = player;
                                break;
                            case 'B':
                                IB = player;
                                break;
                                case 'C':
                            IC = player;
                                    break;
                            case 'D':
                                ID = player;
                                break;
                            case 'E':
                                IE = player;
                                break;
                            case 'F':
                                IF = player;
                                break;
                            case 'G':
                                IG = player;
                                break;
                            case 'H':
                                IH = player;
                                break;
                            case 'I':               
                                II = player;
                                break;
                        }
                        valid++;
                        
                    }
                    break;
            }
            if(valid > 0)
            {
                break;
            }
        }
    }while(1);
    printTileWinner(tile, tileWinner(tile));
    return Y;
    
}

//resets the whole board
void resetBoard()
{
    //set all big and small tiles to an empty space
    A = AA = AB = AC = AD = AE = AF = AG = AH = AI = ' ';
    B = BA = BB = BC = BD = BE = BF = BG = BH = BI = ' ';
    C = CA = CB = CC = CD = CE = CF = CG = CH = CI = ' ';
    D = DA = DB = DC = DD = DE = DF = DG = DH = DI = ' ';
    E = EA = EB = EC = ED = EE = EF = EG = EH = EI = ' ';
    F = FA = FB = FC = FD = FE = FF = FG = FH = FI = ' ';
    G = GA = GB = GC = GD = GE = GF = GG = GH = GI = ' ';
    H = HA = HB = HC = HD = HE = HF = HG = HH = HI = ' ';
    I = IA = IB = IC = ID = IE = IF = IG = IH = II = ' ';
}
//Print's the overall winner
void printTrueWinner(char trueWinner)
{
    char winner = trueWinner;
    if(winner == 'X')
    {
        printf("X WON THE MATCH!");
    }
    else if(winner == 'O')
    {
        printf("O WON THE MATCH!");
    }
    else if(winner == '-')
    {
        printf("IT'S A TIE!");
    }
}
//Checks spaces for the big tiles
int checkBigSpaces()
{
    int spaces = 9;
    //checks each big tile. If tile is occupied, subtract 1 from spaces
    if(A != ' ')
    {
        spaces--;
    }
    else if(B != ' ')
    {
        spaces--;
    }
    else if(C != ' ')
    {
        spaces--;
    }
    else if(D != ' ')
    {
        spaces--;
    }
    else if(E != ' ')
    {
        spaces--;
    }
    else if(F != ' ')
    {
        spaces--;
    }
    else if(G != ' ')
    {
        spaces--;
    }
    else if(H != ' ')
    {
        spaces--;
    }
    else if(I != ' ')
    {
        spaces--;
    }
    return spaces;
}