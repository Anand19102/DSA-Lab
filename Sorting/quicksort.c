/*
Quick Sort Algorithm (Pseudo code- first element as pivot)
QUICKSORT(A, low, high)
    if low < high then
        pivotIndex ← PARTITION(A, low, high)
        QUICKSORT(A, low, pivotIndex - 1)
        QUICKSORT(A, pivotIndex + 1, high)

PARTITION(A, low, high)
    pivot ← A[low]                // choose first element as pivot
    i ← low + 1
    j ← high

    while true do
        while i ≤ high and A[i] ≤ pivot do
            i ← i + 1
        while j ≥ low and A[j] > pivot do
            j ← j - 1

        if i < j then
            swap A[i] and A[j]
        else
            break

    swap A[low] and A[j]           // place pivot in correct position
    return j                       // return pivot index

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

// swap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int low, int high) {
    int pivot = arr[low]; 
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        while (j >= low && arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            swap(&arr[i], &arr[j]);
        } else {
            break;
        }
    }
    swap(&arr[low], &arr[j]);
    
    return j;  
}

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