// circular_linklist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <stdio.h>
#include <conio.h>

using namespace std;
class linklist 
{
public :
	struct node
	{
	  int data;
	  node *link;
	
	}*front,*rear;

	void adddata(int num);
	int deletedata();
	void display();
	 linklist();
	 ~linklist();

};
linklist::linklist()
{
	front=rear=NULL;
}
linklist::~linklist()
{
  node *q;
  while (front !=rear)
  {
	q=front->link;
	delete front;
	front =q;
  }

}
void linklist::adddata(int num)
{
	node *q;
	q= new node;
	q->data=num;
	
	if (front ==NULL)
	front=q;
	else 
		rear->link=q;
	rear=q;
	rear->link=front;

}
int linklist::deletedata()
{
	node *q;
	int item;
	if(front ==NULL)
		cout<<"\n queue is empty";
	else
	{
		if(front==rear)
		{
		 item =front->data;
		 delete front;
		 front=NULL;
		 rear=NULL;
		
		}
		else
		{
			q=front;
			item=q->data;
			front=front->link;
			rear->link=front;
			delete q;
		
		}
		return (item);
	}
	return (item);
}
void linklist::display()
{
	node *q,*p;
	q=front;
	p=NULL;
	cout<<endl;
	while (q !=p)
	{
		cout<<q->data<<" ";
		q=q->link;
		p=front;
	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	linklist li;
	li.adddata(10);
	li.adddata(20);
	li.adddata(30);
	li.adddata(40);
	li.adddata(50);
	li.adddata(60);
	li.display();
	li.deletedata();
	li.display();
	getch();
	return 0;
}

