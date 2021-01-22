#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* First;
void Create(int A[], int n)
{
	int i;
	Node* last, *t;
	First = new Node;
	First->data = A[0];
	First->next = 0;
	last = First;
	for (i = 1; i < n; i++)
	{
		t = new Node;
		t->data = A[i];
		t->next = 0;
		last->next = t;
		last = t;
	}
}
int max(Node *p)
{
	int m;           //OR we can use MIN_INT	
	m=p->data;
	while(p)
	{
		if(p->data>m)
		m=p->data;
		p=p->next;
	}
	return m;
}
int Rmax(Node *p)
{
	int x;
	x=0;
	if(p==0)
	return 0;
	x=Rmax(p->next);
	if(p->data>x)
	return p->data;
	else
	return x;
	
}
int Rcount(Node *p)
{	static int c=0;
	if(p)
	{
		c++;
		Rcount(p->next );
	}
	return c;
}
void RecDisplay(Node *p)
{
	if(p!=0)
	{
		cout<<p->data<<" ";
		RecDisplay(p->next);
	}
}
Node * LSearch(Node *p,int key)   //Move to Head improved Linear search
{
	Node *q=0;
	while(p!=NULL)
	{
		if(p->data ==key)
		{
			q=p->next;
			p->next=First;
			First=p;
		}
		q=p;
		p=p->next;
	}
	if(p!=NULL)
	return First;
	else
	return NULL;
}
int main()
{
	int A[5] = { 23,34,53,54,44 };
	Create(A, 5);
	RecDisplay(First);
	cout<<"No of Nodes in a given Linked List are :- "<<Rcount(First)<<endl;
	cout<<max(First)<<endl;
	cout<<"max value of element in alinked list is "<<Rmax(First)<<endl;
	cout<<"Linear searching for element "<<LSearch(First,53)<<endl;
}
