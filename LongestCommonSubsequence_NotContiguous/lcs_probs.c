#include <stdio.h>
#include <conio.h>
#include "LCS.h"

int main(){
    int count1, count2;
    char* arr1;
    char* arr2;
    int i;
    
    //get the inputs
    printf("Enter count1<tab>count2 : \n");
    scanf("%d\t%d", &count1, &count2);
    
    arr1 = (char*)malloc(sizeof(char)*count1);
    arr2 = (char*)malloc(sizeof(char)*count2);
    
    printf("Enter string1 : \n");
    scanf("%s", arr1);
    
    printf("Enter string2 : \n");
    scanf("%s", arr2);
    
    //form lcs object
    lcs* l = initialize_lcs(count1, count2, arr1, arr2);
    
    //find the LCS
    int res = find_lcs(l);
    
    printf("RESULT : %d\n", res);
    
    getchar();
    getchar();
    return 0;
}
