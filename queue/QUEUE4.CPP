// Program to Insert , Delete, Traverse the Circular Queue using Class
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 10
int choice;
char option='Y';
class cqueue
{
	private:
	   int front;
	   int rear;
	   int cq[SIZE];
	public:
	   cqueue()
	   {
		front=-1;
		rear=-1;
	   }
	   void insert();
	   void Delete();
	   void display();
};
void cqueue::insert()
{
   int num;
   if((front==0 && rear==SIZE-1)||(front==rear+1))
   {
     cout<<"\tCircular Queue is full"<<endl;getch();
     return;
   }
   if(front==-1)
     front=rear=0;
   else if(rear==SIZE-1)
	   rear=0;
	 else
	   rear=rear+1;
   cout<<"\tEnter the data to be inserted";
   cin>>num;
   cq[rear]=num;
}
void cqueue::Delete()
{
  int num;
  if(front==-1)
  {
    cout<<"\tCircular Queue is Empty"<<endl;getch();
    return;
  }
  cout<<"\tDeleted element is "<<cq[front];getch();
  if(front==rear)
     front=rear=-1;
  else
     if(front==SIZE-1)
	front=0;
     else
	front=front+1;
}
void cqueue::display()
{
  int i;
  if(front==-1)
  {
    cout<<"\tCircular Queue is empty"<<endl;getch();
    return;
  }
  cout<<"\tCircular queue elements are "<<endl;
  if(front<=rear)
     for(i=front;i<=rear;i++)
     {
	cout<<cq[i]<<' ';
     }
   else
   {
     for(i=front;i<=SIZE-1;i++)
     {
	cout<<cq[i]<<' ';
     }
     for(i=0;i<=rear;i++)
     {
	cout<<cq[i]<<' ';
     }
    }
  getch();
}
void main()
{
  cqueue CQ;
  int choice;
  clrscr();
  do
  {
     clrscr();
     cout<<"    MENU FOR CIRCULAR QUEUE \n";
     cout<<"    ======================= \n";
     cout<<endl<<"\t1. Insert"<<endl;
     cout<<"\t2. Delete"<<endl;
     cout<<"\t3. Display"<<endl;
     cout<<"\t4. Exit"<<endl;
     cout<<"\tEnter your choice";
     cin>>choice;
     switch(choice)
     {
       case 1 : CQ.insert();break;
       case 2 : CQ.Delete();break;
       case 3 : CQ.display();break;
       case 4: return;
     }
   }while(choice!=4);
}
