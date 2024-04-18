//Author: Isaac Barbosa
//Date: 18/04/2024

#include <stdio.h>
#include <string.h>


//Sice the question don't explicitly asks for a function, but only a program, there's no modularity in this case. Although, it's possible to transfer the logic to a couple of functions.

int main(){

    char str[60];
    fgets(str, 60, stdin);
    int arr[10], num = 0, j = 0;
    size_t i = 0;
    while(i < strlen(str)){
        if(str[i] >= '0' && str[i] <= '9'){
            num = (str[i] - '0') + 10*num;
        } else {
            arr[j] = num;
            num = 0;
            j++;
        }
        i++;
    }

    int revArr[10], k = 0;
    while(j > 0){
        revArr[k] = arr[j - 1];
        printf("%d ", revArr[k]);
        j--;
        k++;
    }

    return 0;
}