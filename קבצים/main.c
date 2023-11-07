#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exe1() {
    FILE *fptr;
    char buff[255];

    if ((fptr = fopen("H:\\C\\lesson 4\\txt files\\exe1.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    } else {
        while (fgets(buff, 255, (FILE *) fptr)) {
            printf("%s", buff);
        }
    }
    fclose(fptr);
}

void exe2() {
    FILE *fptr1, *fptr2;
    char buff[255];

    if ((fptr1 = fopen("H:\\C\\lesson 4\\txt files\\exe1.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    } else {
        fptr2 = fopen("H:\\C\\lesson 4\\txt files\\exe2.txt", "w");
        while (fgets(buff, 255, (FILE *) fptr1)) {
            fputs(buff, fptr2);
        }
    }
    fclose(fptr1);
    fclose(fptr2);
}

void exe3() {
    FILE *fptr1, *fptr2;
    char buff[255];

    if ((fptr1 = fopen("H:\\C\\lesson 4\\txt files\\exe1.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    } else {
        fptr2 = fopen("H:\\C\\lesson 4\\txt files\\exe3.txt", "w");
        while (fgets(buff, 255, (FILE *) fptr1) ){
            if (strlen(buff) >= 5) {
                fputs(buff, fptr2);

            }
        }
    }
    fclose(fptr1);
    fclose(fptr2);
}

int exe4() {
    FILE *fptr1, *fptr2;
    char buff1[255], buff2[255];


    if ((fptr1 = fopen("H:\\C\\lesson 4\\txt files\\exe1.txt", "r")) == NULL ||
        (fptr2 = fopen("H:\\C\\lesson 4\\txt files\\exe4.txt", "r")) == NULL) {
        return -1;
    }

    while (fgets(buff1, 255, (FILE *) fptr1) && fgets(buff2, 255, (FILE *) fptr2)) {
        if (strcmp(buff1, buff2) == 0){}
        else
            return 0;
    }
    fclose(fptr1);
    fclose(fptr2);
    return 1;
}

int main() {
//   exe1();
//    exe2();
//    exe3();
printf("%d\n", exe4());
    return 0;
}
