#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int n)
{
    struct node *p;
    p = (struct node*) malloc (sizeof(struct node));
    p->data=n;
    p->left=NULL;
    p->right=NULL;
    return p;
}
struct node* insert(struct node *temp, int n)
{
    if (temp == NULL)
    {
        temp=newNode(n);
        return temp;
    }
    else if (n <= temp->data)
    {
        insert(temp->left,n);
    }
    else
    {
        insert(temp->right,n);
    }
}
void display(struct node *temp)
{
    if(temp!=NULL)
    {
        display(temp->left);
        printf("%d",temp->data);
        display(temp->right);
    }
}
void main()
{
    struct node *root=NULL;
    int x;
    int i = 1;
    while(i)
    {
        printf("\nPress 1 to insert :");
        printf("\nPress 2 to display :");

        scanf("%d",&i);
        if (i==1)
        {
            printf("\nenter data :");
            scanf("%d",&x);
            root=insert(root,x);
        }
        else if(i==2)
        {
            printf("Tree :\n");
            display(root);
        }
        else
        {
            exit(0);
        }

    }

}
