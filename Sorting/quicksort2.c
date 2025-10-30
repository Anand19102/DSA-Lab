/* 
PARTITION(A, low, high)
    pivot ← A[high]               // choose last element as pivot
    i ← low
    j ← high - 1

    while true do
        while i ≤ high - 1 and A[i] ≤ pivot do
            i ← i + 1
        while j ≥ low and A[j] > pivot do
            j ← j - 1

        if i < j then
            swap A[i] and A[j]
        else
            break

    swap A[i] and A[high]          // place pivot in correct position
    return i                       // return pivot index
*/

#include <stdio.h>
void printArray(int arr[],int low, int high) {
    for (int i=low; i<high; i++)
        printf("%d ", arr[i]);
    
}
void readArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];   
    int i = low;             
    int j = high - 1;       
    while (1) {
        while (i <= high - 1 && arr[i] <= pivot)
            i++;

        while (j >= low && arr[j] > pivot)
            j--;

        if (i >= j)
            break;

        swap(&arr[i], &arr[j]);
    }

    swap(&arr[i], &arr[high]);
    return i; 
}

// Quicksort function
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        printArray(arr,low,pivotIndex);
        printf("\t*%d\t",arr[pivotIndex]);
        printArray(arr,pivotIndex+1,high+1);
        printf("\n");
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int arr[50] ;
    int n;
    
    printf("Enter the number of elements \n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    readArray(arr,n);
    
    printf("Original array: ");
    printArray(arr,0, n);
    printf("\n");
    quicksort(arr,0,n-1);

    printf("Sorted array: ");
    printArray(arr,0, n);
    printf("\n");
    return 0;
}

/* the only difference between quicksort.c and quicksort2.c is the choice of pivot element and also that 
when last element is chosen as pivot, only the final swapping changes
ie arr[i] and arr[high] (pivot) are swapped instead of arr[low] (pivot) and arr[j] */