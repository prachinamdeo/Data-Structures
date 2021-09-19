#include<stdio.h>
void makeheap(int [],int );
void heapsort(int [],int );
void main()
{

    int i,l,u,n;
    int A[10]={11,2,9,13,57,25,17,1,90,3};
    l=0;
    u=9;
    n=(u-l)+1;
    makeheap(A,n);
    printf("Before sorting: ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
    printf("\n");
    heapsort(A,n);
    printf("Sorted array is: ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
}
void makeheap(int x[],int n)
{
    int i, val,s, f;
    for(i=1;i<n;i++)
    {
        val=x[i];
        s=i;
        f=(s-1)/2;
        while(s>0 && x[f]<val)
        {
            x[s]=x[f];
            s=f;
            f=(s-1)/2;
        }
        x[s]=val;
    }
}
void heapsort(int x[],int n)
{
    int i, s, f, ivalue;
    for(i=n-1;i>0;i--)
    {
        ivalue=x[i];
        x[i]=x[0];
        f=0;
        if(i==1)
        {
            s=-1;
        }
        else
        {
            s=1;
        }
        if(i>2 && x[2]>x[1])
        {
            s=2;
        }
        while(s>=0 && ivalue<x[s])
        {
            x[f]=x[s];
            f=s;
            s=2*f+1;
            if(s+1<=i-1 && x[s]<x[s+1])
            {
                s++;
            }
            if(s>i-1)
            {
                s=-1;
            }
        }
        x[f]=ivalue;
    }
}
