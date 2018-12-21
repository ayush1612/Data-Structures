#include<stdio.h>
#include<stdlib.h>
#define size 30

char s[size];
int top=-1;

void push(char item)
{
if(top==size-1)
printf("Overflow");
else
s[++top]=item;
}

int is_operator(char item)
{
if(item=='*'||item=='/'||item=='+'||item=='-'||item=='^')
return(1);
else
return(0);
}

int precedence(char item)
{
if(item=='^')
return(4);
else if(item=='/'||item=='*')
return(3);
else if(item=='+'||item=='-')
return(2);
else
return(1);
}

char pop()
{
char item;
item=s[top];
top--;
return(item);
}

void main()
{
char infix[30],postfix[30],a,item;
int i=0,j=0;
printf("Enter the infix expression\n");
gets(infix);
while(infix[i]!='\0')
{
	item=infix[i];
	if(item=='(')
	push(item);
	else if(isalnum(item))
	{
	postfix[j]=item;
	j=j+1;
	}
	else if(is_operator(item)==1)
	{
    	  if(item!='^')
 	  {
		while(top!=-1&&precedence(s[top])>=precedence(item))
		{
		postfix[j]=pop();
		j=j+1;
		}
	   }
	   push(item);
        }
        else if(item==')')
        {
	  while(s[top]!='(')
	  {
		postfix[j]=pop();
		j=j+1;
	  }
	  a=pop();
	}
        i++;
}

while(top!=-1)
postfix[j++]=pop();

postfix[j]='\0';
puts(postfix);

}
