/*
    Author: Adrian C. Manatad
    Reason: FOR COMMISION
    DATE: APRIL 19, 2022
    CLIENT NAME: DUKE GARCIA

    [1 2]     [5 6]   [1*5 + 2*0 1*6 + 2*7]   [05 20]
           X        =                       =
    [3 4]     [0 7]   [3*5 + 4*0 3*6 + 4*7]   [15 46]
*/
#include <stdio.h>

void matInput(int mat[10][10],int,int);// Function declarations
void matPrint(int mat[10][10],int,int);// Function declarations
void matMultiply(int mat1[10][10], int mat2[10][10], int res[10][10],int,int);// Function declarations

int main() {
    int mat1[10][10];//array size
    int mat2[10][10];//array size
    int product[10][10];//array size
    int x,y;

    printf("Numbers of row: ");
    scanf("%d",&x);//prompt the user to input the value of x
    printf("Numbers of column: ");
    scanf("%d",&y);//prompt the user to input the value of y

    //Input elements in matrices.
    printf("Enter elements in first matrix of size %dx%d\n", x, y);//display output

    //function call
    matInput(mat1,x,y);//passing the value of x and y inside the function

    printf("Enter elements in second matrix of size %dx%d\n", x, y);
    //function call
    matInput(mat2,x,y);//passing the value of x and y inside the function

    // Call the function to multiply both matrices
    matMultiply(mat1, mat2, product, x, y);//passing the value of x, y, mat1, mat2 inside the function

    printf("First Matrix is: \n");
    // Print first matrix
    matPrint(mat1,x,y);//Call the function to display the matrix1

    printf("Second Matrix is: \n");
    // Print Second matrix
    matPrint(mat2,x,y); //Call the function to display the matrix1

    // Print product of both matrix
    printf("Product of both matrices is : \n");
    matPrint(product, x, y);//Call the function to display the product of both matrix

    return 0;
}

//Function definition
void matInput(int mat[10][10],int col,int row){ //to input elements in matrix from user.
    int i,j;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("Enter element (%d %d): ",i,j);
            //scanf("%d", &mat[i][j]);
            scanf("%d", (*(mat + i) + j));
        }
    }
}


//Function definition
void matMultiply(int mat1[10][10], int mat2[10][10], int res[10][10],int Row,int Col) {// to multiply two matrices.
    int i, j, k;
    int sum;

    for (i = 0; i < Row; i++) {
        for (j = 0; j < Col; j++) {
            sum = 0;

            //Find sum of product of each elements of rows of first matrix and columns of second matrix.
            for (k = 0; k < Col; k++) {
                //sum += mat1[i][k] * mat2[k][j];
                sum += (*(*(mat1 + i) + k)) * (*(*(mat2 + k) + j));
            }

            //Store sum of product of row of first matrix and column of second matrix to resultant matrix.
            //res[i][j] = sum;
            *(*(res + i) + j) = sum;
        }
    }
}


//Function definition
void matPrint(int mat[10][10],int col,int row) { //to print elements in a two-dimensional array.
    int i,j;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            //printf("%d ", mat[i][j]);
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}
