#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *rear,*front;
int len;
int peek();
int length();
void enqueue();
void dequeue();
void traverse();
void main()
{
    int op,x;
    while(1)
    {
        printf("1 to perform enqueue operation\n");
        printf("2 to perform dequeue operation\n");
        printf("3 to display queue\n");
        printf("4 to get length\n");
        printf("5 for peek value\n");
        printf("6 to quit\n");
        printf("Enter your choice: ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            enqueue();
        break;
        case 2:
            dequeue();
        break;
        case 3:
            traverse();
        break;
        case 4:
            len = length();
            printf("Length of queue is %d\n",len);
        break;
        case 5:
            x=peek();
            printf("Peek element is %d",x);
        break;
        case 6:
            exit(0);
        break;
        default:
            printf("Wrong Choice\n");
        break;
        }
    }
}
void enqueue()
{
    int n;
    printf("Enter element you want to enter : ");
    scanf("%d",&n);
    struct node *p;
    p->data=n;
    p->link=NULL;
    p=(struct node*) malloc (sizeof(struct node));
    if (rear == NULL && front==NULL)
    {
        front=rear=p;
    }
    else
    {
        rear->link=p;
        rear=p;
    }
}
void dequeue()
{
    if(rear == NULL && front==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct node *temp;
        temp=front;
        front=front->link;
        printf("%d deleted\n",temp->data);
        free(temp);
    }
}
int peek()
{
    if(rear == NULL && front==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
     return front->data;
    }
}
void traverse()
{
    if(rear == NULL && front==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct node *temp;
        temp=front;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->link;
        }
    }
}
int length()
{
    int c=0;
    struct node *temp;
    temp=front;
    while(temp!=NULL)
    {
        c++;
        temp=temp->link;
    }
    return c;
}
