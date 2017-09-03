/*Thomas Schultz
 * Lab: LAB9
 * Section: CS1050C
 * TA: Dheeraj
 * Date: 4/3/17
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50

//prototypes
int check_size(int);
void initialize_array(int *, int);
void print_array(int *, int);
float mean(int *, int);

int main(void) {

    int array[MAX] = {0};
    int *p=0;
    p=array;
    int num;

    printf("Enter the size of the input: ");
    scanf("%d", &num);

    while(check_size(num)==0) {
        printf("\nInvalid input enter the size of the array again: ");
        scanf("%d", &num);
    }

    initialize_array(p, num);

    printf("\nInput Array\n");

    print_array(p, num);

    printf("Average is: %0.2f\n", mean(p, num));

    return 0;
}

int check_size(int num) {

    if(num<=0 || num>50)
        return 0;
    else
        return 1;
}

void initialize_array(int *p, int size) {
    srand(time(NULL));
    int i=0;

    for(i=0; i<size; i++) {
        *(p+i) = (1+ rand()%5);
    }
}

void print_array(int *p, int size) {
    int i=0;

    for(i=0; i<size; i++){
        printf("%d ", *(p+i));
    }
    printf("\n");
}

float mean(int *p, int size) {

    float mean=0;
    int i=0;

    for(i=0; i<size; i++) {
        mean = mean + *(p+i);
    }
    return mean/size;
}




