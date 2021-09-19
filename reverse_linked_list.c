#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

struct node* insert(struct node *, int);
struct node * reverse(struct node *);
void print(struct node *);
void main()
{
    struct node *head=NULL;
    head=insert(head,2);
    head=insert(head,6);
    head=insert(head,8);
    head=insert(head,10);
    printf("list\n");
    print(head);
    printf("\n");
    printf("reverse list\n");
    head = reverse(head);
    print(head);
}
struct node* insert(struct node *temp,int n)
{
    struct node *p;
    p=(struct node*) malloc (sizeof(struct node));
    p->data=n;
    p->link=temp;
    temp = p;
    return temp;
}
struct node * reverse(struct node *root)
{
	struct node *current,*prev,*next;
	current=root;
	prev=NULL;
	next=NULL;
	while(current != NULL)
	{
		next=current->link;
		current->link=prev;
		prev=current;
		current = next;
	}
	root = prev;
	return root;


}
void print(struct node *temp)
{
    if(temp == NULL)
    {
        return ;
    }
    printf("%d\t",temp->data);
    print(temp->link);
}
