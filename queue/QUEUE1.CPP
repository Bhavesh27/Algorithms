// Insert, Delete and Display operation on Linear Queue(as an array)
#include<iostream.h>
#include<conio.h>
#define SIZE 10
void qinsert(int q[],int size,int &front,int &rear,int data)
{
  if(rear==(SIZE-1))
  {
    cout<<"Queue is full"<<endl;getch();
    return;
  }
  rear=rear+1;
  q[rear]=data;
  if(front==-1)
  {
    front=0;
  }
}
void qdelete(int q[],int size,int &front,int &rear)
{
  if(front==-1)
  {
    cout<<"Queue empty"<<endl;getch();
    return;
  }
  cout<<"Deleted Data "<<q[front]<<endl;
  getch();
  if(front==rear)
     front=rear=-1;
  else
     front++;
}
void qdisplay(int q[],int size,int front,int rear)
{
  int i;
  if(front==-1)
  {
    cout<<"Queue empty\n";getch();
    return;
  }
  else
  {
    cout<<endl<<"The status of the queue"<<endl;
    for(i=front;i<=rear;i++)
    {
      cout<<endl<<q[i];
    }
    getch();
  }
  cout<<endl;
}

void main()
{
  clrscr();
  int item,front,rear,choice;
  front=-1;
  rear=-1;
  int q[SIZE];
  do
  {
    clrscr();
    cout<<"1 Insert"<<endl;
    cout<<"2 Delete"<<endl;
    cout<<"3 Display"<<endl;
    cout<<"4 Exit"<<endl;
    cout<<"Enter your choice ";
    cin>>choice;
    switch(choice)
    {
      case 1: cout<<"Enter the data ";
	      cin>>item;
	      qinsert(q,SIZE,front,rear,item);
	      break;
      case 2: qdelete(q,SIZE,front,rear);
	      break;
      case 3: qdisplay(q,SIZE,front,rear);
	      break;
      case 4: return;
      default: cout<<"Wrong choice entered ";getch();
    }
   }while(choice!=4);
}
