#include<stdio.h>
#define CAPACITY 5
int  stack[CAPACITY],top=-1;
int isfull();
int isempty();
int pop();
void push(int );
void peek();
void display();
void main()
{
	int item,op;
	while(1)
	{
		printf("Enter Choice: \n");
		printf("1 Push\n");
		printf("2 Pop\n");
		printf("3 Peep\n");
		printf("4 Display\n");
		printf("5 Exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("Enter data: ");
				scanf("%d",&item);
				push(item);
			break;
			case 2:
				item=pop();
				if(item == 0)
				{
				    printf("Stack is underflow\n");
				}
				else
                {
                    printf("Element popped %d\n",item);
                }
			break;
			case 3:
				peek();
			break;
			case 4:
				display();
			break;
			case 5:
				exit(0);
			break;
			default:
				printf("Wrong Choice :\n");
			break;


		}
	}
}
void display()
{
	if (isempty())
	{
		printf("Stack is empty\n");
	}
	else
	{
		int i;
		for (i=top;i>=0;i-- )
		{
			printf("%d\n",stack[i]);
		}
	}
}
void push(int data)
{
	if (isfull())
	{
		printf("Stack is overflow\n");
	}
	else
	{
		//top=top+1;
		top++;
		stack[top]=data;
		printf("%d pushed\n",data);
	}
}
int pop()
{
	if (isempty())
	{
		return 0;
	}
	else
	{
		/*int n;
		n=stack[top];
		top=top-1;
		return n;*/
		return stack[top--];
	}
}
void peek()
{
	if (isempty())
	{
		printf("Stack is underflow\n");
	}
	else
	{
		printf("Peek Element %d\n",stack[top]);
	}
}
int isfull()
{
	if (top==CAPACITY-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isempty()
{
	if (top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
