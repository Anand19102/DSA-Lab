#include <stdio.h>

// Defines the structure for a single triplet (row, col, value)
struct Sparse {
    int row;
    int col;
    int value;
};

int main() {
    // 1. Initialize the original 4x5 sparse matrix
    int matrix[4][5] = {
        {0, 0, 0, 5, 0},
        {0, 8, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 4}
    };

    // 2. Set up variables
    struct Sparse sparse[20]; // Array to store the triplet representation
    int rows = 4;
    int cols = 5;
    int k = 1; // Index for the sparse array, starts at 1 to reserve index 0 for metadata

    // 3. Store metadata in the first row (index 0) of the sparse array
    sparse[0].row = rows;
    sparse[0].col = cols;
    sparse[0].value = 0; // Placeholder for the count of non-zero elements

    // 4. Traverse the original matrix to find and store non-zero elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {  //check each element column-wise
            // If an element is not zero, store it in the sparse array
            if (matrix[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = matrix[i][j];
                k++; // Increment the sparse array index
            }
        }
    }

    // 5. Update the metadata with the final count of non-zero elements
    sparse[0].value = k - 1;

    // 6. Print the resulting sparse matrix representation
    printf("Row Col Value\n");
    printf("--- --- -----\n");
    for (int i = 0; i < k; i++) {
        printf("%-3d %-3d %-5d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }

    return 0;
}

// WITH USER INPUT FOR THE MATRIX, READ THIS TOO 
/* #include <stdio.h>

// Defines the structure for a single triplet (no changes here)
struct Sparse {
    int row;
    int col;
    int value;
};

int main() {
    int rows, cols;

    // --- 1. Get Matrix Dimensions from User ---
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols]; // Declare matrix with user-defined size

    // --- 2. Get Matrix Elements from User ---
    printf("\nEnter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // --- 3. Set up the Sparse Matrix Array ---
    // The max size is (rows * cols) non-zero elements + 1 for metadata.
    struct Sparse sparse[rows * cols + 1];
    int k = 1; // Index for the sparse array, starts at 1

    // 4. Store metadata (no changes in logic)
    sparse[0].row = rows;
    sparse[0].col = cols;

    // 5. Traverse the user's matrix to find non-zero elements (no changes in logic)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = matrix[i][j];
                k++;
            }
        }
    }

    // 6. Update metadata with the final count (no changes in logic)
    sparse[0].value = k - 1;

    // 7. Print the resulting sparse matrix representation (no changes in logic)
    printf("\nSparse Matrix Representation (3-Tuple Form):\n");
    printf("Row Col Value\n");
    printf("--- --- -----\n");
    for (int i = 0; i < k; i++) {
        printf("%-3d %-3d %-5d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }

    return 0;
} */