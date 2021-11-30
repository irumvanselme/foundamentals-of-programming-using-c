#include<stdio.h>
int findMax(int numbers[],int nums){
    int max = 0;
    for(int i = 0;i <nums;i++){
        if(numbers[i] > max){
            max = numbers[i];
        }
    }
    return max;
}
int main(){
    int n;
    printf("Enter the number of numbers you have \a\a\a : ");
    scanf("%d",&n);
    int numbers[n];
    for(int i = 0;i < n;i++){
        printf("Enter number %d : ",i+1);
        scanf("%d",&numbers[i]);
    }
    int max = findMax(numbers,n);
    printf("In Your numbers the maximum is %d",max);
    return 0;
}
