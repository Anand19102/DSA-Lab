#include <stdio.h>

// Defines the structure for a single term of a polynomial
struct Term {
    int coeff; // Coefficient
    int expo;  // Exponent
};

// Function to add two polynomials
void addPolynomials(struct Term poly1[], int n1, struct Term poly2[], int n2, struct Term polyResult[], int *nResult) {
    int i = 0, j = 0, k = 0; // Pointers for poly1, poly2, and the result array

    // Loop through both polynomials as long as there are terms in both
    while (i < n1 && j < n2) {
        // If exponents are the same, add coefficients
        if (poly1[i].expo == poly2[j].expo) {
            polyResult[k].coeff = poly1[i].coeff + poly2[j].coeff;
            polyResult[k].expo = poly1[i].expo;
            i++;
            j++;
            k++;
        }
        // If exponent of poly1 is greater, copy its term
        else if (poly1[i].expo > poly2[j].expo) {
            polyResult[k] = poly1[i];
            i++;
            k++;
        }
        // If exponent of poly2 is greater, copy its term
        else {
            polyResult[k] = poly2[j];
            j++;
            k++;
        }
    }

    // Copy any remaining terms from the first polynomial
    while (i < n1) {
        polyResult[k] = poly1[i];
        i++;
        k++;
    }

    // Copy any remaining terms from the second polynomial
    while (j < n2) {
        polyResult[k] = poly2[j];
        j++;
        k++;
    }

    *nResult = k; // Set the total number of terms in the result
}

// Function to display a polynomial in a readable format
void displayPolynomial(struct Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%dx^%d", poly[i].coeff, poly[i].expo);
        // Add a " + " sign between terms, but not after the last one
        if (i != n - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

// The main function to drive the program
int main() {
    // First polynomial: 5x^3 + 4x^2 + 2
    struct Term poly1[] = { {5, 3}, {4, 2}, {2, 0} };
    int n1 = 3; // Number of terms in poly1

    // Second polynomial: 5x^2 + 5x^1 + 5
    struct Term poly2[] = { {5, 2}, {5, 1}, {5, 0} };
    int n2 = 3; // Number of terms in poly2

    // Array to store the resulting polynomial
    struct Term polyResult[20]; // Assuming max 20 terms in the result
    int nResult;

    // Display the input polynomials
    printf("First Polynomial: ");
    displayPolynomial(poly1, n1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2, n2);

    // Call the function to perform the addition
    addPolynomials(poly1, n1, poly2, n2, polyResult, &nResult);

    // Display the sum
    printf("Sum of Polynomials: ");
    displayPolynomial(polyResult, nResult);

    return 0;
}

//NOW IF WE HAVE TO TAKE INPUT FROM THE USER

/* #include <stdio.h>

// Structure for a polynomial term (no changes here)
struct Term {
    int coeff;
    int expo;
};

// ******************************************************
// NEW FUNCTION: To read a polynomial from the user
// ******************************************************
void readPolynomial(struct Term poly[], int n) {
    printf("Enter the terms in descending order of exponent.\n");
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &poly[i].coeff, &poly[i].expo);
    }
}

// Function to add two polynomials (no changes here)
void addPolynomials(struct Term poly1[], int n1, struct Term poly2[], int n2, struct Term polyResult[], int *nResult) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (poly1[i].expo == poly2[j].expo) {
            polyResult[k].coeff = poly1[i].coeff + poly2[j].coeff;
            polyResult[k].expo = poly1[i].expo;
            i++; j++; k++;
        } else if (poly1[i].expo > poly2[j].expo) {
            polyResult[k] = poly1[i];
            i++; k++;
        } else {
            polyResult[k] = poly2[j];
            j++; k++;
        }
    }
    while (i < n1) {
        polyResult[k++] = poly1[i++];
    }
    while (j < n2) {
        polyResult[k++] = poly2[j++];
    }
    *nResult = k;
}

// Function to display a polynomial (no changes here)
void displayPolynomial(struct Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%dx^%d", poly[i].coeff, poly[i].expo);
        if (i != n - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}


// ******************************************************
// MODIFIED main FUNCTION
// ******************************************************
int main() {
    struct Term poly1[10], poly2[10], polyResult[20];
    int n1, n2, nResult;

    // --- Read the first polynomial ---
    printf("Enter the number of terms for the first polynomial: ");
    scanf("%d", &n1);
    readPolynomial(poly1, n1);

    // --- Read the second polynomial ---
    printf("\nEnter the number of terms for the second polynomial: ");
    scanf("%d", &n2);
    readPolynomial(poly2, n2);

    // --- Display the input polynomials ---
    printf("\nFirst Polynomial: ");
    displayPolynomial(poly1, n1);
    printf("Second Polynomial: ");
    displayPolynomial(poly2, n2);

    // --- Add and display the result ---
    addPolynomials(poly1, n1, poly2, n2, polyResult, &nResult);
    printf("\nSum of Polynomials: ");
    displayPolynomial(polyResult, nResult);

    return 0;
} */