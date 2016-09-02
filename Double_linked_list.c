#include<stdio.h>
#include<stdlib.h>
struct node
	   {
	   int data;
	   struct node *next,*prev;
	   };
struct node *newnode,*start,*start1,*temp,*temp1,*trav;
void create()
	 {
	 newnode=(struct node *)malloc(sizeof(struct node));
	 printf("Enter data to be inserted : ");
	 scanf("%d",&newnode->data);
	 newnode->next=NULL;
	 newnode->prev=NULL;
	 }
void insert_beg()
	 {
	 create();
	 if(start==NULL)
	   {
	   start=newnode;        
	   }
	 else
	   {
	   newnode->next=start;
	   start->prev=newnode;
	   start=newnode;
	   }
	 }
void insert_middle()
	 {
	 int pos,count=1;
	 temp=start;
	 temp1=start;
	 create();
	 if(start==NULL)
	   {
	   start=newnode;        
	   }
	 else
	   {
	   printf("Enter postion : ");
	   scanf("%d",&pos);
	   while(count!=pos)
		 {
		 temp1=temp;
		 temp=temp->next;
		 count++;
		 }
		 temp1->next=newnode;
		 newnode->prev=temp1;
		 newnode->next=temp;
		 temp->prev=newnode;
	   }
	 }
void insert_end()
	 {
	 create();
	 temp=start;
	 if(start==NULL)
	   {
	   start=newnode;        
	   }
	 else
	   {
	   while(temp->next!=NULL)
	   {
	   temp=temp->next;
	   }
	   temp->next=newnode;
	   newnode->prev=temp;
	   newnode->next=NULL;
	   }
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
	   printf("%d ",temp->data);
	   printf("\n");
	 }
	 else
	   printf("List is empty.\n");
	 }
void delete_beg()
	{
	if(start!=NULL)
	 {
	   temp=start;
	   start=temp->next;
	   start->prev=NULL;
	   free(temp);
	 }
	else
	printf("List is empty.\n");
	}
void delete_middle()
	{
	temp=start;
	temp1=start;
	if(start!=NULL)
	 { 
	   int search;
	   printf("Enter data to be deleted : ");
	   scanf("%d",&search);
	   while(temp->data!=search)
	   {
	   temp1=temp;
	   temp=temp->next;
	   }
	   temp1->next=temp->next;
	   temp->next->prev=temp1;
	   free(temp);
	 }
	else
	printf("List is empty.\n");
	}
void delete_end()
	{
	temp=start;
	temp1=start;
	if(start!=NULL)
	 {
	   while(temp->next!=NULL)
	   {
	   temp1=temp;
	   temp=temp->next;
	   }
	   temp1->next=NULL;
	   free(temp);
	 }
	else
	printf("List is empty.\n");
	}
void concatenate()
	{
	int ch,se,n=1;
	start1=start;
	start=NULL;
	printf("\nENTER LIST 2 DATA\n");
		while(n==1)
			{
			printf("What's up?\n1.Insert()\n  1.Beginning\t2.Middle\t3.End\n2.Delete()\n  1.Beginning\t2.Middle\t3.End\n3.Display()\n4.Exit\nAnswer : ");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:printf("Where : ");
				scanf("%d",&se);
				if(se==1)
				insert_beg();
				if(se==2)
				insert_middle();
				if(se==3)
				insert_end();
				break;
				case 2:printf("Where : ");
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
				case 4:n=0;
				break;
				default:printf("\nInvalid Choice");
			}
		}	
	if(start!=NULL)
	{
	if(start1==NULL)
	{
	printf("\nExited LIST 2\n");
	}	
	else
	{
		temp=start1;
	while(temp->next!=NULL)
	   {
	   temp=temp->next;
	   }
	   temp->next=start;
	   start->prev=temp;
	   start=start1;
	}
	}
	else
	{
	printf("\nExited LIST 2\n");
	start=start1;
	}
}
void traverse()
	{
	int swch,m=1;
	if(start!=NULL)
	{
	 temp=start; 
	 if(temp->next!=NULL)   
	 {
	 while(temp->next!=NULL)
	   {
		if(temp==start)
		printf("|%d| ",temp->data);
		else
	   {
	   printf("%d  ",temp->data);
	   }
	   temp=temp->next;
	   }
	   printf("%d ",temp->data);
	   printf("\n");
	}
	else
	printf("|%d| ",temp->data);
	}
    else
	printf("List is empty\n");
    trav=start;
	while(m==1)
	{
	printf("\n1.Next\t2.Previous   3.Exit Traversing\nAnswer : ");
	scanf("%d",&swch);
	switch(swch)
	{
	case 1:if(trav!=NULL)
    {
    trav=trav->next;
	if(start!=NULL&&trav!=NULL)
	{
	 temp=start;    
	 while(temp->next!=NULL)
	   {
		
        if(trav==temp)
		printf("|%d| ",trav->data);
		else
	    printf("%d  ",temp->data);
       
	   temp=temp->next;
	   }
      if(temp->next==NULL&&temp==trav)
	   printf("|%d| ",temp->data);
	  else
        printf("%d ",temp->data);
	 }
	 else
	   printf("Looks like list is empty or you've reached the end.\n");
     }
     else
     {
     trav=start;
     temp=start;    
	 while(temp->next!=NULL)
	   {
		
        if(trav==temp)
		printf("|%d| ",trav->data);
		else
	    printf("%d  ",temp->data);
        temp=temp->next;
	   }
       printf("%d ",temp->data);
     }
	break;
    
    
    case 2:if(trav!=NULL)
    {
    trav=trav->prev;
	if(start!=NULL&&trav!=NULL)
	{
	 temp=start;    
	 while(temp->next!=NULL)
	   {
		
        if(trav==temp)
		printf("|%d| ",trav->data);
		else
	    printf("%d  ",temp->data);
       
	   temp=temp->next;
	   }
      if(temp->next==NULL&&temp==trav)
	   printf("|%d| ",temp->data);
	  else
        printf("%d ",temp->data);
	 }
	 else
	  { 
        printf("Looks like it's empty or you've reached starting.\n");
      }
     }
     else
     {
     trav=temp;
     temp=start;    
	 while(temp->next!=NULL)
	   {
		if(trav==temp)
		printf("|%d| ",trav->data);
		else
       printf("%d  ",temp->data);
	   temp=temp->next;
	   }
      if(temp->next==NULL&&temp==trav)
	   printf("|%d| ",temp->data);
	  else
        printf("%d ",temp->data);
     }
     break;
     case 3:m=0;
            break;
	 }
     	}
	}
int main()
	{
	int sw,se;
	while(1)
	{
    printf("What's up?\n1.Insert()\n  1.Beginning\t2.Middle\t3.End\n2.Delete()\n  1.Beginning\t2.Middle\t3.End\n3.Concatenate()\n4.Display()\n5.Traverse\n6.Exit.\nAnswer : ");
	scanf("%d",&sw);
	switch(sw)
	{
	case 1:printf("Where : ");
	scanf("%d",&se);
	if(se==1)
	insert_beg();
	if(se==2)
	insert_middle();
	if(se==3)
	insert_end();
	break;
	case 2:printf("Where : ");
	scanf("%d",&se);
	if(se==1)
	delete_beg();
	if(se==2)
	delete_middle();
	if(se==3)
	delete_end();
	break;
	case 3:concatenate();
	break;
	case 4:display();
	break;
	case 5:traverse();
	break;
	case 6:exit(1);
	default:printf("\nInvalid Choice");
	}
	}
	return 0;
	}
