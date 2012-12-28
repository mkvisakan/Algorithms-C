
//structure used to keep the knapsack entries
typedef struct knapsack_t{
        int maxWeight;
        int itemCount;
        int* valuesArray;
        int* weightArray;
} knapsack;


knapsack* initialize_knapsack(int maxWeight, int itemCount, int* valuesArray, int* weightArray);
int do_knapsack(knapsack* k);          
