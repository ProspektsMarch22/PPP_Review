//Author: Isaac Barbosa
//Date of last update: 08/05/2024

//This is an example of the Selecting Sort technique for sorting an integer array in ascending order

#include <stdio.h>

//In the Slecting Sort technique, the objective is to find the minimum value repeatedly, and then sort the array based on this.

void selectSort(int * arr, int size){
    int num;
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i] > arr[j]){
                num = arr[i];
                arr[i] = arr[j];
                arr[j] = num;
            }
        }
    } 
}