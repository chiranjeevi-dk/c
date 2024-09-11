#include<stdio.h>

long fun(long n)
{
    if(n == 7) return 0;  // Base case returns 0 instead of NULL
    printf("%ld", n);     // Use %ld for printing long
    printf(" ");
    return fun(n+1);      // Recursive call
}

int main()
{
    printf("%ld", fun(5));  // Use %ld for printing long

}
