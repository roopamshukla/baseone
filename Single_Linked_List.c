#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
int data;
struct node *next;
};
struct node *start,*newnode,*temp,*temp1;
void create()
{
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter Data : ");
scanf("%d",&newnode->data);
newnode->next=NULL;
}
void insert_beg()
{
create();
if(start==NULL)
start=newnode;
else
{
newnode->next=start;
start=newnode;
}
}
void insert_middle()
{	
temp=start;
temp1=start;
int search; 
create();
if(start==NULL)
start=newnode;
else
{
printf("Enter data before which to insert : ");
scanf("%d",&search);
while(temp->data!=search)
{
temp1=temp;
temp=temp->next;
}
newnode->next=temp;
temp1->next=newnode;
}
}
void insert_end()
{
create();
if(start==NULL)
start=newnode;
else
{
temp=start;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;
}
}
void delete_beg()
{
if(start!=NULL)
temp=start;
start=temp->next;
free(temp);
}
void delete_middle()
{
int search1; 
if(start!=NULL)
temp=start;
temp1=start;
printf("Enter data to be deleted : ");
scanf("%d",&search1);
while(temp->data!=search1)
{
temp1=temp;
temp=temp->next;
}
temp1->next=temp->next;
free(temp);
}
void delete_end()
{
if(start!=NULL)
temp=start;
temp1=start;
while(temp->next!=NULL)
{
temp1=temp;
temp=temp->next;
}
temp1->next=NULL;
free(temp);
}
void display()
{
if(start!=NULL)
{
temp=start;
while(temp->next!=NULL)
{
printf("%d ",temp->data);
temp=temp->next;
}
printf("%d",temp->data);
printf("\n");
}
else
printf("List is Empty\n");
}
int main()
{
int sw;
int se;
while(1)
{
printf("What's Up?\n1.Create Node\n1.)From Beginning 2.)In Middle 3.)At End\n2.Delete Node\n1.)From Beginning 2.)From Middle 3.)From End\n3.Display List\nAnswer : ");
scanf("%d",&sw);
switch(sw)
{
case 1:printf("Where :");
       scanf("%d",&se);
       if(se==1)
       insert_beg();
       if(se==2)
       insert_middle();
       if(se==3)
       insert_end();
       break;
case 2:printf("Where :");
       scanf("%d",&se);
       if(se==1)
       delete_beg();
       if(se==2)
       delete_middle();
       if(se==3)
       delete_end();
       break;       
case 3:display();
       break;
default:printf("Invalid Choice");       
}
}
return 0;
}
