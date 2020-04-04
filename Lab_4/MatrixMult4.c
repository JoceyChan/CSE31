
#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>

int** matMult(int **a, int **b, int size){
	// (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.
    int** mat2 = (int**)malloc(sizeof(int)*size);
    int j ,k;
    
    for(int i = 0;i < size; i++){
        mat2 = (int*)malloc(sizeof(int)*size);
        for(j = 0; j < size; j++){
            int add = 0;
            for(k = 0; k < size; k++){
                add += a[i][k] * b[k][j];
                mat2[i][j] = add;
            }
        }
        return mat2;
    }

}

void printArray(int **arr, int n){
	// (2) Implement your printArray function here
    int i, j;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%d\t", arr[i][j]);
            printf("\n");
            
        }
        
    }

}

int main() {
	int n=0, o=0;
	int **matA, **matB, **matC;
	// (1) Define 2 n x n arrays (matrices).
    printf("Enter num of rows for the array: ");
    scanf("%d", &n);
    printf("Enter num of columns for the array: ");
    scanf("%d", &o);

    
    matA = (int **)malloc(sizeof(int) * n);
    
    printf("Enter %d elements for Matrix A: \n");
    for (int i = 0; i < n; ++i){
        for(int j = 0; j< o; ++j){
            printf("Enter the elemesnts for the array p%d%d: ", i+1,j+1);
            scanf("%d", &p[i][j]);
        }
        printf("Enter %d elements for Matrix B: \n");
        for (int i = 0; i < n; ++i){
        for(int j = 0; j< o; ++j){
            printf("Enter the elemesnts for the array p%d%d: ", i+1,j+1);
            scanf("%d", &b[i][j]);
        }
       
    }

	// (3) Call printArray to print out the 2 arrays here.
	
	
	//(5) Call matMult to multiply the 2 arrays here.
	
	
	//(6) Call printArray to print out resulting array here.



    return 0;
}
