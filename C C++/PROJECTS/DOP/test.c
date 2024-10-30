#include "test.h"

int main(){
    Obj* object1 = testConstruct(10, 20, NULL);
    Obj* object2 = testConstruct(10, 10, NULL);
    printf("Object: %d %d %p\n", object1->xpos, object1->ypos, object1->next);
    printf("Object: %d %d %p\n", object2->xpos, object2->ypos, object2->next);

    test_setPosition(object1, 0, 0);
    test_setPosition(object2, 0, 1);

    printf("Object: %d %d %p\n", object1->xpos, object1->ypos, object1->next);
    printf("Object: %d %d %p\n", object2->xpos, object2->ypos, object2->next);
    
    return 0;
}