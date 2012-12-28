//structure to store the data
typedef struct lcs_t{
    int arr1count;
    int arr2count;
    char* arr1;
    char* arr2;
}lcs;

lcs* initialize_lcs(int count1, int count2, char* arr1, char* arr2);
int find_lcs(lcs* l);
