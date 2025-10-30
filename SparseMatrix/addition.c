#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} Element;

int main() {
    Element A[MAX], B[MAX], C[MAX];
    int i, j, k;
    
    int m, n, tA, tB;

    printf("Enter rows, columns and number of non-zero elements of Matrix A: ");
    scanf("%d %d %d", &A[0].row, &A[0].col, &A[0].value);
    tA = A[0].value;

    printf("Enter elements (row column value) for Matrix A:\n");
    for(i = 1; i <= tA; i++) {
        scanf("%d %d %d", &A[i].row, &A[i].col, &A[i].value);
    }

    printf("Enter rows, columns and number of non-zero elements of Matrix B: ");
    scanf("%d %d %d", &B[0].row, &B[0].col, &B[0].value);
    tB = B[0].value;

    printf("Enter elements (row column value) for Matrix B:\n");
    for(i = 1; i <= tB; i++) {
        scanf("%d %d %d", &B[i].row, &B[i].col, &B[i].value);
    }

    if(A[0].row != B[0].row || A[0].col != B[0].col) {
        printf("Addition not possible. Matrix dimensions do not match.\n");
        return 0;
    }

    i = j = k = 1; 
    C[0].row = A[0].row;
    C[0].col = A[0].col;

    while(i <= tA && j <= tB) {
        if(A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            C[k++] = A[i++];
        }
        else if(B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col)) {
            C[k++] = B[j++];
        }
        else { 
            int sum = A[i].value + B[j].value;
            if(sum != 0) {
                C[k].row = A[i].row;
                C[k].col = A[i].col;
                C[k].value = sum;
                k++;
            }
            i++;
            j++;
        }
    }

    while(i <= tA) {
        C[k++] = A[i++];
    }

    while(j <= tB) {
        C[k++] = B[j++];
    }

    C[0].value = k - 1; 

    printf("\nResultant Sparse Matrix (row column value):\n");
    for(i = 0; i < k; i++) {
        printf("%d %d %d\n", C[i].row, C[i].col, C[i].value);
    }

    return 0;
}

/*
    Steps in detail :
Check if the matrices have the same dimensions:
If A[0].row != B[0].row or A[0].col != B[0].col,
then Addition is not possible. Stop.

Initialize pointers:
i = 1 (for A[])
j = 1 (for B[])
k = 1 (for C[])

Set C[0] metadata:
C[0].row = A[0].row
C[0].col = A[0].col
C[0].value = 0 (for now; update later)

Compare and Merge:
While i <= A[0].value and j <= B[0].value, do:

    If (A[i].row < B[j].row) or
    (A[i].row == B[j].row and A[i].col < B[j].col):
    Copy A[i] to C[k]
    Increment i and k

    Else if (B[j].row < A[i].row) or
    (B[j].row == A[i].row and B[j].col < A[i].col):
    Copy B[j] to C[k]
    Increment j and k

    Else (Same position):
    Add the values: sum = A[i].value + B[j].value
    If sum != 0:
    C[k].row = A[i].row
    C[k].col = A[i].col
    C[k].value = sum
    Increment k
    Increment both i and j

Copy Remaining Elements:

While i <= A[0].value:
Copy A[i] to C[k]
Increment i and k

While j <= B[0].value:
Copy B[j] to C[k]
Increment j and k

Update Metadata:
Set C[0].value = k - 1

End
*/