#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int front,rear,item,ditem,Q[SIZE],i,ch;
void INSERT()
{
    if(rear==SIZE-1)
        printf("Overflow!\n");
    else
    {
        printf("Enter the element to be inserted\n");
        scanf("%d",&item);
        if(rear==-1)
        {
            rear=0;
            front=0;
            Q[rear]=item;
        }
        else
        {
            rear++;
            Q[rear]=item;
        }
    }
}
void DELETE()
{
    if(rear==-1)
        printf("Underflow!\n");
    else
    {
        ditem=Q[front];
        printf("The removed element is %d\n",ditem);
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
        front++;
       
    }
}
void DISPLAY()
{
    if(rear==-1)
    printf("Underflow!\n");
    else
    {
    for(i=front;i<=rear;i++)
        printf("%d-->",Q[i]);
    }
}
void main()
{
    while(1)
    {
    printf("1:INSERT\n2:DELETE\n3:DISPLAY\n4:EXIT\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
        {
        case 1:INSERT();
               break;
        case 2:DELETE();
               break;
        case 3:DISPLAY();
               break;
        case 4:exit(0);
        default:printf("Wrong choice\n");
        }
    }
}

