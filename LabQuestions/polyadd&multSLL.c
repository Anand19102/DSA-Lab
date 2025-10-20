#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial term
struct Node {
    int coeff;              // coefficient
    int pow;                // power of x
    struct Node* next;      // pointer to next node
};

// Function to create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Insert term at end of polynomial
void insertTerm(struct Node** poly, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (*poly == NULL) {
        *poly = newNode;
        return;
    }
    struct Node* temp = *poly;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Display polynomial
void displayPoly(struct Node* poly) {
    if (poly == NULL) {
        printf("0");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL && poly->coeff >= 0)
            printf(" + ");
    }
    printf("\n");
}

// Add two polynomials
struct Node* addPoly(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            insertTerm(&result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } 
        else if (poly2->pow > poly1->pow) {
            insertTerm(&result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } 
        else {
            insertTerm(&result, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

// Multiply two polynomials
struct Node* multiplyPoly(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* temp1 = poly1;

    while (temp1 != NULL) {
        struct Node* temp2 = poly2;
        while (temp2 != NULL) {
            int coeffProduct = temp1->coeff * temp2->coeff;
            int powSum = temp1->pow + temp2->pow;

            // Add to result (combine terms with same power)
            struct Node* tempRes = result;
            struct Node* prev = NULL;
            int found = 0;

            while (tempRes != NULL) {
                if (tempRes->pow == powSum) {
                    tempRes->coeff += coeffProduct;
                    found = 1;
                    break;
                }
                prev = tempRes;
                tempRes = tempRes->next;
            }

            if (!found) {
                struct Node* newNode = createNode(coeffProduct, powSum);
                if (prev == NULL)
                    result = newNode;
                else
                    prev->next = newNode;
            }

            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return result;
}

// Main function
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;
    struct Node* product = NULL;

    int n1, n2, coeff, pow;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d%d", &coeff, &pow);
        insertTerm(&poly1, coeff, pow);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d%d", &coeff, &pow);
        insertTerm(&poly2, coeff, pow);
    }

    printf("\nPolynomial 1: ");
    displayPoly(poly1);
    printf("Polynomial 2: ");
    displayPoly(poly2);

    sum = addPoly(poly1, poly2);
    printf("\nSum of Polynomials: ");
    displayPoly(sum);

    product = multiplyPoly(poly1, poly2);
    printf("Product of Polynomials: ");
    displayPoly(product);

    return 0;
}
