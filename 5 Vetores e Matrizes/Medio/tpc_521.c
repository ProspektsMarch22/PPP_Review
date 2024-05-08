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

//Function for creating and returning an array, given the size of it by the user
//Corresponding to the given purpose of the exercise
int * createArray(int size){
    int * array = (int *)malloc(size * sizeof(int));
    return array;
}

//a.
void inputNumInArray(int * arr, int size){
    for(int i = 0; i < size; i++){
        printf("Input element number %d \n", (i + 1));
        *(arr + i) = castInt();
    }
}

//b.
void printArray(int * arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

//c.
int maxArray(int * arr, int size){
    int max = 0;
    for(int i = 0; i < size; i++){
        if(*(arr + i) > max){
            max = *(arr + i);
        }
    }
    return max;
}

//d.
int minArray(int * arr, int size){
    int min = maxArray(arr, size);
    for(int i = 0; i < size; i++){
        if(*(arr + i) < min){
            min = *(arr + i);
        }
    }
    return min;
}

//e.
int sumArray(int * arr, int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += *(arr + i);
    }
    return sum;
}

//f.
int meanArray(int * arr, int size){
    int sum = sumArray(arr, size);
    int mean = sum/size;
    return mean;
}

//g.
void belowMean(int * arr, int size){
    int mean = meanArray(arr, size);
    for(int i = 0; i < size; i++){
        if(*(arr + i) < mean){
            printf("%d ", *(arr + i));
        }
    }
    printf("\n");
}

//h.
void aboveMean(int * arr, int size){
    int mean = meanArray(arr, size);
    for(int i = 0; i < size; i++){
        if(*(arr + i) > mean){
            printf("%d ", *(arr + i));
        }
    }
    printf("\n");
}

int main() {
    int size;
    printf("How many elements would you like to work with?\n");
    printf("R: ");
    size = castInt();
    int * ptrArr = createArray(size);
    inputNumInArray(ptrArr, size);
    printArray(ptrArr, size);
    printf("The max number is: %d\n", maxArray(ptrArr, size));
    printf("The min number is: %d\n", minArray(ptrArr, size));
    printf("The mean of the sequence is: %d\n", meanArray(ptrArr, size));
    printf("The numbers below the average are: \n");
    belowMean(ptrArr, size);
    printf("The numbers above average are:\n");
    aboveMean(ptrArr, size);    
    free(ptrArr);
    printf("Exiting the program...\n");
    exit(0);
    return 0;
}