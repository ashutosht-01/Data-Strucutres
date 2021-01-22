#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node *next;
};
Node *head=NULL;
void create(int A[],int n)
{
Node *t,*last;
t=new Node;
t->data=A[0];
t->next=NULL;
head=t;
last=t;
for(int i=1;i<n;i++)
{
	t=new Node;
	t->data=A[i];
	t->next=NULL;
	last->next=t;
	last=t;
	}	
	last->next=head;
}
void Display(Node *p)
{
	do
	{
		cout<<p->data<<"  ";
		p=p->next;
	}while(p!=head);
}
void RecDisplay(Node *p)
{
	static int  flag=0;
	if(p!=head || flag==0)
	{
		flag=1;
		cout<<p->data<<"  ";
		RecDisplay(p->next );
	}
	
}
void Insert(int pos,int x)
{
	Node *t,*p;
	p=head;
	t=new Node;
	t->data=x;
	if(pos==0)
	{
		if(head==NULL)
		{
			t->next=t;
			head=t;
		}
		else
		{
		while(p->next!=head)
		{
			p=p->next;
		}
		p->next=t;
		t->next=head;
		head=t;	
		}
	}
	else
	{
		for(int i=0;i<pos-1;i++)
		p=p->next;
		t->next =p->next;
		p->next=t;
	}
}
int main()
{
	int A[5]={32,34,45,56,78};
	create(A,5);
	Display(head);
	cout<<endl<<"Recursively Displaying circular linked list : -";
	RecDisplay(head);
	cout<<endl<<"After inserting 38 at position 3 - ";
	Insert(3,38);
	Display(head);
}
