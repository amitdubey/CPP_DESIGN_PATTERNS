// design_patterns.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include <string>
//#include "SINGLETON.H"
//#include "abstract_factory.h"
#include"factory.h"

using namespace std;


int main()
{
	//singlton
	//mysingleton *obj = mysingleton::getinstance();
	// abstract factory
	/*mymobilefactory *myfactory = new mymobilefactory();
	mobile * mobile1 = myfactory ->getmobile("lowend");
	mobile1->printspec();

	mobile * mobile2 = myfactory->getmobile("highend");
	mobile2->printspec();*/

	//factory
	shape *obj1 = shape::create("square");
	shape *obj2 =shape::create("rectangle");
	obj1->draw();
	obj2->draw();
	 system("pause");
	return 0;
}

