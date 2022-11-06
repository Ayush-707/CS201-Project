#include <stdio.h>
#include <stdlib.h>


#define limit 500

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
    int add = start+finish;
    int centre = add/2;

    if ( start == finish  ) 
    {
        newNode -> data = list[start];
        return ;
    }

    newNode -> left = createNode( NULL, NULL, 0);

    newNode -> right = createNode( NULL, NULL, 0);

    makeTree ( newNode -> left, start, centre);
    makeTree ( newNode -> right, centre+1, finish);

    newNode -> data = newNode -> left -> data + newNode -> right -> data;

}

void updateTree (struct node* past, struct node* present, int start, int finish, int index, int key)
{   
    int add = start + finish;
    int centre = add/2;

    if ( index > finish || index < start || start > finish)
    {
        return;
    }

    if ( start == finish)
    {
        present -> data = key;
        return;
    }

    if ( index <= centre)
    {
        present -> right = past -> right;
        
        present -> left = createNode( NULL, NULL, 0);

        updateTree ( past -> left, present -> left, start, centre, index, key);
    }

    else 
    {
        present -> left = past -> left;
    
        present -> right = createNode ( NULL, NULL, 0);

        updateTree ( past -> right, present -> right, centre + 1, finish, index, key);
    }

    present -> data = present -> left -> data + present -> right -> data;
}

int request ( struct node* myNode, int start, int finish, int begin, int end)
{   
    int add = start + finish;
    int centre = add / 2;
    int half_1,half_2,answer;

    if ( begin > finish || end < start || start > finish)
    {
        return 0;
    }

    if ( begin <= start && finish <= end )
    {
        return myNode -> data; 
    }

    half_1 = request ( myNode -> left, start, centre, begin, end);

    half_2 = request ( myNode -> right, centre + 1, finish, begin, end);

    answer = half_1 + half_2;

    return answer;
}


int main()
{
    int arr_size,queries;
    int ver_count = 0;
    int changedValue,index;
    int l,r;
    int version;

    printf ("Enter the size of the array: ");
    scanf ("%d",&arr_size);

    printf ("Enter array elements separated by spaces: \n");
    for ( int t = 0; t < arr_size; t++)
    {
        scanf("%d",&list[t]);
    }

    int num = arr_size - 1;

    printf ("Enter number of versions to be constructed for the segement tree: ");
    scanf ("%d",&ver_count);


    struct node* node_0 = createNode( NULL, NULL, 0 );
    makeTree( node_0,0,num);

    roots[0] = node_0;


    for (int i = 1; i < ver_count; i++)
    {

        printf("Enter Index to be updated and new value separated with spaces: ");
        scanf("%d %d", &index,&changedValue);
        roots[i] = createNode(NULL, NULL, 0);
        updateTree ( roots[i-1], roots[i], 0, num, index, changedValue );
    }

    while(1) {
        char flag;
        printf ("Press q to quit or y to continue: ");
        scanf (" %c",&flag);
        
        if ( flag != 'q' || flag != 'Q'  || flag != 'y' || flag != 'Y')
        {
            printf("\nInvalid Input Detected!\n");
            continue;
        }
        if( flag == 'q' || flag == 'Q')
        {
            printf("\nExiting Program.............\n");
            exit(0);
        }

        printf("Enter the value of l in arr[l,r]: ");
        scanf("%d",&l);

        printf("Enter the value of r in arr[l,r]: ");
        scanf("%d",&r);

        if ( l > r) {
            perror("\nInvalid Input Detected!\n");
            continue;
        }


        printf ("Enter desired version: ");
        scanf("%d",&version);

        if ( version >= ver_count)
        {
            printf("Invalid version entered!\n");
            continue;
        }

        printf ("\nThe sum of elements in the segment [%d,%d] in version [%d] = %d\n",l,r,version,request(roots[version],0,num,l,r));
    }
}
