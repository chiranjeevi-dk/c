#include <stdio.h>
#include <unistd.h>

int main(){
    void *current_break;

    current_break = sbrk(0);
    printf("The current page break is at : %p\n", current_break);

    return 0;
}