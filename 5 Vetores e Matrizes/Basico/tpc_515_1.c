//Author: Isaac Barbosa
//Date: 18/04/2024

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//The exercise states that i must "create an array", but since the related subject to this exercise is arrays and matrixes, i will define a function that receives an array as a first alternative.

//The alternative 2 will involve an actual array creation

//Helper function
int isPrime(int num){
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            return -1;
        }
    }
    return 0;
}

//Alternative 1
void prime1(int * arr, int n){
    int num = 1, i = 0;
    while(n > 0){
        if(isPrime(num) == 0){
            arr[i] = num;
            if(n == 1){
                printf("%d\n", arr[i]);
            } else {
                printf("%d ", arr[i]);
            }
            i++;
            n--;
        }
        num++;
    }
}

//Alternative 2
void prime2(int n){
    int initial = n;
    int * arr = (int *)malloc(n * sizeof(int));
    int num = 1;
    while(n > 0){
        if(isPrime(num) == 0){
            *(arr + (initial - n)) = num;
            if(n == 1){
                printf("%d\n", *(arr + (initial - n)));
            } else {
                printf("%d ", *(arr + (initial - n)));
            }
            n--;
        }
        num++;
    }
    free(arr);
}

int main(){
    //Alternative 1 code
    //int arr[10]
    //prime1(arr, 10);

    //Alternative 2 code
    prime2(10);
    return 0;
}