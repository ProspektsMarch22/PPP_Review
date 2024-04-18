#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Alternative 1
//Receives a previously created array in Main and then fills it with base ten algarisms until given size is met
void fillIntegerArray(int arr[], int size){
    int i = 0;
    while(i < size){
        int numChar = getchar();
        if(numChar >= '0' && numChar <= '9'){
            arr[i] = numChar - '0';
            i++;
        }
    }
}

//Alternative 2
//Receives a string, converts elements that are numbers in them, then fill a integer array and returns it, together with the integer array size. Must provide a double pointer array to store the pointers to the integer array and for the size. It's not stable yet.

int** createIntegerArray(char* str, int** data){
    int size = strlen(str);
    int i = 0, count32 = 0;
    while(i < size){
        if (*(str + i) == 32){
            count32++;
        }
        i++;
    }
    int sizeArr = size - count32;
    int *arr = (int *)malloc(sizeArr * sizeof(int));
    i = 0;
    int j = 0, num = 0;
    while(i < size){
        if(str[i] >= '0' && str[i] <= '9'){
            num = (str[i] - '0') + 10*num;
        } else {
            *(arr + j) = num;
            j++;
            num = 0;
        }
        i++;
    }

    data[0] = arr;
    data[1] = &sizeArr;
    return data;
}

//Verifies given array until met size, doubles odd elements encountered in them, then prints the array elements to stdout.
void doubleOdd(int arr[], int size){
    int i = 0;
    while(i < size){
        if(arr[i] % 2 != 0){
            arr[i] *= 2;
        }
        printf("%d ", arr[i]);
        i++;
    }
}   

int main(){
    //Here i'm using alternative 2 code
    char str[60];
    fgets(str, 15, stdin);
    int ** data = (int **)malloc(2*sizeof(int *));
    createIntegerArray(str, data);
    doubleOdd(*(data), **(data + 1));
    free(data);
}