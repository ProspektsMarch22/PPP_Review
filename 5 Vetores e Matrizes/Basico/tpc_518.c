#include <stdio.h>

void mirrorMatrix(int size, char * header){
    int matrix[size + 1][size + 1];
    int i = 0;
    while(i < (size + 1)){
        int j = 0;
        if(i == 0 && j == 0){
                matrix[i][j] = 0;
                printf("%s ", header);
        }
        if(j == 0 && i != 0){
            matrix[i][j] = i;
            printf("%d ", matrix[i][j]);
        }
        while(j < (size + 1)){
            if(i == 0 && j != 0){
                matrix[i][j] = j;
                printf("%d ", matrix[i][j]);
            }
            //For a future implementation, i could nest the ifs inside an if(i!=0 && j!= 0) for the sake of readability
            if(i != 0 && j != 0 && i == j){
                matrix[i][j] = 0;
                printf("%d ", matrix[i][j]);
            }
            if(i!= 0 && j!= 0 && j > i){
                matrix[i][j] = ((j - i) + 1) * 10;
                printf("%d ", matrix[i][j]);
            } else if (i != 0 && j != 0 && j < i){
                matrix[i][j] = ((i - j) + 1) * 10;
                printf("%d ", matrix[i][j]);
            }
            j++;
        }
        i++;
        printf("\n");
    }
}

int main(){
    mirrorMatrix(10, "countries");
    return 0;
}