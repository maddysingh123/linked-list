#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int a;
	struct node *p;
};
struct node*header=NULL;
struct node*reverse(struct node*temp);
void create(int);
void display();
int main()
{
	create(10);
	create(20);
	create(40);
	create(50);
	create(60);
	create(70);
	display();
  printf("\n--------------------------\n");
  reverse(header);
  display();

}
void create(int t)
{
	struct node*temp;
	struct node*last;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->a=t;
	temp->p=NULL;
	if(header==NULL)
	{
		header=last=temp;
	}
	else
	{
		last->p=temp;
		last=temp;
	}
}
void display()
{
	struct node*temp=header;
	while(temp!=NULL)
	{
		printf("->%d",temp->a);
		temp=temp->p;
	}
}
struct node*reverse(struct node*temp)
{
struct node*temp1,*temp2 ;
temp1=temp;
if(temp1->p==NULL)
{
	header->p=NULL;
  header=temp1;
  return temp1;
}
temp2=reverse(temp1->p);
temp2->p=temp1;
return temp1;
}
