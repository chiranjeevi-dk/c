#include<stdio.h>
#include<stdlib.h>
int add(int x, int y){
return x + y;
}

int subract(int x, int y){
return x - y;
}

int multiply(int x, int y){
return x * y;
}

int divide(int x, int y){
return x / y;
}

int (*selectoperation()) (int, int){
int option = 0;
printf("Select an operation:\n");
printf("1) add\n");
printf("2) subract\n");
printf("3) multiply\n");
printf("4) divide\n");
scanf("%d",&option);

int (*array[])(int, int) = {add, subract, multiply, divide};

if(option == 1) return array[0];
else if(option == 2) return array[1];
else if(option == 3) return array[2];
else if(option == 4) return array[3];
else return NULL;
}

int main(){

int (*operation) (int, int) = selectoperation();
printf("the answer is : %d\n", operation(500, 20));

return 0;
}