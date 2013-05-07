// datastruct.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

class linklist
{
public:
	struct node
	{
	  int num;
	   node *next;
	
	} *p;
	void append(int num);
	void adddatabeg(int num);
	void display ();
	void deletedata(int num);
	void reverse();
	//void adddatalast(int num);
	void removeduplicate();
	void count();
	//void find();
	linklist();
	~linklist();


};

linklist::linklist()
{
	p =NULL;

}

linklist::~linklist()
{
	node *q;
	while (p !=NULL)
	{
		q=p->next;
		delete p;
		p=q;
	}
	
}
void linklist::adddatabeg(int num)
{
	node * first =new node;
	first->num=num;
	first->next=p;
	p=first;
}

void linklist::display()
{
	node *q;
	q =p;
	while (q !=NULL)
	{
		cout<<q->num<<endl;
		q=q->next;
	}

}
void linklist::count()
{
	node *temp =p;
	int count =0;
	while (temp !=NULL)
	{
	 temp = temp->next;
	 count++;	
	}	
}

void linklist::deletedata(int num)
{
  node *old,*del =p;
  while (del !=NULL)
  {
	  if(del->num ==num)
	  {
		if (del==p)
		{
			p= del->next;
		
		}
		else
			old->next =del->next;
		delete del;
		return;
	  }
	  else 
	  {
		old =del;
		del=del->next;
	  
	  }
  }
  cout<<" \n \n element"<<num<<"not found";
}

void linklist::append(int num)
{
	node *temp,*q;
	

	if( p==NULL)
	{
		temp =new node;
		temp ->num=num;
		temp->next=NULL;
	}
	else
	{
	 temp =p;
	 while (temp ->next !=NULL)	 
	   temp=temp->next;
	   q = new node;
	   q->num=num;
	   q->next=NULL;
	   temp->next=q; 
	
	}
}
void linklist::reverse()
{
  node *q,*r,*s;
  q=p;
  r=NULL;
  while (q !=NULL)
  {
   s=r;
   r=q;
   q=q->next;
   r->next=s;
  
  }
  p=r;
}
void linklist::removeduplicate()
{
  node* current;
  current =p;
  while (current->next !=NULL)
  {
	  if (current->num==current->next->num)
	  {
		  node *q= current->next->next;
		  free(current->next);
		  current->next=q;
	  
	  }
	  else
	  {
	    current=current->next;
	  }
  
  }

}
int _tmain()
{
	linklist li;
	li.adddatabeg(10);
	li.adddatabeg(20);
	li.adddatabeg(30);
	li.adddatabeg(60);
	li.adddatabeg(40);
	li.append(60);
	li.display();
	li.count();
	//li.deletedata(20);
	cout<<"\n \n";
	li.reverse();
	cout<<"\n \n";
	li.display();
	cout<<"\n \n";
	li.removeduplicate();
	li.display();
	getch();
	return 0;
}

