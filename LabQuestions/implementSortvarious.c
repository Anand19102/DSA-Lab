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

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;
    for (i = 0; i < n-1; i++) {
        swapped = 0;
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
   int i,j,key;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; 
    j = 0; 
    k = left; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Quick Sort (Last Element as Pivot)
int partition_last(int arr[], int low, int high) {
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

void quicksort_last(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition_last(arr, low, high);
        quicksort_last(arr, low, pivotIndex - 1);
        quicksort_last(arr, pivotIndex + 1, high);
    }
}

// Radix Sort
void countingSort(int arr[], int n, int exp) {
    int output[n]; 
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int arr[50] , arr_copy[50];
    int n;
    
    printf("Enter the number of elements (max 50)\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    readArray(arr,n);
    
    printf("Original array: ");
    printArray(arr, n);
    printf("\n");

    // --- Bubble Sort ---
    printf("Running Bubble Sort:\n");
    for (int i = 0; i < n; i++) arr_copy[i] = arr[i];
    bubbleSort(arr_copy, n);
    printArray(arr_copy, n);
    
    // --- Insertion Sort ---
    printf("Running Insertion Sort:\n");
    for (int i = 0; i < n; i++) arr_copy[i] = arr[i];
    insertionSort(arr_copy, n);
    printArray(arr_copy, n);
    
    // --- Merge Sort ---
    printf("Running Merge Sort:\n");
    for (int i = 0; i < n; i++) arr_copy[i] = arr[i];
    mergeSort(arr_copy, 0, n - 1);
    printArray(arr_copy, n);
    
    // --- Quick Sort ---
    printf("Running Quick Sort (last element pivot):\n");
    for (int i = 0; i < n; i++) arr_copy[i] = arr[i];
    quicksort_last(arr_copy, 0, n - 1);
    printArray(arr_copy, n);
    
    // --- Radix Sort ---
    printf("Running Radix Sort:\n");
    for (int i = 0; i < n; i++) arr_copy[i] = arr[i];
    radixSort(arr_copy, n);
    printArray(arr_copy, n);

    return 0;
}