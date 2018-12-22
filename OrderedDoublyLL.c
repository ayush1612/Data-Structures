#include <stdio.h>
#include <stdlib.h>
struct node
{ int data;
 struct node *llink;
 struct node *rlink;
};
struct node *ptr, *start=NULL, *temp;
void insert()
{
 temp=(struct node*)malloc(sizeof(struct node)); // newnode creation
 printf("Data -->");
 scanf("%d",&temp->data);
 temp->rlink=NULL;
 temp->llink=NULL;
 if (start == NULL)
 {
 start = temp;
 }
 else
 { ptr=start;
 if (temp->data < start ->data) // if the new node is to be inserted before the
start node
 {
 temp->rlink = start;
 start ->llink=temp;
 start = temp;
 }
 else
 {
 while (ptr->rlink != NULL && ptr->data < temp ->data ) // traverse till we meet an element greater than the newnode
 ptr=ptr->rlink;
 if (ptr -> rlink == NULL && ptr->data < temp ->data ) // end of list but the newnode to be inserted could be after or before th last node
 {
 ptr->rlink=temp;
 temp->llink=ptr;
 }
 else // solves the insertion of node is greater than newnode
 {
 temp->llink=ptr->llink;
 temp->rlink=ptr;
 ptr->llink->rlink = temp;
 ptr->llink=temp;
 }
 }
 }
}
void display()
{
 ptr=start;
 while (ptr != NULL)
 {
 printf("%d", ptr->data);
 ptr = ptr->rlink;
 }
}
void main()
{ int ch;
 while (1)
 {
 printf("1: insert 2: display");
 scanf("%d", &ch);
 switch(ch)
 {
 case 1: insert();
 break;
 case 2: display();
 break;
 case 3: exit(0);
 }
 }
}
