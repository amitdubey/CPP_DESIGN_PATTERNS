// tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<queue>
using namespace std;

class node 
{
public :
	int key;
	node *left;
	node *right;

	node() { key =-1;left =NULL;right=NULL;};
	void setkey(int akey) {key=akey;};
	void setleft(node *aleft){ left =aleft;};
	void setright(node *aRight){ right=aRight;};
	int Key (){ return key;};
	node *Left() {return left;};
	node *Right(){ return right;};

};

class tree
{
	node *root;
public:
	tree();
	~tree();
	node *Root(){return root;};
	void addnode(int key);
	void inorder(node *n);
	void preorder(node *n);
	void postorder(node *n);
	void levelOrder(node *n);
private :
	void addnode(int key,node *leaf);
	void freenode(node *leaf);
};

tree::tree()
{
 root =NULL;
}
tree::~tree()
{

 freenode(root);
}
void tree::freenode(node *leaf)
{
	if(leaf !=NULL)
	{
		freenode(leaf->Left());
		freenode(leaf->Right());
		delete leaf;
	}
}
void tree ::addnode(int key)
{
 if (root==NULL)
 {
  cout<<"add a node"<<key<<endl;
  node *p =new node();
  p->setkey(key);
  root=p;
 }
 else 
 {
  cout<<"add other node "<<endl;
  addnode(key,root);
 }
}

void tree::addnode(int key ,node *leaf)
{
	if (key <=leaf->Key())
	{
		if(leaf->Left() !=NULL)
	 {
		 addnode(key,leaf->Left());
		
		}
		else
		{
			node *n = new node();
			n->setkey(key);
			leaf->setleft(n);
		} 
	}
	else 
	{
		if (leaf->Right() !=NULL)
		{
		 addnode(key,leaf->Right());
		
		}
		else
		{
		 node *n= new node();
		 n->setkey(key);
		 leaf->setright(n);
		
		}
	
	}
}

void tree::inorder(node *n)
{
  if(n)
  {
	  inorder(n->Left());
	  cout<<n->Key()<<endl;
	  inorder(n->Right());
  
  }

}
void tree::preorder(node *n)
{
	if(n)
	{
		cout<<n->Key()<<endl;
		preorder(n->Left());
		preorder(n->Right());
	
	}

}
void tree::postorder(node *n)
{
	if(n)
	{
		postorder(n->Left());
		postorder(n->Right());
		cout<<n->Key()<<endl;
	
	}

}
void tree::levelOrder(node *n)
{ 
	queue<node*> q;
	q.push(n);
	while(!q.empty())
	{
	  node *v =q.front();
	  cout<<v->Key()<<" ";
	  if(v->Left() !=NULL)
		  q.push(v->Left());
	  if(v->Right() !=NULL)
		  q.push(v->Right());
	  q.pop();
	
	}
  

}
int _tmain()
{
	tree *Tree =new tree();
	Tree->addnode(30);
	Tree->addnode(10);
	Tree->addnode(20);
	Tree->addnode(40);
	Tree->addnode(50);

	cout<<"in order"<<endl;
	Tree->inorder(Tree->Root());
	cout<<"pre order"<<endl;
	Tree->preorder(Tree->Root());
	cout<<"post order"<<endl;
	Tree->postorder(Tree->Root());
	cout<<"level order";
	Tree->levelOrder(Tree->Root());
	getch();
	return 0;
}

