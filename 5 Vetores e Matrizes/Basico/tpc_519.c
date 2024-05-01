#include <stdio.h>
#include <string.h>

//Helper function for casting any number from char to int that was inputed through sdtin
int castInt(){
    char numero[10];
    fgets(numero, 10, stdin);
    int length = strlen(numero);
    if(numero[length - 1] == '\n'){
        numero[length - 1] = '\0';
    }
    int i = 0, num = 0;
    while(i < length){
        if(*(numero + i) >= '0' && *(numero + i) <= '9'){
            num = (*(numero + i) - '0') + 10*num;
        }
        i++; 
        }
    return num;    
}

//This is a mandatory item in the exercise's solution, but will also be used as a debug function, since it shows stuff in the terminal
void printSquareMatrix(int size, int (*matrix)[size]){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void writeMatrix(int size, int (*matrix)[size]){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("Please input the number for row %d col %d:\n", i, j);
            matrix[i][j] = castInt();
        }
    }
    printSquareMatrix(size, matrix);
}

void realCoeficient(int coeficient, int size, int (*matrix)[size]){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            matrix[i][j] *= coeficient;
        }
    }
    printSquareMatrix(size, matrix);
}

int main(){
    //I recommend using a smaller size for the matrix testwise.
    int matrix[4][4];
    writeMatrix(4, matrix);
    printf("\n");
    realCoeficient(2, 4, matrix);
    return 0;
}