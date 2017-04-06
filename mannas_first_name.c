/*

Manna is extremely disappointed to find out that no one in his college knows his first name. Even his classmates call him only by his last name. Frustrated, he decides to make his fellow college students know his first name by forcing them to solve this question.
You are given a long string as input in each testcase, containing any ASCII character. Your task is to find out the number of times SUVO and SUVOJIT appears in it.
Note: This problem must be solved in C language only.
Input Format
The first line contains the number of testcases, T. Next, T lines follow each containing a long string S.
Output Format
For each long string S, display the no. of times SUVO and SUVOJIT appears in it.

Sample Input
-----------
3
SUVOJITSU
651SUVOMN
$$$$$SUVOSUVOJIT$$$$$

Sample output
------------
SUVO = 0, SUVOJIT = 1
SUVO = 1, SUVOJIT = 0
SUVO = 1, SUVOJIT = 1
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main()
{
    int suvo_count =0;
    int suvojit_count = 0;
    int number_of_test_case = 0;
    char *string = malloc(sizeof(char)*150);
    char *suvojit = "SUVOJIT";
    char *head_suvojit = suvojit;
    scanf("%d",&number_of_test_case);
    for(int itr_number_of_test_case = 0 ; itr_number_of_test_case < number_of_test_case; itr_number_of_test_case++){
        scanf("%s",string);
        //printf("inside for number_of_test_case");
        //printf("itr_number_of_test_case:%d , number_of_test_case:%d\n", itr_number_of_test_case,number_of_test_case );
        for(int i=0;i< strlen(string);i++){
            //printf("i m here\n" );
            if(string[i] == *suvojit){
                //printf("1-string%d:%d:%c->suvojit:%d:%c\n",i,&string,string[i],suvojit,*suvojit );
                if(*suvojit == *(head_suvojit+3)){
                    //printf("1-head_suvojit:%d:%c->suvojit:%d:%c\n",head_suvojit,*(head_suvojit +3),suvojit,*suvojit );
                    suvo_count++;
                }
                if(*suvojit == *(head_suvojit+6)){
                    //printf("2:%d\n",head_suvojit );
                    suvojit_count++;
                }
                suvojit++;
            }else if(string[i] == *head_suvojit){
                //printf("3:%d\n",head_suvojit );
                suvojit = head_suvojit +1;
            }else{
                //printf("4:%d\n",head_suvojit );
                suvojit = head_suvojit;
            }
 
 
        }
        //printf("itr_number_of_test_case:%d , number_of_test_case:%d\n", itr_number_of_test_case,number_of_test_case );
        printf("SUVO = %d, SUVOJIT = %d\n",(suvo_count-suvojit_count),suvojit_count);
        suvo_count = 0;
        suvojit_count =0;
        //printf("i m here 2%c\n" ,*(head_suvojit+3));
    }
    suvojit = NULL;
    head_suvojit =NULL;
    return 0;
}