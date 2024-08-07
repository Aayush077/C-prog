//WAP to perform transpose of a given sparse matrix in 3-tuple format.

#include <stdio.h>

// Function to read the sparse matrix in 3-tuple format
void readSparseMatrix(int sparseMatrix[][3], int size) {
    printf("Enter sparse matrix in 3-tuple format\n");
    for(int i = 0; i < size; i++) {
        scanf("%d %d %d", &sparseMatrix[i][0], &sparseMatrix[i][1], &sparseMatrix[i][2]);
    }
}

// Function to print the sparse matrix in 3-tuple format
void printSparseMatrix(int sparseMatrix[][3], int size) {
    printf("R\tC\tElement\n");
    for(int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
    }
}

// Function to transpose the sparse matrix
void transposeSparseMatrix(int sparseMatrix[][3], int transposedMatrix[][3], int size) {
    // Copy number of rows, columns, and number of non-zero elements
    transposedMatrix[0][0] = sparseMatrix[0][1];
    transposedMatrix[0][1] = sparseMatrix[0][0];
    transposedMatrix[0][2] = sparseMatrix[0][2];

    // Swap the row and column indices of each non-zero element
    for(int i = 1; i < size; i++) {
        transposedMatrix[i][0] = sparseMatrix[i][1];
        transposedMatrix[i][1] = sparseMatrix[i][0];
        transposedMatrix[i][2] = sparseMatrix[i][2];
    }
}

// Function to sort the transposed matrix
void sortSparseMatrix(int sparseMatrix[][3], int size) {
    for(int i = 1; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if (sparseMatrix[i][0] > sparseMatrix[j][0] ||
               (sparseMatrix[i][0] == sparseMatrix[j][0] && sparseMatrix[i][1] > sparseMatrix[j][1])) {
                // Swap rows
                int temp[3];
                temp[0] = sparseMatrix[i][0];
                temp[1] = sparseMatrix[i][1];
                temp[2] = sparseMatrix[i][2];
                sparseMatrix[i][0] = sparseMatrix[j][0];
                sparseMatrix[i][1] = sparseMatrix[j][1];
                sparseMatrix[i][2] = sparseMatrix[j][2];
                sparseMatrix[j][0] = temp[0];
                sparseMatrix[j][1] = temp[1];
                sparseMatrix[j][2] = temp[2];
            }
        }
    }
}

int main() {
    int sparseMatrix[100][3], transposedMatrix[100][3];
    int size;

    // Read the size of the sparse matrix
    printf("Enter the number of non-zero elements in the sparse matrix: ");
    scanf("%d", &size);
    size += 1; // Including the header row

    // Read the sparse matrix
    readSparseMatrix(sparseMatrix, size);

    // Transpose the sparse matrix
    transposeSparseMatrix(sparseMatrix, transposedMatrix, size);

    // Sort the transposed matrix
    sortSparseMatrix(transposedMatrix, size);

    // Print the transposed sparse matrix
    printf("Transpose of sparse matrix:\n");
    printSparseMatrix(transposedMatrix, size);

    return 0;
}
