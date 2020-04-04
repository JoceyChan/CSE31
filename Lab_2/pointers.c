#include<stdio.h>

int main()
{
    int x, y;
    int *px, *py;
    int arr[10] = {2,4,6,8,12,14,16,18,20};
    
    x = 2; //declared it to a variable in order to understand the process
    y = 4;
    
    printf("%d\n", x);
    printf("%d\n", y);
    
    px = &x;
    py = &y;
    
    printf("%p\n", &px);
    printf("%p\n", &py);
    
    for(int i = 0;i < 10; i++){
        printf("%d\n", *(arr + i));
    }
    
    if(arr == &arr[0]){
        printf("array names are the same as pointers and point to the same address \n");
    }
    else if( arr != &arr[0]){
        printf("array names are not the same as pointers and do not point to the same address \n");
    }
    
    printf("address of arr: %p\n", arr);
    printf("address of &arr[0]: %p\n", &arr[0]);

return 0;
}
