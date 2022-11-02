#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define limit 50

typedef struct node {

    int data;
    struct node* left;
    struct node* right;

} node;

node* accessNode ( node* test, node* l, node* r, int v)
{
    test -> left = l;
    test -> right = r;
    test -> data = v;
    return test;
}

int arr[limit];

node* version[limit];

void buildTree ( node* newNode, int start, int finish )
{   
    if ( start == finish  ) 
    {
        newNode -> data = arr[start];
        return ;
    }

    int add = start+finish;
    int centre = add/2;

    newNode -> left = malloc(sizeof(node));
    newNode -> left = accessNode( newNode -> left, NULL, NULL, 0);

    newNode -> right = malloc(sizeof(node));
    newNode -> right = accessNode( newNode -> right, NULL, NULL, 0);

    buildTree ( newNode -> left, start, centre);
    buildTree ( newNode -> right, centre+1, finish);

    newNode -> data = newNode -> left -> data + newNode -> right -> data;

}

void updateTree (node* past, node* present, int start, int finish, int index, int key)
{
    if ( index > finish || index < start || start > finish)
    {
        return;
    }

    if ( start == finish)
    {
        present -> data = key;
        return;
    }

    int add = start + finish;
    int centre = add/2;

    if ( index <= centre)
    {
        present -> right = past -> right;
        present -> left = malloc ( sizeof(node) );
        present -> left = accessNode(present -> left, NULL, NULL, 0);

        updateTree ( past -> left, present -> left, start, centre, index, key);

    }

    else 
    {
        present -> left = past -> left;
        present -> right = malloc (sizeof(node));
        present -> right = accessNode (present -> right, NULL, NULL, 0);
        updateTree ( past -> right, present -> right, centre + 1, finish, index, key);
    
    }

    present -> data = present -> left -> data + present -> right -> data;
}

int request ( node* myNode, int start, int finish, int begin, int end)
{
    if ( begin > finish || end < finish || start > finish)
    {
        return false;
    }

    if ( begin <= start && finish <= end )
    {
        return myNode -> data; 
    }

    int add = start + finish;
    int centre = add / 2;

    int left = request ( myNode -> left, start, centre, begin, end);

    int right = request ( myNode -> right, centre + 1, finish, begin, end);

    int answer = left + right;

    return answer;
}


int main()
{   
    int arr_size,queries;

    printf ("Enter the size of the array: ");
    scanf ("%d",&arr_size);

    printf ("Enter the number of queries to be performed: ");
    scanf("%d",&queries);

    int array[arr_size];
    int num = arr_size - 1;
    //for ( int w = 0; w < queries; w++)
    //{   
        printf ("Enter array elements separated by spaces: \n");
        for ( int t = 0; t < arr_size; t++)
        {
            scanf("%d",&array[t]);
        }

        node* node_0 = malloc (sizeof(node));
        node_0 = accessNode( node_0, NULL, NULL, 0 );
        buildTree( node_0,0,num);


        version[0] = node_0;
        int choice = 0;
        printf ("Enter number of versions: ");
        scanf ("%d",&choice);
        int changedValue,index;

        for (int i = 1; i < choice; i++)
        {   
            
            printf("Enter Index and new value separated with spaces: ");
            scanf("%d%d", &index,&changedValue);

            node* nodeVersion = malloc ( sizeof(node) );
           
            nodeVersion = accessNode( nodeVersion, NULL, NULL, 0 );
            version[i] = nodeVersion;

            updateTree ( version[i-1], version[i], 0, num, index, changedValue );
        }

        // node* nodeVersion = malloc ( sizeof(node) );
           
        //     nodeVersion = accessNode( nodeVersion, NULL, NULL, 0 );
        //     version[1] = nodeVersion;

        //     updateTree ( version[0], version[1], 0, num, 2, 10 );
        
         
        printf("In version 1, query(0,4) : ");
        printf ("%d\n", request(version[1],0,num,0,4));

        printf("In version 2, query(3,4) : ");
        printf ("%d\n", request(version[2],0,num,3,4));

        printf("In version 0, query(0,3) : ");
        printf ("%d\n", request(version[0],0,num,0,3));


        




    //}

    
}
