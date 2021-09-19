#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

struct node* insert(struct node*, int);
void forwardPrint(struct node*);
void reversePrint(struct node*);
void main()
{
    struct node *head=NULL;
    head=insert(head,2);
    head=insert(head,6);
    head=insert(head,8);
    head=insert(head,10);
    printf("forward traversal\n");
    forwardPrint(head);
    printf("\n");
    printf("recursive travesal\n");
    reversePrint(head);
}
struct node* insert(struct node *temp,int n)
{
    struct node *p;
    p=(struct node*) malloc (sizeof(struct node));
    p->data=n;
    p->link=temp;
    temp = p;
    return temp;
}

void forwardPrint(struct node *temp)
{
    if(temp == NULL)
    {
        return ;
    }
    printf("%d\t",temp->data);
    forwardPrint(temp->link);
}
void reversePrint(struct node *temp)
{
    if(temp == NULL)
    {
        return ;
    }

    reversePrint(temp->link);
    printf("%d\t",temp->data);
}
