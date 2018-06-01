//Linked stack (using structure)
#include<iostream.h>
#include<conio.h>
#include<process.h>

struct stack
{
 int info;
 stack *next;
}*top=NULL;
void push(int data)
{
  stack *ptr=new stack;
  if(ptr)
  {
    ptr->info=data;
    ptr->next=top;
    top=ptr;
  }
  else
  {
    cout<<"Can not create new node "<<endl;getch();
    return;
   }
}
void pop()
{
 stack *ptr;
 if(top==NULL)
 {
   cout<<"Stack is empty"; getch();
   return;
 }
 else
 {
  ptr=top;
  cout<<"Deleted element "<<ptr->info<<endl;getch();
  top=top->next;
  delete ptr;
 }
}
void display()
{
  stack *ptr;
  if(top==NULL)
  {
    cout<<"Stack empty ";getch();
    return;
  }
  ptr=top;
  while(ptr!=NULL)
  {
    cout<<ptr->info<<"-->";
    ptr=ptr->next;
   }
   cout<<"NULL";getch();
}
void main()
{
 int choice,item;
 do
 {
    clrscr();
    cout<<"1. PUSH "<<endl;
    cout<<"2. POP "<<endl;
    cout<<"3. DISPLAY "<<endl;
    cout<<"4. EXIT "<<endl;
    cout<<"Enter your choice ";
    cin>>choice;
    switch (choice)
    {
      case 1: cout<<"Enter the data ";
	      cin>>item;
	      push(item);break;
      case 2: pop(); break;
      case 3: display();break;
      case 4: return;
      default : cout<<"\nWrong choice";getch();
    }
  }while(choice!=4);
}
