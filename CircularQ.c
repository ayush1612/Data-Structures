#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int front=-1,rear=-1,item,ditem,CQ[SIZE],i,ch;
void enQueue()
{
    if(front==(rear+1)%SIZE)
        printf("Overflow!\n");
    else
    {
      
        if(front==-1)
        front=0;
    printf("Enter the element to be inserted\n");
        scanf("%d",&item);
        rear=(rear+1)%SIZE;
        CQ[rear]=item;
    }
        
}
void deQueue()
{
    if(rear==-1)
        printf("Underflow!\n");
    else
    {
        ditem=CQ[front];
        printf("The removed element is %d\n",ditem);
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
        front=(front+1)%SIZE;
        
    }
}
void display()
{
    if(rear==-1)
    printf("Underflow!\n");
    else if(front<=rear)
    {
    for(i=front;i<=rear;i++)
        printf("%d-->",Q[i]);
    }
    else
    {
    for(i=front;i<SIZE;i++)
       printf("%d-->",Q[i]);
    for(i=0;i<=rear;i++)
       printf("%d-->",Q[i]);
    }
}
void main()
{
int ch;
printf("Press 1 for input\nPress 2 to delete\nPress 3 for displaying \nPress 4 for exit\n");
scanf("%d",&ch);
while(1)
{ 
    switch(ch)
    {
    case  1:
    enQueue();
    break;
    
    case 2:
    deQueue();
    break;
    
    case 3:
    display();
    break;
    
    case 4:
    exit(1);
    
    default:
    printf("Wrong choice\n");
    }
  }
  

