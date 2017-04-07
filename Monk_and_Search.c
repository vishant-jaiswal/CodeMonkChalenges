//1 2 3 4 5 6 7 8 9 0 11 12 15

#include <stdio.h>
#include <stdlib.h>

void quicksort(int a[],int l,int r)
{
	int i=l+1;
	int j=r;
	int p=l;
	int temp;
	int z;
	for(;;)
	{
		while(a[i]<=a[p] && (i<r))
		{
			i++;
		}
		while(a[p]<a[j] && (j>l))
		{
			j--;
		}
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}else
			break;
	}
	temp=a[j];
	a[j]=a[p];
	a[p]=temp;
	if((i-1)>l)
	quicksort(a,l,i-1);
	if(i<r)
	quicksort(a,i,r);
}

int findnotless(int *a,int key,int l){
	int len = l;
	int low = 0;
	int mid = 0;
	int start = 0;
	int end = l;

	while(start<end){
		int mid = (start+end)>>1;
		printf("mid%d\n",mid );
		if(a[mid]<=key)
			start = mid + 1;
		else
			end = mid;
	}
	return start;


}


int findgreater(int *a,int key,int l){

	int start = 0;
	int end = l;
	while(start<end){
		int mid = (start+end)>>1;
		if(a[mid]<=key)
			start = mid + 1;
		else
			end = mid;
	}
	return start;


}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d",&N);
	int *A = malloc(sizeof(int)*N);

	for (int i =0 ; i<N; i++){
		scanf("%d",&A[i]);
	}

	int Q;
	quicksort(A,0,N-1);
	scanf("%d",&Q);

	for (int j = 0 ; j<Q ; j++){
		int t;
		scanf("%d",&t);
		int num = 0;
		scanf("%d",&num);
		if(t == 0){
			printf("%d\n",N - findnotless(A,num,N));
		}
		else if (t == 1){
			printf("%d\n",N - findgreater(A,num,N));
			//findgreater(A,num);
		}
	}


	/*for (int i =0 ; i<N; i++){
		printf("%d",A[i]);*/
	return 0;
}