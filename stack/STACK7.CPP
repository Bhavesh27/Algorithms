//Linked stack (using structure and class)
#include<iostream.h>
#include<conio.h>
#include<process.h>

struct node
{
 int info;
 node *next;
};
class stack
{
  node *top;
  node *ptr;
  public:
  stack()
  {
    top=NULL;
  }
  void push()
  {
   ptr=new node;
   if(ptr)
   {
    cout<<"\n Enter the data";
    cin>>ptr->info;
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
  void display();
};
void stack::display()
{
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
 stack S;
 int choice,item;
 do
 {
    clrscr();
    cout<<"1. PUSH "<<endl;
    cout<<"2. POP "<<endl;
    cout<<"3. TRAVERSE "<<endl;
    cout<<"4. Exit "<<endl;
    cout<<"Enter your choice ";
    cin>>choice;
    switch (choice)
    {
      case 1: S.push();break;
      case 2: S.pop(); break;
      case 3: S.display();break;
      case 4: return;
      default : cout<<"\nWrong choice";getch();
    }
  }while(choice!=4);
}
