#include <stdio.h>
#include <stdlib.h>

#include "vertShader.h"

#define WIDTH 64
#define HEIGHT 32

int main(){
    vec3 vertices[] = {
        0, 0, 0,
        -0.5, 0, 0.5,
        0.5, -0.3, 1
    };

    int n = sizeof(vertices)/sizeof(vec3);
    vec3 pixels[n];
    vec3 terminal[n];
    char c;
    //convert 
    for(int i = 0; i < n; i++){
        pixels[i] = toPixel(&vertices[i], WIDTH, HEIGHT);
        terminal[i] = toTerminal(&pixels[i], WIDTH, HEIGHT);
    }
    //test if coords convertion works properly
    for(int i = 0; i < n; i++){
        printf("%2f ", vertices[i].x);
        printf("%2f ", vertices[i].y);
        printf("%2f ", vertices[i].z);
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%2f ", pixels[i].x);
        printf("%2f ", pixels[i].y);
        printf("%2f ", pixels[i].z);
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%2f ", terminal[i].x);
        printf("%2f ", terminal[i].y);
        printf("%2f ", terminal[i].z);
    }
    printf("\n");
    do{
        printf("\e[1;1H\e[2J");
        render(terminal, n);
        for(int i = 0; i < n; i++){
            printf("%2f ", terminal[i].x);
            printf("%2f ", terminal[i].y);
            printf("%2f ", terminal[i].z);
        }
        printf("\n");
        if((scanf("%c", &c) == EOF))
            break;
    }while(1);
    

    for(int i = 0; i < n; i++){
        printf("%2f ", terminal[i].x);
        printf("%2f ", terminal[i].y);
        printf("%2f ", terminal[i].z);
    }
    return 0;
    
}