#include <stdio.h>
#include <stdlib.h>

struct node
{
	int city;
	int gang;
	struct node * left;
	struct node * right;
};

struct node * make_node(int num)
{
	struct node * new_node = (struct node *)malloc(sizeof(struct node));
	new_node->city = num;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

void join_tree(struct node ** p,int num_node)
{
    int i = 0;
    while(i!=num_node){
		if(2*i+1>num_node){
			break;
			i++;
		}
		p[i]->left = p[2*i+1];
		if(2*i+2>num_node){
			break;
			i++;
		}
		p[i]->right = p[2*i+2];
		i++;
      
	}

}

int gang_on_path(struct node ** p, int gang_[],int l,int r)
{
    int a=l-1,b=r-1,n=0;

	while(a!=b){
		
		if(a!=0 && a<b){
		gang_[(p[a]->gang)-1] += 1;
		a=(a-1)/2;
		n++;
		}
		
		if(b!=0 && b>a){
		gang_[(p[b]->gang)-1] += 1;
		b=(b-1)/2;
		n++;
		}
		
	}
	gang_[(p[a]->gang)-1] += 1;
	n++;

    return n;
}

int Safe_or_Dangerous(int gang_no[],int num_node,int n)
{
    int i=0 , k=0;
	while(i!=num_node){
		if(gang_no[i]>n/2){
			
			printf("DANGEROUS AS GANG NO. %d IS IN MAJORITY!!\n",i+1);
			k++;
		}
		i++;
	}
	if(k==0){
		printf("SAFE\n");	
	}
	
}

int main(){
	int num_node,i=0,M;
	printf("Enter no. of cities and Plans : ");
	scanf("%d %d",&num_node,&M);
	
    struct node * p[num_node];
   
	while(i!=num_node){
      
        p[i] = make_node(i+1);
		i++;
	}
    join_tree(p,num_node);

	int gang_[num_node];
	

	printf("Gang number seperated by space: ");
	i=0;
	while(i!=num_node){
        
		scanf("%d",&(p[i]->gang));
		i++;
	}
	
	int l[M],r[M];
    printf("Enter l(starting city) and r(End city): \n");
	for(int m = 0; m < M; m++){
        
	    scanf("%d %d",&l[m],&r[m]);
        
    }
	for(int m = 0; m<M;m++){
		i=0;
	while(i!=num_node){
		gang_[i] = 0;
		i++;
	}
	
    int n = gang_on_path(p,gang_,l[m],r[m]);

    Safe_or_Dangerous(gang_,num_node,n);
        	           
    }
}
