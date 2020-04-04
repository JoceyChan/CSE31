#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void printArr(int *a, int size){
	//Your code here
    int i;
    printf("\nprintArr: \n");
    for(i = 0; i < size; i++){
        printf("%d", *(a+i));
    }
}

int* arrCopy(int *a, int size){
	//Your code here
    int* cop, i;
    
    cop = (int*)malloc(sizeof(int)*size);
    for(i = 0; i < size; i++){
        *(cop+i) = *(a+i);
    }
    return cop;
}

int main(){
    int n;
    int *arr;
    int *arr_copy;
    int i;
    printf("Enter size of array:");
    scanf("%d",&n);

    //Dynamically create an int array of n items
    //Your code here
    
    arr = (int*)malloc(sizeof(int)*n);
    arr_copy = (int*)malloc(sizeof(int)*n);

    //Ask user to input content of array
	//Your code here
    for(int i = 0;i < n;i++){
        printf("Enter array content # %d", (i+1));
        printf(": ");
        scanf("%d", (arr+i));
    }
              
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	//Print original array
    printArr(arr, n);


	//Copy array
    arr_copy = arrCopy(arr, n);

	//Print new array
    printArr(arr_copy, n);

    return 0;
}
