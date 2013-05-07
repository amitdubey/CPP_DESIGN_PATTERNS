// Ccode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;
void showbits(int n);
#define sq(x) x*x

int count (unsigned int num);


int count(unsigned int num)
{
  int count =0;
  for (;num !=0;num=num>>1)
  {
    if(num&1)
	{
		count++;
	}
  }
  return count;
}

void generatebinary(int num)
{
  int temp;
  if(num)
  {
   temp =num % 2;
   generatebinary(num>>=1);
   printf("%d",temp);
  
  }

}



int main()
{
	unsigned int t=15;
	printf("%x",~t);
	
	//int a =10;
	
	/*char p[] ="hello";
	char *ch="hello";
	
	printf("%s %c\n",p[0],ch);*/

	/*int num =10;
	generatebinary(num);*/
	/*int i =64;
	int k;
	k=i<<2;
	printf("%d\n",k);
	showbits(k);*/
	
	unsigned int d =10;
	int c =count(d);
	printf("%d ",c);
	getch();
	return 0;
}

struct c
{ int a ;
int b;
};
void showbits(int n)
{
  int i,j,anmask;
  int count =0;
  for(i=15;i>=0;i--)
  {
   anmask=1<<i;
   j=n & anmask; 
   
   j==0?printf("0"):printf("1");
  }
  cout<<"number of set bits are\n "<<count<<endl;
  printf("\n");
}
