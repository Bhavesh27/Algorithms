// Push and Pop operation on stack (as an array)
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#define SIZE 10
void push(int stack[],int size,int data,int &top)
{
 if(top == size - 1)
  {
    cout<<"\nThe Stack Is Full";
    getch();
    return;
    }
 else
  {
    top= top+1;
    stack[top] = data;
  }
}

void pop(int stack[],int size,int &top)
{
 if(top == -1)
  {
    cout<<"The stack is Empty";
    getch();return;
  }
 else
   {
    cout<<"Deleted element is "<<stack[top]<<endl;
    top--; getch();
   }
}
void traverse(int stack[],int size,int top)
{
 int i;
 if(top == -1)
  {
    cout<<"The Stack is Empty";
    getch();
    return;
  }
 else
  {
    cout<<"Stack element(s) "<<endl;
    for(i=top;i>=0;i--)
     {
      cout<<endl<<stack[i];
     }
     getch();
  }
}

void main()
{
  int Top=-1;
  int stack[SIZE];
  int item;
  int choice;
 do
  {
    clrscr();
    cout<<"1. PUSH "<<endl;
    cout<<"2. POP "<<endl;
    cout<<"3. Display "<<endl;
    cout<<"4. Exit "<<endl;
    cout<<"Enter your choice ";
    cin>>choice;
    switch(choice)
     {
       case 1:  cout<<"Enter the element to be inserted ";
		cin>>item;
		push(stack,SIZE,item,Top);
		break;
       case 2:  pop(stack,SIZE,Top);
		break;
       case 3:  traverse(stack,SIZE,Top);
		break;
       case 4:  exit(0);
       default: cout<<"\nYou Entered Wrong Choice"; getch();
       }
    }
 while(choice!=4);
}
