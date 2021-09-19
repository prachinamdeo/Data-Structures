#include<stdio.h>
#define CAPACITY 100
int A[CAPACITY],top1=-1,top2=CAPACITY;
void push(int , int );
void pop();
void main()
{
    int s,a,b,x,y;
    while (1)
    {
        printf("enter 1 for push op. ");
        printf("enter 2 for pop op. ");
        printf("enter 3 for exit op. ");
        scanf("%d",&s);
        switch(s)
        {
        case 1:
            printf("Enter elements\n");
            scanf("%d%d",&a,&b);
            push(a,b);
        break;
        case 2:
            pop();
        break;
        case 3:
            exit(0);
        break;
        default:
            printf("Wrong choice.. \n");
        break;
        }
    }
}
void push(int x,int y)
{
    if (top2-top1==1)
    {
        printf("Stack full \n");
    }
    else
    {
        top1=top1+1;
        top2=top2-1;
        A[top1]=x;
        A[top2]=y;
    }
}
void pop()
{
    if (top1==-1 && top2==CAPACITY)
    {
        printf("Stack empty \n");
    }
    else
    {
        int x,y;
        x=A[top1];
        y=A[top2];
        top1=top1-1;
        top2=top2+1;
        printf("Popped elements are %d and %d\n",x,y);
    }
}
