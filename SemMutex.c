// Gustavo Galhardo Rodrigues – 10403091 
// Pedro Nogueira Ribeiro – 10324924 

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define NUM_THREADS 3

long long n = 1000000000;
int thread_count = NUM_THREADS;

double factor = 1.0;
double sum = 0.0;

void* Thread_sum(void* rank) {
    long my_rank = (long) rank;
    long long i;
    double my_sum = 0.0;
    long long my_n = n / thread_count;
    long long my_first_i = my_n * my_rank;
    long long my_last_i = my_first_i + my_n;

    if (my_first_i % 2 == 0)
        factor = 1.0;
    else
        factor = -1.0;

    for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
        my_sum += factor / (2 * i + 1);
    }

    sum += my_sum;

    return NULL;
}

int main() {
    pthread_t thrs[NUM_THREADS];
    long idx;

    for (idx = 0; idx < thread_count; idx++) {
        pthread_create(&thrs[idx], NULL, Thread_sum, (void*) idx);
    }

    for (idx = 0; idx < thread_count; idx++) {
        pthread_join(thrs[idx], NULL);
    }

    double pi = 4.0 * sum;
    printf("\nTotal: %d", NUM_THREADS);
    printf("\nValor de PI = %.15f\n", pi);

    return 0;
}
