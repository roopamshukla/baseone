#include<stdio.h>
#include<stdlib.h>
struct vertex
{
	int data;
	struct vertex *next;
	struct edge *edge_start;
};
struct vertex *start,*temp,*new_ver,*temp1;
struct edge
{
	int edge_data;
	struct edge *edge_next;
};
struct edge *edge_temp,*new_edge,*edge_temp1;
void create_vertex()
{
new_ver=(struct vertex*)malloc(sizeof(struct vertex*));
printf("\nEnter vertex : ");
scanf("%d",&new_ver->data);
new_ver->next=NULL;
new_ver->edge_start=NULL;
}
void create_edge()
{
new_edge=(struct edge*)malloc(sizeof(struct edge*));
new_edge->edge_data=-1;
new_edge->edge_next=NULL;
}
void insert_vertex()
{
		create_vertex();
		if(start==NULL)
		{
			start=new_ver;
		}
		else
		{
		temp=start;
		while(temp->next!=NULL&&temp->data!=new_ver->data)
				{
				temp=temp->next;	
				}
			if(temp->data!=new_ver->data)
				{
						temp->next=new_ver;
				}
			else
				{
				printf("\nVertex Already Exist\n");
				return;
				}
		}
}
void insert_edge(int src,int dest)
{
		if(start!=NULL)
		{		
				temp=start;
				while(temp->next!=NULL&&temp->data!=dest)
				{
						temp=temp->next;
				}
				if(temp->data!=dest)
				{
						printf("\nInvalid Destination\n");
						return;
				}
				temp=start;
				while(temp->next!=NULL&&temp->data!=src)
				{
						temp=temp->next;
						
				}
				if(temp->data!=src)
				{
						printf("\nInvalid Source\n");
						return;
				}
				create_edge();
				if(temp->edge_start==NULL)
				{
				temp->edge_start=new_edge;
				new_edge->edge_data=dest;	
				}
				else{
				edge_temp=temp->edge_start;
				while(edge_temp->edge_next!=NULL&&edge_temp->edge_data!=dest)
				{
						edge_temp=edge_temp->edge_next;
				}
				if(edge_temp->edge_data!=dest)
				{
						edge_temp->edge_next=new_edge;
						new_edge->edge_data=dest;
				}
				else
				{
						printf("\nEdge already exist\n");
				}
			}
		}
}
void delete_edge(int src,int dest)
{
		if(start!=NULL)
		{		
				temp=start;
				while(temp->next!=NULL&&temp->data!=dest)
				{
						temp=temp->next;
				}
				if(temp->data!=dest)
				{
						printf("\nInvalid Destination\n");return;
				}
				temp=start;
				while(temp->next!=NULL&&temp->data!=src)
				{
						temp=temp->next;
						
				}
				if(temp->data!=src)
				{
						printf("\nInvalid Source\n");
						return;
				}
				if(temp->edge_start!=NULL)
				{
				if(dest==temp->edge_start->edge_data)
				{
				edge_temp=temp->edge_start;
				temp->edge_start=temp->edge_start->edge_next;
				free(edge_temp);	
				}
				else
				{
				edge_temp=temp->edge_start;
				edge_temp1=temp->edge_start;
				while(edge_temp->edge_next!=NULL&&edge_temp->edge_data!=dest)
						{
						edge_temp1=edge_temp;
						edge_temp=edge_temp->edge_next;	
						}
				if(edge_temp->edge_data==dest)
					{
					edge_temp1->edge_next=edge_temp->edge_next;
					free(edge_temp);	
					}
				else
					{
					printf("\nEdge not exist\n");	
					}
				}
			}
			else
			{
					printf("\nEdge not exist\n");
			}
}
}
void delete_vertex(int src)
{
		if(start!=NULL)
		{		temp=start;
				while(temp->next!=NULL&&temp->data!=src)
				{		
						temp=temp->next;
				}
				if(temp->data!=src)
				{
						printf("\nInvalid Vertex\n");
						return;
				}
				temp=start;
				while(temp->next!=NULL)
				{
				delete_edge(temp->data,src);
				temp=temp->next;	
				}
				temp=start;
				temp1=start;
				while(temp->next!=NULL&&temp->data!=src)
				{		
						temp1=temp;
						temp=temp->next;
				}
				temp1->next=temp->next;
				free(temp);
				
		}
}
void display()
{
		temp=start;
		while(temp!=NULL)
			{
					edge_temp=temp->edge_start;
					printf("%d",temp->data);
					while(edge_temp!=NULL)
					{
							printf(" -> %d",edge_temp->edge_data);
							edge_temp=edge_temp->edge_next;
					}
					temp=temp->next;
					printf("\n");
			}
}
int main()
{
	int sw,s,d,v;
	while(1)
	{
    printf("\nWhat's up?\n1.Insert Vertex\n2.Insert Edge\n3.Delete Vertex\n4.Delete Edge\n5.Display\n6.Exit\nAnswer : ");
	scanf("%d",&sw);
	switch(sw)
	{
	case 1:insert_vertex();
	break;
	case 2:printf("\nEnter source vertex : ");
		   scanf("%d",&s);
		   printf("\nEnter destination vertex : ");
		   scanf("%d",&d);
		   insert_edge(s,d);
		   break;
	case 3:printf("\nEnter vertex : ");
		   scanf("%d",&v);
		   delete_vertex(v);
		   break;
	case 4:printf("\nEnter source vertex : ");
		   scanf("%d",&s);
		   printf("\nEnter destination vertex : ");
		   scanf("%d",&d);
		   delete_edge(s,d);
		   break;
	case 5:display();
		   break;
	case 6:exit(0);
	default:printf("\nInvalid Choice");
		    break;
	}
	}
	return 0;
}
