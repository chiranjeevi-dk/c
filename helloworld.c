
#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define SIZE 2

typedef struct {
    int start_row;
    int end_row;
    int mat_a[SIZE][SIZE];
    int mat_b[SIZE][SIZE];
    int result[SIZE][SIZE];
} thread_data_t;

void *multiply_matrices(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    int i, j, k;

    for (i = data->start_row; i < data->end_row; i++) {
        for (j = 0; j < SIZE; j++) {
            data->result[i][j] = 0;
            for (k = 0; k < SIZE; k++) {
                data->result[i][j] += data->mat_a[i][k] * data->mat_b[k][j];
            }
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[2];
    thread_data_t thread_data[2];

    int mat_a[SIZE][SIZE] = {{1, 2}, {3, 4}};
    int mat_b[SIZE][SIZE] = {{5, 6}, {7, 8}};
    int result[SIZE][SIZE] = {{0, 0}, {0, 0}};

    for (int i = 0; i < 2; i++) {
        thread_data[i].start_row = i * (SIZE / 2);
        thread_data[i].end_row = (i + 1) * (SIZE / 2);
        memcpy(thread_data[i].mat_a, mat_a, sizeof(mat_a));
        memcpy(thread_data[i].mat_b, mat_b, sizeof(mat_b));
        memcpy(thread_data[i].result, result, sizeof(result));
        pthread_create(&threads[i], NULL, multiply_matrices, (void *)&thread_data[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Resultant Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

