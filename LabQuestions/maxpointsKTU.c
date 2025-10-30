//The CSE dept is organizing a tech fest with so many exciting events. By participating in an event,you can claim for activity points as stipulated by KTU. Each event i gives you A[i] activity points where A is an array.If you are not allowed to participate in more than k events, what’s the max number of points that you can earn?

#include <stdio.h>

void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, k;

    printf("Enter number of events: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter activity points for each event:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter maximum events you can participate in (k): ");
    scanf("%d", &k);

    sortDescending(A, n);

    int maxPoints = 0;
    for (int i = 0; i < k && i < n; i++) {
        maxPoints += A[i];
    }

    printf("Maximum Activity Points: %d\n", maxPoints);

    return 0;
}
