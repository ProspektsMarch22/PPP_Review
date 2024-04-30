//Author: Isaac Barbosa
//Date: 19/04/2024

#include <stdio.h>

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

void transposeTable(int sizeCol, int sizeRow, int (*arr)[sizeRow]){
    int trans[sizeRow][sizeCol];
    for(int i = 0; i < sizeCol; i++){
        for(int j = 0; j < sizeRow; j++){
            *(*(trans + j) + i) = *(*(arr + i) + j);
        }
    }
    //In order to print correctly, i must also invert the row and col on the printTable arguments
    printTable(sizeRow, sizeCol, trans);
}

int main(){
    int arr[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    printTable(2, 4, arr);
    transposeTable(2, 4, arr);
    return 0;
}