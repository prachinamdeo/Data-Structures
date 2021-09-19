#include<stdio.h>
void towerOfHanoi(int, char, char, char );
void main()
{
    int n=3;
    towerOfHanoi(n,'S','H','D');
}
void towerOfHanoi(int n, char source, char helper, char destination )
{
    if (n==1)
    {
        printf("transfer disk %d from %c to %c\n",n,source,destination);
        return;
    }
    towerOfHanoi(n-1, source, destination , helper);
    printf("transfer disk %d from %c to %c\n",n,source,destination);
    towerOfHanoi(n-1, helper, source, destination);
}
