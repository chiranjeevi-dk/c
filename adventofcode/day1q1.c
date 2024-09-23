#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

bool checknum(char current) {
    return (current >= '0' && current <= '9');
}

int number(char *line, size_t length) {
    int firstnum = -1, secondnum = -1;
    int current_num = 0;
    bool found_first = false;

    for(size_t i=0; i<length; i++){
        char current = line[i];

        if(checknum(current)){
            current_num = current - '0';
            if(found_first != true){
                firstnum = current_num;
                found_first = true;
            }else{
                secondnum = current_num;
            }
        }

    }
    int number;
    if(secondnum == -1){
        number = firstnum * 10 + firstnum;
    }else{
        number = firstnum * 10 + secondnum;
    }

    return number;
}

int main() {
    FILE *fptr;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fptr = fopen("input.txt", "r");
    if (fptr == NULL) {
        perror("Unable to open file!");
        exit(EXIT_FAILURE);
    }

    int total = 0;
    while ((read = getline(&line, &len, fptr)) != -1) {
        total += number(line, read);
    }

    printf("Total: %d\n", total);

    fclose(fptr);
    if (line) {
        free(line);
    }

    return EXIT_SUCCESS;
}
