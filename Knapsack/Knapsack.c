#include <stdio.h>
#include "Knapsack.h"

//max of 2 integers
int max(int a, int b){
    return a>b?a:b;
}

//get the inputs and initialize the knapsack attributes
knapsack* initialize_knapsack(int maxWeight, int itemCount, int* valuesArray, int* weightArray){
    knapsack* k = (knapsack*)malloc(sizeof(knapsack));
    
    if(k == NULL)
        return NULL;
        
    k->maxWeight = maxWeight;
    k->itemCount = itemCount;
    k->valuesArray = valuesArray;
    k->weightArray = weightArray;
    
    return k;     
}

/** knapsack function :
    A 2-d int array is constructed where
        A[i][w] represents the max value obtained by using items from 1 to i whose weight is <= w
**/
int do_knapsack(knapsack* k){
    
    if(k == NULL || k->maxWeight <= 0 || k->itemCount <= 0)
        return -1;
    
    //initialize a dynamic array to use        
    int dp[k->itemCount + 1][k->maxWeight + 1];
    int i, w;
    
    //initialize dp[i][0] to zero cos weight is decided as 0
    for(i=0; i<=k->itemCount; i++){
        dp[i][0] = 0;
    }
    
    //initialize dp[0][i] to zero as no elts are selected
    for(i=0; i<=k->maxWeight; i++){
        dp[0][i] = 0;
    }
    
    //iterate given each value item, for each weight upto Max weight and update the dp array
    for(i=1; i<=k->itemCount; i++){
        for(w=0; w<=k->maxWeight; w++){
            //default one as the current item not selected
            dp[i][w] = dp[i-1][w];
            if(w-k->weightArray[i - 1] >= 0)
            {
                dp[i][w] = max(dp[i][w], dp[i-1][w-k->weightArray[i - 1]] + k->valuesArray[i - 1]);
            }
            
        }
    }
    
    //the final entry in the table is the result
    return dp[k->itemCount][k->maxWeight];
}



