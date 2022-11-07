
<h3>Persistent Segment Trees</h3>



<h4> A Summary of the project:- </h4>

We have implemented Persistent Segement tree algorithm and solved real life problem based on it.

Problem statement for Algorithm is as follows:
Given an input array A[] and different point update operations. Considering each point operation to create a new version of the array. We need to answer the queries of type
Output the sum of elements of the array A[] in the range [l,r] in the desired version

EXPECTED OUTPUT AND INSTRUCTIONS ON HOW TO ENTER INPUT:

Enter the size of the array: 5
Enter array elements separated by spaces: 
1 2 3 4 5                                                              -----------> Creates the version - 0 of the tree
Enter number of versions to be constructed for the segement tree: 3
Enter Index to be updated and new value separated with spaces: 0 10    -----------> Creates the version - 1 of the tree
Enter Index to be updated and new value separated with spaces: 4 50    -----------> Creates the version - 2 of the tree
Press q to quit or y to continue: y  -----------> Press q to exit the program, else press y to continue. If anything else is entered program should throw an error.
Enter the value of l in arr[l,r]: 0  
Enter the value of r in arr[l,r]: 4
Enter desired version: 0

The sum of elements in the segment [0,4] in version [0] = 15
Press q to quit or y to continue: y
Enter the value of l in arr[l,r]: 0
Enter the value of r in arr[l,r]: 4
Enter desired version: 1

The sum of elements in the segment [0,4] in version [1] = 24
Press q to quit or y to continue: y
Enter the value of l in arr[l,r]: 0
Enter the value of r in arr[l,r]: 4
Enter desired version: 2

The sum of elements in the segment [0,4] in version [2] = 69
Press q to quit or y to continue: q

Exiting Program.............

---------------X----------------- //END FOR Algorithm OUTPUT

EXPECTED INPUT FOR GANGS ON PATH PROBLEM:

Enter no. of cities and Plans : 6 8
Gang number seperated by space: 3 1 2 3 3 3
Enter l(starting city) and r(End city): 
1 2
1 3
2 4
2 5
3 6
4 6
2 3
4 5

EXPECTED OUTPUT FOR GANGS ON PATH PROBLEM:

SAFE
SAFE
SAFE
SAFE
SAFE
DANGEROUS AS GANG NO. 3 IS IN MAJORITY!!
SAFE
DANGEROUS AS GANG NO. 3 IS IN MAJORITY!!

---------------X----------------- //END FOR gangs on path OUTPUT
