#include <stdio.h>

int countOdds(int low, int high){
    if(low % 2 == 0 && high % 2 ==0){
        return (high - low) / 2;
    }
    else{
        return (high - low) / 2 + 1;
    }
}

int main(void){
    // int low = 3;
    // int high = 7;

    // int low = 8;
    // int high = 10;

    int low = 8;
    int high = 11;

    printf("%d\n", countOdds(low, high));

    return 0;
}
