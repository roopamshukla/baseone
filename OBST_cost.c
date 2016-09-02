#include<stdio.h>
int f[10],nodes[10],n,temp_cost=0,cost1=0,cost2=0;
void input()
{
	printf("Enter no of nodes : ");
	scanf("%d",&n);
	printf("\n");
	for(int i=0;i<n;i++)
		{
		printf("Enter node %d : ",i+1);
		scanf("%d",&nodes[i]);
		
		printf("Enter frequency for node %d : ",i+1);
		scanf("%d",&f[i]);
		
		printf("\n");
		}
}
int f_sum(int i,int j,int f[])
{
	int fs=0;
	for(int m=i;m<=j;m++)
		{
		fs=fs+f[m];	
		}
		return fs;
}
int c_obst(int f[],int nodes[],int n)
{
	int cost_m[n][n];
	for(int i=0;i<n;i++)
				{
					for(int j=0;j<n;j++)
					{
						cost_m[i][j]=0;
					}
					printf("\n");
				}
	for(int i=0;i<n;i++)
		{
				cost_m[i][i]=f[i];
		}
	for(int len=2;len<=n;len++)
		{
			for(int i=0;i<n-len+1;i++)
				{
						int j=i+len-1;
						cost_m[i][j]=99999;
						for(int m=i;m<=j;m++)
							{
									if(m>i)
									{
											cost1=cost_m[i][m-1];
									}
									else
									{
										cost1=0;
									}
									if(m<j)
									{
										cost2=cost_m[m+1][j];
									}
									else
									{
										cost2=0;	
									}
									temp_cost=cost1+cost2+f_sum(i,j,f);
									if(temp_cost<cost_m[i][j])
									{
											cost_m[i][j]=temp_cost;
									}
							}
				}
				printf("\n");
			for(int i=0;i<n;i++)
				{
					for(int j=0;j<n;j++)
					{
						printf("%d\t",cost_m[i][j]);
					}
					printf("\n");
				}
		}
		printf("\n");
	return cost_m[0][n-1];
}
int main()
{
		input();
		printf("%d",c_obst(f,nodes,n));
		return 0;
}
