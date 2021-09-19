#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
void insertion(int);
void deletion();
void traverse();
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
void main()
{
    int op,x;
    while(1)
    {
        printf("1 to perform insertion operation\n");
        printf("2 to perform deletion operation\n");
        printf("3 to display \n");
        printf("4 to quit\n");
        printf("Enter your choice: ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("Enter element you want to enter : ");
            scanf("%d",&x);
            insertion(x);
        break;
        case 2:
            printf("Enter element you want to delete : ");
            scanf("%d",&x);
            deletion();
        break;
        case 3:
            traverse();
        break;
        case 4:
            exit(0);
        break;
        default:
            printf("Wrong Choice\n");
        break;
        }
    }
}
void insertion(element)
{
    struct node *temp,*p,*parent;
    temp=root;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=element;
    p->left=NULL;
    p->right=NULL;
    if (root==NULL)
    {
        root=p;
    }
    else
    {
        while(temp)
        {
            parent=temp;
            if(element>temp->data)
            {
                temp=temp->right;
            }
            else
            {
                temp=temp->left;
            }
        }
        if (element>parent->data)
        {
            parent->right=p;
        }
        else
        {
            parent->left=p;
        }
    }

}
void deletion(element)
{
    struct node *temp,*parent;
    temp=root;
    while(temp)
        {
            parent=temp;
            if(element>temp->data)
            {
                temp=temp->right;
            }
            else
            {
                temp=temp->left;
            }
        }
    if (temp->left==NULL && temp->right==NULL)
    {
        //deleting leaf node
        if(temp==parent->right)
        {
            parent->right=NULL;
        }
        else
        {
            parent->left=NULL;
        }
    }
    else if(temp->left!=NULL && temp->right!=NULL)
    {
        //deleting node having 2 child
        //least element of right dub tree(or highest element of left sub tree)
        struct node *t1;
        t1=temp->right;
        if (t1->left==NULL && t1->right==NULL)
        {
            temp->data=t1->data;
            temp->right=NULL;
            free(t1);
        }
        if (t1->right==NULL && t1->left==NULL)
        {
            temp->data=t1->data;
            temp->right=t1->right;
            t1->right=NULL;
            free(t1);
        }
    }
    else
    {
        //deleting node having 1 child
        if (parent->right)
        {
            if (temp->left!=NULL)
            {
                if (temp=parent->right)
                {
                    parent->right=temp->left;
                }
            }
            temp->left=NULL;
            free(temp);
            if (temp->right!=NULL)
            {
                if (temp=parent->right)
                {
                    parent->right=temp->right;
                }
            }
            temp->right=NULL;
                free(temp);
        }
        if (parent->left)
        {
            if (temp->left!=NULL)
            {
                if (temp=parent->left)
                {
                    parent->left=temp->left;
                }
            }
            temp->left=NULL;
            free(temp);
            if (temp->right!=NULL)
            {
                if (temp=parent->left)
                {
                    parent->left=temp->right;
                }
            }
            temp->left=NULL;
                free(temp);
        }

    }

}
void traverse()
{
    printf("Inorder traversal : ");
    inorder(root);
    printf("\n");
    printf("Preorder traversal : ");
    preorder(root);
    printf("\n");
    printf("Postorder traversal : ");
    postorder(root);
    printf("\n");
}
void inorder(struct node *t)
{
    if (t->left)
    {
        inorder(t->left);
    }
    printf("%d",t->data);
    if (t->right)
    {
        inorder(t->right);
    }
}
void preorder(struct node *t)
{
    printf("%d",t->data);
     if (t->left)
    {
        inorder(t->left);
    }
    if (t->right)
    {
        inorder(t->right);
    }
}
void postorder(struct node *t)
{
    if (t->left)
    {
        inorder(t->left);
    }
    if (t->right)
    {
        inorder(t->right);
    }
    printf("%d",t->data);
}
