#include <stdio.h>
#include <stdlib.h>

//literally just the properties
typedef struct Node{
    int xpos;
    int ypos;
    struct Node* next;
} Obj;

//just the methods
//constructor
Obj* testConstruct(int x, int y, Obj* p){
    //omg this is literally just oop
    Obj* newObject = (Obj*) malloc(sizeof(Obj));
    newObject->xpos = x;
    newObject->ypos = y;
    newObject->next = p;

    return newObject;

}

void test_setPosition(Obj* p, int x, int y){
    p->xpos = x;
    p->ypos = y;
}