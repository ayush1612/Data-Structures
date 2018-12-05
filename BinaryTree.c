#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

struct node *root=NULL;
int item;
int is_lchild(struct node *tree)
{
    int ch;
    printf("Do you want to create lchild of %d \n.Enter 1 for YES and 2 for NO\n",tree->data);
    scanf("%d",&ch);

    if(ch==1)
    return(1);
    else
    return(0);
}

int is_rchild(struct node *tree)
{
    int ch;
    printf("Do you want to create rchild of %d \n.Enter 1 for YES and 2 for NO\n",tree->data);
    scanf("%d",&ch);

    if(ch==1)
    return(1);
    else
    return(0);
}

void create(struct node *tree)
{
    struct node* temp;
    if(is_lchild(tree))
    {
        temp=(struct node*)malloc(sizeof(struct node*));
        tree->lchild=temp;
        printf("Enter the data\n");
        scanf("%d",&temp->data);
        create(temp);
    }
    else
    tree->lchild=NULL;

    if(is_rchild(tree))
    {
        temp=(struct node*)malloc(sizeof(struct node*));
        tree->rchild=temp;
        printf("Enter the data\n");
        scanf("%d",&temp->data);
        create(temp);
    }
    else
    tree->rchild=NULL;
}

void inorder(struct node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->lchild);
        printf("%d\t",tree->data);
        inorder(tree->rchild);
    }
}

void preorder(struct node *tree)
{
    if(tree!=NULL)
    {

        printf("%d\t",tree->data);
        preorder(tree->lchild);
        preorder(tree->rchild);
    }
}

void postorder(struct node *tree)
{
    if(tree!=NULL)
    {

        postorder(tree->lchild);
        postorder(tree->rchild);
        printf("%d\t",tree->data);

    }
}

void main()
{
    printf("Create the root node");
    root=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&root->data);
    create(root);
    printf("The inorder traversal is:\n");
    inorder(root);
    printf("\n The preorder traversal is:\n");
    preorder(root);
    printf("\nThe postorder traversal is:\n");
    postorder(root);

}
