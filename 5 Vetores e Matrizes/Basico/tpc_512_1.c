//Author: Isaac Barbosa
//Date: 18/04/2024
#include <stdio.h>
#include <string.h>

void arraySum(double* arr1, double* arr2, double* arr3, int size){
    for(size_t i = 0; i < ((size_t)size); i++){
        arr3[i] = arr1[i] + arr2[i];
        printf("%lf ", arr3[i]);
    }
};

void writeArr(double* arr){
    char str[30];
    fgets(str, 30, stdin);
    int num = 0, i = 0, j = 0;
    while(i < (int)strlen(str)){
        if(str[i] >= '0' && str[i] <= '9'){
            num = (str[i] - '0') + 10*num;
        } else {
            arr[j] = num;
            j++;
            num = 0;
        }
        i++;
    }
}

int main(){
    
    //Test is being made with a string with five numbers, of up to 5 digits each, with max of 1 character space per number

    double arr1[5], arr2[5], arr3[5];

    printf("Write array 1:\n");
    writeArr(arr1);

    printf("Write array 2:\n");
    writeArr(arr2);

    arraySum(arr1, arr2, arr3, 5);
    return 0;
}