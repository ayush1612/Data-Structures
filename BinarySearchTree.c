#include<stdio.h>
struct node
{
	struct node *lchild;
	int data;
	struct node *rchild;
};

struct node *root=NULL,*temp,*parent=NULL,*curr;

void create()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data\n");
	scanf("%d",&temp->data);
	temp->lchild=NULL;
	temp->rchild=NULL;
	
	if(root==NULL)
		root=temp;
	else
	{
	curr=root;
	while(curr)
	{
		parent=curr;
		if(curr->data==temp->data)
		{
			printf("Node exist\n");
			return;
		}
		else if(curr->data<temp->data)
			curr=curr->rchild;
		else
			curr=curr->lchild;
	}
	if(parent->data<temp->data)
		parent->rchild=temp;
	else
		parent->lchild=temp;
	}
}

void inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		printf("%d-",ptr->data);
		inorder(ptr->rchild);
	}
}

void preorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		printf("%d-",ptr->data);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}

void postorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d-",ptr->data);
	}
}

void main()
{
	int ch;
	while(1)
	{
	   printf("Do you want to add data.Press 1 for yes .Press 2 for no\n");	
	   scanf("%d",&ch);
	   if(ch==2)
	   	break;
	   create();
	}
	printf("Inorder:");
	inorder(root);
	printf("\nPreorder:");
	preorder(root);
	printf("\nPostorder");
	postorder(root);
}
