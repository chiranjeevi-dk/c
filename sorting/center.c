#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b){
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    int mid1 , mid2;

    int numsize = 0;

    while(num1!=0){
        if(numsize==3){
            mid1 = num1%10;
        }
        num1 = num1/10;
        numsize++;
    }
    numsize = 0;

    while(num2!=0){
        if(numsize==3){
            mid2 = num2%10;
        }
        num2 = num2/10;
        numsize++;
    }
    return num1 - num2;
}

void center(int *array, int size){
    qsort(array,size,sizeof(int),compare);
    for(int i =0; i < size;i++){
        printf("%d ",array[i]);
    }
}

int main(){

    int size = 0;
    printf("Enter the number of elements in the array : ");
    scanf("%d",&size);

    int *array = (int *)malloc( size * sizeof(int));

    printf("Enter the elements : ");
    
    for(int i = 0; i < size ; i++){
        scanf("%d",&array[i]);
    }

    int numsize = 0;
    int sample = array[0];
    while(sample != 0){
        sample = sample/10;
        numsize++;
    }

    center(array,size);
}