#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
};

struct node *ptr=NULL,*last=NULL,*temp=NULL;

void insert_beg()
{
temp=(struct node*)malloc(sizeof(struct node*));
printf("Enter the data\n");
scanf("%d",&temp->data);
temp->link=NULL;
if(last==NULL)
{
last=temp;
temp->link=last;
}
else
{
temp->link=last->link;
last->link=temp;
}
}

void insert_end()
{
temp=(struct node*)malloc(sizeof(struct node*));
printf("Enter the data\n");
scanf("%d",&temp->data);
temp->link=NULL;
if(last==NULL)
{
last=temp;
temp->link=last;
}
else
{
temp->link=last->link;
last->link=temp;
last=temp;
}
}

void display()
{
if(last==NULL)
{
printf("List is empty");
}
else
{
ptr=last->link;
while(ptr!=last)
{
printf("%d--> ",ptr->data);
ptr=ptr->link;
}
printf("%d",ptr->data);
}
}

void count_node()
{
int count=0;
if(last==NULL)
{
printf("List is empty\n");
}
else
{
ptr=last->link;
while(ptr!=last)
{
count++;
ptr=ptr->link;
}
printf("No. of nodes=%d\n",(count+1));
}
}
void del_beg()
{
if(last==NULL)
{
printf("List is empty\n");
}
else if(last->link==last)
{
ptr=last;
last=NULL;
free(ptr);
}
else
{
ptr=last->link;
last->link=ptr->link;
free(ptr);
}
}
void del_end()
{
if(last==NULL)
printf("List is empty\n");
else if(last->link==last)
{
ptr=last;
last=NULL;
free(ptr);
}
else
{
ptr=last->link;
while(ptr!=last)
{
temp=ptr;
ptr=ptr->link;
}
temp->link=last->link;
last=temp;
free(ptr);
}
}

void del_loc_based()
{
if(last!=NULL)
{
int count=0,pos;
printf("Enter the position\n");
scanf("%d",&pos);
ptr=last->link;
while(ptr!=last)
{
count++;
ptr=ptr->link;
}
count++;

if(pos==1)
del_beg();
else if(pos>1&&pos<count)
{
int i;
ptr=last->link;
for(i=1;i<pos;i++)
{
temp=ptr;
ptr=ptr->link;
}
temp->link=ptr->link;
free(ptr);
}
else if(pos==count)
del_end();
else
{
printf("Wrong location\n");
}
}
else
printf("List is empty\n");
}

 void location_based()
  {
    int count=0,pos;
    ptr=last->link;
    
    while(ptr!=last)
    {
      count++;
      ptr=ptr->link;
     }
     count++;


     printf("Enter the position of the node\n");
     scanf("%d",&pos);
     
     if(pos==1)
       insert_beg();
       else
       if(pos==count+1)
       insert_end();
       else
       if(pos>1&&pos<=count)
       {
       temp=(struct node*)malloc(sizeof(struct node*));
       printf("Enter the data\n");
       
       scanf("%d",&temp->data);
       temp->link=NULL;
       
       ptr=last->link;
       
       int i;
       for(i=1;i<pos-1;i++)
       {
       ptr=ptr->link;
       }
       
       temp->link=ptr->link;
       ptr->link=temp;
       }
       else
       printf("Invalid Position\n");
     }
void search_node()
 {
 
 int item,flag=0;
 printf("Enter the data to be searched\n");
 scanf("%d",&item);
 
 if(last==NULL)
   printf("List is empty\n");
   
   else
   {
   ptr=last->link;
   while(ptr!=last)
   {
    if(item==ptr->data)
    {
    printf("Item found");
    flag=1;
    break;
    }
    else
    ptr=ptr->link;
    }
    if(last->data==item)
    {
    printf("Item found\n");
    flag=1;
    }
    if(flag==0)
    printf("Item not found");
    }
 }
    
    
void main()
{

  while(1)
       {
       int ch;
       printf("\n1.Insert_end\n2.Insert_beg\n3.Insert at loc\n4.Search node\n5.Display\n6.Count data nodes\n7.Delete_beginning\n8.Delete_end\n9.Delte_at_loc\n10.Exit\n");
       printf("Enter your choice \n");
       scanf("%d",&ch);
       
       switch(ch)
       {
       case 1:insert_end();
       break;
       
       case 2:insert_beg();
       break;
       
       case 3:location_based();
       break;
       
       case 4:search_node();
       break;
       
       case 5:display();
       break;
       
       case 6:count_node();
       break;
       
       case 7:del_beg();
       break;
       
       case 8:
       del_end();
       break;
       
       case 9:
       del_loc_based();
       break;
       
       case 10:
       exit(1);
       
       default:
       printf("Wrong choice");
       
       }
    }
}
