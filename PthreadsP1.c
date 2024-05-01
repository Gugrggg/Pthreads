// Gustavo Galhardo Rodrigues – 10403091 
// Pedro Nogueira Ribeiro – 10324924 

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define M 4  
#define N 4  
#define THREAD_COUNT 2  

double A[M][N];   
double x[N];      
double y[M];      
int thread_count = THREAD_COUNT;  

void *Pth_mat_vect(void* rank) {
    long my_rank = (long) rank;
    int i, j;
    int local_m = M / thread_count;
    int my_first_row = my_rank * local_m;
    int my_last_row = (my_rank + 1) * local_m - 1;

    for (i = my_first_row; i <= my_last_row; i++) {
        y[i] = 0.0;
        for (j = 0; j < N; j++) {
            y[i] += A[i][j] * x[j];
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[THREAD_COUNT];
    long thread;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = i + j;  
        }
    }

    for (int i = 0; i < N; i++) {
        x[i] = 1;  
    }

    for (thread = 0; thread < THREAD_COUNT; thread++) {
        pthread_create(&threads[thread], NULL, Pth_mat_vect, (void*) thread);
    }

    for (thread = 0; thread < THREAD_COUNT; thread++) {
        pthread_join(threads[thread], NULL);
    }
    for (int i = 0; i < M; i++) {
        printf("y[%d] = %f\n", i, y[i]);
    }

    return 0;
}
