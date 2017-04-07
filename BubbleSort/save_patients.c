/*

A new deadly virus has infected large population of a planet. A brilliant scientist has discovered a new strain of virus which can cure this disease. Vaccine produced from this virus has various strength depending on midichlorians count. A person is cured only if midichlorians count in vaccine batch is more than midichlorians count of person. A doctor receives a new set of report which contains midichlorians count of each infected patient, Practo stores all vaccine doctor has and their midichlorians count. You need to determine if doctor can save all patients with the vaccines he has. The number of vaccines and patients are equal.

Input Format

First line contains the number of vaccines - 
N
N. Second line contains 
N
N integers, which are strength of vaccines. Third line contains 
N
N integers, which are midichlorians count of patients.

Output Format

Print a single line containing 
′Yes′
′Yes′ or′No′
′No′.

Input Constraint

1
<
N
<
10
1<N<10
Strength of vaccines and midichlorians count of patients fit in integer.

Sample Input
-----------
5
123 146 454 542 456
100 328 248 689 200

Sample Output
-------------
No

*/

#include <stdio.h>
#include <stdlib.h>


void bubblesort(int *a,int N){
	for (int i = 0 ; i < N-1 ; i++){
		for (int j = 0 ; j < N - i - 1 ; j++){
			if(a[j] > a[j+1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}



int main(int argc, char const *argv[])
{
	/* code */
	int *a,*b,N,cantreat=0;

	scanf("%d",&N);
	a = malloc(sizeof(int)*N);
	b = malloc(sizeof(int)*N);

	for(int i = 0; i<N ; i++){
		//printf("here i:%d N:%d\n",i,N);
		scanf("%d",&a[i]);
	}

	for(int i = 0; i<N ; i++){
		//printf("be here\n");
		scanf("%d",&b[i]);
	}

	bubblesort(a,N);
	bubblesort(b,N);

	for(int i = 0; i<N ;i++){
		if(b[i] > a[i]){
			cantreat++;
		}
	}

	if(cantreat > 0){
		printf("No");
	}else{
		printf("Yes");
	}

	return 0;
}