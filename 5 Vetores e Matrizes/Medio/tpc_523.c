//Author: Isaac Barbosa
//Date of last update: 08/05/2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Helper function to receive numbers from stdin
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

//Helper function for creating the arrays
int * createArray(int size){
    int * array = (int *)malloc(size * sizeof(int));
    return array;
}

//Helper function for inputing numbers on the array
void inputNumInArray(int * arr, int size){
    for(int i = 0; i < size; i++){
        printf("Input element number %d \n", (i + 1));
        *(arr + i) = castInt();
    }
}

//Helper function for printing the array elements in the stdout
void printArray(int * arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

//This is an implementation with Selection Sort. The Selection Sort is a technique for sorting an array based on repeatedly finding the minimum element.
void sortSelectionAscending(int * arr, int size){
    int num;
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i]>arr[j]){
                num = arr[i];
                arr[i] = arr[j];
                arr[j] = num;
            }
        }
    }
}

int * mergeSortedArrays(int * arr1, int * arr2, int size1, int size2){
    int * merged = createArray((size1 + size2));
    
    //K is the index of the merged array
    //I is the index of the arr1
    //J is the index of arr2

    //The program simply compares the elements in both arrays, and searches for the minimum value. If one of the arrays is larger than the other, then it just adds the elements to the merged array, given that the arr1 and arr2 are already sorted.

    int k = 0, i = 0, j = 0;
    while(i < size1 && j < size2){
        if(arr1[i] < arr2[j]){
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while(i < size1){
        merged[k++] = arr1[i++];
    }

    while(j < size2){
        merged[k++] = arr2[j++];
    }

    return merged;
}

int main(){
    int size = 5;
    int *v1, *v2, *merged;
    v1 = createArray(size), v2  = createArray(size);
    int * arr[2] = {v1, v2};
    for(int i = 0; i < 2; i++){
        printf("For v%d\n", (i + 1));
        inputNumInArray(arr[i], size);
        sortSelectionAscending(arr[i], size);
        printArray(arr[i], size);
    }
    merged = mergeSortedArrays(v1, v2, size, size);
    printArray(merged, (size + size));

    //Free block
    free(v1);
    free(v2);
    free(merged);
}
