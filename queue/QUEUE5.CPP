//Linked Queue (using structure)
#include<iostream.h>
#include<alloc.h>
#include<conio.h>
struct node
{
 int info;
 node *next;
}*front=NULL,*rear=NULL;
void add(int data)
{
  node *ptr=new node;
  ptr->info=data;
  ptr->next=NULL;
  if(front==NULL)
    front=ptr;
  else
    rear->next=ptr;
  rear=ptr;
}
void Delete()
{
  node *ptr;
  if(front==NULL)
  {
    cout<<endl<<"Linked Queue is empty";
    getch();return;
  }
    ptr=front;
    cout<<"Deleted Data "<<ptr->info<<endl;getch();
    front=front->next;
    if(front==NULL)
      rear=NULL;
    delete ptr;
}
void display()
{
  node *ptr;
  ptr=front;
  if(front==NULL)
  {
    cout<<endl<<"Linked Queue is empty";
    getch();
    return;
  }
  cout<<"Element(s) are "<<endl;
  while(ptr!=NULL)
  {
    cout<<ptr->info<<"-->";
    ptr=ptr->next;
  }
  cout<<"NULL";
  getch();
}
void main()
{
  int choice,item;
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
     case 1: cout<<"Enter the data ";
	     cin>>item;
	     add(item);break;
     case 2: Delete();
	     break;
     case 3: display(); break;
     case 4: return;
     default : cout<<endl<<"Wrong choice";getch();
   }
  }while(choice!=4);
}
