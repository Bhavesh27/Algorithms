// Evaluation of Postfix expression
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<ctype.h>
int top=-1;
struct postfix
{
  float stack[10];
}S;

void push(char num)
{
  top=top+1;
  S.stack[top]=num;
}

float pop()
{
  float num;
  num=S.stack[top];
  top=top-1;
  return(num);
}
float eval(char suffix[],float data[])
{
 int i=0;
 float op1,op2,res;
 char ch;
 while(suffix[i]!='\0')
 {
   ch=suffix[i];
   if(isalpha(suffix[i]))
   {
     push(data[i]);
   }
   else
   {
     op2=pop();
     op1=pop();
     switch(ch)
     {
       case '+' : push(op1+op2); break;
       case '-' : push(op1-op2); break;
       case '*' : push(op1*op2); break;
       case '/' :push(op1/op2);  break;
       case '^' : push(pow(op1,op2)); break;
      }
    }
 i++;
 }
 res=pop();
 return(res);
}


void main()
{
 int i=0;
 char suffix[20];
 float value[20],result;
 clrscr();
 cout<<"Enter a valid postfix expression\t";
 cin.getline(suffix,20);
 while (suffix[i]!='\0')
 {
   if(isalpha(suffix[i]))
   {
     cout<<"\nEnter the value of "<<suffix[i];
     cin>>value[i];
   }
   i++;
 }
 result=eval(suffix,value);
 cout<<"The result = "<<result;
 getch();
}
