#include<stdio.h>
#include<stdlib.h>

int main()
{
int n;
int l;

printf("Enter the number of lines for the punishment: ");
scanf("%d", &n);
if(n <= 0)
{
printf("You entered an incorrect value for the number of lines!");
exit(0);
}
printf("Enter the line for which we want to make a typo: ");
scanf("%d", &l);
if(l <= 0 || l > n)
{
printf("You entered an incorrect value for the line typo!!");
exit(0);
}

int i;
    for(i = 0; i < n; i++)
    {
        if(i + 1 == l){
            printf("C programming langauge is the bet!");
        }
        else
        {
            printf("C programming language is the best!");
        }}
    return(0);
    }
