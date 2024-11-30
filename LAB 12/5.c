#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} Element;

typedef struct {
    int rows;
    int cols;
    int numElements;
    Element *elements;
} SparseMatrix;

SparseMatrix createSparseMatrix(int rows, int cols, int numElements) {
    SparseMatrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.numElements = numElements;
    matrix.elements = (Element *)malloc(numElements * sizeof(Element));
    return matrix;
}

void freeSparseMatrix(SparseMatrix *matrix) {
    free(matrix->elements);
    matrix->elements = NULL;
}

void inputSparseMatrix(SparseMatrix *matrix) {
    printf("Enter row, column, and value for each non-zero element:\n");
    for (int i = 0; i < matrix->numElements; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d %d %d", &matrix->elements[i].row, &matrix->elements[i].col, &matrix->elements[i].value);
    }
}

void printSparseMatrix(SparseMatrix matrix) {
    printf("Sparse Matrix (row, column, value):\n");
    for (int i = 0; i < matrix.numElements; i++) {
        printf("(%d, %d, %d)\n", matrix.elements[i].row, matrix.elements[i].col, matrix.elements[i].value);
    }
}

SparseMatrix addSparseMatrices(SparseMatrix a, SparseMatrix b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        printf("Addition not possible: matrices have different dimensions.\n");
        exit(1);
    }

    SparseMatrix result = createSparseMatrix(a.rows, a.cols, a.numElements + b.numElements);
    int i = 0, j = 0, k = 0;

    while (i < a.numElements && j < b.numElements) {
        if (a.elements[i].row < b.elements[j].row || 
           (a.elements[i].row == b.elements[j].row && a.elements[i].col < b.elements[j].col)) {
            result.elements[k++] = a.elements[i++];
        } else if (b.elements[j].row < a.elements[i].row || 
                  (b.elements[j].row == a.elements[i].row && b.elements[j].col < a.elements[i].col)) {
            result.elements[k++] = b.elements[j++];
        } else {
            result.elements[k] = a.elements[i];
            result.elements[k++].value += b.elements[j++].value;
            i++;
        }
    }

    while (i < a.numElements) result.elements[k++] = a.elements[i++];
    while (j < b.numElements) result.elements[k++] = b.elements[j++];

    result.numElements = k;
    return result;
}

SparseMatrix multiplySparseMatrices(SparseMatrix a, SparseMatrix b) {
    if (a.cols != b.rows) {
        printf("Multiplication not possible: matrices have incompatible dimensions.\n");
        exit(1);
    }

    SparseMatrix result = createSparseMatrix(a.rows, b.cols, a.numElements * b.numElements);
    int k = 0;

    for (int i = 0; i < a.numElements; i++) {
        for (int j = 0; j < b.numElements; j++) {
            if (a.elements[i].col == b.elements[j].row) {
                result.elements[k].row = a.elements[i].row;
                result.elements[k].col = b.elements[j].col;
                result.elements[k].value = a.elements[i].value * b.elements[j].value;
                k++;
            }
        }
    }

    result.numElements = k;
    return result;
}

int main() {
    int rows, cols, numElements;

    printf("Matrix A:\n");
    printf("Enter rows, columns, and number of non-zero elements: ");
    scanf("%d %d %d", &rows, &cols, &numElements);
    SparseMatrix matrixA = createSparseMatrix(rows, cols, numElements);
    inputSparseMatrix(&matrixA);

    printf("\nMatrix B:\n");
    printf("Enter rows, columns, and number of non-zero elements: ");
    scanf("%d %d %d", &rows, &cols, &numElements);
    SparseMatrix matrixB = createSparseMatrix(rows, cols, numElements);
    inputSparseMatrix(&matrixB);

    int choice;
    printf("\nChoose an operation:\n1. Addition\n2. Multiplication\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        SparseMatrix result = addSparseMatrices(matrixA, matrixB);
        printf("\nResultant Matrix after Addition:\n");
        printSparseMatrix(result);
        freeSparseMatrix(&result);
    } else if (choice == 2) {
        SparseMatrix result = multiplySparseMatrices(matrixA, matrixB);
        printf("\nResultant Matrix after Multiplication:\n");
        printSparseMatrix(result);
        freeSparseMatrix(&result);
    } else {
        printf("Invalid choice.\n");
    }

    freeSparseMatrix(&matrixA);
    freeSparseMatrix(&matrixB);

    return 0;
}
