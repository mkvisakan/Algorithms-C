#include <stdio.h>
#include "LCS.h"

//find the max value
int max(int a, int b){
    return a>b?a:b;
}

//initialize the lcs structure
lcs* initialize_lcs(int count1, int count2, char* arr1, char* arr2){
     lcs* l = (lcs*)malloc(sizeof(lcs));
     
     if(l==NULL)
         return NULL;
         
     l->arr1count = count1;
     l->arr2count = count2;
     l->arr1 = arr1;
     l->arr2 = arr2;
     
     return l;
}


/**find lcs using DP
   - uses a table dp[i][j] which gives the LCS using i chars from string 1 and j chars from string 2
**/
int find_lcs(lcs* l){
    //dp table
    int dp[l->arr1count + 1][l->arr2count + 1];
    int i, j;
    
    //initialize zeros for necessary entries
    for(i=0; i<=l->arr1count; i++)
        dp[i][0] = 0;
    for(i=0; i<=l->arr2count; i++)
        dp[0][i] = 0;
        
    //iterate given for each i chars from string 1 find common items from string 2
    for(i=1; i<=l->arr1count; i++){
        for(j=1; j<=l->arr2count; j++){
            if(l->arr1[i-1] == l->arr2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[l->arr1count][l->arr2count];
}


