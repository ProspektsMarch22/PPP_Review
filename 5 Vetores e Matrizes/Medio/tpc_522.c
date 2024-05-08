//Author: Isaac Barbosa
//Date of last update: 08/05/2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Again, i wil use the same helper functions as in 5.2.1, for casting inputs to int, and then creating an array, given the size by the user, and finally asking the user to input the elements of the array into it:
int castInt(){
    char number[10];
    fgets(number, 10, stdin);
    int len = strlen(number), num = 0;
    if(number[len - 1] == '\n'){
        number[len - 1] = '\0';
    }
    for(int i = 0; i < len; i++){
        if(number[i] >= '0' && number[i] <= '9'){
            num = (number[i] - '0') + 10*num;
        }
    }
    return num;
}

int * createArray(int size){
    int * array = (int *)malloc(size * sizeof(int));
    return array;
}

void inputNumInArray(int * arr, int size){
    for(int i = 0; i < size; i++){
        printf("Input element number %d \n", (i + 1));
        *(arr + i) = castInt();
    }
}

void trocaTroca(int * arr, int size){
    for(int i = 1; i < size; i++){
        int before = *(arr + (i - 1)), after = *(arr + (i + 1));
        if(i != (size - 1)){
            if(*(arr + i) < before && *(arr + i) > after){
            *(arr + (i - 1)) = after;
            *(arr + (i + 1)) = before;
            }
        }
    }
}

//I will utilise again one function from the last exercise, to display the elements in the stdout:
void printArray(int * arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main(){
    int size = castInt();
    int * ptrArr = createArray(size);
    inputNumInArray(ptrArr, size);
    //Prints original array
    printArray(ptrArr, size);
    trocaTroca(ptrArr, size);
    //Prints TrocaTroca array
    printArray(ptrArr, size);
    return 0;
}