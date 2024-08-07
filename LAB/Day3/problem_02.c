#include <stdio.h>

// Function to read a sparse matrix in 3-tuple format
void readSparseMatrix(int sparseMatrix[][3], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d %d %d", &sparseMatrix[i][0], &sparseMatrix[i][1], &sparseMatrix[i][2]);
    }
}

// Function to print a sparse matrix in 3-tuple format
void printSparseMatrix(int sparseMatrix[][3], int size) {
    printf("%d %d %d\n", sparseMatrix[0][0], sparseMatrix[0][1], sparseMatrix[0][2]);
    for (int i = 1; i < size; i++) {
        printf("%d %d %d\n", sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
    }
}

// Function to add two sparse matrices
void addSparseMatrices(int matrix1[][3], int matrix2[][3], int result[][3]) {
    int rows1 = matrix1[0][0], cols1 = matrix1[0][1], size1 = matrix1[0][2];
    int rows2 = matrix2[0][0], cols2 = matrix2[0][1], size2 = matrix2[0][2];

    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrices dimensions do not match.\n");
        return;
    }

    int i = 1, j = 1, k = 1;
    result[0][0] = rows1;
    result[0][1] = cols1;

    while (i <= size1 && j <= size2) {
        if (matrix1[i][0] < matrix2[j][0] || (matrix1[i][0] == matrix2[j][0] && matrix1[i][1] < matrix2[j][1])) {
            result[k][0] = matrix1[i][0];
            result[k][1] = matrix1[i][1];
            result[k][2] = matrix1[i][2];
            i++;
        } else if (matrix1[i][0] > matrix2[j][0] || (matrix1[i][0] == matrix2[j][0] && matrix1[i][1] > matrix2[j][1])) {
            result[k][0] = matrix2[j][0];
            result[k][1] = matrix2[j][1];
            result[k][2] = matrix2[j][2];
            j++;
        } else {
            result[k][0] = matrix1[i][0];
            result[k][1] = matrix1[i][1];
            result[k][2] = matrix1[i][2] + matrix2[j][2];
            i++;
            j++;
        }
        k++;
    }

    while (i <= size1) {
        result[k][0] = matrix1[i][0];
        result[k][1] = matrix1[i][1];
        result[k][2] = matrix1[i][2];
        i++;
        k++;
    }

    while (j <= size2) {
        result[k][0] = matrix2[j][0];
        result[k][1] = matrix2[j][1];
        result[k][2] = matrix2[j][2];
        j++;
        k++;
    }

    result[0][2] = k - 1; // Number of non-zero elements in the result
}

int main() {
    int sparseMatrix1[100][3], sparseMatrix2[100][3], resultMatrix[100][3];
    int size1, size2;

    // Read the first sparse matrix
    printf("Enter sparse matrix-1 in 3-tuple format\n");
    scanf("%d %d %d", &sparseMatrix1[0][0], &sparseMatrix1[0][1], &sparseMatrix1[0][2]);
    size1 = sparseMatrix1[0][2] + 1;
    readSparseMatrix(sparseMatrix1, size1);

    // Read the second sparse matrix
    printf("Enter sparse matrix-2 in 3-tuple format\n");
    scanf("%d %d %d", &sparseMatrix2[0][0], &sparseMatrix2[0][1], &sparseMatrix2[0][2]);
    size2 = sparseMatrix2[0][2] + 1;
    readSparseMatrix(sparseMatrix2, size2);

    // Add the two sparse matrices
    addSparseMatrices(sparseMatrix1, sparseMatrix2, resultMatrix);

    // Print the resultant sparse matrix
    printf("Resultant Matrix in 3-tuple format\n");
    printSparseMatrix(resultMatrix, resultMatrix[0][2] + 1);

    return 0;
}
