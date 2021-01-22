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
			q->next =p->next;
			p->next=First;
			First=p;
			return First;
		}
		q=p;
		p=p->next;
	
	}
	return NULL;
}
void Insert(int pos,int x)
{
	Node *t,*p;
	p=First;
	if(pos==0)
	{
		t=new Node;
		t->data=x;
		t->next=First;
		First=t;
	}
	else if(pos>0)
	{
		for(int i=0;(i<pos-1 && p);i++)
	    	p=p->next;
		 if(p)
		 {
		 	t=new Node;
		 	t->data=x;
		 	t->next=p->next;
			 p->next =t; 
		 }
	}
}
void sort_Insertion(int x)
{
Node *p=First;
Node *q=NULL;
while(p && p->data<x)
{
	q=p;
	p=p->next;
	}	
	Node *t;
	t=new Node;
     t->data=x;
     t->next=q->next;
     q->next =t;
}
void Delete(int pos)
{
	int i;
	Node *p,*q;
	if(pos==1)
	{
	p=First;
	First=First->next;
	delete p;	
	}
	else
	{
		p=First;
		q=NULL;
		for(i=0;i<pos-1 && p;i++)
		{
			q=p;
			p=p->next;
		}
		if(p)
		{
			q->next=p->next ;
			delete p;
		}
	}
}
bool IsSorted()
{
	Node *p=First;
	int x=INT_MIN;
	while(p!=NULL)
	{
		if(p->data<x)
		return false;
		x=p->data;
		p=p->next;
	}
	return true;
}
void RemoveDuplicates()
{
Node* p =First;
Node *q=First->next;
while(q!=NULL)
{
	if(p->data!=q->data)
	{
		p=q;
		q=q->next;
	}
	else
	{
		p->next=q->next;
		q=q->next;
		delete q;
	}
	}	
}
void Reverse()    //Reversing the links   We can also use Reversin the data but linked can be of any type i.e it can be of records or anything which needs a large size array for storing its element & then swapping it takes a lot of space & time
{
Node *p=First;
Node *q,*r;       //We genrally do NOT prefer changing the nodes value
q=r=NULL;
while(p!=NULL)
{
	r=q;
	q=p;            //Conncept of liding pointers
	p=p->next;
	q->next=r;      //for reversing
	}	
	First=q;
}
void RecReverse(Node *p,Node *q)
{
   if(p!=NULL)
    {
	RecReverse(p->next,p);      //Reversing a LInked List By using Recursion
	p->next =q;
	}
	if(p==NULL)
	First=q;	
}
int main()
{
	int A[5] = { 23,34,53,53,89 };
	Create(A, 5);
	RecDisplay(First);
	cout<<"No of Nodes in a given Linked List are :- "<<Rcount(First)<<endl;
	cout<<max(First)<<endl;
	cout<<"max value of element in alinked list is "<<Rmax(First)<<endl;
	cout<<"Linear searching for element "<<LSearch(First,34)<<endl;
	Insert(2,47);
	RecDisplay(First);
	cout<<endl;
	sort_Insertion(78);
		RecDisplay(First);
		cout<<endl;
		Delete(3);
		cout<<"After Deleting the Node at Index 3"<<endl;
		RecDisplay(First);
		Delete(12);
		cout<<endl<<"after giving the invalid index to the delete function Nothing will happen to Linked List"<<endl;
		RecDisplay(First);
		bool b=IsSorted();
		if(b==1)
		cout<<"linked list is sorted"<<endl;
		else
		cout<<"Linked list is not sorted"<<endl;
		cout<<"After removing duplicates fromm linked list linked list is :- "<<endl;
		RemoveDuplicates();
		RecDisplay(First);
		cout<<"After Reversing the linked list :- "<<endl;
		Reverse();
		RecDisplay(First);
		 RecReverse(First,NULL);
		 cout<<"After Recursively Reversing  a linked list : - "<<endl;
	
		 	RecDisplay(First);
		 	Node *p=First;
Node *q=NULL;
if(p->data==q->data)
cout<<"MY NAME IS ASHU"<<endl;
else 
cout<<"tripathi";
}

