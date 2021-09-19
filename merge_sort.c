#include<stdio.h>
void mergeSort(int A[],int,int);
void merge(int A[],int,int,int);
void main()
{
    int i,l,u,n;
    int A[7]={2,6,5,9,1,1,3};
    l=0;
    u=6;
    //n=(u-l)+1;
    mergeSort(A,l,u);
    printf("Sorted array is: ");
    for(i=l;i<=u;i++)
    {
        printf("%d",A[i]);
    }
}
void mergeSort(int A[],int l,int u)
{
    int mid;
    if(l<u)
    {
        mid=(l+u)/2;
        mergeSort(A,l,mid);
        mergeSort(A,mid+1,u);
        merge(A,l,mid,u);
    }
}
void merge(int A[],int l,int mid,int u)
{
    int P,Q,R;
    int i,B[7];
    P=l;Q=mid+1;R=l;
    while(P<=mid && Q<=u)
    {
        if (A[P]<A[Q])
        {
            B[R]=A[P];
            P++;R++;
        }
        else
        {
            B[R]=A[Q];
            Q++;R++;
        }
    }
    while(P<=mid)
    {
        B[R]=A[P];
        P++;R++;
    }
    while(Q<=u)
    {
        B[R]=A[Q];
        Q++;R++;
    }

    for(i=l;i<=u;i++)
    {
        A[i]=B[i];
    }
}
