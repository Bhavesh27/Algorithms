// Insert, Delete and Display operation on Circular Queue(as an array)
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#define SIZE 6
void cqinsert(int cq[],int size,int &front,int &rear,int data)
{
	if(front==(rear+1)%size)
	{
	  cout<<"Circular Queue is full"<<endl;getch();
	  return;
	}
	if(front==-1)
	  front=rear=0;
	else
	  rear=(rear+1)%size;
	cq[rear]=data;
}

void cqdelete(int cq[],int size,int &front,int &rear)
{
  if(front==-1)
  {
	 cout<<"Circular Queue is Empty"<<endl;getch();
	 return;
  }
  cout<<"Deleted element is "<<cq[front];getch();
  if(front==rear)
	  front=rear=-1;
  else
	 front=(front+1)%size;
}
void cqdisplay(int cq[],int size,int front,int rear)
{
  int i;
  if(front==-1)
  {
	 cout<<"Circular Queue is empty"<<endl;getch();
	 return;
  }
  cout<<"Circular queue elements are "<<endl;
  if(front<=rear)
	  for(i=front;i<=rear;i++)
	  {
	cout<<cq[i]<<' ';
	  }
	else
   {
     for(i=front;i<=size-1;i++)
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
  int cq[SIZE],front,rear,choice,item;
  front=rear= -1;
  clrscr();
  do
  {
     clrscr();
     cout<<endl<<"1. Insert"<<endl;
     cout<<"2. Delete"<<endl;
     cout<<"3. Display"<<endl;
     cout<<"4. Exit"<<endl;
     cout<<"Enter your choice ";
     cin>>choice;
     switch(choice)
     {
       case 1 : cout<<"Enter the element ";
		cin>>item;
		cqinsert(cq,SIZE,front,rear,item);break;
       case 2 : cqdelete(cq,SIZE,front,rear);break;
       case 3 : cqdisplay(cq,SIZE,front,rear);break;
       case 4: return;
     }
   }while(choice!=4);
}
