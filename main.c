#include <stdio.h>
#include <stdlib.h>

// matrix dimensions defined as constants for easy modification
#define A 3  // number of rows
#define B 2  // number of columns

/* define a two-dimensional integer array (matrix) with A(3) rows and B(2) columns.

        write a function that takes the elements of this matrix from the user.
        write a function that prints the entered matrix to the screen in an organized format.
        write a function that calculates the matrix's:
            *maximum element,
            *minimum element,
            *sum of its elements
            and sends these values back to the main program using addresses (by using pointers).

        print the maximum, minimum, and sum values to the screen.*/


// takes matrix elements as input from the user
void createTable(int matrix[A][B]){

    int i, j;

    printf("enter the elements of the matrix:\n");

    for(i=0; i<A; i++){
        for(j=0; j<B; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\n");
}

// prints the matrix to the screen in a formatted layout
void printTable(int matrix[A][B]){

    int i, j;

    printf("the matrix is:\n");

    for(i=0; i<A; i++){
        for(j=0; j<B; j++){
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*
  calculates the maximum, minimum, and sum of matrix elements.
  results are returned via pointers (max, min, sum).
*/
void calculations(int matrix[A][B], int *max, int *min, int *sum){

    int i, j;

    // initialize max, min with the first element and sum with 0
    *max = matrix[0][0];
    *min = matrix[0][0];
    *sum = 0;

     for(i = 0; i < A; i++) {
        for(j = 0; j < B; j++) {
            if(matrix[i][j] > *max) {
                *max = matrix[i][j];  // update max if larger value found
            }
            if(matrix[i][j] < *min) {
                *min = matrix[i][j];  // update min if smaller value found
            }
            *sum += matrix[i][j];     // accumulate sum
        }
    }
}

int main()
{
    int matrix[A][B], max, min, sum;

    createTable(matrix); // get matrix input from user
    printTable(matrix); // display the matrix
    calculations(matrix, &max, &min, &sum); // compute statistics

    printf("%d is the maximum value, %d is the minimum value and %d is the sum of all elements.\n", max, min, sum);

    return 0;
}
