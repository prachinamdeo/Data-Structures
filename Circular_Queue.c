#include <stdio.h>
#include <stdlib.h>
#define n 5
int A[n],rear,front;
void enqueue(int );
void dequeue();
void print();
void main()
{
    int s,x;
    while(1)
    {
        printf("Enter 1 to perform ENQUEUE op.\n");
        printf("Enter 2 to perform DEQUEUE op.\n");
        printf("Enter 3 to perform PRINT op.\n");
        printf("Enter 4 to perform EXIT op.\n");
        scanf("%d",&s);
        switch(s)
        {
            case 1:
                printf("Enter element : ");
                scanf("%d",&x);
                enqueue(x);
            break;
            case 2:
                dequeue();
            break;
            case 3:
                print();
            break;
            case 4:
                exit(0);
            break;
            default:
                printf("Wrong Choice\n");
            break;
        }
    }
}
void enqueue(int x)
{
    if((rear+1)%n == front)
    {
        printf("Queue Full\n");
    }
    else
    {
        A[rear]=x;
        rear=(rear+1)%n;
    }
}
void dequeue()
{
    if(rear == front)
    {
        printf("Queue Empty\n");
    }
    else
    {
        int x;
        x=A[front];
        front=(front+1)%n;
        printf("%d element deleted\n",x);
    }
}
void print()
{
    int i;
    for(i=front;i<rear;i++)
    {
        printf("%d\n",A[i]);
    }
}
