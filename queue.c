#include<stdio.h>
#define CAPACITY 5
int len;int rear=0,front=0;
int queue[CAPACITY];
int length();
void enqueue();
void dequeue();
void traverse();
void main()
{
    int op;
    while(1)
    {
        printf("1 to perform enqueue operation\n");
        printf("2 to perform dequeue operation\n");
        printf("3 to display queue\n");
        printf("4 to get length\n");
        printf("5 to quit\n");
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
    int data;
    if (rear==CAPACITY)
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("Enter element you want to enter : ");
        scanf("%d",&data);
        queue[rear]=data;
        rear++;
    }
}
void dequeue()
{
    if(rear==0 && front==0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i,ele;
        ele=queue[front];
        for(i=front;i<rear-1;i++)
        {
        queue[i]=queue[i+1];
        }
        rear--;
        printf("%d deleted\n",ele);
    }
}
void traverse()
{
    if(rear==0 && front==0)
    {
        printf("Queue is empty\n");
    }
    else
    {
    int i;
    for(i=front;i<rear;i++)
    {
        printf("%d\n",queue[i]);
    }
    }
}
int length()
{
    int i,c=0;
    for(i=front;i<rear;i++)
    {
        c++;
    }
    return c;
}
