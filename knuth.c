#include <stdio.h>
#include <stdlib.h>

#define N 100
#define M 10

void print_array(int * array, int len) {
    int i;

    printf("[ ");
    for (i = 0; i < len - 1; ++i) {
        printf("%d, ", array[i]);
    }

    printf("%d ]", array[len - 1]);
}

int * generate_array() {
    int in;
    int im = 0;

    int * a = (int *)(malloc(sizeof(int) * M));

    for (in = 0; in < N && im < M; ++in) {
        int rn = N - in;
        int rm = M - im;

        if (rand() % rn < rm)
            a[im++] = in + 1;
    }

    return a;
}

int main(int argc, char **argv) {
    srand(time(NULL));
    int * arr = generate_array();
    print_array(arr, M);
}
