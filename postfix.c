#include<math.h>
#include<stdio.h>
#include<ctype.h>
#define size 30

int s[size],top=-1;

int is_operand(char item)
{
   if((item>='A'&&item<='Z')||(item>='a'&&item<='z'))
     return(1);
   else 
     return(0);
     }
     
void push(int m)
{
     s[++top]=m;
}

int pop()
{
int m;
m=s[top];
top--;
return(m);
}

void main()
{
  char postfix[30],item;
  int i=0,m,op2,op1,res;
  
  printf("Enter the postfix expression\n");
  gets(postfix);
  
  while(postfix[i]!='\0')
  {
    item=postfix[i];
    if(is_operand(item)==1)
    {
      printf("Enter the value for %c",item);
      scanf("%d",&m);
      push(m);
    }
    else if(isdigit(item))
    push((int)item-48);
    else
    {
      op2=pop();
      op1=pop();
      
      switch(item)
      {
      case '*':
      res=op1*op2;
      push(res);
      break;
      
      case '/':
      res=op1/op2;
      push(res);
      break;
      
      case '+':
      res=op1+op2;
      push(res);
      break;
      
      case '-':
      res=op1-op2;
      push(res);
      break;
      
      case '^':
      res=pow(op1,op2);
      push(res);
     }
    }
    i++;
    }
    res=pop();
    printf("%d",res);
  }
           
