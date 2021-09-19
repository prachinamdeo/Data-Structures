#include<stdio.h>
void selectionSort(int A[],int );
void main()
{
    int i,l,u,n;
    int A[7]={2,6,5,9 ,1,1,3};
    l=0;
    u=6;
    n=(u-l)+1;
    selectionSort(A,n);
    printf("Sorted array is: ");
    for(i=0;i<n;i++)
    {
        printf("%d",A[i]);
    }
}
void selectionSort(int A[],int n)
{
    int i,j,temp;
    int min,min_index;
    for(i=0;i<n;i++)
    {
        min=A[i];
        min_index=i;
        for(j=i+1;j<n;j++)
        {
            if (A[j]<min)
            {
                min=A[j];
                min_index=j;
            }
        }
        temp=A[min_index];
        A[min_index]=A[i];
        A[i]=temp;
    }
}
