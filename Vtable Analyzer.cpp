using namespace std;
#include<iostream>

class Base
{
	int i,j;
	
	virtual void fun()
	{
		cout<<"Base Fun \n";
	}
	
	virtual void gun()
	{
		cout<<"Base Gun \n";
	}
	
	virtual void sun()
	{
		cout<<"Base Sun \n";
	}
};


class Derived : public Base{
	public:
	int x,y;
	
	void fun(){
		cout<<"Derived Fun \n";
	}
	
	void sun(){
		cout<<"Derived Sun \n";
	}
	
	virtual void run(){
		cout<<"Derived Run \n";
	}
};	


int main()
{
	Base bobj;
	Derived dobj;
	
	cout<<sizeof(bobj);
	cout<<sizeof(dobj);
	
	long int *op = (long int *)(&dobj);
	cout<<"Base address of bobj is :"<<op<<"\n";
	
	long int *vptr = (long int*)(*op);
	cout<<"Address of VTABLE is "<<vptr<<"\n";
	
	void (*fp)();
	
	fp = (void(*)())(*vptr);
	
	fp();
	
	fp = (void(*)())(*(vptr+1));
	
	fp();
	
	fp = (void(*)())(*(vptr+2));
	
	fp();
	
	return 0;
}		