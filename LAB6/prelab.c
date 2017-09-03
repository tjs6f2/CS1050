/*Thomas Schultz
 * Lab: LAB6
 * Section: CS1050C
 * Pawprint: TJS6F2
 * Date: 3/05/17
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//setting and initializing the array
#define SIZE 50
int array[SIZE] = {0};

//prototypes
int check_error(int);
void set_array(int);
void print_array(int);

int main(void) {

    int num;

    printf("Enter the size of the input: ");
    scanf("%d", &num);

    while(check_error(num)==1) {
        printf("\nInvalid input enter the size of the input again: ");
        scanf("%d", &num);
    }

    set_array(num);

    printf("\nInput Array 1\n");

    print_array(num);

    set_array(num);

    printf("Input Array 2\n");

    print_array(num);

    return 0;
}

int check_error(int x) {//error checker

    if(x<=0 || x>50)
        return 1;

    return 0;
}

void set_array(int size) {//sets the values of the array

    int i;

    for(i=0; i<size; i++) {
        array[i]=(rand()%10);
    }
}

void print_array(int size) {//prints arrary

    int i;

    for(i=0; i<size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}



