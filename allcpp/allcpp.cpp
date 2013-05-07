// allcpp.cpp : Defines the entry point for the console application.
//

#include<stdafx.h>

#include <iostream>
#include<stdio.h>
#include <conio.h>
#include<string>
#include<memory>
#include<vector>
#include<list>
#include<map>
#include<bitset>
#include<iterator>

using namespace std ;


class linklist 
{
public :
 struct node
 {
   int data;
   node *link;
 
 } *p;

 linklist();
 void display();
 void adddata(int num);
 //void deletedata();
 //void reverse();
 //void addmid();
 //void addend();
 ~linklist();

};
linklist::linklist()
{

	p=NULL;

}

linklist::~linklist()
{
 node *q=p;
 while (p!=NULL);
 {
   q=p->link;
   delete p;

 }
 p=q;
}
void linklist::adddata(int num)
{
  node *ptr = new node;
  ptr->data=num;
  ptr->link=p;
  p=ptr;
}
void linklist::display()
{
  node *current =p;
  
  while (current !=NULL)
  {
	  cout<<current->data<<" ";
	  current=current->link;
  }

}

class base1
{
public :
	 base1 ()
	{
	 cout<<"base class contructor called ";	
	}
	virtual ~base1()
	 {
	 cout<<"base destruct";
	 }
	/*
	 base (const base &base)
	 {
	   
		 
		 cout<<"copy constructor called";
	 }
	 */
	/* int operator=(const base &base)
	 {
	   
		 return base;
	 }*/


};

class derieved :public base1 
{
public :
	derieved()
	{
	 cout<<"derieved class constructor called";
	
	}

	~derieved()
	{
	cout<<"derieved destruct";
	}
};

class sample 
{
  static int  i;
public:
	/*sample();
	sample(sample &p)
	{
		i=p.i;
	}*/


};
class sample1:public sample
{
  
};

class s
{
private :
	mutable int i;

public:
	s (int ii)
	{
		i =ii;
	
	}
	 void fun() const
	 {
	  i++;
	  cout <<i;
	 
	 }
};
static int count = 0;
const int INPUT_SIZE = 10;

void print (int *input )
{
 for (int i =0; i<INPUT_SIZE;i++)
 {
   cout<<input[i];
   cout<<endl;
 
 }

}

void bubblesort(int *input )
{
 count++;
 int exchange =0;
 for(int i=0;i<INPUT_SIZE;i++)
 {
	 if(input[i]>input[i+1])
	 {
  int temp =input[i];
  input[i]=input[i+1];
  input[i+1]=temp;
 exchange ++;
	 }
 }
  if (exchange ==0) return ;
  cout<<"pass"<<count<<":";
  print(input);
  bubblesort(input);
}

char* format_number(int n)
{
    char temp[10];
    sprintf(temp, "%d", n);
    return temp;
} 

class Wrapper
{
private:
    char* _data;

public:
    Wrapper(char* input)
    {
        int length = strlen(input) + 1;
        _data = new char[length];
        strcpy_s(_data, length, input);
    }

    ~Wrapper()
    {
        delete[] _data;
    }

    operator char*()
    {
        return _data;
    }
};

 
class base {

public:
	 virtual int show()
	 {
	   cout<<"base";
	   return 0;
	 }
	 base()
	 {
	  cout<<"inside base ctor";
	 }
	virtual ~base()
	 {
	  cout<<"inside base dtor";
	 }
};

class der: public base
{
public :
	der()
	{
	  cout<<" inside der ctor";
	}
	~der()
	{
	 cout<<"inside dtor";
	}
	int show()
	{
	 cout<<"der";
	 return 0;
	}
};
class der2:public base
{

public :
	int show()
	{
	 cout<<" inside der 2 shwo";
	 return 0;
	}



};
class grndchld:virtual public der, virtual public der2
{
public:
 int show()
 {
  cout<<" inside grand child";
  return 0;
 }
};

void bubsort(int * input)
{

  int count=0;

  for ( int i=0; i<10;i++)
  {
	  if (input[i] >input[i+1])
	  {
    int temp =input[i];
	input[i] =input[i+1];
	input[i+1]=temp;
	count++;
	  }
  
  }
  if (count==0) return ;
	  bubsort(input);

};


template <class T>


    void swap(T &a,T &b)
    {T temp=a;
    a=b;
    b=temp;
        
        
        }
//template <class d>
//void printsu (d &a,d &b)
//{
//  cout<<a<<" "<<b<<endl;
//}
	int palindrome(char string[80])
	{
	
	 int len =strlen(string);
	 int flag =1;
	 int i,j;
	 for (i=0,j=0;i<len/2;i++,j--)
	 {
	   if (string[i] !=string[j])
	  {flag =0;
	  break;
	  }
	 }
	 if(flag)
		 cout<<" palindrome"<<endl;
	 else
		 cout<<"not a palindrom"<<endl;
	return flag;
	}
	
	//singleton
	class m
	{
	public :

		static m *instance;
		static m* getinstance();
	private :
		m();
	
	};
	 m *m::instance=NULL;
	 m ::m()
	 {
	   cout<<" inside ctor"<<endl;
	 }
	 m *m::getinstance()
	 {
	  if (instance == NULL)
	  {
		instance =new m();
	  }
	  return instance;
	 }
	 //factory
	 class st
	 {
	 public :
		 static st * create(string type);
		 virtual void show()=0;
	 
	 };
	 class c :public st
	 {
	 public:
		 void show(){ cout<<" i am c"<<endl;};
	 
	 };
	 class sq: public st
	 {
		 void show() {cout<<"i am sq"<<endl;}
	 };
	 st *st::create(string type)
	 {
		if (type =="c") return new c();
		if (type =="sq") return new sq();
	 
	 }
	 //abstract factory

	 class mobile
	 {
	 public: 
		 virtual string camera()=0;
		 virtual string keyboard()=0;
		 void printspec()
		 {
			cout<<camera()<<endl;
			cout<<keyboard()<<endl;
		 }
	 };
	 
	 class lowend:public mobile
	 {
	 public:
		 string camera()
		 {
		  return "2 megapixel";
		 }
		 string keyboard()
		 {
		  return "itu-t";
		 }
	 
	 };
	 
	 class highend:public mobile
	 {
	 public:
		 string camera()
		 {
		  return "5 megapixel";
		 }
		 string keyboard()
		 {
		  return "querty";
		 
		 }
	 
	 };
	 class mobilefactory
	 {
	 public:
	   mobile *getmobile(string type);
	 
	 };
	 mobile *mobilefactory::getmobile(string type)
	 {
		if (type=="lowend")
			return new lowend();
		if (type=="highend")
		return new highend();
		else NULL;	 
	 }
	 //auto ptr
	 class myclass
	 {
	 public:
		int data;
		myclass()
		{
			data=100;
		}
	 void print()
	 {
	 
	 cout<<data<<endl;
	 }
	 };
	 void func()
	 {
		auto_ptr<myclass> ptr(new myclass());
		ptr->print();	 
	 }
	 //auto ptr end
	 class b
	 {
	 public:
		 void mf()
		 {
			cout<<"base mf"<<endl;
		 }
	 };
	 class d:public b
	 {
	 public:

	 
	 
	 };

	 list<int> l;
	 //placement new
	 class place
	 {
	 public:
		void* operator new (size_t sz,void *v)
		 {
			cout<<"placement new invoked"<<endl;
		 return v;
		}
	 ~ place()
	 {}
	 
	 };
	 class temp
	 {
	 private:
		 volatile int i;
	 public:
		 temp::temp(int ii):i(ii)
		 {}
		  void fun() volatile
		  {
			  i++;
			  
		   cout<<i<<endl;
		  }

	 };

int main()
{ 
	//  base b1,b2;
//	//base *b =new derieved ;
//	//delete b;
//  b1=b2;

	//sample s;
	//sample1 s1;
	//cout<<"sample "<<sizeof(s)<<"\t sample1"<<sizeof(s1);
/*
	const s s1(10);
	s1.fun();*/


	/*int input[INPUT_SIZE] ={100,1000,300,400,500,900,600,800};
	print(input);
	bubsort(input);
	print(input);
*/
	/*char *C=format_number(10);
	cout<<*C;*/
	/*char* username = Wrapper("kevin");
    printf(username);*/
    //return 0;

	//base *b;
	//der d1;
	//der2 d2;
	//grndchld gl;
	//b= &gl;
	//gl.show();
	//linklist li;

	//li.adddata(10);
	//li.adddata(20);
	//li.display();
	/*int x=10, y=20;
       swap(x,y);
       cout<<x<<" "<<y<<endl;
       char *s1="hello",*s2="hi";
       swap(s1,s2);
       cout<<s1<<"  "<<s2<<endl;*/
	//printsu(s,s2);
	 
	//float * i =0;
	//float *j =i+1;
	// cout<<(long)j -(long) i;
	/*char string[80];
	cout<<"enter the string";
	cin.getline(string,80);
	int k=palindrome(string);*/
	/*m *obj;
	obj =m::getinstance();*/
	//shape * obj1 =shape::create("circle");
	//obj1->show();
	//shape * obj2 = shape ::create("square");
	//obj2->show();
	/*st *obj1 = st::create("c");
	obj1->show();
	st *obj2 =st::create("sq");
	obj2->show();
	getch();*/

	//mobilefactory *myfact = new mobilefactory();
	//mobile *mymobile = myfact->getmobile("lowend");
	//mymobile->printspec();

	//mobile *mymobile2=myfact->getmobile("highend");
	//mymobile2->printspec();

	//func();
	/* d x;
	 b *pb =&x;
	 pb->mf();
	 d *pd =&x;
	 pd->mf();*/
	//
	//l.push_back(10);
	//l.push_front(20);
	//l.push_front(30);
	//l.push_front(50);
	//l.push_front(60);
	//l.insert(++l.begin(),2);
	//l.insert(++l.begin(),4);
	//l.reverse();

	//list<int>::iterator it ;
	//for (it=l.begin();it !=l.end();it++)
	//{
	//	cout<<*it<<endl;
	//
	//}
/*
	int buffer[10];
	cout<<"starting address of my buffer"<<&buffer<<endl;
	place *ptr = new (buffer) place();
	cout<<"location of my obj"<<ptr<<endl;
	ptr->~place();*/
	
	volatile temp t(10);
	t.fun();
	
		
	getch();
	return 0;
}




