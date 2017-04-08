/*

Consider an Array 
a of size N
Iterate from 1 to N In ith
ith iteration select the 
ith
ith minimum and swap it with 
a[i]
a[i]
You are given an array 
a, size of the array 
N and an integer 
x. Follow the above algorithm and print the state of the array after 
x iterations have been performed.

Input Format

The first line contains two integer 
N and x denoting the size of the array and the steps of the above algorithm to be performed respectively. The next line contains 
N space separated integers denoting the elements of the array.

Output Format

Print 
N space separated integers denoting the state of the array after 
x steps

Constraints
1≤N≤100
1≤a[i]≤100
1≤x≤N

Sample Input
-----------
2
5 2
1 2 3 4 5

Sample Output
-------------
1 2 3 4 5

*/

#include <stdio.h>
#include <stdlib.h>


void selection_sort (int *A, int n,int x) {
        // temporary variable to store the position of minimum element

        int minimum;        
        // reduces the effective size of the array by one in  each iteration.

        for(int i = 0; i < x; i++)  {

           // assuming the first element to be the minimum of the unsorted array .
             minimum = i ;

          // gives the effective size of the unsorted  array .

            for(int j = i+1; j < n ; j++ ) {
                if(A[ j ] < A[ minimum ])  {                //finds the minimum element
                minimum = j ;
                }
             }
          // putting minimum element on its proper position.

             int temp = A[minimum];
             A[minimum] = A[i];
             A[i] = temp;
//          swap ( A[ minimum ], A[ i ]) ; 
        }
   }





int main(int argc, char const *argv[])
{
	/* code */
	int n,x;
	int *a;

	scanf("%d",&n);
	scanf("%d",&x);

	a = malloc(sizeof(int)*n);

	for(int i=0; i < n ; i++){
		scanf("%d",&a[i]);
	}

	selection_sort(a,n,x);

	for(int i = 0; i<n ;i++){
		printf("%d ",a[i]);
	}

	return 0;
}