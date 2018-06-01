// Program for conversion of infix to postfix.
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<process.h>
#define Blank ' '
#define Tab '\t'
#define MAX 50

char infix[MAX], postfix[MAX];
long int stack[MAX];
int top=-1;

void push(long int symbol)
{
	if(top > MAX)
	{
		cout<<"Stack overflow\n";
		exit(1);
	}
	else
	{
		top=top+1;
		stack[top] = symbol;
	}
}

long int pop()
{
	if (top == -1 )
	{
		cout<<"Stack underflow \n";
		exit(2);
	}
	else
		return (stack[top--]);
}

int white_space(char symbol)
{
	if( symbol == Blank || symbol == Tab || symbol == '\0')
		return 1;
	else
		return 0;
}

int prec(char symbol )
{
	switch(symbol)
	{
	case '(': return 0;
	case '+':
	case '-': return 1;
	case '*':
	case '/':
	case '%': return 2;
	case '^': return 3;
	}
}

void infix_to_postfix()
{
	int i,p=0,type,precedence,len;
	char next ;
	stack[top]='#';
	len=strlen(infix);
	infix[len]='#';
	for(i=0; infix[i]!='#';i++)
	{

		if( !white_space(infix[i]))
		{
			switch(infix[i])
			{
			case '(':
				push(infix[i]);
				break;

			case ')':
				while((next = pop()) != '(')
					postfix[p++] = next;

				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
				precedence = prec(infix[i]);
				while(stack[top]!='#' && precedence<= prec(stack[top]))
					postfix[p++] = pop();
				push(infix[i]);
				break;
			default: postfix[p++] = infix[i];
			}
		}
	}
	while(stack[top]!='#')
		postfix[p++] = pop();
	postfix[p] = '\0' ;
}

void main()
{
	clrscr();
	long int value;
	char choice='y';
	while(choice == 'y')
	{
		top = 0;
		cout<<"Enter infix : ";
		cin.getline(infix,MAX);
		infix_to_postfix();
		cout<<"Postfix : "<<postfix;getch();
		cout<<"\nWant to continue(y/n) : ";
		cin>>choice;
		cin.ignore();
	}
}

