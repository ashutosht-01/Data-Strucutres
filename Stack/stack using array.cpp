#include<iostream>
using namespace std;
class stack
{
	private:
		int size;
		int top;
		int *s;
		public:
			stack(int sz)
			{
				size=sz;
				top=-1;
				s=new int[sz];
			}
			void push(int x);
			int pop();
			int peek(int pos);
};
void stack::push(int x)
{
	if(this->top==this->size-1 )
	cout<<"stack overflow "<<endl;
	else
	{
		this->top++;
		this->s[this->top]=x;
	}
 } 
 int stack::pop()
 {
 	int x=-1;
 	if(this->top==-1)
 	cout<<" stack underflow"<<endl;
 	else
 	{
 		x=this->s[this->top];
 		this->top--;
	 }
	 return x;
 }
 int stack::peek(int pos)
 {
 	int x=-1;
 	if(top-pos+1<0)
 	cout<<"invalid position "<<endl;
 	else
    x=s[top-pos+1];
    return x;
 }
int main()
{
	stack s(5);
	s.push(6);
	s.push(9);
	s.push(89);
	s.push(67);
	cout<<"Elements in stack are :- "<<endl;
	cout<<s.peek(1)<<"\n "<<s.peek(2)<<"\n "<<s.peek(3)<<"\n "<<s.peek(4);    
}
