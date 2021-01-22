#include<iostream>
using namespace std;
template<class t>
class Stack                         //this stack data structure works for all type of data types
{
	private:
		int size;
		int top;
		t *stk;
		public:
			Stack(int sz)
			{
				size=sz;
				top=-1;
				stk=new t[size];
			}
			void push(t x);
			t popup();
};
template<class t>
void Stack<t>::push(t x)    //class is if template type so we have to write template parameter 
{                              //whenever we write name of a class we have to write template parameter with it
	if(top==size-1)              //top pointer will not increase when it reaches size-1 
	cout<<"stack is full"<<endl; //if further create objects then value of top pointer is not going to change
	else                             //and it will be equals to size-1  
	{                           //if we further call push it will display same msg
     top++;
     stk[top]=x;
}
}
template<class t>
t Stack<t>::popup()
{
	if(top==-1)
	cout<<"stack is empty "<<endl;
	else
	{
	t x=stk[top];
	top--;
return x;
}
}
main()
{
	Stack <float>s(5);
	s.push(34.334);
	s.push(45);
	s.push(53);
	s.push(4543);
	s.push(434);
	s.push(432);      //value of top pointer is same as 4 not increase hence dispaly same msg
	s.push(437);      //here also value of top pointer is not going to be change
	cout<<s.popup()<<" "<<s.popup()<<" "<<s.popup()<<" "<<s.popup()<<" "<<s.popup()<<endl;;  
	       
}
