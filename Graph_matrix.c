#include<stdio.h>
#include<stdlib.h>
int i,j,n,edges,dest,src,graph[10][10],q[10],s[10],v[10];
void create_graph()
{
	printf("\nEnter no of nodes : ");
	scanf("%d",&n);
	edges=n*(n-1);
	for(i=1;i<=edges;i++)
	{
		printf("\nEnter for edge %d (0,0 to exit): ",i);
		printf("Enter source vertex : ");
		scanf("%d",&src);
		printf("\nEnter destination vertex : ");
		scanf("%d",&dest);
		if(src==0&&dest==0)
		break;
		if(src>n||dest>n||dest<=0||src<=0)
		{
		printf("\nerror : invalid vertex\nEnter again\n");
		i--;
		}
		else
		{
		graph[src][dest]=1;
		}
	}
}
void display()
{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
					printf("%d  ",graph[i][j]);
			}
			printf("\n");
		}
}
void insert_vertex()
{
		n++;
		printf("\nAdded vertex is %d\n",n);
		for(i=1;i<=n;i++)
		{
				graph[i][n]=0;
				graph[n][i]=0;
		}
		
}
void insert_edge()
{
	printf("\nEnter source vertex : ");
		scanf("%d",&src);
		printf("\nEnter destination vertex : ");
		scanf("%d",&dest);
		if(src>n||dest>n||dest<=0||src<=0)
		{
				printf("\nerror : invalid destination or source\n");
				return;
		}
		graph[src][dest]=1;
}
void delete_edge()
{
	printf("\nEnter source vertex : ");
		scanf("%d",&src);
		printf("\nEnter destination vertex : ");
		scanf("%d",&dest);
		if(src>n||dest>n||dest<=0||src<=0)
		{
				printf("\nerror : invalid destination or source.\n");
				return;
		}
		if(graph[src][dest]==0)
		{
		printf("\nerror : edge not exist\n");
				return;	
		}
		
		graph[src][dest]=0;
}
void delete_vertex()
{	    int ver;
		printf("\nEnter vertex : ");
		scanf("%d",&ver);
		if(ver>n||ver<=0)
		{
				printf("\nerror : vertex not exist\n");
				return;
		}
		if(n==0)
		{
				printf("\nerror : graph is empty\n");
				return;
		}
		for(i=ver;i<n-1;i++)
		{
				for(j=1;j<n;j++)
					{
							graph[i][j]=graph[i+1][j];
							graph[j][i]=graph[j][i+1];
							
					}
		}
		n--;
		
		
}
void b_search()
{
		int rear=-1, front=-1,f,l;
		for(l=1;l<=n;l++)
		{
			v[l]=0;	
		}
		printf("\nEnter search node : ");
		scanf("%d",&f);
		printf("\n%d]\t",f);
		v[f]=1;
		front++;
		rear++;
		q[rear]=f;
		while(front<=rear)
		{
				f=q[front];
				front++;
				for(l=1;l<=n;l++)
				{
					if(graph[f][l]==1&&v[l]==0)
					{
					printf("%d]\t",l);
					rear++;
					q[rear]=l;	
					v[l]=1;
					}
				}
		}
		
}
void d_search()
{
		int l,top=-1,f,popped;
		for(l=1;l<=n;l++)
		{
			v[l]=0;	
		}
		printf("\nEnter search node : ");
		scanf("%d",&f);
		top++;
		s[top]=f;
		while(top>=0)
		{
			
				popped=s[top];
				top--;
				if(v[popped]==0)
				{
						printf("[%d\t",popped);
						v[popped]=1;
				}
				else
				{
						continue;
				}
				for(l=n;l>=1;l--)
				{
						if(graph[popped][l]==1&&v[l]==0)
						{
							top++;
							s[top]=l;
						}
				}
				
		}
		
		
}
int main()
{
	int sw;
	while(1)
	{
    printf("\nWhat's up?\n1.Create Graph\n2.Insert Vertex\n3.Insert Edge\n4.Delete Vertex\n5.Delete Edge\n6.Display\n7.Breadth First Search\n8.Depth First Search\n9.Exit\nAnswer : ");
	scanf("%d",&sw);
	switch(sw)
	{
	case 1:create_graph();
	break;
	case 2:insert_vertex();
		   break;
	case 3:insert_edge();
		   break;
	case 4:delete_vertex();
		   break;
	case 5:delete_edge();
		   break;
	case 6:display();
	       break;
	case 7:b_search();
		   break;
	case 8:d_search();
		   break;
	case 9:exit(0);
	default:printf("\nInvalid Choice");
			break;
	}
	}
	return 0;
}
