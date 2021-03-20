## Tim’s Note on C Programming

**Reset a 2D array**
- Useful in array for strings too.
- Assume: `target_array[100][120]`
```c
#include<string.h>
	
memset(target_array, 0, sizeof(target_array[0][0]) * 100 * 120)
```

**Trim new line character before `fgets()`**
- Useful when we want to use `fgets()` after using `scanf()` earlier.
```c
	scanf("%d", &n);
	getchar();
```

** Loop for n amount of times**
```c
	scanf("%d", &n);
	getchar();

	while(n--){
		// Do stuff here ~
	}
```

** Trim new line character in an array**
```c
	char input[100];

	fgets(input, 100, stdin);
	input[strcspn(input, 0, "\n")] = 0;
```

** Check if an index has been processed before**
```c
	int checked[1000] = {0}, temp;
	time_t t;

	srand((unsigned) time(&t));

	while(1){
		temp = rand() % 1000;
			
		if(checked[temp] == 1) break;
		else checked[temp] = 1;
	}
```

**Sort Array Ascending**
```c
int cmpfunc(const void *a, const void *b){
	// Swap a & b position to make it sort Descending !!!
	return (*(int*) a - *(int*) b);
}

int main(void){
	int array[5] = {100, 6, 50, 20, 4};

	qsort(array, 5, sizeof(int), cmpfunc);
}
```

