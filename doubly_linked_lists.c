#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev ,*next;
};
struct node *head;
int len;
int length();
void display();
void insertAtBegin();
void insertAtEnd();
void insertAtPosition();
void deleteFromPosition();

void main()
{
    int op;
    while(1)
    {
       printf("1 insert data at beginning\n");
       printf("2 insert data at end\n");
       printf("3 insert data at specific position\n");
       printf("4 delete data from specific position\n");
       printf("5 to get length of the linked list\n");
       printf("6 to display linked list\n");
       printf("7 to quit\n");
       printf("Enter your choice : ");
       scanf("%d",&op);
       switch(op)
       {
        case 1:
        insertAtBegin();
        break;
        case 2:
        insertAtEnd();
        break;
        case 3:
        insertAtPosition();
        break;
        case 4:
        deleteFromPosition();
        break;
        case 5:
        len = length();
        printf("Length of the linked list is %d\n",len);
        break;
        case 6:
        display();
        break;
        case 7:
        exit(0);
        break;
        default:
        printf("Wrong Choice\n");
        break;
       }
    }
}
void insertAtBegin()
{
    int n;
    printf("Enter data you want to insert : ");
    scanf("%d",&n);
    struct node *p;
    p= (struct node*) malloc (sizeof(struct node));
    p->data=n;
    p->prev=NULL;
    p->next=NULL;
    if(head == NULL)
    {
        head=p;
    }
    else
    {
        p->next=head;
        head->prev=p;
        head=p;
    }
}
void insertAtEnd()
{
    int n;
    printf("Enter data you want to insert : ");
    scanf("%d",&n);
    struct node *temp,*p;
    p= (struct node*) malloc (sizeof(struct node));
    temp=head;
    p->data=n;
    p->prev=NULL;
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        p->prev=temp;
        temp->next=p;
    }
}
void insertAtPosition()
{
    int n,pos;
    printf("Enter data you want to insert : ");
    scanf("%d",&n);
    printf("Enter position where you want to insert : ");
    scanf("%d",&pos);
    struct node *temp,*p;
    p= (struct node*) malloc (sizeof(struct node));
    temp=head;
    p->data=n;
    p->prev=NULL;
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
    }
    else
    {
        int i;
        for(i=0;i<pos-2;i++)
        {
            temp=temp->next;
        }
        p->prev=temp;
        p->next=temp->next;
        temp->next->prev=p;
        temp->next=p;
    }
}
void deleteFromPosition()
{
    int pos;
    printf("Enter position from where you want to delete : ");
    scanf("%d",&pos);
    struct node *temp,*q;
    temp=head;
    len=length();
    if(head==NULL)
    {
        printf("No data in linked list to delete\n");
    }
    else if(pos>len || pos == 0 || pos<0 )
    {
        printf("Invalid position\n");
    }
    else if (pos==1)
    {
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
    else if (pos==len)
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->prev->next=NULL;
        free(temp);
    }
    else
    {
        int i;
        for(i=0;i<pos-2;i++)
        {
            temp=temp->next;
        }
        q=temp->next;
        q->next->prev=q->prev;
        temp->next=q->next;
        free(q);
    }
}
int length()
{
    struct node *temp;
    temp=head;
    int count=0;
    while(temp != NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
void display()
{
    struct node *temp;
    temp=head;
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("|<--%d-->|",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}



















