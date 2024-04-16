#include <stdio.h>

//This is a example of pointer comparison, a property of pointer arithmetic.

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr1 = arr + 1;
    int *ptr2 = arr + 3;

    if (ptr1 > ptr2){
        printf("ptr1 is after ptr2\n");
    } else if (ptr1 < ptr2){
        printf("ptr2 is after ptr1\n");
    } else {
        printf("ptr1 and ptr2 points to the same location\n");
    }
    return 0;
}