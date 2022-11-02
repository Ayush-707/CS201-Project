#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define limit 50

struct node {

    int data;
    struct node* left;
    struct node* right;

};

struct node* createNode ( struct node* l, struct node* r, int v)
{   
    struct node* test = malloc (sizeof(struct node));
    test -> left = l;
    test -> right = r;
    test -> data = v;
    return test;
}

int list[limit];

struct node* roots[limit];

void makeTree ( struct node* newNode, int start, int finish )
{   
    if ( start == finish  ) 
    {
        newNode -> data = list[start];
        return ;
    }

    int add = start+finish;
    int centre = add/2;

    //newNode -> left = malloc(sizeof(struct node));
    newNode -> left = createNode( NULL, NULL, 0);

    //newNode -> right = malloc(sizeof(struct node));
    newNode -> right = createNode( NULL, NULL, 0);

    makeTree ( newNode -> left, start, centre);
    makeTree ( newNode -> right, centre+1, finish);

    newNode -> data = newNode -> left -> data + newNode -> right -> data;

}

void updateTree (struct node* past, struct node* present, int start, int finish, int index, int key)
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
        //present -> left = malloc ( sizeof(struct node) );
        present -> left = createNode( NULL, NULL, 0);

        updateTree ( past -> left, present -> left, start, centre, index, key);

    }

    else 
    {
        present -> left = past -> left;
        //present -> right = malloc (sizeof(struct node));
        present -> right = createNode ( NULL, NULL, 0);
        updateTree ( past -> right, present -> right, centre + 1, finish, index, key);
    
    }

    present -> data = present -> left -> data + present -> right -> data;
}

int request ( struct node* myNode, int start, int finish, int begin, int end)
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

    //int array[arr_size];
    int num = arr_size - 1;
    //for ( int w = 0; w < queries; w++)
    //{   
        printf ("Enter array elements separated by spaces: \n");
        for ( int t = 0; t < arr_size; t++)
        {
            scanf("%d",&list[t]);
        }

        //struct node* node_0 = malloc (sizeof(struct node));
        struct node* node_0 = createNode( NULL, NULL, 0 );
        makeTree( node_0,0,num);


        roots[0] = node_0;
        int choice = 0;
        printf ("Enter number of versions: ");
        scanf ("%d",&choice);
        int changedValue,index;

        for (int i = 1; i < choice; i++)
        {   
            
            printf("Enter Index and new value separated with spaces: ");
            scanf("%d%d", &index,&changedValue);

            //struct node* struct nodeVersion = malloc ( sizeof(struct node) );
           
            struct node* nodeVersion = createNode( NULL, NULL, 0 );
            roots[i] = nodeVersion;

            updateTree ( roots[i-1], roots[i], 0, num, index, changedValue );
        }

       // struct node* struct nodeVersion = malloc ( sizeof(struct node) );
           
            // struct node* nodeVersion = createNode( NULL, NULL, 0 );
            // roots[1] = nodeVersion;

            // updateTree ( roots[0], roots[1], 0, num, 2, 10 );
        
         
        printf("In version 1, query(0,4) : ");
        printf ("%d\n", request(roots[1],0,num,0,4));

        printf("In version 2, query(3,4) : ");
        printf ("%d\n", request(roots[2],0,num,3,4));

        printf("In version 0, query(0,3) : ");
        printf ("%d\n", request(roots[0],0,num,0,3));


        




    //}

    
}

