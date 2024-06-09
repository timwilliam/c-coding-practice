#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long long sum = 0;

/* generate sum from 0 up to limit */
void* sum_to_limit(void *limit_ptr)
{
    long long limit = *((long long*) limit_ptr);

    /* free up dynamically allocated memory pointed by limit_ptr */
    free(limit_ptr);

    long long i, sum_temp = 0;
    for(i = 0; i <= limit; i++)
    {
        sum_temp += i;
    }

    /* return data with dynamically allocated memory */
    long long *sum = (long long*) malloc(sizeof(*sum));
    *sum = sum_temp;

    /* note that receiving end should at some point free(), otherwise memory leak */
    pthread_exit(sum);
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Invalid number of arguments! Expected 2!\n");
        return -1;
    }

    long long *limit = (long long*) malloc(sizeof(*limit));
    *limit = atoll(argv[1]);
    
    pthread_t t_id;
    pthread_attr_t t_attr;
    pthread_attr_init(&t_attr);
    
    pthread_create(&t_id, &t_attr, sum_to_limit, limit);

    /* wait for the thread to terminate */
    long long *sum;
    pthread_join(t_id, (void**) &sum);

    printf("Sum is %lld\n", *sum);

    free(sum);
    return 0;
}
