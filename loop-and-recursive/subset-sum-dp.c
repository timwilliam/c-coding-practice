// Problem  : Subset Sum w/ Memoization
// Author   : timwilliam
// Compiled : 08/11/2021
// Notes    : Reference YouTube Tutorial https://youtu.be/nqlNzOcnCfs

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct _MEMORY{
    char key[10];
    int return_value;
}MEMORY;

// clear out the memory
void resetMem(MEMORY *my_mem, int size_of_mem){
    int i;

    for(i = 0; i < size_of_mem; i++){
        strcpy(my_mem[i].key, "NA");
        my_mem[i].return_value = -1;
    }
    return;
}

// print out the contents of the memory for debugging purposes
void printMem(MEMORY *my_mem, int size_of_mem){
    int i;
    for(i = 0; i < size_of_mem; i++){
        if(strcmp(my_mem[i].key, "NA") == 0 && my_mem[i].return_value == -1)
            printf("Mem slot %d is empty!\n", i);
        else
            printf("Mem slot %d has key = %s & ret_value = %d\n", i, my_mem[i].key, my_mem[i].return_value);
    }

    return;
}

int isKeyExist(MEMORY *my_mem, int size_of_mem, char *target_key){
    int i;
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

void insertKey(MEMORY *my_mem, int size_of_mem, char *key, int return_value){
    // only fill in new data
    if(isKeyExist(my_mem, size_of_mem, key) > -1)
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
int getNumberOfSubset(int *set, int target_sum, int marker, MEMORY *my_mem, int size_of_mem){
    char key[10];
    char *ptr;
    int key_location, temp;

    hashFunction(target_sum, marker, key);
    key_location = isKeyExist(my_mem, size_of_mem, key);
    
    if(key_location > -1)
        return my_mem[key_location].return_value;
    
    if(target_sum == 0)
        return 1;
    else if(target_sum < 0)
        return 0;
    else if(marker < 0)
        return 0;
    else if(set[marker] > target_sum)
        temp = getNumberOfSubset(set, target_sum, marker - 1, my_mem, size_of_mem);
    else
        temp = getNumberOfSubset(set, target_sum, marker - 1, my_mem, size_of_mem) + \
                getNumberOfSubset(set, target_sum - set[marker], marker - 1, my_mem, size_of_mem);
    
    insertKey(my_mem, size_of_mem, key, temp);
    return temp;
}

int main(void){
    int set[4] = {2, 4, 6, 10};
    int target_sum = 16;

    int size_of_set = sizeof(set) / sizeof(int);
    int size_of_mem = (int) (pow(2, sizeof + 1) - 1);
    
    int n_subset;
    MEMORY *my_mem = (MEMORY*) malloc(size_of_mem * sizeof(MEMORY));
    resetMem(my_mem, size_of_mem);

    n_subset = getNumberOfSubset(set, target_sum, size_of_set - 1, my_mem, size_of_mem);
    printf("%d\n", n_subset);
    printMem(my_mem, size_of_mem);

    return 0;
}