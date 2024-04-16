#include <stdio.h>

//This a example of accessing values of a struct with pointers

typedef struct{
    int id;
    char name[20];
} Employee;

//Prints data of a employee
void print_emp(Employee *emp){
    printf("Id: %d\n", emp->id);
    printf("Name: %s\n", emp-> name);
}

//Another way of accessing fields within a structure besides the ->, is to use (*ep).field

int main(){
    Employee Isaac = {1234, "Isaac"};
    print_emp(&Isaac);
    return 0;
}