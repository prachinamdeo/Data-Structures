#include<stdio.h>
void insertionSort(int A[],int );
void main()
{
    int i,l,u,n;
    int A[7]={2,6,5,9,1,1,3};
    l=0;
    u=6;
    n=(u-l)+1;
    insertionSort(A,n);
    printf("Sorted array is: ");
    for(i=0;i<n;i++)
    {
        printf("%d",A[i]);
    }
}
void insertionSort(int A[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        j=i+1;
        while(j>0 && A[j]<A[j-1])
        {
            temp=A[j];
            A[j]=A[j-1];
            A[j-1]=temp;
            j--;
        }
    }
}
