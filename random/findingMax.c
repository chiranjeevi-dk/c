#include<stdio.h>
#include<stdlib.h>
void findingMaxPair(int *arr, int arrSize, int target){
    int maxPair[2];
    int maxValue = 0;
    maxPair[0]=0;
    maxPair[1]=0;
    for(int i=0;i<arrSize;i++){
        for(int j=0;j<arrSize;j++){
            if(i!=j){
                if(arr[i]+arr[j]==target && arr[i] * arr[j] >= maxValue){
                    maxValue = arr[i] * arr[j];
                    if(arr[i]>maxPair[0]){
                        int first = arr[i];
                        int second = arr[j];
                        maxPair[0] = first;
                        maxPair[1] = second;
                    }
                }
            }
        }
    }
    printf("%d,%d",maxPair[0],maxPair[1]);
}

int main(){

    int arrSize = 0 ;
    printf("Enter the size of array : ");
    scanf("%d",&arrSize);
    
    int *arr = (int *)calloc(arrSize,sizeof(int));
    printf("Enter the %d of elements to add in array :",arrSize);
    for(int i =0;i<arrSize;i++){
        scanf("%d",&arr[i]);
    }

    int target;
    printf("Enter the target : ");
    scanf("%d",&target);

    findingMaxPair(arr,arrSize,target);
}