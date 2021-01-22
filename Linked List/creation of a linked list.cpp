#include<stdio.h>
#include<stdlib.h>
void createlist(int );
void addbeg(int );
struct node
{
	int info;
	struct  node *link;
} *start;
main()
{
	int ch,n,m,position,i;
	printf("1. create list ");
	printf("2. add at begining");
	printf("3. add at end");
	printf("4.delete");
	printf("5. display");
	printf("6. search");
	printf(" enter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			start=NULL;
			printf(" enter no of nodes");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				printf(" enter the element of the list");
				scanf("%d",&m);
				createlist(m);
			}
			break;
			case 2:
				printf(" enter the element");
				scanf("%d",&m);
				addbeg(m);
				break;
					}}
void createlist(int data)	
	{
		struct node *q;
		struct node *tmp;	
		tmp=(struct node*)malloc(sizeof(struct node));
		tmp->info =data;
		tmp->link =NULL;
		if(start==NULL)
	start=tmp;
	else
	{
	q=start;
	while(q!=NULL)
	{
		q=q->link ;
		q=tmp;
	}
	}}
	void addbeg(int data)
	{
		struct node *tmp;
		tmp=(struct node*)malloc(sizeof(struct node));
		tmp->info =data;
		tmp->link =start;
		start=tmp;
	}
