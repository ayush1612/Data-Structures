#include<stdio.h>
#include<stdlib.h>
#define size 5

int rear=-1,front=-1,item;
int PQ[size];
void PQinsert()
{
  if(rear==size-1)
  {
    printf("Overflow\n");
  }
  else
  {
   printf("Enter the element");
   scanf("%d",&item);
   if(rear==-1)
   {
    front=rear=0;
    PQ[rear]=item;
   }
   else
   {
    int i,j;
     for(i=front;i<=rear;i++)
     {
      if(PQ[i]>=item)
       {
      for(j=rear;j>=i;j--)
           PQ[j+1]=PQ[j];
          PQ[i]=item;
    rear++;
        return;
     }
    }
    PQ[++rear]=item;
}
}
}
void PQdelete()
{
if(rear==-1)
printf("Underflow\n");
else
{
int ditem=PQ[front];
int i;
for(i=front;i<rear;i++)
PQ[i]=PQ[i+1];
printf("Deleted item :-%d\n",ditem);
}
rear--;
}

void display()
{
if(front==-1)
printf("No elements to be displayed\n");
else
{
int i;
for(i=front;i<=rear;i++)
printf("%d-->",PQ[i]);
}
}
void main()
{
while(1)
{
printf("1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
int ch;
printf("Enter your choice\n");
scanf("%d",&ch);

switch(ch)
{
case 1:
PQinsert();
break;
case 2:
PQdelete();
break;
case 3:
display();
break;
case 4:
exit(0);
}
}
}
