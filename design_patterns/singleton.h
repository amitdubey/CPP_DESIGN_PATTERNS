# ifndef SINGLETON
# define SINGLETON



class mysingleton
{
public:
	 static mysingleton * instance;
	 static mysingleton *getinstance();
private:
	mysingleton();

  
};
mysingleton ::mysingleton()
{
	cout<<"inside constructor"<<endl;

}

mysingleton *mysingleton::instance=NULL;

mysingleton *mysingleton::getinstance()
{
   if (instance == NULL)
   {
		instance = new mysingleton();
   }

   return instance;
}
#endif