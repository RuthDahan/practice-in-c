#include <stdio.h>
#include <string.h>

#define MAX_LEN 5
#define COLUMNS_NUMBER 6
struct person
{
    char name[MAX_LEN];
    int roomNumber;
} arr[5];
typedef struct person person;

void EmployeeSystem(int arrLen, person arr[])
{
    person p;
    for (int i = 0; i < arrLen; ++i) {
        for (int j = 0; j < arrLen; ++j) {
            if(arr[j].roomNumber > arr[i].roomNumber){
                p = arr[j];
                arr[j] = arr[i];
                arr[i] = p;
            }
        }
    }
    for (int k = 0; k < arrLen; k+=6) {
        for (int i = 0; i < COLUMNS_NUMBER && i<arrLen; i++) {
            if(arr[i].roomNumber != arr[i-1].roomNumber){
                printf("%5d" , arr[i].roomNumber);
            }
        }
        printf("\n");
        for (int i = 0; i < COLUMNS_NUMBER && i<arrLen; i++) {
            if(arr[i].roomNumber == arr[i-1].roomNumber) {
                printf("\n");
            }
            printf("%5s", arr[i].name);
        }
    }
}


int main() {
    strcpy(arr[0].name, "Dani");
    arr[0].roomNumber = 1;
    strcpy(arr[1].name , "Yosi");
    arr[1].roomNumber = 3;
    strcpy(arr[2].name , "Yaeli");
    arr[2].roomNumber = 2;
    strcpy(arr[3].name, "Chani");
    arr[0].roomNumber = 5;
    strcpy(arr[4].name, "Ruti");
    arr[0].roomNumber = 4;
    EmployeeSystem(5, arr);
    return 0;
}
