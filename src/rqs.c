#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int lo, int hi){
    int pivot = arr[hi];
    int i = lo-1, temp;

    for (size_t j = lo; j < hi-1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[hi]);
    return i+1;
}

int partition_r(int arr[], int lo, int hi){
    srand(time(0));
    int r = (rand() % (hi - lo +1)) + lo;
    swap(&arr[r], &arr[hi]);
    return partition(arr, lo, hi);
}

void quickSort(int nums[], int first, int last){
    if (first < last)
    {
        int p = partition_r(nums, first, last);
        quickSort(nums, first, p-1);
        quickSort(nums, p+1, last);
    }
    
}