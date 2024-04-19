//Author: Isaac Barbosa
//Date: 19/04/2024

#include <stdio.h>


//The int (*arr)[sizeRow] is a implementation due to the 'type expected is int (*)[n]' problem

void printTable(int sizeCol, int sizeRow, int (*arr)[sizeRow]){
    int i = 0;
    while(i < sizeCol){
        int j = 0;
        while(j < sizeRow){
            printf("%d ", *(*(arr + i) + j));
            j++;
        }
        printf("\n");
        i++;
    }
}

int main(){
    int arr[3][4] = {{1,2,3,4}, {5,6,7,8}, {9, 0, 1, 2}};
    printTable(3, 4, arr);
    return 0;
}