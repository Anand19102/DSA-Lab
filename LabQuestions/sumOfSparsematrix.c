#include <stdio.h>

// Define the structure for a single non-zero element (a "triplet")
struct Element {
    int row;    // Row index
    int col;    // Column index
    int value;  // The non-zero value
};

/*   Adds two sparse matrices A and B and prints the result.
     The first sparse matrix (as an array of Elements)
     The number of non-zero elements in A
     The second sparse matrix (as an array of Elements)
     The number of non-zero elements in B
 */

void addSparse(struct Element A[], int m, struct Element B[], int n) {
    // Array to store the resulting sum. Size 50 is an assumption.
    // A better way would be (m + n), but 50 is fine for a lab.
    struct Element result[50];
    
    // Initialize indices (pointers) for A, B, and result arrays
    int i = 0, j = 0, k = 0;

    // Loop while there are still elements to compare in BOTH matrices
    while (i < m && j < n) {
        
        // --- CASE 1: Positions are identical ---
        // If row and col match, add the values.
        if (A[i].row == B[j].row && A[i].col == B[j].col) {
            result[k].row = A[i].row;       // Copy row
            result[k].col = A[i].col;       // Copy col
            result[k].value = A[i].value + B[j].value; // Add values
            
            // Advance all three pointers
            i++; 
            j++; 
            k++;
        } 
        
        // --- CASE 2: Element from A comes first ---
        // This checks for "row-major" order:
        // 1. Is A's row smaller?
        // 2. OR, if rows are same, is A's column smaller?
        else if (A[i].row < B[j].row || 
                (A[i].row == B[j].row && A[i].col < B[j].col)) {
            
            // Copy the entire element from A to result
            result[k] = A[i];
            
            // Advance pointers for A and result
            i++;
            k++;
            // Note: j is not advanced, as we haven't processed B[j] yet
        } 
        
        // --- CASE 3: Element from B comes first ---
        // This is the only remaining possibility.
        else {
            // Copy the entire element from B to result
            result[k] = B[j];
            
            // Advance pointers for B and result
            j++;
            k++;
            // Note: i is not advanced
        }
    } // end of main while loop

    // --- Cleanup Phase ---
    // At this point, one of the input matrices is exhausted.
    // We just need to copy the remaining elements from the other matrix.

    // Copy any remaining elements from A
    while (i < m) {
        result[k] = A[i];
        i++;
        k++;
    }

    // Copy any remaining elements from B
    while (j < n) {
        result[k] = B[j];
        j++;
        k++;
    }

    // --- Print the Result ---
    // 'k' now holds the total number of non-zero elements in the sum
    printf("\nSum of the sparse matrices (row col value):\n");
    for (int t = 0; t < k; t++) {
        // Print each triplet, separated by tabs for clean formatting
        printf("%d\t%d\t%d\n", result[t].row, result[t].col, result[t].value);
    }
}

// The main function to drive the program
int main() {
    // Declare arrays to hold the sparse matrix data
    struct Element A[20], B[20];
    // Variables to hold the count of non-zero elements
    int m, n;

    // --- Get Input for Matrix A ---
    printf("Enter number of non-zero elements in first matrix: ");
    scanf("%d", &m);
    printf("Enter row, col, and value for matrix A (in row-major sorted order):\n");
    // Loop 'm' times to read in each triplet
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &A[i].row, &A[i].col, &A[i].value);
    }

    // --- Get Input for Matrix B ---
    printf("\nEnter number of non-zero elements in second matrix: ");
    scanf("%d", &n);
    printf("Enter row, col, and value for matrix B (in row-major sorted order):\n");
    // Loop 'n' times to read in each triplet
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &B[i].row, &B[i].col, &B[i].value);
    }

    // Call the function to perform the addition and print the sum
    addSparse(A, m, B, n);

    return 0; // Indicate successful execution
}