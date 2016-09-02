#include<stdio.h>
#include<stdlib.h>
int count,count1;
struct node
	{
		int data;
		struct node *left,*right; 
	};
struct node *newnode,*root,*temp,*temp1,*temp2;
void create()
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter data : ");
		scanf("%d",&newnode->data);
		newnode->left=NULL;
		newnode->right=NULL;
	}
void insert()
	{  
		create();
		if(root==NULL)
			{
				root=newnode;
			}
		else
		{
		temp=root;
		while(1)
			{
				if(newnode->data<=temp->data&&temp->left!=NULL)
				{
					temp=temp->left;
				}
				if(newnode->data>=temp->data&&temp->right!=NULL)
				{
					temp=temp->right;
				}
				if(newnode->data<=temp->data&&temp->left==NULL)
				{
					temp->left=newnode;
					break;
				}
				if(newnode->data>=temp->data&&temp->right==NULL)
				{
					temp->right=newnode;
					break;
				}
				
			}
		}
	}
void delete()
	{	
	if(root!=NULL)
		{
			int search;
			printf("\nEnter data to be deleted : ");
			scanf("%d",&search);
			temp=root;
			temp1=root;
			while(1)
			{
				if(search>temp->data)
					{
						temp1=temp;
						temp=temp->right;
					}
				else if(search<temp->data)
					{  
						temp1=temp;
						temp=temp->left;
					}
				else
				 break;
			}
			if(temp->left==NULL&&temp->right==NULL)
			{
				free(temp);
				if(temp1->data<search)
				temp1->right=NULL;
				else
				temp1->left=NULL;
			}
			else if(temp->left==NULL||temp->right==NULL)
				{
					if(temp->data>temp1->data&&temp->right==NULL)
						{
						temp1->right=temp->left;
						}
					if(temp->data>temp1->data&&temp->left==NULL)
						{
						temp1->right=temp->right;
						}	
					if(temp->data<temp1->data&&temp->left==NULL)
						{
						temp1->left=temp->right;
						}
					if(temp->data<temp1->data&&temp->right==NULL)
						{
						temp1->left=temp->left;
						}	
					free(temp);
				}
			else if(temp->left!=NULL&&temp->right!=NULL)
			{
				temp2=temp;
				temp=temp->right;
				while(temp->left!=NULL)
				{
					temp=temp->left;
				}
				if(search>temp1->data)
				{					
						temp1->right=temp2->right;
						temp->left=temp2->left;
				}
				if(search<temp1->data)
				{					
						temp1->left=temp2->right;
						temp->left=temp2->left;
				}				
				free(temp2);
			}
				
				
		}
	}
void inorder(struct node *root1)
   {
   	if(root1!=NULL)
		{ 
       	inorder(root1->left);
       	printf("\t %d",root1->data);
       	inorder(root1->right);
		}
	}
void preorder(struct node *root1)
   {
   	if(root1!=NULL)
		{ 
       	printf("\t %d",root1->data);
       	inorder(root1->left);
       	inorder(root1->right);
		}
	}
void postorder(struct node *root1)
   {
   	if(root1!=NULL)
		{ 
       	inorder(root1->left);
       	inorder(root1->right);
       	printf("\t %d",root1->data);
		}
	}
int counter(struct node *root1)
   {
   	if(root1!=NULL)
		{ 
		count++;
       	counter(root1->left);
       	counter(root1->right);
		}
		return count;
	}
int counter_leaf(struct node *root1)
   {
	if(root1!=NULL&&root1->left==NULL&&root1->right==NULL&&root1==root)
	count1=0;
   	else if(root1!=NULL)
		{ 
		if(root1->left==NULL&&root1->right==NULL)
		count1++;
       	counter_leaf(root1->left);
       	counter_leaf(root1->right);
		}
		return count1;
	}
int max_of(int a,int b)
{
		if(a>=b)
		{
				return a;
		}
		else
		{
				return b;
		}
}
int height(struct node* root1)
{
		if(root1==NULL)
		{
				printf("\nTree is empty.");
				return 0;
		}
		return 1+max_of(height(root1->left),height(root1->right));
}
int  check_avl(struct node* root1)
{
	int h_left,h_right;
	if(root1==NULL)
		{
				printf("\nTree is empty.");
				return 1;
		}
	h_left=height(root1->left);
	h_right=height(root1->right);
	if(h_left-h_right<=1&&h_left-h_right>=-1&&check_avl(root1->left)&&check_avl(root1->right))
	{
			return 1;
	}
	return 0;
}
int main()
{
	int sw,se,cnt=0,cnt1=0,a;
	while(1)
	{
    printf("\nWhat's up?\n1.Insert()\n2.Delete()\n3.Display()\n 1.Preorder\t2.Inorder\t3.Postorder\n4.Count Nodes\n5.Count Leaf Nodes\n6.AVL or not?\n7.Exit\n.\nAnswer : ");
	scanf("%d",&sw);
	switch(sw)
	{
	case 1:insert();
	break;
	case 2:delete();
	break;
	case 3:printf("How : ");
	scanf("%d",&se);
	if(se==1)
	preorder(root);
	if(se==2)
	inorder(root);
	if(se==3)
	postorder(root);
	break;
	case 4:count=0;
	cnt=counter(root);
	printf("%d",cnt);
	break;
	case 5:count1=0;
	cnt1=counter_leaf(root);
	printf("%d",cnt1);
	break;
	case 6:a=check_avl(root);
	if(a==1)
	printf("\nAVL");
	else
	printf("\nNOT AVL");
	break;
	case 7:exit(1);
	break;
	default:printf("\nInvalid Choice");
	}
	}
	
	return 0;
}
