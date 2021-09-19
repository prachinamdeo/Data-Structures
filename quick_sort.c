#include<stdio.h>
void quickSort(int A[],int,int);
int partition(int A[],int,int);
//void swap(int,int);
void main()
{
    int i,l,u,n;
    int A[7]={2,6,5,9,1,1,3};
    l=0;
    u=6;
    //n=(u-l)+1;
    quickSort(A,l,u);
    printf("Sorted array is: ");
    for(i=l;i<=u;i++)
    {
        printf("%d",A[i]);
    }
}
void quickSort(int A[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(A,l,u);
        quickSort(A,l,j-1);
        quickSort(A,j+1,u);
    }

}
int partition(int A[],int l,int u)
{
    int temp;
    int pivot,L,R;
    pivot=l;
    L=l;R=u;
    while(L<R)
    {
        while (A[L]<=A[pivot] && L<=u)
        {
            L++;
        }
        while (A[R]>A[pivot] && R>=l)
        {
            R--;
        }
        if(L<R)
        {
            //swap(A[L],A[R]);
            temp=A[L];
            A[L]=A[R];
            A[R]=temp;
        }
    }

    //swap(pivot,A[R]);
        temp=A[R];
        A[R]=A[pivot];
        A[pivot]=temp;
    return R;
}
