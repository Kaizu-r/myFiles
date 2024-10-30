//PROGRAMMING EXERCISES 6
//JOHN LESTER L. JOLOC
//BSCS 1 - B
//SWITCH ALPHABET SONG

#include<stdio.h>

int main()
{
    char letter;
    printf("ALPHABET SONG\n");
    printf("Enter a letter: ");
    scanf(" %c", &letter);
    
    switch(letter)
    {
        case 'A': case 'a':
            printf(" \t\'%c\' - You're adorable\n", letter);
            break;
        case 'B': case 'b':
            printf(" \t\'%c\' - You're so beautiful\n", letter);
            break;
        case 'C': case 'c':
            printf(" \t\'%c\' - You're a cutie full of charms\n", letter);
            break;
        case 'D': case 'd':
            printf(" \t\'%c\' - You're a darling\n", letter);
            break;
        case 'E': case 'e':
            printf(" \t\'%c\' - You're exciting\n", letter);
            break;
        case 'F': case 'f':
            printf(" \t\'%c\' - You're a feather in my arms\n", letter);
            break;
        case 'G': case 'g':
            printf(" \t\'%c\' - You look good to me\n", letter);
            break;
        case 'H': case 'h':
            printf(" \t\'%c\' - You're so heavenly\n", letter);
            break;
        case 'I': case 'i':
            printf(" \t\'%c\' - You're the one I idolize\n", letter);
            break;
        case 'J': case 'j':
            printf(" \t\'%c\' - We're like Jack and Jill\n", letter);
            break;
        case 'K': case 'k':
            printf(" \t\'%c\' - You're so kissable\n", letter);
            break;
        case 'L': case 'l':
            printf(" \t\'%c\' - Is the love light in your eyes\n", letter);
            break;
        case 'M': case 'm':
        case 'N': case 'n':
        case 'O': case 'o':
        case 'P': case 'p':
            printf(" \t\'%c\' - I could go on all day\n", letter);
            break;
        case 'Q': case 'q':
        case 'R': case 'r':
        case 'S': case 's':
        case 'T': case 't':
            printf(" \t\'%c\' - Alphabetically speaking you're okay\n", letter);
            break;
        case 'U': case 'u':
            printf(" \t\'%c\' - Made my life complete\n", letter);
            break;
        case 'V': case 'v':
            printf(" \t\'%c\' - Means you're very sweet\n", letter);
            break;
        case 'W': case 'w':
        case 'X': case 'x':
        case 'Y': case 'y':
        case 'Z': case 'z':
            printf(" \t\'%c\' - It's fun to wander through\n\t      The alphabet with you\n\t      To tell you what you mean to me\n", letter);
            break;
        default:
            printf(" \t\'%c\' - Invalid character\n", letter);
            break;
    }

    return 0;
}