#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long long sum = 0;

/* generate sum from 0 up to limit */
void* sum_to_limit(void *arg)
{
    long long *limit = (long long*) arg;

    long long i;
    for(i = 0; i <= *limit; i++)
    {
        sum += i;
    }

    pthread_exit(0);
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Invalid number of arguments! Expected 2!\n");
        return -1;
    }

    long long limit = atoll(argv[1]);
    
    pthread_t t_id;
    pthread_attr_t t_attr;
    pthread_attr_init(&t_attr);
    
    pthread_create(&t_id, &t_attr, sum_to_limit, &limit);

    /* wait for the thread to terminate */
    pthread_join(t_id, NULL);

    printf("Sum is %lld\n", sum);

    return 0;
}
