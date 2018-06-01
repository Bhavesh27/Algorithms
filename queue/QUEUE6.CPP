//Linked Queue having Employee informations(using Structure and Class)
#include<iostream.h>
#include<alloc.h>
#include<conio.h>
struct employee
{
 int empno;
 char name[20];
 int salary;
 employee *next;
};
class queue
{
 employee *front,*rear,*ptr;
 public:
 queue()
 {
   front=rear=NULL;
 }
 void add()
 {
  ptr=new employee;
  cout<<"Enter empcode ";
  cin>>ptr->empno;
  cout<<"Enter employee name ";
  cin>>ptr->name;
  cout<<"Enter salary ";
  cin>>ptr->salary;
  ptr->next=NULL;
  if(front==NULL)
    front=ptr;
  else
    rear->next=ptr;
  rear=ptr;
 }
 void Delete()
 {
  if(front==NULL)
  {
    cout<<endl<<"Linked Queue is empty";
    getch();return;
  }
    ptr=front;
    cout<<"Deleted Data "<<ptr->empno<<'\t'<<ptr->name<<'\t'<<ptr->salary<<endl;getch();
    front=front->next;
    if(front==NULL)
      rear=NULL;
    delete ptr;
 }
 void display();
};
void queue::display()
{
  ptr=front;
  if(front==NULL)
  {
    cout<<endl<<"Linked Queue is empty";
    getch();
    return;
  }
  cout<<"Elements are "<<endl;
  while(ptr!=NULL)
  {
    cout<<ptr->empno<<'\t'<<ptr->name<<'\t'<<ptr->salary<<endl;
    ptr=ptr->next;
  }
  cout<<"NULL";
  getch();
}
void main()
{
  queue Q;
  int choice;
  clrscr();
  do
  {
   clrscr();
   cout<<endl<<"1. Add"<<endl;
   cout<<"2. Delete"<<endl;
   cout<<"3. Traverse"<<endl;
   cout<<"4. Exit"<<endl;
   cout<<"Enter your choice ";
   cin>>choice;
   switch(choice)
   {
     case 1: Q.add();break;
     case 2: Q.Delete();
	     break;
     case 3: Q.display(); break;
     case 4: return;
     default : cout<<endl<<"Wrong choice";getch();
   }
  }while(choice!=4);
}
