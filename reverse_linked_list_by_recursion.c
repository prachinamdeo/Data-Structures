#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *head=NULL;
struct node* insert(struct node *, int);
void recursiveReverse(struct node *);
void print(struct node *);
void main()
{

    head=insert(head,2);
    head=insert(head,6);
    head=insert(head,8);
    head=insert(head,10);
    printf("list\n");
    print(head);
    printf("\n");
    printf("reverse list\n");
    recursiveReverse(head);
    print(head);
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
void recursiveReverse(struct node *p)
{
    if(p->link == NULL)
    {
        head=p;
        return;

    }

    else
    {
        recursiveReverse(p->link);
        struct node *q = p->link;
        q->link = p;
        p->link = NULL;
    }
}
void print(struct node *temp)
{
    if(temp == NULL)
    {
        return ;
    }
    printf("%d\t",temp->data);
    print(temp->link);
}
