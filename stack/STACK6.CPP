// Program to Push,Pop, Display the Stack using Class
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#define size 10
class stack
{
	private:
	    int top;
	    int a[size];
	public:
	    stack()
	    {
		top=-1;
	    }
	    int under()
	    {
		if(top==-1)
		   return 0;
		else
		   return 1;
	    }
	    int over()
	    {
		if(top>=size-1)
		    return 0;
		else
		    return 1;
	    }
	    void push(int x);
	    int pop();
	    void display();
};
void stack::push(int x)
{
	a[++top]=x;
}
int stack::pop()
{
	return a[top--];
}
void stack::display()
{
	if(top==-1)
	{
		cout<<"Stack Empty\n";
	}
	else
	{
		cout<<"Stack value ";
		for(int i=top;i>=0;i--)
			cout<<a[i]<<' ';
		cout<<endl;
	}
}
void main()
{
	stack S;
	clrscr();
	int choice,value,r;
	do
	{
	  clrscr();
	  cout<<"    MENU FOR STACK \n";
	  cout<<"    ============== \n";
	  cout<<"\n\t1. Push ";
	  cout<<"\n\t2. Pop ";
	  cout<<"\n\t3. Display ";
	  cout<<"\n\t4. Exit ";
	  cout<<"\n\t\n\tEnter your choice ";
	  cin>>choice;
	  switch(choice)
	  {
		case 1: clrscr();
			r=S.over();
			if(r==0)
			  cout<<"\nStack Full ";
			else
			{
			  cout<<"\nEnter the value to Push->";
			  cin>>value;
			  S.push(value);
			}
			cout<<"\nPress any key to continue..";
			getch();
			break;
		case 2: clrscr();
			r=S.under();
			if(r==0)
			  cout<<"\nStack Empty"<<endl;
			else
			{
			  value=S.pop();
			  cout<<"\nThe poped element->"<<value<<endl;
			}
			cout<<"Press any key to continue..";
			getch();
			break;
		case 3: clrscr();
			cout<<endl;
			S.display();
			cout<<"Press any key to continue..";
			getch();
			break;
		case 4: clrscr();
			exit(1);
		default: clrscr();
			 cout<<"\nInvalid Input  "<<endl;
			 cout<<"Press any key to continue..";
			 getch();
	  }
	}while(choice!=4);
}
