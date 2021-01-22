#include<iostream>
using namespace std;
class Node
{
public:
 int data;
 Node *next;	
};
class stack
{  
  	Node *top;
  	  public:
	stack()
	{
		top=NULL;
	}
	void push(int x);
	int pop();
	int peek(int pos);
};
void stack::push(int x)
{
	Node *p=new Node;
	if(p==NULL)
	cout<<"stack overflow"<<endl;
	else
	{
		p->data=x;
		p->next=top;
		top=p;
	}
 } 
 int stack::pop()
 {
 	int x=-1;
 	Node *p=top;
 	if(top==NULL)
 	cout<<"stack is empty or stack underflow"<<endl;
 	else
 	{
 		top=top->next;
 		x=p->data;
 		delete p;
	 }
	 return x;
 }
 int stack::peek(int pos)
 {
 	Node *p=top;
 	for(int i=0;i<pos-1 && p!=NULL;i++)
 	p=p->next;
 	if(p!=NULL)
 	return p->data;
 	else
 	return -1;
 }
int main()
{
	stack st;
	st.push(34);
	st.push(456);
	st.push(435534);
	st.push(345657463);
	cout<<pop()<<endl;
	cout<<"values at different indices :- "<<peek(1)<<" "<<peek(2)<<" "<<peek(3)<<endl; 
}
