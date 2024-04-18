//Author: Isaac Barbosa
//Date: 18/04/2024

#include <stdio.h>
#include <string.h>

//The exercise demands that the integers are put into the "adequate structure", but after that, it imposes the use of arrays. So, i will not be using structs in this suggested answer.

//I am also presuming that when the exercise says "write a program that reads a set of 10 integers", the program is reading them from stdin.

void readInt(int* arr, int n){
    char str[60];
    fgets(str, 60, stdin);
    size_t i = 0;
    int num = 0, j = 0;
    while(i < strlen(str) && n > 0){
        if(str[i] >= '0' && str[i] <= '9'){
            num = (str[i] - '0') + 10*num;
        } else {
            arr[j] = num;
            n--;
            j++;
            num = 0;
        }
        i++;
    }
}

int maxNum(int* arr, int sizeArr, int start){
    int max = -1;
    for(int i = start; i < sizeArr; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int main(){
    int arr[10];
    readInt(arr, 10);
    int max = maxNum(arr, 10, 5);
    printf("The max is: %d\n", max);
    return 0;
}