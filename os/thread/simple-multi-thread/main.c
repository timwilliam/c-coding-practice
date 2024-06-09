#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

/* because pthread_create only accepts one pointer argument,
 * use structure to return multiple variable */
struct sum_s{
    long long limit;
    long long sum;
    pid_t tid;
};

/* generate sum from 0 up to limit */
void* sum_to_limit(void *arg)
{
    struct sum_s *sum_s_ptr = (struct sum_s*) arg;

    long long i, sum = 0;
    for(i = 0; i <= sum_s_ptr->limit; i++)
    {
        sum += i;
    }

    sum_s_ptr->sum = sum;
    sum_s_ptr->tid = gettid();

    pthread_exit(0);
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Invalid number of arguments! Expected > 2!\n");
        return -1;
    }

    int i, n_args = argc - 1;

    pthread_t t_ids[n_args];
    struct sum_s sum_from_thread[n_args];

    for(i = 0; i < n_args; i++)
    {
        sum_from_thread[i].limit = atoll(argv[i+1]);

        pthread_attr_t t_attr;
        pthread_attr_init(&t_attr);

        pthread_create(&t_ids[i], &t_attr, sum_to_limit, &sum_from_thread[i]);
    }

    for(i = 0; i < n_args; i++)
    {
        /* wait for the thread to terminate, processing still done sequentially */
        pthread_join(t_ids[i], NULL);

        printf("Sum from tid=%d is %lld\n", sum_from_thread[i].tid, sum_from_thread[i].sum);
    }
    
    return 0;
}
