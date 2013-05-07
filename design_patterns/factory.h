#ifndef factory
#define factory

using namespace std;
class shape
{


public:
	virtual void draw()=0;
	static shape *create(string str);
};

class rectangle:public shape
{
public: 
	void draw()
	{
		cout<<"i am rectangle"<<endl;
	}
	friend class shape;

};

class square:public shape
{

public:
	void draw()
	{
	 cout<<"i am square"<<endl;
	
	}
	friend class shape;
};
shape *shape::create(string type)
{
  if (type =="square") return new square();
  if(type =="rectangle") return new rectangle();
  return NULL;

}


#endif