#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N_LOOP 500000

long long sum = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *sum_func(void *arg)
{
    long long i;
    int offset = *(int*) arg;

    for(i = 0; i < N_LOOP; i++)
    {
        /* critical section start */
        pthread_mutex_lock(&mutex);

        sum += offset;

        /* critical section end */
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main(void)
{
    pthread_t t1, t2;
    int offset1, offset2;

    offset1 = 1;
    pthread_create(&t1, NULL, sum_func, &offset1);

    offset2 = -1;
    pthread_create(&t2, NULL, sum_func, &offset2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Sum = %lld\n", sum);

    return 0;
}
