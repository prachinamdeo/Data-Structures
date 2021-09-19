#include<stdio.h>
void bubbleSort(int A[],int );
void main()
{
    int i,l,u,n;
    int A[7]={2,6,5,9,1,1,3};
    l=0;
    u=6;
    n=(u-l)+1;
    bubbleSort(A,n);
    printf("Sorted array is: ");
    for(i=0;i<n;i++)
    {
        printf("%d",A[i]);
    }
}
void bubbleSort(int A[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}
