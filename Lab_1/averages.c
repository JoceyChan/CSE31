#include<stdio.h>

int main() 
{
    int num;
    int pos_count = 0;
    int neg_count = 0;
    int pos_sum = 0;
    int neg_sum = 0;
    
    printf("Please enter an integer: ");
    scanf("%d", &num);
    
    while(num != 0){
        if(num > 0){
            pos_sum += num;
            pos_count++;
        }
        else if(num < 0){
            neg_count++;
            neg_sum += num;
        }
        printf("Please enter an integer: ");
        scanf("%d", &num);
        
    }
    if(pos_count > 0 && neg_count > 0){
        printf("Positive average: %d\n", pos_sum/pos_count);
        printf("Negative average: %d\n", neg_sum/neg_count);
        }
    else if(neg_count > 0 && pos_count <=0){
        printf("Negative average: %d\n", neg_sum/neg_count);
        }
    else if(pos_count > 0 && neg_count <= 0){
        printf("Positive average: %d\n", pos_sum/pos_count);
    }
    else{
        printf("no averages");
    }
    
    return(0);
    
}
