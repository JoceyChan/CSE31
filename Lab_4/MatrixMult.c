
#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>


int** matMult(int **a, int **b, int size){
	// (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.
    int **ans = (int**)malloc(size*sizeof(int*));

    int i, j, k;

    for (i = 0; i < size; i++){
        *(ans + i) = (int *)malloc(sizeof(int) * size);
    }
    for(i=0;i<size;i++){
        for (k = 0; k < size; k++){
            int sum = 0;
            for (j = 0; j < size; j++){
                sum += *(*(a+i)+j) * *(*(b+k)+j);
            }
                *(*(ans+i)+k)= sum;
        
    }

    }

    return ans;

}

void printArray(int **arr, int n){
	// (2) Implement your printArray function here
    int i, j;
    
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%d ", *(*(arr+i)+j));
    }
        printf("\n");
    }
    printf("\n\n");
}

int main() {
	int n = 2, i=0, j=0;
	int **matA, **matB, **matC;
   
	// (1) Define 2 n x n arrays (matrices).
   
    matA = (int**)malloc(n * sizeof(int*));
    matB = (int**)malloc(n * sizeof(int*));

    for(int i = 0; i < n; i++){
        *(matA+i) = (int*)malloc(n * sizeof(int));
        *(matB+i) = (int*)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++){
            *(*(matA + i) + j) = i + 1;
            *(*(matB + i) + j) = j + i;
            
        }
    }


	// (3) Call printArray to print out the 2 arrays here.
    printf("Matrix-A is:\n");
    printArray(matA, n);
    printf("Matrix-B is:\n");
    printArray(matB, n);
	
	//(5) Call matMult to multiply the 2 arrays here.
    matC = matMult(matA, matB, n);
	
	//(6) Call printArray to print out resulting array here.
    printf("Multipication Martis is:\n");
    printArray(matC, n);


    return 0;
}
