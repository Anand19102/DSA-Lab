#include <stdio.h>

struct Term {
    int coeff;
    int expo;
};

void addPolynomials(struct Term poly1[], int n1, struct Term poly2[], int n2, struct Term polyResult[], int *nResult) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (poly1[i].expo == poly2[j].expo) {
        int sum_coeff = poly1[i].coeff + poly2[j].coeff;
        if (sum_coeff != 0) {
            polyResult[k].coeff = sum_coeff;
            polyResult[k].expo = poly1[i].expo;
            k++;
}
        i++;
        j++;
        }
        else if (poly1[i].expo > poly2[j].expo) {
            polyResult[k] = poly1[i];
            i++;
            k++;
        }
        else {
            polyResult[k] = poly2[j];
            j++;
            k++;
        }
    }

    // Copy remaining terms of poly1
    while (i < n1) {
        polyResult[k] = poly1[i];
        i++;
        k++;
    }

    // Copy remaining terms of poly2
    while (j < n2) {
        polyResult[k] = poly2[j];
        j++;
        k++;
    }

    *nResult = k; // Total number of terms in result
}

void displayPolynomial(struct Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%dx^%d", poly[i].coeff, poly[i].expo);
        if (i != n - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct Term poly1[] = { {5, 3}, {4, 2}, {2, 0} };
    struct Term poly2[] = { {5, 2}, {5, 1}, {5, 0} };
    struct Term polyResult[20];
    int nResult;

    int n1 = 3; // Number of terms in poly1
    int n2 = 3; // Number of terms in poly2

    printf("First Polynomial: ");
    displayPolynomial(poly1, n1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2, n2);

    addPolynomials(poly1, n1, poly2, n2, polyResult, &nResult);

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

/* Steps:


Initialize three pointers (indexes):
i = 0 for first polynomial (poly1),
j = 0 for second polynomial (poly2),
k = 0 for result polynomial (polyResult).

Repeat while both i and j are within their respective array sizes:

If poly1[i].expo == poly2[j].expo:

Add their coefficients.

Store the sum and the common exponent in polyResult[k].

Increment i, j, and k.

Else if poly1[i].expo > poly2[j].expo:

Copy poly1[i] to polyResult[k].

Increment i and k.

Else:

Copy poly2[j] to polyResult[k].

Increment j and k.

Copy any remaining terms from poly1 (if any) to polyResult.

Copy any remaining terms from poly2 (if any) to polyResult.

Done.

*/