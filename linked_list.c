#include<Stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *head;
int len;
int length();
void display();
void insertAtHead();
void insertAtTail();
void insertAtPosition();
void deleteFromPosition();
void main()
{
    int op;
    while(1)
    {
        printf("1 insert data at head: \n");
        printf("2 insert data at end: \n");
        printf("3 insert after specific position: \n");
        printf("4 delete data from specific position: \n");
        printf("5 to get length of linked list: \n");
        printf("6 to display linked list\n");
        printf("7 to quit\n");
        printf("Enter your choice : ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            insertAtHead();
        break;
        case 2:
            insertAtTail();
        break;
        case 3:
            insertAtPosition();
        break;
        case 4:
            deleteFromPosition();
        break;
        case 5:
            len = length();
            printf("length of the linked list is : %d\n",len);
        break;
        case 6:
            display();
        break;
        case 7:
            exit(0);
        break;
        default:
            printf("Wrong choice\n");
        break;
        }
    }

}
void insertAtHead()
{
    int n;
    struct node *p;
    printf("Enter data you want to insert :");
    scanf("%d",&n);
    p= (struct node*) malloc (sizeof(struct node));
    p->data=n;
    p->link=NULL;
    if(head == NULL)
    {
        head=p;
    }
    else
    {
        p->link=head;
        head=p;
    }
}
void insertAtTail()
{
    int n;
    struct node *p,*temp;
    temp=head;
    p= (struct node*) malloc (sizeof(struct node));
    printf("Enter data you want to insert :");
    scanf("%d",&n);
    p->data=n;
    p->link=NULL;
    if(head == NULL)
    {
        head=p;
    }
    else
    {
        while(temp->link != NULL)
        {
            temp=temp->link;
        }
        temp->link = p;
    }
}
void insertAtPosition()
{
    int n,pos;
    struct node *p,*temp;
    temp=head;
    p= (struct node*) malloc (sizeof(struct node));
    printf("Enter data you want to insert :");
    scanf("%d",&n);
    printf("Enter position where you want to insert :");
    scanf("%d",&pos);
    p->data=n;
    p->link=NULL;
    len = length();
    if(head == NULL)
    {
        head=p;
    }
    else if(pos > len)
    {
        printf("Invalid position\n");
    }
    else
    {
        int i;
        for(i=0;i<pos-2;i++)
        {
            temp=temp->link;
        }
        p->link=temp->link;
        temp->link=p;
    }
}
void deleteFromPosition()
{
    int n,pos;
    struct node *temp,*q;
    temp=head;
    printf("Enter position from where you want to delete :");
    scanf("%d",&pos);
    len = length();
    if(head == NULL)
    {
        printf("No data to delete from linked list\n");
    }
    else if(pos > len || pos == 0 || pos<0 )
    {
        printf("Invalid position\n");
    }
    else if (pos==1)
    {
        head=head->link;
    }
    else
    {
        int i;
        for(i=0;i<pos-2;i++)
        {
            temp=temp->link;
        }
        q=temp->link;
        temp->link=temp->link->link;
        free(q);
    }
}
void display()
{
    if(head == NULL)
    {
        printf("Linked List is empty\n");
    }
    else
    {
        struct node *temp;
        temp=head;
        while(temp != NULL)
        {
            printf("%d -> ",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}
int length()
{
    if(head == NULL)
    {
        return 0;
    }
    else
    {
        int c=0;
        struct node *temp;
        temp=head;
        while(temp != NULL)
        {
            c++;
            temp=temp->link;
        }
        return c;
    }
}
