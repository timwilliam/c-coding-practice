// Problem  : Subset Sum w/ Memoization
// Author   : timwilliam
// Compiled : 08/11/2021
// Notes    : Reference YouTube Tutorial https://youtu.be/nqlNzOcnCfs

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define KEYSIZE 10

typedef struct _MEMORY{
    char key[KEYSIZE];
    int return_value;
}MEMORY;

// global variable declaration for memory
int size_of_mem;
MEMORY *my_mem;

// clear out the memory
void resetMem(){
    int i;

    for(i = 0; i < size_of_mem; i++){
        strcpy(my_mem[i].key, "NA");
        my_mem[i].return_value = -1;
    }

    return;
}

// print out the contents of the memory for debugging purposes
void printMem(){
    int i;
    
    for(i = 0; i < size_of_mem; i++){
        if(strcmp(my_mem[i].key, "NA") == 0 && my_mem[i].return_value == -1)
            printf("Mem slot %d is empty!\n", i);
        else
            printf("Mem slot %d has key = %s & ret_value = %d\n", i, my_mem[i].key, my_mem[i].return_value);
    }

    return;
}

int isKeyExist(char *target_key){
    int i;
    
    // return the location of the key
    for(i = 0; i < size_of_mem; i++)
        if(strcmp(my_mem[i].key, target_key) == 0)
            return i;

    return -1;
}

// hashes target_sum and marker together to make a key
void hashFunction(int target_sum, int marker, char *key){
    // concatenate target_sum and marker together to make a key, separated by semicolon
    sprintf(key, "%d:%d", target_sum, marker);
    return;
}

void insertKey(char *key, int return_value){
    // only fill in new data
    if(isKeyExist(key) > -1)
        return;

    int i;
    for(i = 0; i < size_of_mem; i++){
        // look for an empty memory slot and then fill in the data
        if(strcmp(my_mem[i].key, "NA") == 0  && my_mem[i].return_value == -1){
            strcpy(my_mem[i].key, key);
            my_mem[i].return_value = return_value;
            break;
        }
    }

    return;
}

// the main function used to calculate the results
int getNumberOfSubset(int *set, int target_sum, int marker){
    char key[10], *ptr;
    int key_location, temp;

    // hashes are stored in key variable
    hashFunction(target_sum, marker, key);
    key_location = isKeyExist(key);
    
    // return previously calculate value that is stored in memory
    if(key_location > -1)
        return my_mem[key_location].return_value;
    
    if(target_sum == 0)
        return 1;
    else if(target_sum < 0)
        return 0;
    else if(marker < 0)
        return 0;
    else if(set[marker] > target_sum)
        temp = getNumberOfSubset(set, target_sum, marker - 1);
    else
        temp = getNumberOfSubset(set, target_sum, marker - 1) + \
                getNumberOfSubset(set, target_sum - set[marker], marker - 1);
    
    insertKey(key, temp);
    return temp;
}

int main(void){
    // User Input
    int set[4] = {2, 4, 6, 10};
    int target_sum = 16;

    int n_subset;
    int size_of_set = sizeof(set) / sizeof(int);

    // the number of all possible nodes in the tree is 2^(n+1) - 1
    size_of_mem = (int) (pow(2, sizeof + 1) - 1);
    my_mem = (MEMORY*) malloc(size_of_mem * sizeof(MEMORY));
    resetMem();

    n_subset = getNumberOfSubset(set, target_sum, size_of_set - 1);
    printf("%d\n", n_subset);
    
    // use the following function to show the content of memory
    // printMem();

    return 0;
}