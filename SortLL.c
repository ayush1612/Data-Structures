#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *link;
} NODE;

NODE *head=NULL,*ptr=NULL,*temp=NULL;


void insert_node_end()
{
int item;
  temp=(NODE*)malloc(sizeof(NODE));
  printf("Enter the element");
  scanf("%d",&item);
  temp->data=item;
  temp->link=NULL;
  
  if(head==NULL)
  {
    head=temp;
    }
    else
    {
      ptr=head;
      while(ptr->link!=NULL)
      { 
      ptr=ptr->link;
      }
      
      ptr->link=temp;
    }
 }
   
   
   
    
   void insert_beg()
   {
     temp=(NODE*)malloc(sizeof(NODE));
     printf("Enter the data\n");
     scanf("%d",&temp->data);
     temp->link=NULL;
     
     if(head==NULL)
       head=temp;
       
       else
       {
       temp->link=head;
       head=temp;
       }
     }
     
    
    
        
    void count_node()
    {
    int count=0;
    if(head==NULL)
    printf("List is empty");
    else
    {
    ptr=head;
    while(ptr!=NULL)
    {
    count++;
    ptr=ptr->link;
    }
    printf("Count=%d",count);
    }
    }
    
    
    
    //Display the list
    
    void display()
    {
    if(head==NULL)
    printf("List is empty\n");
    else
    {
    ptr=head;
    while(ptr!=NULL)
    { 
      printf("%d-->",ptr->data);
      ptr=ptr->link;
      }
    }
 }
 
 
 
 void search_node()
 {
 
 int item,flag=0;
 printf("Enter the data to be searched\n");
 scanf("%d",&item);
 
 if(head==NULL)
   printf("List is empty\n");
   
   else
   {
   ptr=head;
   while(ptr!=NULL)
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
    if(flag==0)
    printf("Item not found");
    }
    }
    
    
   
  
  void location_based()
  {
    int count=0,pos;
    ptr=head;
    
    while(ptr!=NULL)
    {
      count++;
      ptr=ptr->link;
     }
     
     printf("Enter the position of the node\n");
     scanf("%d",&pos);
     
     if(pos==1)
       insert_beg();
       else
       if(pos==count+1)
       insert_node_end();
       else
       if(pos>1&&pos<=count)
       {
       temp=(NODE*)malloc(sizeof(NODE));
       printf("Enter the data\n");
       
       scanf("%d",&temp->data);
       temp->link=NULL;
       
       ptr=head;
       
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
   
   void del_beg()
   {
     if(head==NULL)
     printf("Linked List is empty");
     else
     {
     ptr=head;
     head=head->link;
     free(ptr);
     }
     }
     
     void del_end()
     {
       if(head==NULL)
       {
       printf("Linked List is empty\n");
       }
       else
       {
       ptr=head;
       
       while(ptr->link!=NULL)
       {
       temp=ptr;
       ptr=ptr->link;
       }
       
       temp->link=NULL;
       free(ptr);
       }
       }
       
       void del_loc_based()
       {
         int count=0,pos;
         printf("Enter the location\n");
         scanf("%d",&pos);
         ptr=head;
         while(ptr!=NULL)
         {
         count++;
         ptr=ptr->link;
         }
         
         if(pos==1)
         del_beg();
         else if(pos>1&&pos<=count)
         {
         ptr=head;
         int i;
         for(i=1;i<pos;i++)
         {
         temp=ptr;
         ptr=ptr->link;
         }
         temp->link=ptr->link;
         }
         else
         printf("Wrong location\n");
         }
         
         void reverse()
         {
         NODE *rev;
         ptr=head;
         NODE *prev=NULL,*link=NULL;
         while(ptr!=NULL)
         {
         link=ptr->link;
         ptr->link=prev;
         prev=ptr;
         ptr=link;
         }
         head=prev;
         }
         
         void sort()
         {
          NODE *prev=head,*current=head,*temp=NULL;
          int count=0,i,j,temp;
          if(head==NULL)
            printf("List is empty\n");
          else
          {
           ptr=head;
           while(ptr!=NULL)
           {
           count++;
           ptr=ptr->link;
           }
           
           ptr=head;
           for(i=0;i<=count;i++)
           {
             for(j=1;j<=count-i;j++)
             {
             while(ptr->link!=NULL)
             {
             if(ptr->data>ptr->link->data)
             {
               temp=ptr->data;
               ptr->data=ptr->link->data;
               ptr->link->data=temp;
               }
               ptr=ptr->link;
               }
             }
             ptr=head;
         }
         }
         }
         
            
   	    	
   
     void main()
     {
       while(1)
       {
       int ch;
       printf("\n1.Insert_end\n2.Insert_beg\n3.Insert at loc\n4.Search node\n5.Display\n6.Count data nodes\n7.Delete_beginning\n8.Delete_end\n9.Delte_at_loc\n10.Reverse\n11.Sort\n12.Exit\n");
       printf("Enter your choice \n");
       scanf("%d",&ch);
       
       switch(ch)
       {
       case 1:insert_node_end();
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
       reverse();
       break;
       
       case 11:
       sort();
       break;
       
       case 12:exit(1);
       
       
       default:
       printf("Wrong choice");
       
       
    }
    }
    }
    
