#include<stdio.h>
#include<string.h>

typedef struct nd{
    int x;
    struct nd * ptr;
}node;

node *create_list();
void insert(node *curr);
void delete(node * curr);
int main()
{


    return 0;
}

void insert(node *curr)
{
    node * tmp = (node*) malloc(sizeof(node));
    
}
void delete(node * curr);
node *create_list()
{
    int n;
    node *p, *head;
    printf("How many elements?");
    scanf("%d", &n);
    
    for(int k = 0; k<n; k++)
    {
        if(k == 0)
        {
            head = (node*) malloc(sizeof(node));
            p = head;
        }
        else
        {
            p->ptr = (node *) malloc(sizeof(node));
            p = p->ptr;
        }
        scanf("%d", &p->x);
    }
    p->ptr = NULL;
    return head;
}