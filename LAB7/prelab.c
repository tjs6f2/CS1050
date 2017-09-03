/*Thomas Schultz
 * Lab: LAB7
 * Section: CS1050C
 * Pawprint: TJS6F2
 * TA: Dheeraj
 * Date: 3/13/17
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

//prototypes
int check_error(int);
void set_2Darray(int[MAX][MAX], int);
void print_2Darray(int [MAX][MAX], int);

int main(void) {

    srand(time(NULL));
    int array[MAX][MAX] = {};
    int num;

    printf("\nEnter the size of the 2-D array: ");
    scanf("%d", &num);

    while(check_error(num)==0){//call to check error function
        printf("Please enter a value between 1-20 only: ");
        scanf("%d", &num);
    }

    printf("\nThe first 2-D array is: \n");

    set_2Darray(array, num);

    print_2Darray(array, num);

    return 0;
}

int check_error(int x){

    if(x<=0 || x>=21)
        return 0;
    else
        return 1;

}

void set_2Darray(int a[MAX][MAX], int size) {

    int i;
    int j;

    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {

            a[i][j]=rand()%10;
        }
    }
}

void print_2Darray(int a[MAX][MAX], int size) {

    int i;
    int j;

    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
