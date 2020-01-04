#include <stdlib.h>
#include <time.h>
/*
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
    
}*/
void quicksort(int number[],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}