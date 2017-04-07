/*

It's Lolympics 2016 right now, and we all know who's the best player there right now: Kalyani! Obviously, he has a huge female fan following and he has to make sure they are all happy and rooting for him to win the gold medals.

But with fan following comes arrogance and lack of time. Thus, he has sufficient time to interact with atmost T of his fans. Each fan is defined by two parameters : Name and Fan Quotient. The name defines the name of the fan, while the fan quotient is a measure of the fan's devotion towards Kalyani. Higher the fan quotient, greater is the devotion. Kalyani now wants to meet T of his fans. While selecting the fans he wants to meet, he wants to make sure that a fan with a higher fan quotient should be given a chance in favour of those with lesser fan quotient. In case of ties, he sorts their name lexicographically and chooses the lexicographically lesser named fan.

Given details of N fans, can you help out Kalyani by giving him a list of fans he would be interacting with?

Input Format :

The first line contains N and T, the number of fans and the maximum number of fans Kalyani can meet. Each of the next N lines contains a string and an integer separated by a space. The string denotes the name of the fan while the integer depicts the fan quotient.

Output Format :

Output T lines, each containing the name of the fans selected. Fans with higher fan quotient should be outputted first and in case of a tie, the lexicographically minimum name should come first.

Constraints :

1≤T≤N≤1000
1≤lengthofname≤20
1≤fanquotient≤109
1≤fanquotient≤109
Name would only consist of characters in set [a-z]. It is not guaranteed that the names are distinct.

Sample Input
-----------
3 2
surbhi 3
surpanakha 3
shreya 5

Sample Output
-------------
shreya
surbhi

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	long long int coeff;
	char name[20];
}fan;

int stringCompare(char str1[],char str2[]){
    int i=0,flag=0;
   
    while(str1[i]!='\0' && str2[i]!='\0'){
         if(str1[i]!=str2[i]){
             flag=1;
             break;
         }
         i++;
    }

    if (flag==0 && str1[i]=='\0' && str2[i]=='\0')
         return 0;
    else if(str1[i] < str2[i])
         return 1;
     else
     	return -1;

}


void bubblesort(fan *a,int N){
	for (int i = 0 ; i < N-1 ; i++){
		for (int j = 0 ; j < N - i - 1 ; j++){
			if(a[j].coeff > a[j+1].coeff){
				fan temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}else if(a[j].coeff == a[j+1].coeff){
				int cmp_result = stringCompare(a[j].name,a[j+1].name);
				if(cmp_result > 0){
					fan temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
			}
		}
	}
}



int main(int argc, char const *argv[])
{
	/* code */
	int num_fans,num_fans_can_meet;
	int *a,*b,N,cantreat=0;

	scanf("%d",&num_fans);
	scanf("%d",&num_fans_can_meet);

	fan *fans = malloc(sizeof(fan)*num_fans);

	for(int i = 0; i < num_fans; i++){
		scanf("%s",&fans[i].name);
		scanf("%lld",&fans[i].coeff);
	}

	bubblesort(fans,num_fans);

	for(int i = 0; i<num_fans_can_meet ;i++){
		printf("%s\n",fans[num_fans -i -1].name );
	}

	return 0;
}