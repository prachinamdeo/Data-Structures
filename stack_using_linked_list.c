#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *head;
int len;
int length();
int pop();
void push();
void traverse();
void main()
{
    int item,op;
    while(1)
    {
        printf("1 push operation\n");
        printf("2 pop operation\n");
        printf("3 display stack\n");
        printf("4 to get length\n");
        printf("5 to quit\n");
        printf("Enter you choice: ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            push();
        break;
        case 2:
            item = pop();
            if (item==0)
            {
                printf("Stack is empty\n");
            }
            else
            {
             printf("Popped item is %d\n",item);
            }
        break;
        case 3:
            traverse();
        break;
        case 4:
            len=length();
            printf("%d\n",len);
        break;
        case 5:
            exit(0);
        break;
        default:
            printf("Wrong choice\n");
        break;
        }
    }
}
void push()
{
    int x;
    printf("Enter data you want to enter : ");
    scanf("%d",&x);
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->link=NULL;
    if (head==NULL)
    {
        head=p;
    }
    else
    {
        p->link=head;
        head=p;
    }
}
int pop()
{
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        int x;
        struct node *temp;
        temp=head;
        head=head->link;
        x=temp->data;
        temp->link=NULL;
        free(temp);
        return x;
    }
}
void traverse()
{
    if(head==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct node *temp;
        temp=head;
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
    temp=head;
    while(temp!=NULL)
    {
        c++;
        temp=temp->link;
    }
    return c;
}





















