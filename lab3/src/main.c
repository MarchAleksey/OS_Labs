#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <errno.h>
#include <pthread.h>
#include <time.h>

pthread_mutex_t mutex;

typedef struct data_{
    int ind_first;
    int ind_last;
    int d;
    int r;
    int p;
    int N;
    int step;
    int *Arr; 
} data_;

typedef struct data_ data;

void *thread_func(void *arg) {
    pthread_mutex_lock(&mutex);
    data *a = (data*)arg;
    for (int j = a->ind_first; j < a->ind_last; j++) {
        if ((j & a->p) == a->r) {
            if (a->Arr[j] > a->Arr[j + a->d]){
                int temp = a->Arr[j];
                a->Arr[j] = a->Arr[j + a->d];
                a->Arr[j + a->d] = temp;
            }
        }
    }
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(int argc, char* argv[]) {
    int stm = 1;
    if (argc > 2) {
        perror("Usage: ./a.out <number of threads>\n");
        return 1;
    }
    else if (argc == 2) {
    	stm = atoi(argv[1]);
    }
    int threads = stm;
    if (threads < 1) {
        perror("Incorrect number of threads\n");
        return 2;
    }
    int N;
    scanf("%d", &N);
    int st2 = 1;
    while (st2 < N) {
        st2 *= 2;
    }
    int Arr[st2];
    for (int i = 0; i < N; i++) {
        scanf("%d", &Arr[i]);
    }
    for (int i = N; i < st2; i++) {
        Arr[i] = INT_MAX;
    }
    if (stm >= st2 / 2) {
        stm = st2 / 2;
        threads = stm;
    }
    printf("Number of used threads: %d\n", threads);
    for (int p = st2; p > 0; p /= 2) {
        int q = st2, r = 0, d = p;
        bool b; 
        pthread_t thread[threads];
        do{
            int nTo = st2 - d;
            int k = nTo / threads;
            if (k < 2) {
                k = 2;
            }
            if (threads * k < nTo) {
                k++;
            }
            int pt = 0;
            for(int i = 0; i < nTo; i += k) {
                data* arg = malloc(sizeof(data));
                arg->ind_first = i;
                if (i + k < nTo) {
                    arg->ind_last = i + k;
                } else {
                    arg->ind_last = nTo;
                }
                arg->d = d; 
                arg->N = st2;
                arg->p = p;
                arg->r = r;
                arg->Arr = Arr;
                //printf("First %d Second %d\n", arg->ind_first, arg->ind_last);
                if (pthread_create(&thread[pt], NULL, thread_func, (void *)arg) != 0) {
                    perror("Error: can't create thread");
                    return 3;
                }
                pt++;
            }
            for (int i = 0; i < pt; i++) {
                if (pthread_join(thread[i], NULL) != 0) {
                    perror("Error: can't join thread");
                    return -3;
                }
            }
            b = q != p;
            if (b) {
                d = q - p;
                q >>= 1;
                r = p;
            }
        } while (b);
    }
    int res[N];
    for (int i = 0; i < N; i++) {
        res[i] = Arr[i];
    }
    printf("Sorted massive: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}
