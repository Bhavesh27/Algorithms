// Program for conversion of infix to prefix.
#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#define MAX 50
char input[MAX];
char output[MAX];
char stack[MAX];
char *s,*t;
char ch;
int top;
int len;
void push(char num)
{
  if(top==MAX-1)
    cout<<"\nStack is full ";
  else
  {
    top=top+1;
    stack[top]=num;
  }
}
char pop()
{
  if(top== -1)
     return -1;
   else
   {
     char item=stack[top];
     top--;
     return item;
   }
}
void setexpression(char *str)
{
 s=str;
 len=strlen(s);
 *(output+1)='\0';
 t=output;
}
int priority(char c)
{
   switch(c)
   {
     case '+':
     case '-': return 1;
     case '*':
     case '/':
     case '%': return 2;
     case '$':
     case '^': return 3;
     default: return 0;
   }
}
void converttoprefix()
{
  char opr;
  while(*s)
  {
    if(*s==' '||*s=='\t')
    {
      s++; continue;
    }
    if(isdigit(*s)||isalpha(*s))
    {
      while(isdigit(*s)||isalpha(*s))
      {
	*t=*s;
	s++;
	t++;
      }
    }
    if(*s==')')
    {
      push(*s);
      s++;
    }
    if(*s=='*'||*s=='/'||*s=='+'||*s=='-'||*s=='^'||*s=='$')
    {
      if(top!=-1)
      {
	opr=pop();
	while(priority(opr)>priority(*s))
	{
	  *t=opr;
	  t++;
	  opr=pop();
	}
	push(opr);
	push(*s);
      }
      else
	push(*s);
      s++;
     }
      if(*s=='(')
      {
	opr=pop();
	while(opr!=')')
	{
	  *t=opr;
	  t++;
	  opr=pop();
	 }
	 s++;
       }
    }
    while(top!=-1)
    {
      opr=pop();
      *t=opr;
      t++;
    }
    t++;
  }
void main()
{
 clrscr();
 top=-1;
 strcpy(output," ");
 strcpy(stack," ");
 len=0;
 cout<<"\nEnter an infix expression ";
 cin.getline(input,MAX);
 setexpression(input);
 strrev(s);
 converttoprefix();
 strrev(output);
 cout<<"\nThe Prefix expression is : ";
 cout<<output;
 getch();
}
