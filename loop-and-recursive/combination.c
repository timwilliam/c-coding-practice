#include <stdio.h>
#include <stdlib.h>

int factorial(int number){
    if(number == 1 || number == 0)
        return 1;

    return number * factorial(number-1);
}

int get_n_combination(int n, int r){
    return factorial(n) / (factorial(r) * factorial(n-r));
}

void print_combination(int *combo, int r){
    int i;
    char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(i = 0; i < r; i++)
        printf("%d", combo[i]);
    
    // for(i = 0; i < r; i++)
    //     printf("%c", str[combo[i]]);

    printf("\n");

    return;
}

void list_combinations(int n, int r){
    int i, j, key, *combo;

    combo = malloc(r * sizeof(int));
    for(i = 0; i < r; i++)
        combo[i] = i;

    if(n == r){
        print_combination(combo, r);
        return;
    }

    key = r - 1;
    while(key >= 0){
        print_combination(combo, r);
        for(i = r-1; i >= key; i--){
            while(combo[i] < n-r+i){
                combo[i]++;
                print_combination(combo, r);
            }
        }
        
        // reset
        key--;
        combo[key]++;
        for(j = key+1; j < r; j++)
            combo[j] = combo[j-1] + 1;
        printf("Reset to ");
        print_combination(combo, r);
    }

    return;
}

int main(void){
    int n, r, n_combination;

    // while(scanf("%d %d", &n, &r)){
    //     if(n == 0 && r == 0)
    //         break;

    //     n_combination = get_n_combination(n, r);
    //     printf("Number of possible combination: %d\n", n_combination);
    //     list_combinations(n, r);
    // }
    n = 5; r = 3;
    n_combination = get_n_combination(n, r);
    printf("Number of possible combination: %d\n", n_combination);
    list_combinations(n, r);

    return 0;
}