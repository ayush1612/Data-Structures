#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *right;
	struct node *left;
}node;

int top = -1;
node *stack[40];

void push(node *newnode)
{
	stack[++top]=newnode;
}


node *pop()
{
	return stack[top--];
}

int check(char ch)
{
	if(ch =='+'||ch=='-'||ch=='*'||ch=='/')
		return 1;
	else 
		return 0;
}

int calc(node *newnode)
{
	int p = check(newnode->data);
	if(p==0)
		return newnode->data-48;
	else if(p==1)
		{
			if(newnode->data == '+')
				return calc(newnode->left)+calc(newnode->right);
			if(newnode->data == '-')
				return calc(newnode->left)-calc(newnode->right);
			if(newnode->data == '/')
				return calc(newnode->left)/calc(newnode->right);
			if(newnode->data == '*')
				return calc(newnode->left)*calc(newnode->right);
		}

}

node *operator(char ch)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->right = pop();
	newnode->left = pop();
	newnode->data = ch;
	push(newnode);
}

void operand(char ch)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->right = NULL;
	newnode->left = NULL;
	newnode->data = ch;
	push(newnode);
}

void inorder(node *root)
{
	if(root == NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%c",root->data );
	inorder(root->right);
}

void main()
{
	char postfix[20];

	scanf("%s",postfix);


	for(int i = 0 ; postfix[i]!='\0';i++)
	{
		int p = check(postfix[i]);
		if(p==0)
		{
			operand(postfix[i]);
		}
		else if(p==1)
			operator(postfix[i]);
	}

	int result = calc(stack[top]);

	printf("The result of postfix expression is %d \n",result);
	printf("The inorder traversal of the expression is\n");

	inorder(stack[top]);

	printf("\n");
}
