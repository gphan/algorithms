/*
 * Quicksort Implementation
 */
#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int partition(int * a, int lo, int hi, int pivot)
{
    int pv = a[pivot];
    swap(a, pivot, hi);
    int lp = lo;
    int i;

    for (i = lo; i < hi; i++) 
    {
        if (a[i] < pv) {
            swap(a, i, lp);
            lp++;
        }
    }

    swap(a, lp, hi);
    return lp;
}

void sort(int * a, int l, int h) 
{
    if (l < h)
    {
        int pidx = l + (h - l) / 2;
        pidx = partition(a, l, h, pidx);
        sort(a, l, pidx-1);
        sort(a, pidx+1, h);
    } 
}

void quicksort(int * a, int len) 
{
    sort(a, 0, len-1);
}

void print_array(int * a, int len) {
    int i;
    printf("(%d) { ", len);
    for (i = 0; i < len; i++) 
    {
        printf("%d ", a[i]);
    }
    printf("}\n");
}

int main(int argc, char **argv) {
    int array[] = {48,81,53,1,85,3,64,73,70,69,8,72,80,12,38,96,65,5,77,11,95,68,94,31,20,25,84,57,75,49,51,99,90,43,92,50,91,55,13,15,71,41,61,74,98,88,28,79,24,97,6,33,58,47,44,52,35,19,10,22,21,46,7,82,67,32,18,63,66,83,76,27,9,45,34,2,56,78,42,17,16,59,23,4,60,89,29,37,62,86,100,54,26,40,93,87,14,39,36,30};
    int length = 100;

    print_array(array, length);
    quicksort(array, length);
    print_array(array, length);

    return 0;
}
