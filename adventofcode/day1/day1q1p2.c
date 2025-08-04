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
        }else{
            if((current=='o')&&(i<=(length-2))&&(line[i+1]=='n')&&(line[i+2]=='e')){
                if(found_first != true){
                    firstnum = 1;
                    found_first = true;
                }else{
                    secondnum = 1;
                }
            }
            if((current=='t')&&(i<=(length-2))&&(line[i+1]=='w')&&(line[i+2]=='o')){
                if(found_first != true){
                    firstnum = 2;
                    found_first = true;
                }else{
                    secondnum = 2;
                }
            }
            if((current=='t')&&(i<=(length-4))&&(line[i+1]=='h')&&(line[i+2]=='r')&&(line[i+3]=='e')&&(line[i+4]=='e')){
                if(found_first != true){
                    firstnum = 3;
                    found_first = true;
                }else{
                    secondnum = 3;
                }
            }
            if((current=='f')&&(i<=(length-3))&&(line[i+1]=='o')&&(line[i+2]=='u')&&(line[i+3]='r')){
                if(found_first != true){
                    firstnum = 4;
                    found_first = true;
                }else{
                    secondnum = 4;
                }
            }
            if((current=='f')&&(i<=(length-3))&&(line[i+1]=='i')&&(line[i+2]=='v')&&(line[i+3]='e')){
                if(found_first != true){
                    firstnum = 5;
                    found_first = true;
                }else{
                    secondnum = 5;
                }
            }
            if((current=='s')&&(i<=(length-2))&&(line[i+1]=='i')&&(line[i+2]='x')){
                if(found_first != true){
                    firstnum = 6;
                    found_first = true;
                }else{
                    secondnum = 6;
                }
            }
            if((current=='s')&&(i<=(length-4))&&(line[i+1]=='e')&&(line[i+2]=='v')&&(line[i+3]=='e')&&(line[i+4]='n')){
                if(found_first != true){
                    firstnum = 7;
                    found_first = true;
                }else{
                    secondnum = 7;
                }
            }
            if((current=='e')&&(i<=(length-4))&&(line[i+1]=='i')&&(line[i+2]=='g')&&(line[i+3]=='h')&&(line[i+4]='t')){
                if(found_first != true){
                    firstnum = 8;
                    found_first = true;
                }else{
                    secondnum = 8;
                }
            }
            if((current=='n')&&(i<=(length-3))&&(line[i+1]=='i')&&(line[i+2]=='n')&&(line[i+3]='e')){
                if(found_first != true){
                    firstnum = 9;
                    found_first = true;
                }else{
                    secondnum = 9;
                }
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

    fptr = fopen("/home/invalid/storage/coding/c/adventofcode/day1/input1.txt", "r");
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
