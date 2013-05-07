#ifndef abstract_factory
#define abstract_factory
using namespace std;

class mobile
{
 
public:
	virtual string camera()=0;
	virtual string keyboard()=0;
	
	void printspec()
	{
	 cout << camera()<<endl;
	  cout << keyboard()<<endl;
	}

};

class lowendmobile: public mobile
{
public:
	string camera()
   {
    return "2 megapixel";
   }
   string keyboard()
   {
   
   return " normal keyboard";
   }

};

class highendmobile: public mobile
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

class mymobilefactory
{

public:
	mobile *getmobile(string type);
};

mobile *mymobilefactory::getmobile(string type)
{
	if(type =="lowend") return new lowendmobile();
	if(type =="highend") return new highendmobile();
	return NULL;
}
#endif