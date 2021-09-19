#include<stdio.h>
#define CAPACITY 100
void s1push(int );
int s1pop();
void s2push(int );
int s2pop();
int isempty(int );
int isfull(int );
void enqueue(int );
void dequeue();
int top1=-1,top2=-1;
int s1[CAPACITY],s2[CAPACITY];
void main()
{
    int s,n;
    while(1)
    {
        printf("1 to perform enqueue op. ");
        printf("2 to perform dequeue op. ");
        printf("3 to exit. ");
        scanf("%d",&s);
        switch(s)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d",&n);
            enqueue(n);
        break;
        case 2:
            dequeue();
        break;
        case 3:
            exit(0);
        break;
        default:
            printf("wrong Choice.\n");
        break;
        }
    }
}
void enqueue(int x)
{
    if (isfull(top1))
    {
        printf("not enqueued.\n");
    }
    else
    {
        s1push(x);
    }
}
void dequeue()
{
    int x,d;
    if (isempty(top1))
    {
        printf("not dequeued.\n");
    }
    else
    {
        while(!isempty(top1))
        {
            x=s1pop();
            s2push(x);
        }
        d=s2pop();
        while(!isempty(top2))
        {
            x=s2pop();
            s1push(x);
        }
        printf("%d removed.\n",d);
    }
}
void s1push(int x)
{
    if(top1==CAPACITY-1)
    {
        printf("not inserted.\n");
    }
    else
    {
        top1++;
        s1[top1]=x;
    }
}
int s1pop()
{
    int x;
    if(top1==-1)
    {
        printf("not removed.\n");
    }
    else
    {
        x=s1[top1];
        top1--;
        return x;
    }
}
void s2push(int x)
{
    if(top2==CAPACITY-1)
    {
        printf("not inserted.\n");
    }
    else
    {
        top2++;
        s2[top2]=x;
    }
}
int s2pop()
{
    int x;
    if(top2==-1)
    {
        printf("not removed.\n");
    }
    else
    {
        x=s2[top2];
        top2--;
        return x;
    }
}
int isempty(int top)
{
    if (top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(int top)
{
    if (top==CAPACITY-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
