#include <stdio.h>
#include <stdlib.h>

void swap(int * arr, int a, int b) {
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

int partition(int * arr, int lo, int hi, int pivot) {
    int lp = lo;
    int pv = arr[pivot];
    int i;
    
    swap(arr, pivot, hi);

    for (i = lo; i < hi; i++) {
        if (arr[i] < pv) {
            swap(arr, i, lp++);
        }
    }

    swap(arr, lp, hi);
    return lp;
}

int * generate_array(int N, int M) {
    int in;
    int im = 0;

    int * arr = (int *)malloc(sizeof(int) * M);

    for (in = 0; in < N && im < M; in++) {
        int rn = N - in;
        int rm = M - im;
        if (rand() % rn < rm) 
            arr[im++] = in + 1;
    }

    return arr;
}

void shuffle_array(int * array, int len) {
    int i;
    for (i = 0; i < len; i++) {
        swap(array, i, rand() % len);
    }
}

int kth_smallest(int * arr, int len, int k) {
    int hi = len;
    int lo = 0;
    int pivot = (hi + lo) / 2;

    while (1) {
        pivot = (hi + lo) / 2;
        pivot = partition(arr, lo, hi, pivot);

        if (pivot == k) 
            return arr[pivot];
        else if (pivot < k) {
            lo = pivot;
        } else {
            hi = pivot;
        }
    }
}

void print_array(int * array, int len) {
    int i;
    if (len < 2) {
        printf("[ %d ]\n", array[len]);
        return;
    }

    printf("[ %d, ", array[0]);
    for (i = 1; i < len - 1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d ]\n", array[len - 1]);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("usage: %s <N> <M> [k]\n", argv[0]);
        return 0;
    }

    srand(time(NULL));
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    int k = 2;

    if (argc > 3) {
        k = atoi(argv[3]);
        if (!k) 
            k = 2;
    }

    int * a = generate_array(N, M);
    shuffle_array(a, M);
    print_array(a, M);
    int small = kth_smallest(a, M, k);
    printf("%d smallest: %d\n", k, small);

    return 0;
}
