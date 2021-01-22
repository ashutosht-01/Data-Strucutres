#include<iostream>
using namespace std;
struct Node
{
	Node *prev;
	int data;
	Node *next;
};
Node *head= NULL;
void create(int A[],int n)
{
	Node *t,*last;
	head=new Node;
	head->prev=NULL;
	head->data=A[0];
	head->next=NULL;
	last=head;
	for(int i=1;i<n;i++)
	{
		t=new Node;
		t->prev=last;
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}
int length()
{
	Node *p;
	p=head;
	int count=0;
	while(p)
	{
		count++;
		p=p->next;
	}
	return count;
}
void Display()
{
	Node *p=head;
	while(p)
	{
		cout<<p->data<<"  ";
		p=p->next; 
	}
}
void insert(int pos,int x)
{
	if(pos<0 || pos>length())
	return;
	Node *t=new Node;
	Node *p=head;
	t->data =x;
	if(pos==0)
	{
		t->next=head;
		t->prev=NULL;
		head->prev=t;
		head=t;
	}
	else
	{
		for(int i=0;i<pos-1;i++)
		p=p->next;
		t->next=p->next;              //Maximum 4 links are modified 
		t->prev=p;
		if(p->next)                  //Minimum 3 links are modified if we insert at last node
		p->next->prev=t;
		p->next=t;
	}
}
void Delete(int pos)
{
	Node *p=head;
	if(pos==1)
	{
	head=head->next;
	if(head)
	head->prev=NULL;
	delete p;	
	}
	else
	{
		for(int i=0;i<pos-1;i++)
		p=p->next;
		p->prev->next=p->next;
		if(p->next)
		p->next->prev=p->prev;
		delete p;
	}
}
void Reverse()
{
	Node *p=head;
	Node *tmp;
	while(p)
	{
		tmp=p->next;
		p->next=p->prev;
		p->prev=tmp;
		p=p->prev;
		if(p!=NULL && p->next==NULL)
		head=p;
	}
	
}
int main()
{
	int A[5]={45,67,89,99,468};
	create(A,5);
	Display();
	cout<<endl<<"The Length of created doubly linked list is :- ";
	cout<<length();
	cout<<endl<<"Inserting at a given position :- "<<endl;
	insert(5,5665);
	Display();
	cout<<endl<<" After delteing the last element : - "<<endl;
	Delete(6);	
	Display();
	Reverse();
	cout<<endl<<"Reversing a linked list :--"<<endl;
	Display();
	
}
