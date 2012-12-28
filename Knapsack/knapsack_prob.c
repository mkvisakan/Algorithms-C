#include <stdio.h>
#include <conio.h>
#include "Knapsack.h"

int main(){
    int maxWeight, itemCount;
    int* valuesArray;
    int* weightArray;
    int i;
    
    //get the input
    printf("Enter the Max Weight: \n");
    scanf("%d", &maxWeight);
    
    printf("Enter the itemCount : \n");
    scanf("%d", &itemCount);
    
    valuesArray = (int*)malloc(itemCount * sizeof(int));
    weightArray = (int*)malloc(itemCount * sizeof(int));
    
    printf("Enter value followed by its weight separated by tab : \n");
    for(i=0; i<itemCount; i++)
        scanf("%d\t%d", valuesArray+i, weightArray+i);
        
    //initialize knapsack
    knapsack* k = initialize_knapsack(maxWeight, itemCount, valuesArray, weightArray);
    
    int res = do_knapsack(k);
    
    if (res!= -1)
       printf("RESULT : %d\n", res);
    
    getchar();
    getchar();
    return 0;
}
