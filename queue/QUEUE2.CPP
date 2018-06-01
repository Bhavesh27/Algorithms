// Program to Insert , Delete, Traverse the Linear Queue using Class
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 10
int choice;
char option='Y';
class queue
{
	private:
	   int front;
	   int rear;
	   int a[size];
	public:
	   queue()
	   {
		front=-1;
		rear=-1;
	   }
	   void insert();
	   int remove();
	   void display();
};
void queue::insert()
{
	do
	{
		if(front==-1)
		  front=rear=0;
		else if(rear==(size-1))
		{
			for(int i=front;i<=rear;i++)
				a[i-front]=a[i];
			rear=rear-front+1;
			front=0;
		}
		else
			rear=rear+1;
		cout<<"Enter the value to be added int the Queue ";
		cin>>a[rear];
		cout<<"Do you want to add more elememt <Y/N> ";
		cin>>option;
		if(front==0 && rear>=size-1)
		{
			cout<<"Queue Full\n";
			getch();
			return;
		}
	}while(toupper(option)=='Y');
}
int queue::remove()
{
	int n;
	if(front==-1)
	{
		cout<<"Queue Empty\n";
		cout<<"Press any key to continue.....\n";
		getch();
		return -1;
	}
	else
	{
		n=a[front];
		if(front==rear)
		    front=rear=-1;
		else
		    front++;
	}
	return n;
}
void queue::display()
{
	if(front==-1)
	{
		cout<<"Queue Empty\n";
		cout<<"Press any key to continue...\n";
	}
	else
	{
		cout<<"Queue value ";
		for(int i=front;i<=rear;i++)
			cout<<a[i]<<' ';
		cout<<endl;
	}
}
void main()
{
	queue Q;
	clrscr();
	do
	{
		clrscr();
		cout<<"    MENU FOR LINEAR QUEUE \n";
		cout<<"    ===================== \n";
		cout<<"\n\t1. Add";
		cout<<"\n\t2. Delete ";
		cout<<"\n\t3. Display ";
		cout<<"\n\t4. Exit  ";
		cout<<"\n\t\n\tEnter your choice ";
		cin>>choice;
		switch(choice)
		{
		  case 1: clrscr();
			  Q.insert();
			  break;
		  case 2: clrscr();
			  do
			  {
			    int x=Q.remove();
			    if(x!=-1)
			    {
				cout<<"Value deleted "<<x;
				cout<<"\nDo you want to delete more element <Y/N>";
				cin>>option;
			    }
			    else
				break;
			  }while(toupper(option)=='Y');
			   break;
		  case 3: clrscr();
			  Q.display();
			  getch();
			  break;
		  case 4: clrscr();
			  exit(1);
		}
	}while(choice!=4);
}
