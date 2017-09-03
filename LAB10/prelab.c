/*Thomas Schultz
 * LAB: LAB10
 * SECTION: CS1050C
 * TA: Dheeraj
 * Date:
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//prototypeps
void set_array(int *, int);
void print_array(int *, int);
float mean(int *, int);
int max(int *, int);
int min(int *, int);

int main(void) {

    int *p;
    p = malloc(sizeof(int)*10);
    int size = 10;

    if(p==NULL) {
        printf("Error: Out of memory\n");
        return 1;
    }

    set_array(p, size);

    print_array(p, size);

    printf("The average number in the array is: %.2lf\n", mean(p, size));

    printf("The largest number in the array is: %d\n", max(p, size));

    printf("The smallest number in the array is: %d\n", min(p,size));


    return 0;

}

void set_array(int *p, int size){

    srand(time(NULL));
    int i;

    for(i=0; i<size; i++) {
        *(p+i)= 1 + (rand()%5);
    }
}

void print_array(int *p, int size) {
    int i;

    for(i=0; i<size; i++) {
        printf("%d ", *(p+i));
    }
    printf("\n");
}

float mean( int *p, int size) {

    int i;
    float mean;

    for(i=0; i<size; i++) {
        mean+=*(p+i);
    }
    mean/=size;

    return mean;
}

int max( int *p, int size) {

    int i;
    int location;
    int max;

    max=*p;
    location =0;

    for(i=0; i<size; i++) {
        if(*(p+i)>max) {
            max=*(p+i);
            location = *(p+i);
        }
    }

    return location;
}

int min(int *p, int size) {

    int i;
    int location;
    int min;

    min=*p;
    location=0;

    for(i=0; i<size; i++) {
        if(*(p+i)<min) {
            min=*(p+i);
            location= *(p+i);
        }
    }

    return location;
}

