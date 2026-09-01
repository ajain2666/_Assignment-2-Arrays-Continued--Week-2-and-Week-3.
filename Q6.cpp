#include <stdio.h>

#define MAX 100

// Display triplet matrix
void display(int T[MAX][3]) {
    int n = T[0][2];

    printf("\nRow\tColumn\tValue\n");
    for (int i = 0; i <= n; i++) {
        printf("%d\t%d\t%d\n", T[i][0], T[i][1], T[i][2]);
    }
}

// Convert normal matrix to triplet form
void createTriplet(int A[MAX][MAX], int rows, int cols,
                   int T[MAX][3]) {
    int k = 1;

    T[0][0] = rows;
    T[0][1] = cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A[i][j] != 0) {
                T[k][0] = i;
                T[k][1] = j;
                T[k][2] = A[i][j];
                k++;
            }
        }
    }

    T[0][2] = k - 1;
}

// (a) Transpose
void transpose(int T[MAX][3], int R[MAX][3]) {
    int k = 1;

    R[0][0] = T[0][1];
    R[0][1] = T[0][0];
    R[0][2] = T[0][2];

    for (int col = 0; col < T[0][1]; col++) {
        for (int i = 1; i <= T[0][2]; i++) {
            if (T[i][1] == col) {
                R[k][0] = T[i][1];
                R[k][1] = T[i][0];
                R[k][2] = T[i][2];
                k++;
            }
        }
    }
}

// (b) Addition
void addition(int A[MAX][3], int B[MAX][3], int C[MAX][3]) {

    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        printf("\nAddition not possible.");
        return;
    }

    int i = 1, j = 1, k = 1;

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while (i <= A[0][2] && j <= B[0][2]) {

        if (A[i][0] < B[j][0] ||
           (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {

            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];

            i++;
            k++;
        }

        else if (B[j][0] < A[i][0] ||
                (A[i][0] == B[j][0] && B[j][1] < A[i][1])) {

            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];

            j++;
            k++;
        }

        else {
            int sum = A[i][2] + B[j][2];

            if (sum != 0) {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = sum;
                k++;
            }

            i++;
            j++;
        }
    }

    while (i <= A[0][2]) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++;
        k++;
    }

    while (j <= B[0][2]) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++;
        k++;
    }

    C[0][2] = k - 1;
}

// (c) Multiplication
void multiplication(int A[MAX][3], int B[MAX][3], int C[MAX][3]) {

    if (A[0][1] != B[0][0]) {
        printf("\nMultiplication not possible.");
        return;
    }

    int result[MAX][MAX] = {0};

    // Multiply using non-zero elements only
    for (int i = 1; i <= A[0][2]; i++) {
        for (int j = 1; j <= B[0][2]; j++) {

            if (A[i][1] == B[j][0]) {
                int row = A[i][0];
                int col = B[j][1];

                result[row][col] += A[i][2] * B[j][2];
            }
        }
    }

    createTriplet(result, A[0][0], B[0][1], C);
}

int main() {

    int A[MAX][MAX], B[MAX][MAX];
    int TA[MAX][3], TB[MAX][3];
    int TR[MAX][3], SUM[MAX][3], PROD[MAX][3];

    int r1, c1, r2, c2;

    // First matrix
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter first matrix:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    // Second matrix
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter second matrix:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    // Convert to triplet
    createTriplet(A, r1, c1, TA);
    createTriplet(B, r2, c2, TB);

    printf("\nFirst Matrix in Triplet Form:");
    display(TA);

    printf("\nSecond Matrix in Triplet Form:");
    display(TB);

    // Transpose
    transpose(TA, TR);

    printf("\nTranspose of First Matrix:");
    display(TR);

    // Addition
    printf("\nAddition of Matrices:");
    addition(TA, TB, SUM);

    if (TA[0][0] == TB[0][0] &&
        TA[0][1] == TB[0][1]) {
        display(SUM);
    }

    // Multiplication
    printf("\nMultiplication of Matrices:");
    multiplication(TA, TB, PROD);

    if (TA[0][1] == TB[0][0]) {
        display(PROD);
    }

    return 0;
}

