/* for heap, the tree is a "complete binary tree" which means the array will be filled
with no spaces, the left and right children being in the 2i+1 and 2i+2 positions
and also it satisfies the heap property. so use that to visualise or draw trees*/

//swap and heapify, and we make this heap in the array itself

#include <stdio.h>
void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void readArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
}
// To heapify a subtree rooted with node i which is an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i) {
    int largest = i;       
    int left = 2 * i + 1;   
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        printArray(arr, n);
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        printArray(arr, n);
        heapify(arr, i, 0);
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
    printArray(arr, n);

    heapSort(arr,n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
