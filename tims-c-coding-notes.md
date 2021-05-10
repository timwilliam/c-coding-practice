# Tim’s Note on C Programming

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

**Loop for n amount of times**

```c
scanf("%d", &n);
getchar();

while(n--){
    // Do stuff here ~
}
```

**Trim new line character in an array**

```c
    char input[100];

    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;
```

**Check if an index has been processed before**

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

- For Integer Array

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

- For String
  
  ```c
  int cmpfunc(const void *a, const void *b){
      return strcmp(*(const char**) a, *(const char**) b);
  }
  
  int main(void){
      const char *arr[] = {"Basswood", "Cherry", "Hard Maple", "Yellow Birch", "Ash", "Aspen"};
      int n = sizeof(arr) / sizeof(arr[0]);
  
      qsort(arr, n, sizeof(const char*), cmpfunc);
  }
  ```

- For Structure

```c
struct order{
    int number;
};

int fcmp(const void *a, const void *b){
    return((struct order*)a)->number - ((struct order*)b)->number);
}

int main(void){
    qsort(orders, n, sizeof(struct(order), fcmp);
}
```

**Defining a Macro Function**

```c
#define MAX(x, y) (x > y? x : y)
#define MIN(x, y) (x < y? x : y)
```

**Split Strings into Tokens**

```c
char *token;
char text[5] = "test";
char delim[2] = " ";

token = strtok(text, delim);

while(token != NULL){
    printf("%s\n", token);
    token = strtok(NULL, delim);
}
```

**Copy an Array to another Array**

```c
int original[15], copy[15];

memcpy(copy, original, sizeof(int) * 15);
```

**Defining a 2D Array**

```c
int array[2][5] = {
    {0, 1, 2, 3, 4},
    {5, 6, 7, 8, 9}
};

int i, j;
for(i = 0; i < 2; i++){
    for(j = 0; j < 5; j++){
        printf("%d, ", array[i][j]);
       }
    printf("\n");
}
```

**Find a string in another string**

```c
const char haystack[20] = "This is a test";
const char needle[10] = "is";
char *ret;

ret = strstr(haystack, needle); // will get the substring
printf("The substring is: %s\n", ret);
```
