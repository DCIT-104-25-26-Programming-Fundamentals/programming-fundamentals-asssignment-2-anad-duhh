// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAXSIZE = 10;

void readMatrix(int matrix[MAXSIZE][MAXSIZE], int rows, int cols, const string& name);
void displayMatrix(int matrix[MAXSIZE][MAXSIZE], int rows, int cols, const string& title);
void transposeMatrix(int matrix[MAXSIZE][MAXSIZE], int rows, int cols,
                      int result[MAXSIZE][MAXSIZE]);
void addMatrices(int a[MAXSIZE][MAXSIZE], int b[MAXSIZE][MAXSIZE], int rows, int cols,
                  int result[MAXSIZE][MAXSIZE]);
void multiplyMatrices(int a[MAXSIZE][MAXSIZE], int b[MAXSIZE][MAXSIZE],
                       int rowsA, int colsA, int colsB,
                       int result[MAXSIZE][MAXSIZE]);

int main() {
    int choice;

    do {
        cout << "\n=============================================\n";
        cout << "           MATRIX OPERATIONS MENU\n";
        cout << "=============================================\n";
        cout << "1. Transpose a Matrix\n";
        cout << "2. Add Two Matrices\n";
        cout << "3. Multiply Two Matrices\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int matrix[MAXSIZE][MAXSIZE], result[MAXSIZE][MAXSIZE];
            int rows, cols;

            cout << "\n--- Transpose a Matrix ---\n";
            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;

            readMatrix(matrix, rows, cols, "Matrix");
            displayMatrix(matrix, rows, cols, "Original Matrix");

            transposeMatrix(matrix, rows, cols, result);
            displayMatrix(result, cols, rows, "Transposed Matrix");

        } else if (choice == 2) {
            int a[MAXSIZE][MAXSIZE], b[MAXSIZE][MAXSIZE], result[MAXSIZE][MAXSIZE];
            int rows, cols;

            cout << "\n--- Add Two Matrices ---\n";
            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;

            readMatrix(a, rows, cols, "Matrix A");
            readMatrix(b, rows, cols, "Matrix B");

            displayMatrix(a, rows, cols, "Matrix A");
            displayMatrix(b, rows, cols, "Matrix B");

            addMatrices(a, b, rows, cols, result);
            displayMatrix(result, rows, cols, "Sum (A + B)");

        } else if (choice == 3) {
            int a[MAXSIZE][MAXSIZE], b[MAXSIZE][MAXSIZE], result[MAXSIZE][MAXSIZE];
            int rowsA, colsA, rowsB, colsB;

            cout << "\n--- Multiply Two Matrices ---\n";
            cout << "Enter number of rows for Matrix A: ";
            cin >> rowsA;
            cout << "Enter number of columns for Matrix A: ";
            cin >> colsA;
            readMatrix(a, rowsA, colsA, "Matrix A");

            cout << "Enter number of rows for Matrix B: ";
            cin >> rowsB;
            cout << "Enter number of columns for Matrix B: ";
            cin >> colsB;

            if (colsA != rowsB) {
                cout << "\nError: Number of columns in Matrix A (" << colsA
                     << ") must equal number of rows in Matrix B (" << rowsB
                     << "). Cannot multiply.\n";
            } else {
                readMatrix(b, rowsB, colsB, "Matrix B");

                displayMatrix(a, rowsA, colsA, "Matrix A");
                displayMatrix(b, rowsB, colsB, "Matrix B");

                multiplyMatrices(a, b, rowsA, colsA, colsB, result);
                displayMatrix(result, rowsA, colsB, "Product (A x B)");
            }

        } else if (choice == 4) {
            cout << "\nExiting program. Goodbye!\n";
        } else {
            cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}

void readMatrix(int matrix[MAXSIZE][MAXSIZE], int rows, int cols, const string& name) {
    cout << "\nEnter elements for " << name << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[MAXSIZE][MAXSIZE], int rows, int cols, const string& title) {
    cout << "\n" << title << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[MAXSIZE][MAXSIZE], int rows, int cols,
                      int result[MAXSIZE][MAXSIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int a[MAXSIZE][MAXSIZE], int b[MAXSIZE][MAXSIZE], int rows, int cols,
                  int result[MAXSIZE][MAXSIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAXSIZE][MAXSIZE], int b[MAXSIZE][MAXSIZE],
                       int rowsA, int colsA, int colsB,
                       int result[MAXSIZE][MAXSIZE]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}